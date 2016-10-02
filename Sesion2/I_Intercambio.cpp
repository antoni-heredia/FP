/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
//
//
/* Programa para intercambiar el valor de dos cajas
   Implementa la siguiente formula

   Entradas: caja_dcha, caja_izda;
   Salidas: caja_dcha, caja_izda;
   Usamos una variable intermedia para poder introducir temporalmente el valor de la cajaDerecha antes de cambiarlo

*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std;


int main() // Programa Principal
{
    double caja_dcha;               // caja derecha
    double caja_izda;               // caja izquierda
    double varIntercambio;           // caja donde intercambiaremos los valores
    cout << "Introduzca el valor de la caja derecha: ";
    cin >> caja_dcha;
    cout << endl << "Introduzca el valor de la caja izquierda: " << end;
    cin >> caja_izda;

    varIntercambio = caja_dcha;
    caja_dcha=caja_izda;
    caja_izda = varIntercambio;
    cout << "La caja izquierda vale " << caja_izda << "\n" << end;
    cout << "La caja derecha vale " << caja_dcha;
}
