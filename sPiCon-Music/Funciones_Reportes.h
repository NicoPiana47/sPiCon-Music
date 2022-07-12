#ifndef FUNCIONES_REPORTES_H_INCLUDED
#define FUNCIONES_REPORTES_H_INCLUDED
///PROTOTIPOS
void menuReportes();
void punto1();
int buscarTipodeArticulo(const char *cod);
//////////////
void punto1din();
int buscarRegistrosDetalle();
void copiarArchivoDetalles(DetalleV *,int);
void contarVentasPorTipo(DetalleV *, int);
//////////////
void punto2();
bool gastoMenos3000(int );
void punto2din();
///////////
void punto3din();
void setearCantidadVentas(Cliente2 *,int ,int );
void mostrarClientes2();
///DESARROLLO
void menuReportes(){
    char opc;
    while(true){
        system("color DF");
        rlutil::hidecursor();
        recuadro(6, 2, 109, 27, 15, 5);
        rlutil::locate(59,6);
        cout<<"Menu Reportes";
        recuadro(32, 7, 60, 18, 15, 5);
        rlutil::locate(34,9);
        cout<<"1) CANTIDAD DE VENTAS DE CADA TIPO";
        rlutil::locate(34,10);
        cout<<"2) CANTIDAD DE VENTAS DE CADA TIPO DIN";
        rlutil::locate(34,11);
        cout<<"3) CANTIDAD DE NO MUSICOS QUE GASTARON MENOS DE 30000 ";
        rlutil::locate(34,12);
        cout<<"4) CANTIDAD DE NO MUSICOS QUE GASTARON MENOS DE 30000 DIN";
        rlutil::locate(34,13);
        cout<<"5) ARCHIVO NUEVO CON PROPIEDAD DE CANTIDAD DE VENTAS DIN";
        rlutil::locate(34,14);
        cout<<"6) MOSTRAR REGISTROS DEL ARCHIVO NUEVO";
        rlutil::locate(34,15);
        cout<<"";
        rlutil::locate(37,16);
        cout<<"";
        rlutil::locate(33,17);
        cout<<"-----------------------------------------------------------";
        rlutil::locate(34,21);
        cout<<"0) VOLVER AL MENU PRINCIPAL";
        rlutil::locate(45,23);
        cout<<"INGRESE UNA OPCION";
        opc=getch();
        system("cls");
        system("color DF");
        switch(opc){
            case '1':
                punto1();
                break;
            case '2':
                punto1din();
                break;
            case '3':
                punto2();
                break;
            case '4':
                punto2din();
                break;
            case '5':
                punto3din();
                break;
            case '6':
                mostrarClientes2();
                break;
            case '0':
                return;
                break;
            default:
                recuadro(6, 2, 109, 27, 15, 5);
                recuadro(50,13, 18, 2, 15, 5);
                rlutil::locate(51,14);
                cout<<"OPCION INCORRECTA";
                break;
        }
        system("pause>null");
        system("cls");
    }
}

void punto1(){
    DetalleV obj;
    int pos=0,vTipo[4]={},tipo;
    while(obj.leerDeDisco(pos)){
        tipo=buscarTipodeArticulo(obj.getCodigo());
        if(tipo!=-1) vTipo[tipo-1]++;
        pos++;
    }
    for(int i=0;i<4;i++){
        cout<< "TIPO "<<i+1<<"\t"<<vTipo[i]<<endl;
    }
}
int buscarTipodeArticulo(const char *cod){
    Instrumento obj;
    int pos=0;
    while(obj.leerDeDisco(pos)){
        if(obj==cod){
            return obj.getTipo();
        }
        pos++;
    }
    return -1;
}
///////////////////////////////
void punto1din(){
    DetalleV *pDetalle;
    int cantReg=buscarRegistrosDetalle();
    pDetalle=new DetalleV [cantReg];
    if(pDetalle==NULL) return;

    copiarArchivoDetalles(pDetalle,cantReg);
    contarVentasPorTipo(pDetalle,cantReg);
    delete(pDetalle);

}

int buscarRegistrosDetalle(){
    FILE *p;
    p=fopen("detallev.dat", "rb");
    if(p==NULL)
        return -1;
    fseek(p, 0,2);
    int cantByte=ftell(p);
    fclose(p);
    return cantByte/sizeof(DetalleV);
}
void copiarArchivoDetalles(DetalleV *p,int cantReg){
    int i;
    for(i=0; i<cantReg; i++){
        p[i].leerDeDisco(i);
    }
}
void contarVentasPorTipo(DetalleV *p, int cantReg){
    int vTipo[4]={};
    for(int i=0; i<cantReg; i++){
        int tipo=buscarTipodeArticulo(p[i].getCodigo());
        if(tipo!=-1) vTipo[tipo-1]++;
    }

    for(int i=0;i<4;i++){
        cout<< "TIPO "<<i+1<<"\t"<<vTipo[i]<<endl;
    }
}
///////////////////////
void punto2(){
    Cliente obj;
    int pos=0,c=0;
    while(obj.leerDeDisco(pos)){
        if(obj.getMusico()=='N'){
            bool gastoMenos=gastoMenos3000(obj.getDni());
            if(gastoMenos==true){
                c++;
            }
        }
        pos++;
    }
    cout<<c;
}

bool gastoMenos3000(int dni){
    Venta obj;
    int pos=0;
    while(obj.leerDeDisco(pos)){
        if(obj.getDni()==dni){
            if(obj.getImporte()<30000){
                return true;
            }
        }
        pos++;
    }
    return false;
}
/////////////////////
void punto2din(){
    Cliente *pCliente;
    int cantReg=contarClientes();
    pCliente=new Cliente [cantReg];
    if(pCliente==NULL) return;

    copiarArchivoEnVector(pCliente,cantReg);
    int c=0;
    for(int i=0;i<cantReg;i++){
        if(pCliente[i].getMusico()=='N'){
            bool gastoMenos=gastoMenos3000(pCliente[i].getDni());
            if(gastoMenos==true){
                c++;
            }
        }
    }
    cout<<c;
    delete(pCliente);
}
//////////////
void punto3din(){
    Cliente obj;
    Cliente2 *paux;
    int cantReg=contarClientes();
    paux=new Cliente2[cantReg];
    if(paux==NULL) return;

    int pos=0;
    while(obj.leerDeDisco(pos)){
        paux[pos].setApellido(obj.getApellido());
        paux[pos].setNombre(obj.getNombre());
        paux[pos].setDni(obj.getDni());
        setearCantidadVentas(paux,cantReg,pos);
        paux[pos].setEstado(true);
        paux[pos].grabarEnDisco();
        pos++;
    }
    cout<<"se creo";
}

void setearCantidadVentas(Cliente2 *v,int cantReg,int pos){
    Venta obj;
    int pos2=0,venta=0;
    while(obj.leerDeDisco(pos2)){
        if(v[pos].getDni()==obj.getDni()){
            venta++;
        }
        pos2++;
    }
    v[pos].setCantVentas(venta);
}

void mostrarClientes2(){
    Cliente2 obj;
    int pos=0;
    while(obj.leerDeDisco(pos)){
        obj.Mostrar();
        pos++;
    }
    if(pos==0){
        recuadro(6, 2, 109, 27, 15, 5);
        cuadro(44,77,15,17);
        rlutil::locate(45,16);
        cout<<"NO SE CARGARON REGISTROS TODAVIA";
    }
}
#endif // FUNCIONES_REPORTES_H_INCLUDED
