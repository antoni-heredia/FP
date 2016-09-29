/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
//
// 
/* Programa para reparto de ganancias
   Implementa la siguiente formula

   Entradas: gananciaTotal
   Salidas:  gananciasDesing,salarioFabricante
             gananciasDesing = 2*gananciaTotal/5
             gananciasFabricante = gananciaTotal/5
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std; 


int main() // Programa Principal
{                       
	double gananciaTotal;               // Ganancias introducidas
	double gananciasDesing;               // Ganancias introducidas
	double gananciasFabricante;               // Ganancias introducidas
   // Entrada de datos
   cout << "Introduzca las ganancias totales: " ;
   cin >> gananciaTotal;
	// Implementacion de la formula
	
   	gananciasFabricante = gananciaTotal/5;
   	//Como el diseñador gana el doble de cada fabricante quedaria tal que asi.
   	gananciasDesing = 2*gananciasFabricante;

	// Salida de datos
	cout << "\nLa ganancia del diseñador es: " << gananciasDesing << " Euros\n\n" ;
   	cout << "\nLa ganancia de cada fabricante es: " << gananciasFabricante << " Euros\n\n" ;

	return (0);
}
