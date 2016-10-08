/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   El programa para calcular el minimo numero de bits que son necesarios para
   transformar un numero en decimal a binario

   Como no hay log en base 2 usamos el cambio de base del logaritmo para
   obtener el mismo resultado
   resultado = (log10(numero)/log10(2))+1;
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std;


int main() // Programa Principal
{
    // Declaramos las variables
    int numero,cantidad_de_bits;

    // Pedimos al usuario que introduzca los datos
    cout << "Por favor introduzca un numero entero: ";
    cin >> numero;

    //Calculamos el numero minimo de bits necesarios
    cantidad_de_bits = (log10(numero)/log10(2))+1;
    // Mostramos el resultado
    cout << endl << "El numero de bits necesarios son: " << cantidad_de_bits;
}
