/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   El programa calculara la funcion gausiana a partir de los

   Entradas: caracter en mayuscula --> caracter
   Salidas:  caracter en minuscula
   El metodo consiste en restar 33 al caracter, que guardado en memoria sera
   un int con el valor de dicho caracter en ascii
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S

using namespace std;


int main() // Programa Principal
{
    //DEclaracion de variables
    char caracter, caracter_minuscula;
    //Peticion de introduccion de datos
    cout << "Introduzca un caracter en mayuscula por favor: ";
    cin >> caracter;
    //Calcular el caracter en minuscula
    caracter_minuscula = caracter + 32;
    //Mostrar el resultado
    cout << endl << "El caracter " << caracter<< " en minuscula es: " << caracter_minuscula;
}
