#ifndef FUNCIONES_INSTRUMENTO_H_INCLUDED
#define FUNCIONES_INSTRUMENTO_H_INCLUDED
///PROTOTIPOS
void menuInstrumento();
void agregarInstrumento();
void listarInstrumentoxCodigo();
void listarInstrumento();
int borrarInstrumento();
int buscarCodigo(const char *codigo,bool borrado=false);
int modificarPrecio();
///ORDENAMIENTO DINAMICO
void listarInstrumentosOrdenado();
int contarInstrumentos();
void copiarArchivoEnVector(Instrumento *pInstrumento,int cantReg);
void ordenarVectorInstrumentos(Instrumento *pInstrumento,int cantReg);
void mostrarVectorInstrumentos(Instrumento *pInstrumento,int cantReg);

///DESARROLLO
void menuInstrumento(){
    char opc;
    while(true){
        system("color DF");
        rlutil::hidecursor();
        recuadro(6, 2, 109, 27, 15, 5);
        rlutil::locate(55,6);
        cout<<"Menu Instrumentos";
        recuadro(44, 7, 38, 15, 15, 5);
        rlutil::locate(46,9);
        cout<<"1) AGREGAR INSTRUMENTO";
        rlutil::locate(46,10);
        cout<<"2) LISTAR INSTRUMENTO POR CODIGO";
        rlutil::locate(46,11);
        cout<<"3) LISTAR TODOS LOS INSTRUMENTOS";
        rlutil::locate(46,12);
        cout<<"4) LISTAR LOS INSTRUMENTOS POR TIPO";
        rlutil::locate(46,13);
        cout<<"5) MODIFICAR PRECIO";
        rlutil::locate(46,14);
        cout<<"6) ELIMINAR INSTRUMENTO";
        rlutil::locate(45,15);
        cout<<"-------------------------------------";
        rlutil::locate(46,16);
        cout<<"0) VOLVER AL MENU PRINCIPAL";
        rlutil::locate(53,19);
        cout<<"INGRESE UNA OPCION";
        opc=getch();
        system("cls");
        system("color DF");
        switch(opc){
            case '1':
                agregarInstrumento();
                break;
            case '2':
                listarInstrumentoxCodigo();
                break;
            case '3':
                listarInstrumento();
                break;
            case '4':
                listarInstrumentosOrdenado();
                break;
            case '5':
                modificarPrecio();
                break;
            case '6':
                borrarInstrumento();
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
///AGREGA INSTRUMENTO
void agregarInstrumento(){
    Instrumento obj;
    char codigo[30];
    int encontro;
    recuadro(6, 2, 109, 27, 15, 5);
    rlutil::locate(51,6);
    cout<<"Agregar Instrumento";
    recuadro(40, 7, 40, 7, 15, 5);
    rlutil::locate(47,8);
    cout<<"CODIGO: ";
    cargarCadena(codigo,30);
    encontro=buscarCodigo(codigo,1);
    if(encontro==-1){
        if(obj.Cargar(codigo)!=false){
            if(obj.grabarEnDisco()!=1){
                recuadro(51,19, 17, 2, 15, 5);
                rlutil::locate(52,20);
                cout<<"ERROR DE ARCHIVO";
            }
            else{
                recuadro(50,19, 19, 2, 15, 5);
                rlutil::locate(51,20);
                cout<<"REGISTRO AGREGADO!";
            }
        }
    }
    else if(encontro==-2){
        recuadro(31,19, 60, 2, 15, 5);
        rlutil::locate(33,20);
        cout<<"YA SE AGREGO UN REGISTRO CON ESTE CODIGO PERO FUE BORRADO";
    }
    else{
        recuadro(40,19, 40, 2, 15, 5);
        rlutil::locate(42,20);
        cout<<"YA EXISTE UN REGISTRO CON ESTE CODIGO";
    }
}
///LISTA INSTRUMENTO POR EL CODIGO
void listarInstrumentoxCodigo(){
    Instrumento obj;
    int pos=0;
    char codigo[30];
    recuadro(6, 2, 109, 27, 15, 5);
    rlutil::locate(46,6);
    cout<<"Listar Instrumento por Codigo";
    recuadro(40, 7, 40, 2, 15, 5);
    rlutil::locate(47,8);
    cout<<"CODIGO: ";
    cargarCadena(codigo,30);
    pos=buscarCodigo(codigo);
    if(pos!=-1){
        obj.leerDeDisco(pos);
        obj.Mostrar(1);
    }
    else{
        recuadro(49,19, 21, 2, 15, 5);
        rlutil::locate(50,20);
        cout<<"CODIGO NO ENCONTRADO";
    }
}
///LISTA TODOS LOS INSTRUMENTOS
void listarInstrumento(){
    Instrumento obj;
    rlutil::locate(48,2);
    cout<<"Listado Instrumentos";
    int pos=0,y=7;
    while(obj.leerDeDisco(pos)==true){
        obj.Mostrar(0,y);
        for(int i=11;i<104;i++){
            rlutil::locate(i,y-2);
            cout<<(char) 205;
        }
        pos++;
        if(obj.getEstado()==true){
            y+=3;
        }
    }
    cuadro(11,104,3,y-2);
    if(pos==0){
        recuadro(6, 2, 109, 27, 15, 5);
        cuadro(44,77,15,17);
        rlutil::locate(45,16);;
        cout<<"NO SE CARGARON REGISTROS TODAVIA";
    }
}

int buscarCodigo(const char *codigo ,bool borrado){
    Instrumento obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==1){
        if(obj==codigo){
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
///BORRA INSTRUMENTO
int borrarInstrumento(){
    recuadro(6, 2, 109, 27, 15, 5);
    Instrumento obj;
    int pos=0,escribio;
    char codigo[30],opc;
    rlutil::locate(46,6);
    cout<<"Borrar Instrumento";

    recuadro(32,8, 47, 2, 15, 5);
    rlutil::locate(33,9);
    cout<<"INGRESE EL CODIGO DEL REGISTRO A BORRAR: ";
    cargarCadena(codigo,30);
    ///TRAE LA POSICION DEL REGISTRO BUSCANDO POR CODIGO
    pos=buscarCodigo(codigo);
    if(pos>=0){
        ///LA LEE, LA SETEA EN FALSO Y MODIFICA EN DISCO
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
int modificarPrecio(){
    recuadro(6, 2, 109, 27, 15, 5);
    Instrumento obj;
    int pos=0,escribio;
    int precio;
    char codigo[30];
    rlutil::locate(49,6);
    cout<<"Modificar Precio";
    recuadro(32,11, 50, 2, 15, 5);
    rlutil::locate(33,12);
    cout<<"INGRESE EL CODIGO DEL REGISTRO A MODIFICAR: ";
    cargarCadena(codigo,30);
    ///BUSCA LA POSICION DEL REGISTRO POR CODIGO
    pos=buscarCodigo(codigo);
    if(pos>=0){
        recuadro(39,15, 36, 2, 15, 5);
        rlutil::locate(40,16);
        ///INGRESA EL NUEVO PRECIO, LO CHEQUEA Y LO MODIFICA EN DISCO
        cout<<"INGRESE EL NUEVO PRECIO: ";
        cin>>precio;
        obj.leerDeDisco(pos);
        obj.setPrecio(precio);
        if(obj.verificarPrecioCantidad(obj,1)==true){
            escribio=obj.modificarEnDisco(pos);
            if(escribio==1){
                recuadro(49,19, 19, 2, 15, 5);
                rlutil::locate(50,20);
                cout<<"PRECIO MODIFICADO!";
            }
            else{
                recuadro(49,19, 19, 2, 15, 5);
                rlutil::locate(50,20);
                cout<<"NO SE PUDO MODIFICAR EL PRECIO.";
                return -1;
            }
        }
        else{
            recuadro(42,19, 29, 2, 15, 5);
            rlutil::locate(43,20);
            cout<<"INGRESE UN PRECIO POSITIVO";
        }
    }
    else{
        recuadro(43,19, 25, 2, 15, 5);
        rlutil::locate(44,20);
        cout<<"NO SE ENCONTRO EL CODIGO";
        return -2;
    }

    return escribio;
}

void listarInstrumentosOrdenado(){
    int cantReg;
    Instrumento *pInstrumento;
    cantReg=contarInstrumentos();
    if(cantReg==-1){
        recuadro(6, 2, 109, 27, 15, 5);
        cuadro(44,77,15,17);
        rlutil::locate(45,16);
        cout<<"NO SE CARGARON REGISTROS TODAVIA";
        return;
    }
    pInstrumento=new Instrumento[cantReg];
    if(pInstrumento==NULL)
        return;

    copiarArchivoEnVector(pInstrumento,cantReg);
    ordenarVectorInstrumentos(pInstrumento,cantReg);
    mostrarVectorInstrumentos(pInstrumento,cantReg);
    delete pInstrumento;
}

int contarInstrumentos(){
    FILE *p;
    p=fopen("instrumento.dat", "rb");
    if(p==NULL)
        return -1;
    fseek(p, 0,2);
    int cantByte=ftell(p);
    fclose(p);
    return cantByte/sizeof(Instrumento);
}

void copiarArchivoEnVector(Instrumento *pInstrumento,int cantReg) {
    int i;
    for(i=0; i<cantReg; i++)
        pInstrumento[i].leerDeDisco(i);

}
void ordenarVectorInstrumentos(Instrumento *pInstrumento,int cantReg) {
    int i, j, posMin;
    Instrumento aux;
    for(i=0; i<cantReg-1; i++) {
        posMin=i;
        for(j=i+1; j<cantReg; j++) {
            if(pInstrumento[j].getTipo()<pInstrumento[posMin].getTipo()){
                posMin=j;
            }
        }
        aux=pInstrumento[i];
        pInstrumento[i]=pInstrumento[posMin];
        pInstrumento[posMin]=aux;

    }
}

void mostrarVectorInstrumentos(Instrumento *pInstrumento,int cantReg) {
    int i,y=7;
    rlutil::locate(44,2);
    cout<<"Listado Clientes Por Tipo";
    for(i=0; i<cantReg; i++) {
        pInstrumento[i].Mostrar(0,y);
        for(int i=11;i<104;i++){
            rlutil::locate(i,y-2);
            cout<<(char) 205;
        }
        if(pInstrumento[i].getEstado()==true){
            y+=3;
        }
    }
    cuadro(11,104,3,y-2);
}

#endif // FUNCIONES_INSTRUMENTO_H_INCLUDED
