/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
//
// 
/* Programa para incremento de salario
   Implementa la siguiente formula

   Entradas: salario_base
   Salidas:  salario_base
             salario_base= salario_base*1.02
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std; 


int main() // Programa Principal
{                       
	double salario_base;               // Salario base introducido 
	
   // Entrada de datos
   cout << "Introduzca el salario base: " ;
   cin >> salario_base;
	// Implementacion de la formula
   	salario_base = salario_base*1.02;
	
	/*
	He elegido esta forma debido que ha mi parecer, demuestra que se esta haciendo un calculo,
	pero sin necesidad de declarar otra variable, ademas quedaria mas claro que si se hiciera directamente en el cout
	*/
	cout << "\nEl salario final es: " << salario_base << " Euros\n\n" ;
   
	return (0);
}
