#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

using namespace std;

#include"rlutil.h"
#include"Funciones Utiles.h"
#include"ClsFecha.h"
#include"ClsInstrumento.h"
#include"ClsCliente.h"
#include"ClsVenta.h"
#include"ClsDetalleV.h"
#include"Funciones_Instrumento.h"
#include"Funciones_Cliente.h"
#include"Funciones_Venta.h"
#include"Funciones_Reportes.h"
#include"Funciones_Configuracion.h"
#include"MenuPrincipal.h"
HANDLE wHnd;

int main(){
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, 120, 30};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    menuPrincipal();
    return 0;
}
