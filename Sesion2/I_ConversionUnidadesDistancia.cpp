/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
//
//
/* Programa para convertir unidades
   Implementa la siguiente formula

   Entradas: metros
   Salidas:  millas, yardas, pulgadas, pies
             yarda = metros * 0.9144
             milla = metros = 1609,344
             pulgada = 25.4 milimetros
             pie = 30.48

*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std;


int main() // Programa Principal
{
    double metros;               // cantidad de metros introducidos por el usuario
    double salida;           // salida una vez convertida a cada unidad
    const double conversionYardas = 0.9144;
    const double conversionMillas = 1609.344;
    const double conversionPulgada = 25400;
    const double conversionPie = 30480;

    // Entrada de datos
    cout << "Introduzca los metros: " ;
    cin >> metros;

    // Implementacion de la formula
    salida = metros * conversionYardas;
    cout << "\n "<< metros << " metros son : " << salida << " yardas\n\n" ;

    salida = metros * conversionMillas;
    cout << "\n "<< metros << " metros son : " << salida << " millas\n\n" ;

    salida = metros * conversionPulgada;
    cout << "\n "<< metros << " metros son : " << salida << " pulgada\n\n" ;

    salida = metros * conversionPie;
    cout << "\n "<< metros << " metros son : " << salida << " pie\n\n" ;

    return (0);
}
