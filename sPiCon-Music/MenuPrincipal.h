#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

///PROTOTIPOS
void menuPrincipal();
void menuInformacion();
///DESARROLLO
void menuPrincipal(){
    char opc;
    while(true){
        system("color DF");
        rlutil::hidecursor();
        recuadro(6, 2, 109, 27, 15, 5);
        rlutil::locate(56,6);
        cout<<"SPiCon Music";
        recuadro(49, 7, 25, 15, 15, 5);
        rlutil::locate(52,9);
        cout<<"1) MENU INSTRUMENTOS";
        rlutil::locate(52,10);
        cout<<"2) MENU CLIENTES";
        rlutil::locate(52,11);
        cout<<"3) MENU VENTAS";
        rlutil::locate(52,12);
        cout<<"4) REPORTES";
        rlutil::locate(52,13);
        cout<<"5) CONFIGURACION";
        rlutil::locate(52,14);
        cout<<"6) INFORMACION UTIL";
        rlutil::locate(50,15);
        cout<<"------------------------";
        rlutil::locate(52,16);
        cout<<"0) FIN DEL PROGRAMA";
        rlutil::locate(53,19);
        cout<<"INGRESE UNA OPCION";
        opc=getch();
        system("color DF");
        system("cls");
        switch(opc){
            case '1':
                menuInstrumento();
                break;
            case '2':
                menuCliente();
                break;
            case '3':
                menuVenta();
                break;
            case '4':
                menuReportes();
                break;
            case '5':
                menuConfiguracion();
                break;
            case '6':
                menuInformacion();
                break;

            case '0':

                return;
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

void menuInformacion(){
    char opc2;
    bool noToco0=true;
    while(noToco0==true){
        system("color DF");
        rlutil::hidecursor();
        recuadro(6, 2, 109, 27, 15, 5);
        rlutil::locate(54,6);
        cout<<"Menu Informacion";
        recuadro(45, 7, 34, 15, 15, 5);
        rlutil::locate(47,9);
        cout<<"TIPOS DE INSTRUMENTO";
        rlutil::locate(47,10);
        cout<<"- 1: PERCUSION";
        rlutil::locate(47,11);
        cout<<"- 2: VIENTO";
        rlutil::locate(47,12);
        cout<<"- 3: CUERDA";
        rlutil::locate(47,13);
        cout<<"- 4: OTROS Y ACCESORIOS";
        rlutil::locate(47,16);
        cout<<"TIPOS DE DESCUENTO";
        rlutil::locate(47,17);
        cout<<"- 1: MENOR DE 18 (10%)";
        rlutil::locate(47,18);
        cout<<"- 2: IMPORTE MAYOR A 50000 (10%)";
        rlutil::locate(47,19);
        cout<<"- 3: USTED ES MUSICO (10%)";
        rlutil::locate(46,20);
        cout<<"---------------------------------";
        rlutil::locate(47,21);
        cout<<"0) VOLVER AL MENU PRINCIPAL";
        opc2=getch();
        if(opc2=='0') return;
        else{
            recuadro(6, 2, 109, 27, 15, 5);
            recuadro(50,13, 18, 2, 15, 5);
            rlutil::locate(51,14);
            cout<<"OPCION INCORRECTA";
            system("pause>null");
        }
    }
}

#endif // MENUPRINCIPAL_H_INCLUDED
