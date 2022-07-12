#ifndef FUNCIONES_CONFIGURACION_H_INCLUDED
#define FUNCIONES_CONFIGURACION_H_INCLUDED
///PROTOTIPOS
void menuConfiguracion();
///DESARROLLO
///PROTOTIPOS
void menuConfiguracion();
bool backupClientes();
bool backupInstrumentos();
bool backupVentas();
bool backupDetallesVenta();
bool restauracionClientes();
bool restauracionInstrumentos();
bool restauracionVentas();
bool restauracionDetallesVenta();
bool clienteddi();
bool articuloddi();
bool ventaddi();
void dditotal();
///DESARROLLO
void menuConfiguracion(){
    char opc;
    while(true){
        system("color DF");
        rlutil::hidecursor();
        recuadro(6, 2, 109, 27, 15, 5);
        rlutil::locate(52,6);
        cout<<"Menu Configuracion";
        recuadro(32, 7, 57, 16, 15, 5);
        rlutil::locate(34,9);
        cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE CLIENTES";
        rlutil::locate(34,10);
        cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE INSTRUMENTOS";
        rlutil::locate(34,11);
        cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO DE VENTAS";
        rlutil::locate(34,12);
        cout<<"4) RESTAURAR EL ARCHIVO DE CLIENTES";
        rlutil::locate(34,13);
        cout<<"5) RESTAURAR EL ARCHIVO DE INSTRUMENTOS";
        rlutil::locate(34,14);
        cout<<"6) RESTAURAR EL ARCHIVO DE VENTAS";
        rlutil::locate(34,15);
        cout<<"7) ESTABLECER DATOS DE INICIO";
        rlutil::locate(33,17);
        cout<<"--------------------------------------------------------";
        rlutil::locate(34,18);
        cout<<"0) VOLVER AL MENU PRINCIPAL";
        rlutil::locate(52,21);
        cout<<"INGRESE UNA OPCION";
        opc=getch();
        system("cls");
        system("color DF");
        switch(opc){
            case '1':
                if(backupClientes()==true){
                    recuadro(6, 2, 109, 27, 15, 5);
                    cuadro(42,72,14,16);
                    rlutil::locate(43,15);
                    cout<<"COPIA DE SEGURIDAD REALIZADA!";
                }
                else{
                    recuadro(6, 2, 109, 27, 15, 5);
                    cuadro(42,85,14,16);
                    rlutil::locate(43,15);
                    cout<<"NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD";
                }
                break;
            case '2':
                if(backupInstrumentos()==true){
                    recuadro(6, 2, 109, 27, 15, 5);
                    cuadro(42,72,14,16);
                    rlutil::locate(43,15);
                    cout<<"COPIA DE SEGURIDAD REALIZADA!";
                }
                else{
                    recuadro(6, 2, 109, 27, 15, 5);
                    cuadro(42,85,14,16);
                    rlutil::locate(43,15);
                    cout<<"NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD";
                }
                break;
            case '3':
               if(backupVentas()==true){
                    recuadro(6, 2, 109, 27, 15, 5);
                    cuadro(42,72,14,16);
                    rlutil::locate(43,15);
                    cout<<"COPIA DE SEGURIDAD REALIZADA!";
                }
                else{
                    cuadro(42,85,14,16);
                    rlutil::locate(43,15);
                    cout<<"NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD";
                }
                break;
            case '4':
                if(restauracionClientes()==true){
                    recuadro(6, 2, 109, 27, 15, 5);
                    cuadro(42,66,14,16);
                    rlutil::locate(43,15);
                    cout<<"RESTAURACION REALIZADA!";
                }
                else{
                    recuadro(6, 2, 109, 27, 15, 5);
                    cuadro(42,79,14,16);
                    rlutil::locate(43,15);
                    cout<<"NO SE PUDO REALIZAR LA RESTAURACION";
                }
                break;
            case '5':
                if(restauracionInstrumentos()==true){
                    recuadro(6, 2, 109, 27, 15, 5);
                    cuadro(42,66,14,16);
                    rlutil::locate(43,15);
                    cout<<"RESTAURACION REALIZADA!";
                }
                else{
                    recuadro(6, 2, 109, 27, 15, 5);
                    cuadro(42,79,14,16);
                    rlutil::locate(43,15);
                    cout<<"NO SE PUDO REALIZAR LA RESTAURACION";
                }
                break;
            case '6':
                if(restauracionVentas()==true){
                    recuadro(6, 2, 109, 27, 15, 5);
                    cuadro(42,66,14,16);
                    rlutil::locate(43,15);
                    cout<<"RESTAURACION REALIZADA!";
                }
                else{
                    recuadro(6, 2, 109, 27, 15, 5);
                    cuadro(42,79,14,16);
                    rlutil::locate(43,15);
                    cout<<"NO SE PUDO REALIZAR LA RESTAURACION";
                }
                break;
            case '7':
               dditotal();
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
bool backupClientes(){
    FILE *p;
    p=fopen("cliente.bkp","wb");
    if(p==NULL) return false;
    Cliente obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==1){
        if(obj.getEstado()==true){ ///SOLO GUARDA LOS QUE ESTA EN TRUE
            fwrite(&obj,sizeof obj,1,p);
        }
        pos++;
    }
    fclose(p);
    if(pos==0){
        return false;
    }
    else{
        return true;
    }
}
bool backupInstrumentos(){
    FILE *p;
    p=fopen("instrumento.bkp","wb");
    if(p==NULL){
        return false;
    }
    Instrumento obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==1){
        if(obj.getEstado()==true){ ///SOLO GUARDA LOS QUE ESTA EN TRUE
            fwrite(&obj,sizeof obj,1,p);
        }
        pos++;
    }
    fclose(p);
    if(pos==0){
        return false;
    }
    else{
        return true;
    }
}
bool backupVentas(){
    int c=0;
    FILE *p;
    p=fopen("venta.bkp","wb");
    if(p==NULL) return false;
    Venta obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==1){
        if(obj.getEstado()==true){ ///SOLO GUARDA LOS QUE ESTA EN TRUE
            fwrite(&obj,sizeof obj,1,p);
        }
        pos++;
    }
    fclose(p);
    if(pos==0)c=0;
    else{
        c++;
    }
    if(backupDetallesVenta()==true) c++;
    else c=0;

    if(c==2)return true;
    else return false;
}
bool backupDetallesVenta(){
    FILE *p;
    p=fopen("detallev.bkp","wb");
    if(p==NULL) return false;
    DetalleV obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==1){
        if(obj.getEstado()==true){ ///SOLO GUARDA LOS QUE ESTA EN TRUE
            fwrite(&obj,sizeof obj,1,p);
        }
        pos++;
    }
    fclose(p);
    if(pos==0)return false;
    else{
        return true;
    }
}
bool restauracionClientes(){
    FILE *b;
    b=fopen("cliente.bkp","rb");
    if(b==NULL) return false;

    FILE *p;
    p=fopen("cliente.dat","wb");
    if(p==NULL){
        fclose(b);
        return false;
    }

    Cliente obj;
    while(fread(&obj,sizeof(Cliente),1,b)==1){
        fwrite(&obj,sizeof(Cliente),1, p);
    }

    fclose(b);
    fclose(p);
    return true;

}
bool restauracionInstrumentos(){
    FILE *b;
    b=fopen("instrumento.bkp","rb");
    if(b==NULL) return false;

    FILE *p;
    p=fopen("instrumento.dat","wb");
    if(p==NULL){
        fclose(b);
        return false;
    }

    Instrumento obj;
    while(fread(&obj,sizeof(Instrumento),1,b)==1){
        fwrite(&obj,sizeof(Instrumento),1,p);
    }

    fclose(b);
    fclose(p);
    return true;
}
bool restauracionVentas(){
    FILE *b;
    b=fopen("venta.bkp","rb");
    if(b==NULL) return false;

    FILE *p;
    p=fopen("venta.dat","wb");
    if(p==NULL){
        fclose(b);
        return false;
    }

    Venta obj;
    while(fread(&obj,sizeof(Venta),1,b)==1){
        fwrite(&obj,sizeof(Venta),1,p);
    }

    fclose(b);
    fclose(p);
    if(restauracionDetallesVenta()==true) return true;
    else return false;

}

