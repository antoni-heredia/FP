/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
//
//
/* Programa implementar un interes bancario

   Entradas: capital, interes
   Salidas:  total
             voltaje = intensidad x resistencia
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std;


int main() // Programa Principal
{
    double capital,interes;               // Declara variables de entrada
    double total;

    const string MENSAJE_ERROR = "El dato introducido es incorrecto";
    // Entrada de datos
    cout << "Introduzca el capital: " ;
    cin >> capital;
    if(capital < 0 )
    {
        cout << MENSAJE_ERROR;
        return(0);
    }
    cout << "Introduzca el interes: ";
    cin >> interes;
    if(interes < 0 )
    {
        cout << MENSAJE_ERROR;
        return(0);
    }

    // Implementacion de la formula
    total = capital+capital*interes/100;

    cout << "\nEl total es: " << total << " Euros\n\n" ;

    return (0);
}
