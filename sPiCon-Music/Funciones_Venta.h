#ifndef FUNCIONES_VENTA_H_INCLUDED
#define FUNCIONES_VENTA_H_INCLUDED
///PROTOTIPOS
void menuVenta();
void agregarVenta();
void listarVentaxId();
void listarVenta();
void listarDetallesVenta();
int buscarId(int id,bool borrado=false);
int modificarCantidad();
bool validarCliente(int);
bool validarInstrumento(const char*);
bool restaroSumarStock(int,const char*,bool);
int autonumerico();
void descuento(int,int,bool);
void modificarPrecioVentaPrincipal(int);
int buscarRegistroModificar(int ,const char *);
///ORDENAMIENTO DINAMICO
void listarVentasOrdenado();
int contarVentas();
void copiarArchivoEnVector(Venta *pVenta,int cantReg);
void ordenarVectorVentas(Venta *pVenta,int cantReg);
void mostrarVectorVentas(Venta *pVenta,int cantReg);




///DESARROLLO
void menuVenta(){
    int opc;
    while(true){
        system("color DF");
        rlutil::hidecursor();
        recuadro(6, 2, 109, 27, 15, 5);
        rlutil::locate(57,6);
        cout<<"Menu Ventas";
        recuadro(44, 7, 37, 15, 15, 5);
        rlutil::locate(46,9);
        cout<<"1) AGREGAR VENTA";
        rlutil::locate(46,10);
        cout<<"2) LISTAR VENTA POR ID";
        rlutil::locate(46,11);
        cout<<"3) LISTAR TODAS LAS VENTAS";
        rlutil::locate(46,12);
        cout<<"4) LISTAR VENTAS POR IMPORTE";
        rlutil::locate(46,13);
        cout<<"5) LISTAR DETALLES DE VENTA POR ID";
        rlutil::locate(46,14);
        cout<<"6) MODIFICAR CANTIDAD";
        rlutil::locate(45,15);
        cout<<"------------------------------------";
        rlutil::locate(46,16);
        cout<<"0) VOLVER AL MENU PRINCIPAL";
        rlutil::locate(52,19);
        cout<<"INGRESE UNA OPCION";
        opc=getch();
        system("cls");
        system("color DF");
        switch(opc){
            case '1':
                agregarVenta();
                break;
            case '2':
                listarVentaxId();
                break;
            case '3':
                listarVenta();
                break;
            case '4':
                listarVentasOrdenado();
                break;
            case '5':
                listarDetallesVenta();
                break;
            case '6':
                modificarCantidad();
                break;
            case '0':
                return;
                break;
            default:
                recuadro(6, 2, 109, 27, 15, 5);
                recuadro(50,13, 18, 2, 15, 5);
                rlutil::locate(51,14);
                cout<<"OPCION INCORRECTA";
                system("pause>null");
                break;
        }
        system("cls");
    }
}

