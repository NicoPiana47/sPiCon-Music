#ifndef CLSVENTA_H_INCLUDED
#define CLSVENTA_H_INCLUDED
class Venta{
private:
    int id,dni;
    float importe;
    Fecha fechaV;
    bool estado;
public:
    ///SETS
    void setId(int i){id=i;}
    void setImporte(float im){importe=im;}
    void setDni(int d){dni=d;}
    void setFechaV(Fecha f){fechaV=f;}
    void setEstado(bool e){estado=e;}

    ///GETS
    int getId(){return id;}
    float getImporte(){return importe;}
    int getDni(){return dni;}
    Fecha getFechaV(){return fechaV;}
    int getSoloAnio(){return fechaV.getAnio();}
    int getSoloDia(){return fechaV.getDia();}
    int getSoloMes(){return fechaV.getMes();}
    bool getEstado(){return estado;}

    ///METODOS
    bool Cargar(int);
    void Mostrar(int,int);
    int leerDeDisco(int pos);
    int grabarEnDisco();
    int modificarEnDisco(int pos);
    int buscarPrecio(const char*);
};
bool Venta::Cargar(int i=0){
    rlutil::locate(47,8);
    cout<<"ID: ";
    id=i;
    cout<<id;
    rlutil::locate(47,9);
    cout<<"FECHA DE VENTA";
    if(fechaV.Cargar(1,1)==false){
        system("pause>null");
        return false;
    }

    rlutil::locate(47,13);
    cout<<"DNI CLIENTE: ";
    cin>>dni;

    string dniString;
    dniString = to_string(dni);
    if(dniString.size()>8){
        recuadro(44, 19, 17, 5, 15, 5);
        rlutil::locate(45,20);
        cout<<"DNI MAYOR A 8 DIGITOS";
        system("pause>null");
        return false;
    }

    rlutil::locate(47,14);
    cout<<"IMPORTE: ";
    importe=0;
    estado=true;
    return true;
}

void Venta::Mostrar(int modo,int y2=0){
    int x=0,y=0;
    if(estado==true){
        if(modo==1 || modo == 2){
            if(modo==1){
                x=45;
                y=13;
            }
            if(modo==2){
                x=10;
                y=13;
            }
            recuadro(x-1, y-1, 30, 5, 15, 5);
            rlutil::locate(x,y++);
            cout<<"ID: ";
            cout<<id<<endl;
            rlutil::locate(x,y++);
            cout<<"FECHA DE VENTA: ";
            fechaV.Mostrar();
            rlutil::locate(x,y++);
            cout<<"DNI CLIENTE: ";
            cout<<dni<<endl;
            rlutil::locate(x,y++);
            cout<<"IMPORTE: ";
            cout<<importe<<endl<<endl;
        }
        else{
            rlutil::locate(28,4);
            cout<<"ID ";
            rlutil::locate(42,4);
            cout<<"FECHA VENTA ";
            rlutil::locate(58,4);
            cout<<"DNI CLIENTE ";
            rlutil::locate(79,4);
            cout<<"IMPORTE ";

            rlutil::locate(28,y2);
            cout<<id;
            rlutil::locate(42,y2);
            fechaV.Mostrar();
            rlutil::locate(58,y2);
            cout<<dni;
            rlutil::locate(79,y2);
            cout<<importe;
        }
    }
}

int Venta::leerDeDisco(int pos){
    FILE *p;
    int leyo;
    p=fopen("venta.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, pos*sizeof(Venta),0);
    leyo=fread(this,sizeof(Venta),1,p);

    fclose(p);
    return leyo;
}

int Venta::grabarEnDisco(){
    FILE *p;
    int escribio;
    p=fopen("venta.dat","ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    escribio=fwrite(this,sizeof(Venta),1,p);
	fclose(p);
	return escribio;
}

int Venta::modificarEnDisco(int pos){
    FILE *p;
    int modifico;
    p=fopen("venta.dat","rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(p,pos*sizeof(Venta),0);
    modifico=fwrite(this,sizeof(Venta),1,p);
    fclose(p);
    return modifico;
}

#endif // CLSVENTA_H_INCLUDED