bool restauracionDetallesVenta(){
    FILE *b;
    b=fopen("detallev.bkp","rb");
    if(b==NULL) return false;

    FILE *p;
    p=fopen("detallev.dat","wb");
    if(p==NULL){
        fclose(b);
        return false;
    }

    DetalleV obj;
    while(fread(&obj,sizeof(DetalleV),1,b)==1){
        fwrite(&obj,sizeof(DetalleV),1,p);
    }

    fclose(b);
    fclose(p);
    return true;
}
bool clienteddi(){
    FILE *b;
    b=fopen("cliente.ddi","rb");
    if(b==NULL) return false;

    FILE *p;
    p=fopen("cliente.dat","wb");
    if(p==NULL){
        fclose(b);
        return false;
    }

    Cliente obj;
    while(fread(&obj,sizeof(Cliente),1,b)==1){
        fwrite(&obj,sizeof(Cliente),1, p);
    }

    fclose(b);
    fclose(p);
    return true;
}
bool instrumentoddi(){
    FILE *b;
    b=fopen("instrumento.ddi","rb");
    if(b==NULL) return false;

    FILE *p;
    p=fopen("instrumento.dat","wb");
    if(p==NULL){
        fclose(b);
        return false;
    }

    Instrumento obj;
    while(fread(&obj,sizeof(Instrumento),1,b)==1){
        fwrite(&obj,sizeof(Instrumento),1,p);
    }

    fclose(b);
    fclose(p);
    return true;
}
bool ventaddi(){
    FILE *b;
    b=fopen("venta.ddi","rb");
    if(b==NULL) return false;

    FILE *p;
    p=fopen("venta.dat","wb");
    if(p==NULL){
        fclose(b);
        return false;
    }

    Venta obj;
    while(fread(&obj,sizeof(Venta),1,b)==1){
        fwrite(&obj,sizeof(Venta),1,p);
    }

    fclose(b);
    fclose(p);
    return true;
}
bool detallevddi(){
    FILE *b;
    b=fopen("detallev.ddi","rb");
    if(b==NULL) return false;

    FILE *p;
    p=fopen("detallev.dat","wb");
    if(p==NULL){
        fclose(b);
        return false;
    }

    DetalleV obj;
    while(fread(&obj,sizeof(DetalleV),1,b)==1){
        fwrite(&obj,sizeof(DetalleV),1,p);
    }

    fclose(b);
    fclose(p);
    return true;
}

void dditotal(){
    int verificar=0;
    if(clienteddi()==true){
        verificar++;
    }
    if(instrumentoddi()==true){
        verificar++;
    }
    if(ventaddi()==true){
        verificar++;
    }
    if(detallevddi()==true){
        verificar++;
    }

    if(verificar==4){
        recuadro(6, 2, 109, 27, 15, 5);
        cuadro(42,81,14,16);
        rlutil::locate(43,15);
        cout<<"DATOS DE INICIO COPIADOS CORRECTAMENTE";
    }
}



#endif // FUNCIONES_CONFIGURACION_H_INCLUDED
