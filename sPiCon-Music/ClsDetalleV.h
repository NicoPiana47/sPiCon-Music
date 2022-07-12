#ifndef CLSDETALLEV_H_INCLUDED
#define CLSDETALLEV_H_INCLUDED

class DetalleV{
private:
    int id;
    char codigo[5];
    float importe;
    int cant;
    bool estado;
public:
    ///SETS
    void setId(int i){id=i;}
    void setCodigo(const char *c){strcpy(codigo,c);}
    void setImporte(float im){importe=im;}
    void setCantidad(int ca){cant=ca;}
    void setEstado(bool e){estado=e;}

    ///GETS
    int getId(){return id;}
    const char *getCodigo(){return codigo;}
    float getImporte(){return importe;}
    int getCantidad(){return cant;}
    bool getEstado(){return estado;}

    ///METODOS
    bool Cargar(int);
    void Mostrar(int);
    int leerDeDisco(int pos);
    int grabarEnDisco();
    int modificarEnDisco(int pos);
    int buscarPrecio(const char*);
    bool noRepetir(int, const char*);

    ///SOBRECARDA DE OPERADORES
    bool operator==(const char *cad){
        if(strcmp(codigo,cad)==0) return true;
        return false;
    }
};
bool DetalleV::Cargar(int i=0){
    int precio;
    rlutil::locate(59,9);
    cout<<"ID: ";
    id=i;
    cout<<id;
    rlutil::locate(59,10);
    cout<<"CODIGO DE ARTICULO: ";
    cargarCadena(codigo, 20);

    if(strlen(codigo)>5){
        recuadro(56, 19, 17, 2, 15, 5);
        rlutil::locate(57,20);
        cout<<"CODIGO MAYOR A 5";
        return false;
    }

    rlutil::locate(59,11);
    cout<<"CANTIDAD: ";
    cin>>cant;

    while(cant<=0){
        recuadro(56, 19, 31, 2, 15, 5);
        rlutil::locate(57,20);
        cout<<"INGRESE UNA CANTIDAD POSITIVA";
        system("pause>null");
        rlutil::locate(57,19);
        cout << "                                 ";
        rlutil::locate(57,20);
        cout << "                                  ";
        rlutil::locate(57,21);
        cout << "                                  ";
        rlutil::locate(69,11);
        cout << "                    ";
        rlutil::locate(69,11);
        cin >> cant;
    }

    rlutil::locate(59,12);
    cout<<"IMPORTE: ";
    precio=buscarPrecio(getCodigo());
    importe=precio*cant;
    cout<<importe;
    estado=true;
    return true;
}

void DetalleV::Mostrar(int y2){
    if(estado==true){
        rlutil::locate(28,12);
        cout<<"ID ";
        rlutil::locate(42,12);
        cout<<"CODIGO DE ARTICULO ";
        rlutil::locate(64,12);
        cout<<"CANTIDAD ";
        rlutil::locate(79,12);
        cout<<"IMPORTE ";

        rlutil::locate(28,y2+3);
        cout<<id;
        rlutil::locate(42,y2+3);
        cout<<codigo;
        rlutil::locate(64,y2+3);
        cout<<cant;
        rlutil::locate(79,y2+3);
        cout<<importe;
    }
}

int DetalleV::leerDeDisco(int pos){
    FILE *p;
    int leyo;
    p=fopen("detallev.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, pos*sizeof(DetalleV),0);
    leyo=fread(this,sizeof(DetalleV),1,p);

    fclose(p);
    return leyo;
}

int DetalleV::grabarEnDisco(){
    FILE *p;
    int escribio;
    p=fopen("detallev.dat","ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    escribio=fwrite(this,sizeof(DetalleV),1,p);
	fclose(p);
	return escribio;
}

int DetalleV::modificarEnDisco(int pos){
    FILE *p;
    int modifico;
    p=fopen("detallev.dat","rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(p,pos*sizeof(DetalleV),0);
    modifico=fwrite(this,sizeof(DetalleV),1,p);
    fclose(p);
    return modifico;
}
int DetalleV::buscarPrecio(const char *codigo){
    Instrumento obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)==1){
        if(strcmp(codigo,obj.getCodigo())==0){
            return obj.getPrecio();
        }
    }
    return -1;
}
bool DetalleV::noRepetir(int id, const char *codigo){
    DetalleV obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)==1){
        if(id==obj.getId()){
            if(strcmp(codigo,obj.getCodigo())==0){
                return false;
            }
        }
    }
    return true;
}

#endif // CLSDETALLEV_H_INCLUDED
