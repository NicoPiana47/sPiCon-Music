#ifndef CLSCLIENTE_H_INCLUDED
#define CLSCLIENTE_H_INCLUDED
#include <stdio.h>
#include<cstring>
class Cliente{
private:
    int dni;
    Fecha fechaN;
    char nombre[20],apellido[20],mail[30],telefono[20],musico='N';
    bool estado;
public:
    ///SETS
    void setDni(int d){dni=d;}
    void setMusico(char m){musico=m;}
    void setFechaN(Fecha f){fechaN=f;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setTelefono(const char *t){strcpy(telefono,t);}
    void setApellido(const char *a){strcpy(apellido,a);}
    void setMail(const char *m){strcpy(mail,m);}
    void setEstado(bool e){estado=e;}
    ///GETS
    int getDni(){return dni;}
    char getMusico(){return musico;}
    Fecha getFechaN(){return fechaN;}
    int getSoloAnio(){return fechaN.getAnio();}
    int getSoloDia(){return fechaN.getDia();}
    int getSoloMes(){return fechaN.getMes();}
    const char *setTelefono(){return telefono;}
    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    const char *getMail(){return mail;}
    bool getEstado(){return estado;}


    ///METODOS
    bool Cargar(int);
    void Mostrar(bool, int);
    int leerDeDisco(int pos);
    int grabarEnDisco();
    int modificarEnDisco(int pos);
};
bool Cliente::Cargar(int d=0){
    if(d!=0){
        dni=d;
    }
    else{
        rlutil::locate(47,8);
        cout<<"DNI: ";
        cin>>dni;
    }

    string dniString;
    dniString = to_string(dni);
    if(dniString.size()>8){
        recuadro(44, 21, 22, 2, 15, 5);
        rlutil::locate(45,22);
        cout<<"DNI MAYOR A 8 DIGITOS";
        return false;
    }

    rlutil::locate(47,9);
    cout<<"FECHA DE NACIMIENTO";
    if(fechaN.Cargar(1)==false) return false;

    rlutil::locate(47,13);
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 20);
    rlutil::locate(47,14);
    cout<<"APELLIDO: ";
    cargarCadena(apellido,20);
    rlutil::locate(47,15);
    cout<<"ES MUSICO? (S/N): ";
    cin>>musico;

    while(musico!='S' && musico!='N'){
        recuadro(44, 19, 17, 2, 15, 5);
        rlutil::locate(45,20);
        cout<<"INGRESE S O N";
        system("pause>null");
        rlutil::locate(44,19);
        cout << "                             ";
        rlutil::locate(44,20);
        cout << "                             ";
        rlutil::locate(44,21);
        cout << "                              ";
        rlutil::locate(64,15);
        cout << "               ";
        rlutil::locate(65,15);
        cin >> musico;
    }

    rlutil::locate(47,16);
    cout<<"MAIL: ";
    cargarCadena(mail,30);
    rlutil::locate(47,17);
    cout<<"TELEFONO: ";
    cargarCadena(telefono,30);

    estado=true;
    return true;
}

void Cliente::Mostrar(bool modo=0, int y2=0){
    int x=0, y=0;
    if(estado==true){
        if(modo==1){
            x=45;
            y=13;
            recuadro(44, 12, 31, 8, 15, 5);
            rlutil::locate(x,y++);
            cout<<"DNI: ";
            cout<<dni<<endl;
            rlutil::locate(x,y++);
            cout<<"FECHA DE NACIMIENTO: ";
            fechaN.Mostrar();
            rlutil::locate(x,y++);
            cout<<"NOMBRE: ";
            cout<<nombre<<endl;
            rlutil::locate(x,y++);
            cout<<"APELLIDO: ";
            cout<<apellido<<endl;
            rlutil::locate(x,y++);
            cout<<"MUSICO: ";
            cout<<musico<<endl;
            rlutil::locate(x,y++);
            cout<<"MAIL: ";
            cout<<mail<<endl;
            rlutil::locate(x,y++);
            cout<<"TELEFONO: ";
            cout<<telefono<<endl<<endl;
        }
        else{
            rlutil::locate(4,4);
            cout<<"DNI";
            rlutil::locate(18,4);
            cout<<"FECHA NAC.";
            rlutil::locate(33,4);
            cout<<"NOMBRE ";
            rlutil::locate(48,4);
            cout<<"APELLIDO ";
            rlutil::locate(66,4);
            cout<<"MUSICO ";
            rlutil::locate(78,4);
            cout<<"MAIL ";
            rlutil::locate(106,4);
            cout<<"TELEFONO ";


            rlutil::locate(4,y2);
            cout<<dni;
            rlutil::locate(18,y2);
            fechaN.Mostrar();
            rlutil::locate(33,y2);
            cout<<nombre;
            rlutil::locate(48,y2);
            cout<<apellido;
            rlutil::locate(66,y2);
            cout<<musico;
            rlutil::locate(78,y2);
            cout<<mail;
            rlutil::locate(106,y2);
            cout<<telefono;
        }
    }
}

int Cliente::leerDeDisco(int pos){
    FILE *p;
    int leyo;
    p=fopen("cliente.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, pos*sizeof(Cliente),0);
    leyo=fread(this,sizeof(Cliente),1,p);

    fclose(p);
    return leyo;
}

int Cliente::grabarEnDisco(){
    FILE *p;
    int escribio;
    p=fopen("cliente.dat","ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    escribio=fwrite(this,sizeof(Cliente),1,p);
	fclose(p);
	return escribio;
}

int Cliente::modificarEnDisco(int pos){
    FILE *p;
    int modifico;
    p=fopen("cliente.dat","rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(p,pos*sizeof(Cliente),0);
    modifico=fwrite(this,sizeof(Cliente),1,p);
    fclose(p);
    return modifico;
}

class Cliente2{
private:
    int dni,cantVentas;
    char nombre[20],apellido[20];
    bool estado;
public:
    ///SETS
    void setDni(int d){dni=d;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *a){strcpy(apellido,a);}
    void setCantVentas(int cv){cantVentas=cv;}
    void setEstado(bool e){estado=e;}
    ///GETS
    int getDni(){return dni;}
    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    int getCantVentas(){return cantVentas;}
    bool getEstado(){return estado;}


    ///METODOS
    void Mostrar();
    int leerDeDisco(int pos);
    int grabarEnDisco();
    int modificarEnDisco(int pos);
};
void Cliente2::Mostrar(){
    if(estado==true){
        cout<<"DNI: ";
        cout<<dni<<endl;
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;
        cout<<"APELLIDO: ";
        cout<<apellido<<endl;
        cout<<"CANT VENTAS: ";
        cout<<cantVentas<<endl<<endl;
    }
}

int Cliente2::leerDeDisco(int pos){
    FILE *p;
    int leyo;
    p=fopen("cliente2.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, pos*sizeof(Cliente2),0);
    leyo=fread(this,sizeof(Cliente2),1,p);

    fclose(p);
    return leyo;
}

int Cliente2::grabarEnDisco(){
    FILE *p;
    int escribio;
    p=fopen("cliente2.dat","ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    escribio=fwrite(this,sizeof(Cliente2),1,p);
	fclose(p);
	return escribio;
}

int Cliente2::modificarEnDisco(int pos){
    FILE *p;
    int modifico;
    p=fopen("cliente2.dat","rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(p,pos*sizeof(Cliente2),0);
    modifico=fwrite(this,sizeof(Cliente2),1,p);
    fclose(p);
    return modifico;
}
#endif // CLSCLIENTE_H_INCLUDED