void agregarVenta(){
    Venta obj;
    DetalleV reg;
    int id, acumImporte=0,i=1,y=5;
    char seguirComprando='S';
    bool validado=true, ingresoMal=false,cargoBien=true;
    recuadro(6, 2, 109, 24, 15, 5);
    rlutil::locate(51,6);
    cout<<"Agregar Venta";
    recuadro(40, 7, 40, 9, 15, 5);
    rlutil::locate(47,9);
    id=autonumerico();
    if(id!=-1){
        validado=obj.Cargar(id);
    }
    if(validado==true){
        if(validarCliente(obj.getDni())==true){
                if(obj.grabarEnDisco()!=1){
                    cuadro(49,68,19,21);
                    rlutil::locate(50,20);
                    cout<<"ERROR DE ARCHIVO";
                }
                else{
                    cuadro(49,68,19,21);
                    rlutil::locate(50,20);
                    cout<<"REGISTRO AGREGADO!";
                    rlutil::locate(57,14);
                    cout<<"A CALCULAR";
                    system("pause>null");
                    system("cls");
                    while(seguirComprando=='S'|| seguirComprando=='s'){
                        system("color DF");
                        recuadro(6, 3, 109, 24, 15, 5);
                        obj.Mostrar(2,y);
                        rlutil::locate(63,6);
                        cout<<"Detalle de Venta "<<i;
                        recuadro(52, 7, 40, 11, 15, 5);
                        ingresoMal=false;
                        cargoBien=reg.Cargar(id);
                        if(cargoBien==true){
                            if(validarInstrumento(reg.getCodigo())==true){
                                if(reg.noRepetir(id,reg.getCodigo())==true){
                                    if(restaroSumarStock(reg.getCantidad(),reg.getCodigo(),1)==true){
                                        if(reg.grabarEnDisco()!=1){
                                            cuadro(49,68,19,21);
                                            rlutil::locate(50,20);
                                            cout<<"ERROR DE ARCHIVO";
                                        }
                                        else{
                                            cuadro(49,68,19,21);
                                            rlutil::locate(50,20);
                                            cout<<"REGISTRO AGREGADO!";

                                            acumImporte+=reg.getImporte();
                                            obj.setImporte(acumImporte);
                                            obj.modificarEnDisco(id-1);


                                            rlutil::locate(19,16);
                                            cout << obj.getImporte();

                                            recuadro(49,22, 34, 2, 15, 5);
                                            rlutil::locate(50,23);
                                            cout<<"QUIERE SEGUIR COMPRANDO? (S/N): ";
                                            cin>>seguirComprando;
                                            i++;
                                           ///APLICACION DE DESCUENTO
                                            if(seguirComprando=='N' || seguirComprando=='n'){
                                                descuento(id,obj.getDni(),1);
                                            }
                                            system("cls");
                                        }
                                    }
                                    else{
                                        cuadro(48,92,19,21);
                                        rlutil::locate(52,20);
                                        cout << "ERROR: STOCK INSUFICIENTE";
                                        rlutil::locate(62,12);
                                        cout<<"NO CALCULADO";
                                        ingresoMal=true;
                                    }
                                }
                                else{
                                    recuadro(48, 19, 59, 2, 15, 5);
                                    rlutil::locate(52,20);
                                    cout << "ERROR: YA SE INGRESO UNA VENTA CON ESTE CODIGO DE ARTICULO";
                                    rlutil::locate(68,12);
                                    cout<<"NO CALCULADO";
                                    ingresoMal=true;
                                }
                            }
                            else{
                                cuadro(50,90,19,21);
                                rlutil::locate(52,20);
                                cout << "ERROR: CODIGO DE ARTICULO INEXISTENTE";
                                rlutil::locate(68,12);
                                cout<<"NO CALCULADO";
                                ingresoMal=true;
                            }
                        }
                        if(ingresoMal==true || cargoBien==false){
                            recuadro(61,22, 27, 2, 15, 5);
                            rlutil::locate(62,23);
                            cout<<"VUELVA A INGRESAR LA VENTA";
                            system("pause>null");
                            system("cls");
                            seguirComprando='S';
                        }
                    }
                }
        }
        else{
            cuadro(39,83,19,21);
            rlutil::locate(40,20);
            cout << "ERROR: DNI INEXISTENTE";
            rlutil::locate(57,14);
            cout<<"ERROR";
            system("pause>null");
        }
    }
}


bool validarCliente(int dni){
    Cliente obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==1){
        if(dni==obj.getDni() && obj.getEstado()==true){
            return true;
        }
        pos++;
    }
    return false;
}

bool validarInstrumento(const char* cod){
    Instrumento obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==1){
        if(obj==cod && obj.getEstado()==true){
            return true;
        }
        pos++;
    }
    return false;
}

