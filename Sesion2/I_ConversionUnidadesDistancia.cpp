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
             conversionYardas = 0.9144;
             conversionMillas = 1609.344;
             conversionPulgada = 0.0254;
             conversionPie = 0.3048;

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
    const double conversionPulgada = 0.0254;
    const double conversionPie = 0.3048;

    // Entrada de datos
    cout << "Introduzca los metros: " ;
    cin >> metros;

    // Implementacion de la formula y mostrar los datos
    salida = metros / conversionYardas;
    cout << "\n "<< metros << " metros son : " << salida << " yardas\n\n" ;

    salida = metros / conversionMillas;
    cout << "\n "<< metros << " metros son : " << salida << " millas\n\n" ;

    salida = metros / conversionPulgada;
    cout << "\n "<< metros << " metros son : " << salida << " pulgada\n\n" ;

    salida = metros / conversionPie;
    cout << "\n "<< metros << " metros son : " << salida << " pie\n\n" ;

    return (0);
}
