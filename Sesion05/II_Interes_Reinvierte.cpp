/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*

/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S

using namespace std;


int main() // Programa Principal
{
    double capital,interes;
    int anios;

    capital = 0;
    while(capital <= 0){
        cout << "Por favor introduzca el capital inicial: ";
        cin >> capital;
    }

    interes = 0;
    while(interes <= 0 || interes >10){
        cout << "Por favor introduzca el interes: ";
        cin >> interes;
    }
    anios = 0;
    while(anios <= 0 || anios > 20){
        cout << "Por favor introduzca los años: ";
        cin >> anios;
    }

    int anios_pasados = 1;
    while ( anios_pasados <= anios){
        capital += capital*(interes/100);
        cout << "El capital al cabo de " << anios_pasados << " es de: "
             << capital<< endl;
        anios_pasados++;
    }

}