bool restaroSumarStock(int cantidad,const char* cod,bool modo){
    int pos=buscarCodigo(cod);
    Instrumento obj;
    obj.leerDeDisco(pos);
    if(modo==1){
        obj.setStock(obj.getStock()-cantidad);
    }
    else{
         obj.setStock(obj.getStock()+cantidad);
    }

    if(obj.getStock()>=0){
        obj.modificarEnDisco(pos);
        return true;
    }
    else{
        return false;
    }
}

void listarVentaxId(){
    Venta obj;
    int pos=0,id;
    recuadro(6, 2, 109, 27, 15, 5);
    rlutil::locate(46,6);
    cout<<"Listar Venta por ID";
    recuadro(40, 7, 40, 2, 15, 5);
    rlutil::locate(47,8);;
    cout<<"ID: ";
    cin>>id;
    pos=buscarId(id);
    if(pos!=-1){
        obj.leerDeDisco(pos);
        obj.Mostrar(1);
    }
    else{
        cuadro(44,62,15,17);
        rlutil::locate(45,16);
        cout<<"ID NO ENCONTRADO";
    }
    system("pause>null");
}

void listarDetallesVenta(){
    recuadro(6, 2, 109, 27, 15, 5);
    DetalleV obj;
    Venta aux;
    int pos=0, pos2=0,id,y=7,y2=12;
    bool encontro=false;
    recuadro(6, 2, 109, 27, 15, 5);
    rlutil::locate(46,6);
    cout<<"Listar Detalles de Venta por ID";
    recuadro(40, 7, 40, 2, 15, 5);
    rlutil::locate(47,8);
    cout<<"ID: ";
    cin>>id;
    system("cls");

    system("color DF");
    rlutil::locate(50,2);
    cout<<"Venta Principal";
    while(aux.leerDeDisco(pos2)==1){
        if(aux.getId()==id){
            aux.Mostrar(0,y);
            for(int i=27;i<87;i++){
                rlutil::locate(i,y-2);
                cout<<(char) 205;
            }
            encontro=true;
            if(aux.getEstado()==true){
                y+=3;
            }
        }
        pos2++;
    }
    cuadro(27,87,3,y-2);

    rlutil::locate(50,10);
    cout<<"Detalles De Venta";
    while(obj.leerDeDisco(pos)==1){
        if(obj.getId()==id){
            obj.Mostrar(y2);
            for(int i=27;i<87;i++){
                rlutil::locate(i,y2+1);
                cout<<(char) 205;
            }
            encontro=true;
            if(obj.getEstado()==true){
                y2+=3;
            }
        }
        pos++;
    }
    cuadro(27,87,11,y2+1);

    if(encontro==false){
        system("color DF");
        recuadro(6, 2, 109, 27, 15, 5);
        cuadro(53,70,12,14);
        rlutil::locate(54,13);
        cout<<"ID NO ENCONTRADO";
    }

    system("pause>null");
}

void listarVenta(){
    Venta obj;
    int pos=0,y=7;
    rlutil::locate(50,2);
    cout<<"Listado Ventas";
    while(obj.leerDeDisco(pos)==true){
        obj.Mostrar(0,y);
        for(int i=27;i<87;i++){
            rlutil::locate(i,3);
            cout<<(char) 205;
            rlutil::locate(i,y-2);
            cout<<(char) 205;
        }
        pos++;
        if(obj.getEstado()==true){
            y+=3;
        }
    }
    cuadro(27,87,3,y-2);
    if(pos==0){
        recuadro(6, 2, 109, 27, 15, 5);
        cuadro(44,77,15,17);
        rlutil::locate(45,16);
        cout<<"NO SE CARGARON REGISTROS TODAVIA";
    }
    system("pause>null");
}

