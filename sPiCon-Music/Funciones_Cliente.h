#ifndef FUNCIONES_CLIENTE_H_INCLUDED
#define FUNCIONES_CLIENTE_H_INCLUDED

///PROTOTIPOS
void menuCliente();
void agregarCliente();
void listarClientexDni();
void listarCliente();
int borrarCliente();
int buscarDni(int dni,bool borrado=false);
int modificarFechaNac();
///ORDENAMIENTO DINAMICO
void listarClientesOrdenado();
int contarClientes();
void copiarArchivoEnVector(Cliente *pCliente,int cantReg);
void ordenarVectorClientes(Cliente *pCliente,int cantReg);
void mostrarVectorClientes(Cliente *pCliente,int cantReg);
///DESARROLLO
void menuCliente(){
    char opc;
    while(true){
        system("color DF");
        rlutil::hidecursor();
        recuadro(6, 2, 109, 27, 15, 5);
        rlutil::locate(55,6);
        cout<<"Menu Clientes";
        recuadro(44, 7, 35, 15, 15, 5);
        rlutil::locate(46,9);
        cout<<"1) AGREGAR CLIENTE";
        rlutil::locate(46,10);
        cout<<"2) LISTAR CLIENTE POR DNI";
        rlutil::locate(46,11);
        cout<<"3) LISTAR TODOS LOS CLIENTES";
        rlutil::locate(46,12);
        cout<<"4) LISTAR LOS CLIENTES POR ANIO";
        rlutil::locate(46,13);
        cout<<"5) MODIFICAR FECHA DE NACIMIENTO ";
        rlutil::locate(46,14);
        cout<<"6) ELIMINAR CLIENTE";
        rlutil::locate(45,15);
        cout<<"----------------------------------";
        rlutil::locate(46,16);
        cout<<"0) VOLVER AL MENU PRINCIPAL";
        rlutil::locate(52,19);
        cout<<"INGRESE UNA OPCION";
        opc=getch();
        system("cls");
        system("color DF");
        switch(opc){
            case '1':
                agregarCliente();
                break;
            case '2':
                listarClientexDni();
                break;
            case '3':
                listarCliente();
                break;
            case '4':
                listarClientesOrdenado();
                break;
            case '5':
                modificarFechaNac();
                break;
            case '6':
                borrarCliente();
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
///AGREGA CLIENTES
void agregarCliente(){
    Cliente obj;
    int long long dni,encontro;
    recuadro(6, 2, 109, 27, 15, 5);
    rlutil::locate(51,6);
    cout<<"Agregar Clientes";
    recuadro(40, 7, 40, 11, 15, 5);
    rlutil::locate(47,8);
    cout<<"DNI: ";
    cin>>dni;
    encontro=buscarDni(dni,1);
    if(encontro==-1){
        if(obj.Cargar(dni)!=false){
            if(obj.grabarEnDisco()!=1){
                recuadro(51,19, 17, 2, 15, 5);
                rlutil::locate(52,20);
                cout<<"ERROR DE ARCHIVO";
            }
            else{
                recuadro(50,20, 20, 2, 15, 5);
                rlutil::locate(51,21);
                cout<<"REGISTRO AGREGADO!";
            }
        }
    }
    else if(encontro==-2){
        recuadro(31,19, 57, 2, 15, 5);
        rlutil::locate(33,20);
        cout<<"YA SE AGREGO UN REGISTRO CON ESTE DNI PERO FUE BORRADO";
    }
    else{
        recuadro(40,19, 40, 2, 15, 5);
        rlutil::locate(42,20);
        cout<<"YA EXISTE UN REGISTRO CON ESTE DNI";
    }
}

///LISTA CLIENTES POR DNI
void listarClientexDni(){
    Cliente obj;
    int pos=0,dni;
    recuadro(6, 2, 109, 27, 15, 5);
    rlutil::locate(46,6);
    cout<<"Listar Cliente por DNI";
    recuadro(40, 7, 40, 2, 15, 5);
    rlutil::locate(47,8);
    cout<<"DNI: ";
    cin>>dni;
    ///TRAE LA POSICION Y LA LEE
    pos=buscarDni(dni);
    if(pos!=-1){
        obj.leerDeDisco(pos);
        obj.Mostrar(1);
    }
    else{
        recuadro(49,19, 19, 2, 15, 5);
        rlutil::locate(50,20);
        cout<<"DNI NO ENCONTRADO";
    }
}

void listarCliente(){
    Cliente obj;
    int pos=0, y=7;
    rlutil::locate(48,2);
    cout<<"Listado Clientes";
    while(obj.leerDeDisco(pos)==true){

        obj.Mostrar(0, y);
        for(int i=3;i<115;i++){
            rlutil::locate(i,y-2);
            cout<<(char) 205;
        }
        pos++;
        if(obj.getEstado()==true){
            y+=3;
        }
    }
    cuadro(3,115,3,y-2);
    if(pos==0){
        recuadro(3, 2, 109, 27, 15, 5);
        cuadro(44,77,15,17);
        rlutil::locate(45,16);
        cout<<"NO SE CARGARON REGISTROS TODAVIA";
    }
}

int buscarDni(int dni,bool borrado){
    Cliente obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==1){
            if(obj.getDni()==dni){
                    if(obj.getEstado()==true){
                            return pos;
                    }
                    else{
                        if(borrado==false){
                            return -1;
                        }
                        else{
                            return -2;
                        }
                    }
            }
            pos++;
    }
    return -1;
}
///BORRA CLIENTES
int borrarCliente(){
    recuadro(6, 2, 109, 27, 15, 5);
    Cliente obj;
    int pos=0,escribio;
    int dni;
    char opc;
    rlutil::locate(46,6);
    cout<<"Borrar Cliente";
    recuadro(32,8, 47, 2, 15, 5);
    rlutil::locate(33,9);
    cout<<"INGRESE EL DNI DEL REGISTRO A BORRAR: ";
    cin>>dni;
    ///TRAE LA POSICION DEL REGISTRO A BORRAR
    pos=buscarDni(dni);
    if(pos>=0){
        ///LO LEE, LO SETEA EN FALSO Y MODIFICA EN DISCO
        obj.leerDeDisco(pos);
        obj.Mostrar(1);
        recuadro(32,22, 39, 2, 15, 5);
        rlutil::locate(33,23);
        cout<<"QUIERE BORRAR ESTE REGISTRO? (S/N): ";
        cin>>opc;
        if(opc=='S' || opc=='s'){
            obj.setEstado(false);
            escribio=obj.modificarEnDisco(pos);
            if(escribio==1){
                recuadro(49,25, 22, 2, 15, 5);
                rlutil::locate(50,26);
                cout<<"SE BORRO EL REGISTRO!";
            }
            else{
                recuadro(49,25, 19, 2, 15, 5);
                rlutil::locate(50,26);
                cout<<"NO SE PUDO BORRAR EL REGISTRO";
            }
        }
        else if(opc=='N' || opc=='n'){
            recuadro(49,25, 24, 2, 15, 5);
            rlutil::locate(50,26);
            cout<<"NO SE BORRO EL REGISTRO";
            return -1;
        }
        else{
            recuadro(49,24, 18, 2, 15, 5);
            rlutil::locate(50,25);
            cout<<"OPCION INCORRECTA";
            return -1;
        }
    }
    else{
        recuadro(49,19, 25, 2, 15, 5);
        rlutil::locate(50,20);
        cout<<"NO SE ENCONTRO EL CODIGO";
        return -2;
    }
    return escribio;
}
///MODIFICA FECHA DE NACIMIENTO
int modificarFechaNac(){
    recuadro(6, 2, 109, 27, 15, 5);
    Cliente obj;
    Fecha nac;
    int pos=0,escribio;
    int dni;
    rlutil::locate(49,6);
    cout<<"Modificar Fecha";
    recuadro(32,11, 50, 2, 15, 5);
    rlutil::locate(33,12);;
    cout<<"INGRESE EL DNI DEL REGISTRO A MODIFICAR: ";
    cin>>dni;
    ///TRAE LA POSICION DEL REGISTRO A MODIFICAR
    pos=buscarDni(dni);
    if(pos>=0){
        recuadro(32,15, 35, 5, 15, 5);
        rlutil::locate(33,16);
        ///INGRESA LA NUEVA FECHA Y LA SETEA, LA CHEQUEA Y LA MODIFICA EN DISCO
        cout<<"INGRESE LA NUEVA FECHA: "<<endl;
        nac.Cargar(4);
        obj.leerDeDisco(pos);
        obj.setFechaN(nac);
        if(obj.getFechaN().validarFecha(obj.getFechaN(),0)==true){
            escribio=obj.modificarEnDisco(pos);
            if(escribio==1){
                recuadro(40,22, 19, 2, 15, 5);
                rlutil::locate(41,23);
                cout<<"FECHA MODIFICADA!";
            }
        }
    }
    else{
        recuadro(40,19, 27, 2, 15, 5);
        rlutil::locate(41,20);
        cout<<"NO SE ENCONTRO EL DNI";
        return -2;
    }

    return escribio;
}

///ORDENAMIENTO DINAMICO
void listarClientesOrdenado(){
    int cantReg;
    Cliente *pCliente;
    cantReg=contarClientes();
    if(cantReg==-1){
        recuadro(6, 2, 109, 27, 15, 5);
        cuadro(44,77,15,17);
        rlutil::locate(45,16);
        cout<<"NO SE CARGARON REGISTROS TODAVIA";
        return;
    }
    pCliente=new Cliente[cantReg];
    if(pCliente==NULL) return;

    copiarArchivoEnVector(pCliente,cantReg);
    ordenarVectorClientes(pCliente,cantReg);
    mostrarVectorClientes(pCliente,cantReg);
    delete pCliente;
}

int contarClientes(){
    FILE *p;
    p=fopen("cliente.dat", "rb");
    if(p==NULL)
        return -1;
    fseek(p, 0,2);
    int cantByte=ftell(p);
    fclose(p);
    return cantByte/sizeof(Cliente);
}

void copiarArchivoEnVector(Cliente *pCliente,int cantReg) {
    int i;
    for(i=0; i<cantReg; i++)
        pCliente[i].leerDeDisco(i);

}
void ordenarVectorClientes(Cliente *pCliente,int cantReg) {
    int i, j, posMin;
    Cliente aux;
    for(i=0; i<cantReg-1; i++) {
        posMin=i;
        for(j=i+1; j<cantReg; j++) {
            if(pCliente[j].getSoloAnio()<pCliente[posMin].getSoloAnio()){
                posMin=j;
            }
        }
        aux=pCliente[i];
        pCliente[i]=pCliente[posMin];
        pCliente[posMin]=aux;

    }
}

void mostrarVectorClientes(Cliente *pCliente,int cantReg) {
    int i,y=7;
    rlutil::locate(43,2);
    cout<<"Listado Clientes Por Anio";
    for(i=0; i<cantReg; i++) {
        pCliente[i].Mostrar(0,y);
         for(int i=3;i<115;i++){
            rlutil::locate(i,y-2);
            cout<<(char) 205;
        }
        if(pCliente[i].getEstado()==true){
            y+=3;
        }
    }
     cuadro(3,115,3,y-2);
}
#endif // FUNCIONES_CLIENTE_H_INCLUDED
