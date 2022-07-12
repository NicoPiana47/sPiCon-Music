#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED
class Fecha{
private:
    int dia,mes,anio;
public:
    ///CONSTRUCTOR
    Fecha(int d=00,int m=00,int a=0000){
        dia=d;
        mes=m;
        anio=a;
    }
    ///SETS
    void setDia(int d){if(d>0 && d<32)dia=d;}
    void setMes(int m){if(m>0 && m<13)mes=m;}
    void setAnio(int a){anio=a;}
    ///GETS
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    ///METODOS
    bool Cargar(int,bool);
    void Mostrar();
    bool validarFecha(Fecha obj, bool modo);
};
///METODOS
bool Fecha::Cargar(int num, bool modo=0){
    int dia,mes,anio,val;
    int posy, posx;
    int cuadroy,cuadrox;
    if(num==1){
        posx=47;
        posy=10;
        cuadrox=44;
        cuadroy=19;
    }
    else if(num==4){
        posx=57;
        posy=16;
        cuadrox=44;
        cuadroy=22;
    }
    rlutil::locate(posx,posy++);
    cout<<"DIA: ";
    cin>>dia;
    while(dia<1 || dia>31){
        recuadro(cuadrox, cuadroy, 17, 2, 15, 5);
        rlutil::locate(cuadrox+1,cuadroy+1);
        cout<<"ERROR EN EL DIA";
        system("pause>null");
        rlutil::locate(cuadrox,cuadroy);
        cout << "                             ";
        rlutil::locate(cuadrox,cuadroy+1);
        cout << "                             ";
        rlutil::locate(cuadrox,cuadroy+2);
        cout << "                              ";
        rlutil::locate(posx+4,posy-1);
        cout << "            ";
        rlutil::locate(posx+5,posy-1);
        cin >> dia;
    }

    rlutil::locate(posx,posy++);
    cout<<"MES: ";
    cin>>mes;

    while(mes<1 || mes>12){
        recuadro(cuadrox, cuadroy, 17, 2, 15, 5);
        rlutil::locate(cuadrox+1,cuadroy+1);
        cout<<"ERROR EN EL MES";
        system("pause>null");
        rlutil::locate(cuadrox,cuadroy);
        cout << "                             ";
        rlutil::locate(cuadrox,cuadroy+1);
        cout << "                             ";
        rlutil::locate(cuadrox,cuadroy+2);
        cout << "                              ";
        rlutil::locate(posx+4,posy-1);
        cout << "            ";
        rlutil::locate(posx+5,posy-1);
        cin >> mes;
    }

    rlutil::locate(posx,posy++);
    cout<<"ANIO: ";
    cin>>anio;

    if(modo==0) val=2010;
    else val=2022;

    while(anio<1920 || anio>val){
        recuadro(cuadrox, cuadroy, 17, 2, 15, 5);
        rlutil::locate(cuadrox+1,cuadroy+1);
        cout<<"ERROR EN EL ANIO";
        system("pause>null");
        rlutil::locate(cuadrox,cuadroy);
        cout << "                             ";
        rlutil::locate(cuadrox,cuadroy+1);
        cout << "                             ";
        rlutil::locate(cuadrox,cuadroy+2);
        cout << "                              ";
        rlutil::locate(posx+5,posy-1);
        cout << "            ";
        rlutil::locate(posx+6,posy-1);
        cin >> anio;
    }

    setDia(dia);
    setMes(mes);
    setAnio(anio);

    return true;
}

void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio;
}
bool Fecha::validarFecha(Fecha obj,bool modo){
    bool eanio=true,emes=true,edia=true;
    ///VERIFICA AÑO
    if(modo==0){
        if(obj.getAnio()>1920 && obj.getAnio()<2010){
            eanio=false;
        }
    }
    else{
        if(obj.getAnio()>1920 && obj.getAnio()<2023){
            eanio=false;
        }
    }
    ///VERIFICA MES
    if(obj.getMes()>0 && obj.getMes()<13){
        emes=false;
    }
    ///VERIFICA DIA
    if(obj.getDia()>0 && obj.getDia()<32){
        edia=false;
    }

    if(eanio==false && emes==false && edia==false){
        return true;
    }
    else if(eanio==true&&emes==true&&edia==true){
        return false;
    }
    return false;
}
#endif // CLSFECHA_H_INCLUDED