int buscarId(int id,bool borrado){
    Venta obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==1){
            if(obj.getId()==id){
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
int modificarCantidad(){
    recuadro(6, 2, 109, 27, 15, 5);
    DetalleV obj;
    int registroModificar,escribio;
    int id,cantidadNueva,cantidadVieja,resto,sumo,precio;
    char cod[5];
    rlutil::locate(49,6);
    cout<<"Modificar Cantidad";

    recuadro(32,9, 66, 2, 15, 5);
    rlutil::locate(33,10);
    cout<<"INGRESE EL ID DE LA VENTA A MODIFICAR: ";
    cin>>id;

    recuadro(32,12, 71, 2, 15, 5);
    rlutil::locate(33,13);
    cout<<"INGRESE EL CODIGO DE ARTICULO DEL DETALLE DE VENTA A MODIFICAR: ";
    cargarCadena(cod,5);

    ///BUSCA LA POSICION DEL DETALLE DE VENTA A TRAVES DEL ID Y EL CODIGO (YA QUE NO SE PUEDEN REPETIR AL COMPRAR)
    ///DEVUELVE LA POSICION Y LA LEO EN DISCO
    registroModificar=buscarRegistroModificar(id,cod);
    obj.leerDeDisco(registroModificar-1);

    if(registroModificar!=-1){
        cuadro(32,69,15,17);
        rlutil::locate(33,16);
        cout<<"INGRESE LA NUEVA CANTIDAD: ";
        cin>>cantidadNueva;

        ///SETEA CANTIDAD NUEVAsystem("pause>null");
        cantidadVieja=obj.getCantidad();
        obj.setCantidad(cantidadNueva);
        ///SETEA IMPORTE NUEVO EN AMBAS CLASES Y GRABA EN DISCO
        precio=obj.buscarPrecio(cod);
        obj.setImporte(cantidadNueva*precio);
        escribio=obj.modificarEnDisco(registroModificar-1);

        ///ACUMULA LOS IMPORTES DE LOS DETALLES DE LA VENTA PRINCIPAL, LOS SETEA Y LOS MODIFICA EN DISCO
        modificarPrecioVentaPrincipal(id);

        if(cantidadNueva>cantidadVieja){
            ///SACA LA DIFERENCIA Y SE LA RESTA AL STOCK (YA QE SE COMPRO MAS)
            int cantidadResta=cantidadNueva-cantidadVieja;
            resto=restaroSumarStock(cantidadResta,obj.getCodigo(),1);
        }
        else{
            ///SACA LA DIFERENCIA Y SE LA SUMA AL STOCK (YA QE SE COMPRO MENOS)
            int cantidadSuma=cantidadVieja-cantidadNueva;
            sumo=restaroSumarStock(cantidadSuma,obj.getCodigo(),0);
        }

        if(registroModificar!=-1 && (resto==true||sumo==true)){
            cuadro(34,70,24,26);
            rlutil::locate(35,25);
            cout<<"CANTIDAD MODIFICADA!";
            system("pause>null");

        }
        else if(resto==false){
            cuadro(44,92,19,21);
            rlutil::locate(45,20);
            cout << "ERROR: STOCK INSUFICIENTE";
            system("pause>null");
        }
    }
    else{
        cuadro(34,74,20,22);
        rlutil::locate(35,21);
        cout<<"NO SE ENCONTRO EL ID/CODIGO DE ARTICULO";
        system("pause>null");
        return -2;
    }

    return escribio;
    system("pause>null");
}

int autonumerico(){
    Venta obj;
    int pos=0;
    int id;
    while(obj.leerDeDisco(pos)==1){
        id=obj.getId();
        pos++;
    }

    if(pos==0){
        id=1;
        return id;
    }
    if(pos>0){
        id=id+1;
        return id;
    }
    return -1;
}

void descuento(int id,int dni,bool modo=0){
    Venta obj;
    int c=0;

    ///DESC 1
    obj.leerDeDisco(id-1);
    if(obj.getImporte()>=50000){
        c++;
    }
    ///DESC 2
    Cliente reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getDni()==dni){
            if(reg.getMusico()=='S'||reg.getMusico()=='s'){
                c++;
            }
            ///DESC 3
            if(2022-reg.getSoloAnio()<=18){
                c++;
            }
        }
    }
    float desc=-1;
    if(c==1){
        desc=0.9;
    }
    if(c==2){
        desc=0.8;
    }
    if(c==3){
        desc=0.7;
    }
    if(desc!=-1){
        obj.setImporte(obj.getImporte()*desc);
        obj.modificarEnDisco(id-1);
        recuadro(8, 19, 23, 2, 15, 5);
        rlutil::locate(9,20);
        if(modo==1){
            recuadro(8, 19, 23, 2, 15, 5);
            rlutil::locate(9,20);
            cout << "DESCUENTO/S APLICADO/S";
            rlutil::locate(19,16);
            cout << obj.getImporte();
            system("pause>null");
        }
        if(modo==0){
            recuadro(8, 19, 28, 2, 15, 5);
            rlutil::locate(9,20);
            cout << "DESCUENTO/S ACTUALIZADO/S";
        }

    }
}

