/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
//
//
/* Programa para pasar de millas a kilometros
   Implementa la siguiente formula

   Entradas: millas
   Salidas:  kilometros
             kilometros = millas * 1,609

*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std;


int main() // Programa Principal
{
    double millas;               // cantidad de millas introducidas por el usuario
    double kilometros;           // kilometros una vez convertidas la smillas
    const double conversion = 1.609;
    // Entrada de datos
    cout << "Introduzca las millas: " ;
    cin >> millas;

    // Implementacion de la formula
    kilometros = millas * conversion;
    cout << "\n "<< millas << " millas son : " << kilometros << " kilometros\n\n" ;

    cout << "Introduzca los kilometros: " ;
    cin >> kilometros;

    // Implementacion de la formula
    millas = kilometros / conversion;
    cout << "\n "<< kilometros << " kilometros son : " << millas << " millas\n\n" ;
    return (0);
}
