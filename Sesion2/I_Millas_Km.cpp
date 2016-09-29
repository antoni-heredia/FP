/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
//
// 
/* Programa para calcular el area y la circunferencia
   Implementa la siguiente formula

   Entradas: radio(cm)
   Salidas:  
             longitud circunferencia = 2 x pi x radio
			 área circulo = pi x radio^2
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std; 


int main() // Programa Principal
{                       
	double radio;               // Declara variables para guardar
	double circunferencia;               // los el radio, la longitud de la circunferencia y el area
	double area;
	const double pi = 3.1415927;

   // Entrada de datos
   cout << "Introduzca el radio: " ;
   cin >> radio;
   
	// Implementacion de la formula
   	circunferencia = radio * pi * 2;
	area = radio * radio * pi;
	/*
		Usando constantes, te ahorras cambiar el valor de pi en todos los lados que la uses,
		solo tendrias que cambiarlo donde declares la constante
	*/
	cout << "\nLa longitud de la circunferencia vale: " << circunferencia << " cm\n\n" ;
   	cout << "\n El area vale: " << area << " cm^2\n\n" ;

	return (0);
}