void modificarPrecioVentaPrincipal(int id){
    DetalleV obj;
    Venta reg;
    int pos=0,acumImporte=0;
    while(obj.leerDeDisco(pos++)){
        if(obj.getId()==id){
            acumImporte+=obj.getImporte();
        }
    }
    reg.leerDeDisco(id-1);
    reg.setImporte(acumImporte);
    reg.modificarEnDisco(id-1);
    descuento(id,reg.getDni(),0);
}
int buscarRegistroModificar(int id,const char* cod){
    DetalleV obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
        if(obj.getId()==id){
            if(obj==cod){
                return pos;
            }
        }
    }
    return -1;
}

///ORDENAMIENTO DINAMICO
void listarVentasOrdenado(){
    int cantReg;
    Venta *pVenta;
    cantReg=contarVentas();
    if(cantReg==-1) {
        recuadro(6, 2, 109, 27, 15, 5);
        cuadro(44,77,15,17);
        rlutil::locate(45,16);
        cout<<"NO SE CARGARON REGISTROS TODAVIA";
        return;
    }
    pVenta=new Venta[cantReg];
    if(pVenta==NULL)
        return;

    copiarArchivoEnVector(pVenta,cantReg);
    ordenarVectorVentas(pVenta,cantReg);
    mostrarVectorVentas(pVenta,cantReg);
    system("pause>null");
    delete pVenta;
}
int contarVentas(){
    FILE *p;
    p=fopen("venta.dat", "rb");
    if(p==NULL)
        return -1;
    fseek(p, 0,2);
    int cantByte=ftell(p);
    fclose(p);
    return cantByte/sizeof(Venta);
}
void copiarArchivoEnVector(Venta *pVenta,int cantReg){
    int i;
    for(i=0; i<cantReg; i++)
        pVenta[i].leerDeDisco(i);
}
void ordenarVectorVentas(Venta *pVenta,int cantReg){
    int i, j, posMin;
    Venta aux;
    for(i=0; i<cantReg-1; i++) {
        posMin=i;
        for(j=i+1; j<cantReg; j++) {
            if(pVenta[j].getImporte()<pVenta[posMin].getImporte()){
                posMin=j;
            }
        }
        aux=pVenta[i];
        pVenta[i]=pVenta[posMin];
        pVenta[posMin]=aux;

    }
}
void mostrarVectorVentas(Venta *pVenta,int cantReg){
    int i,y=7;
    rlutil::locate(45,2);
    cout<<"Listado Ventas Por Importe";
    for(i=0; i<cantReg; i++){
        pVenta[i].Mostrar(0,y);
        for(int i=27;i<87;i++){
            rlutil::locate(i,y-2);
            cout<<(char) 205;
        }
        if(pVenta[i].getEstado()==true){
            y+=3;
        }
    }
    cuadro(27,87,3,y-2);
}

#endif // FUNCIONES_VENTA_H_INCLUDED
