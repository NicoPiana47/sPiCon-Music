#ifndef CLSINSTRUMENTO_H_INCLUDED
#define CLSINSTRUMENTO_H_INCLUDED

class Instrumento{
private:
    char codigo[5];
    char descripcion[30];
    char modelo[30];
    float precio;
    int stock,tipo;
    bool estado;
public:
    ///SETS
    void setCodigo(const char *c){strcpy(codigo,c);}
    void setDescripcion(const char *d){strcpy(descripcion,d);}
    void setModelo(const char *m){strcpy(modelo,m);}
    void setTipo(int t){tipo=t;}
    void setPrecio(float p){precio=p;}
    void setStock(int s){stock=s;}
    void setEstado(bool e){estado=e;}
    ///GETS
    const char *getCodigo(){return codigo;}
    const char *getDescripcion(){return descripcion;}
    const char  *getModelo(){return modelo;}
    int getTipo(){return tipo;}
    float getPrecio(){return precio;}
    int getStock(){return stock;}
    bool getEstado(){return estado;}

    ///METODOS
    bool Cargar(char *);
    void Mostrar(bool,int);
    int grabarEnDisco();
    int leerDeDisco(int pos);
    int modificarEnDisco(int pos);
    bool verificarPrecioCantidad(Instrumento obj,bool modo);
    ///SOBRECARGA OPERADORES

    bool operator==(const char *cad){
        if(strcmp(codigo,cad)==0) return true;
        return false;
    }

};
bool Instrumento::Cargar(char *c){
    if(c!=0){
        strcpy(codigo,c);
    }
    else{
        cout << "CODIGO: ";
        cargarCadena(codigo,30);
    }
    if(strlen(codigo)>5){
        recuadro(49, 19, 16, 2, 15, 5);
        rlutil::locate(50,20);
        cout<<"CODIGO INVALIDO";
        return false;
    }
    rlutil::locate(47,9);
    cout << "INSTRUMENTO: ";
    cargarCadena(descripcion,30);
    rlutil::locate(47,10);
    cout << "MODELO: ";
    cargarCadena(modelo,30);
    rlutil::locate(47,11);
    cout << "TIPO (1 A 4): ";
    cin >> tipo;

    while(tipo<1 || tipo>4){
        recuadro(49, 19, 14, 2, 15, 5);
        rlutil::locate(50,20);
        cout<<"TIPO INVALIDO";
        system("pause>null");
        rlutil::locate(49,19);
        cout << "                             ";
        rlutil::locate(49,20);
        cout << "                             ";
        rlutil::locate(49,21);
        cout << "                              ";
        rlutil::locate(60,11);
        cout << "                    ";
        rlutil::locate(61,11);
        cin >> tipo;
    }

    rlutil::locate(47,12);
    cout << "PRECIO: ";
    cin >> precio;

    while(precio<1){
        recuadro(45, 19, 29, 2, 15, 5);
        rlutil::locate(47,20);
        cout<<"INGRESE UN PRECIO POSITIVO";
        system("pause>null");
        rlutil::locate(45,19);
        cout << "                                 ";
        rlutil::locate(45,20);
        cout << "                                  ";
        rlutil::locate(45,21);
        cout << "                                  ";
        rlutil::locate(55,12);
        cout << "                    ";
        rlutil::locate(55,12);
        cin >> precio;
    }

    rlutil::locate(47,13);
    cout << "STOCK: ";
    cin >> stock;

    while(stock<1){
        recuadro(45, 19, 28, 2, 15, 5);
        rlutil::locate(47,20);
        cout<<"INGRESE UN STOCK POSITIVO";
        system("pause>null");
        rlutil::locate(45,19);
        cout << "                                 ";
        rlutil::locate(45,20);
        cout << "                                 ";
        rlutil::locate(45,21);
        cout << "                                 ";
        rlutil::locate(54,13);
        cout << "                    ";
        rlutil::locate(54,13);
        cin >> stock;
    }

    estado=true;
    return true;
}

void Instrumento::Mostrar(bool modo=0,int y2=0){
    int x=0, y=0;
    if(estado==true){
        if(modo==1){
            x=45;
            y=13;
            recuadro(43, 12, 34, 7, 15, 5);
            rlutil::locate(x,y++);
            cout<<"CODIGO: ";
            cout<<codigo<<endl;
            rlutil::locate(x,y++);
            cout<<"DESCRIPCION: ";
            cout<<descripcion<<endl;
            rlutil::locate(x,y++);
            cout<<"MODELO: ";
            cout<<modelo<<endl;
            rlutil::locate(x,y++);
            cout<<"TIPO: ";
            cout<<tipo<<endl;
            rlutil::locate(x,y++);
            cout<<"PRECIO: ";
            cout<<precio<<endl;
            rlutil::locate(x,y++);
            cout<<"STOCK: ";
            cout<<stock<<endl<<endl;
        }
        else{
            rlutil::locate(12,4);
            cout<<"CODIGO ";
            rlutil::locate(24,4);
            cout<<"DESCRIPCION ";
            rlutil::locate(44,4);
            cout<<"MODELO ";
            rlutil::locate(70,4);
            cout<<"TIPO ";
            rlutil::locate(83,4);
            cout<<"PRECIO ";;
            rlutil::locate(99,4);
            cout<<"STOCK ";

            rlutil::locate(12,y2);
            cout<<codigo;
            rlutil::locate(24,y2);
            cout<<descripcion;
            rlutil::locate(44,y2);
            cout<<modelo;
            rlutil::locate(70,y2);
            cout<<tipo;
            rlutil::locate(83,y2);
            cout<<precio;
            rlutil::locate(99,y2);
            cout<<stock;
        }
    }
}
int Instrumento::grabarEnDisco(){
    FILE *p;
    int escribio;
    p=fopen("instrumento.dat","ab");
    if(p==NULL) return -1;
    escribio=fwrite(this,sizeof(Instrumento),1,p);

    fclose(p);
    return escribio;
}
int Instrumento::leerDeDisco(int pos){
    FILE *p;
    int leyo;
    p=fopen("instrumento.dat","rb");
    if(p==NULL) return -1;
    fseek(p,pos*sizeof(Instrumento),0);
    leyo=fread(this,sizeof(Instrumento),1,p);

    fclose(p);
    return leyo;
}
int Instrumento::modificarEnDisco(int pos){
    FILE *p;
    int modifico;
    p=fopen("instrumento.dat","rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(p,pos*sizeof(Instrumento),0);
    modifico=fwrite(this,sizeof(Instrumento),1,p);
    fclose(p);
    return modifico;
}

bool Instrumento::verificarPrecioCantidad(Instrumento obj,bool modo){
    bool eprecio=true,ecodigo=true;
    if(obj.getPrecio()>0){
            eprecio=false;
    }
    if(strlen(obj.getCodigo())<6){
            ecodigo=false;
    }

    if(modo==0){
        if(ecodigo==false){
            return true;
        }
        if(ecodigo==true){
            return false;
        }
    }
    if(modo==1){
        if(eprecio==false){
            return true;
        }
        if(eprecio==true){
            return false;
        }
    }
    return -1;
}

#endif // CLSINSTRUMENTO_H_INCLUDED
