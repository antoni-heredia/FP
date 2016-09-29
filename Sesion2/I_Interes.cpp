/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
//
// 
/* Programa para realizar la ley de Ohm
   Implementa la siguiente formula

   Entradas: intensidad (A), resistencia (ohmios)
   Salidas:  voltaje (v)
             voltaje = intensidad x resistencia
*/
/***************************************************************************/


#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>      // Inclusi�n de los recursos matem�ticos

using namespace std; 


int main() // Programa Principal
{                       
	double capital;               // Declara variables para guardar
	double interes;               // los dos capital, interes, total
	double total;
   // Entrada de datos
   cout << "Introduzca el capital: " ;
   cin >> capital;
   cout << "Introduzca el interes: ";
   cin >> interes;

	// Implementacion de la formula
   	total = capital+capital*interes/100;

	cout << "\nEl total es: " << total << " Euros\n\n" ;
   
	return (0);
}
