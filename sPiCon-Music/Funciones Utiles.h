#ifndef CARGARCADENA_H_INCLUDED
#define CARGARCADENA_H_INCLUDED

///PROTOTIPOS
void cuadro (int x1,int x2,int y1,int y2);
void cargarCadena(char *pal, int tam);
void pin(int,int);
void sin(int);
void cambiarcolor(int);
void charmander();
///DESARROLLO
void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}
void cuadro (int x1,int x2,int y1,int y2) {
    int x=y1, j=y1;
    rlutil::locate(x1, y1);

    cout << (char)201;

    for (int i=0; i<x2-x1-1; i++) {
        cout << (char)205;
    }

    rlutil::locate(x2, y1);
    cout << (char)187;

    for (int i=0; i<y2-y1-1; i++) {
        x++;
        rlutil::locate(x2, x);
        cout << (char)186 << endl;
    }
    cout << endl;
    for (int i=0; i<y2-y1-1; i++) {
        j++;
        rlutil::locate(x1, j);

        cout << (char)186 << endl;
    }

    rlutil::locate(x1, y2);
    cout << (char)200;void cargarCadena(char *pal, int tam);

    for (int i=0; i<x2-x1-1; i++){
        cout << (char)205;
    }
    rlutil::locate (x2, y2);
    cout << (char)188;
}
///CHARMANDER
void cambiarcolor(int X) {
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}


void pin(int x,int c) {
    cambiarcolor(c);
    int i;
    for(i=1; i<=x; i++) {
        cout<<char(219)<<char(219);
    }
}
void sin(int o) {

    int j;
    for(j=1; j<=o; j++) {
        cout<<char(255)<<char(255);
    }
}

enum Color{
cNEGRO=0,
cAZUL=1,
cVERDE=2,
cCIAN=3,
cROJO=4,
cMAGENTA=5,
cMARRON=6,
cGRIS_CLARO=7,
cGRIS=8,
cAZUL_CLARO=9,
cVERDE_CLARO=10,
cCIAN_CLARO=11,
cROJO_CLARO=12,
cMAGENTA_CLARO=13,
cAMARILLO=14,
cBLANCO=15
};
void clrscr(void){
    system("cls");
}
void pause(void){
    system("pause >nul");
}
void gotoxy(short x, short y){
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void textcolor(short colorTexto=15, short colorFondo=0){
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}
void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 188;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}
struct console
  {
  console( unsigned width, unsigned height )
    {
    SMALL_RECT r;
    COORD      c;
    hConOut = GetStdHandle( STD_OUTPUT_HANDLE );
    if (!GetConsoleScreenBufferInfo( hConOut, &csbi ))
      throw runtime_error( "You must be attached to a human." );

    r.Left   =
    r.Top    = 0;
    r.Right  = width -1;
    r.Bottom = height -1;
    SetConsoleWindowInfo( hConOut, TRUE, &r );

    c.X = width;
    c.Y = height;
    SetConsoleScreenBufferSize( hConOut, c );
    }

  ~console()
    {
    SetConsoleTextAttribute(    hConOut,        csbi.wAttributes );
    SetConsoleScreenBufferSize( hConOut,        csbi.dwSize      );
    SetConsoleWindowInfo(       hConOut, TRUE, &csbi.srWindow    );
    }

  void color( WORD color = 0x07 )
    {
    SetConsoleTextAttribute( hConOut, color );
    }

  HANDLE                     hConOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  };
#endif // CARGARCADENA_H_INCLUDED
