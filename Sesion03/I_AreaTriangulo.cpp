/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   El programa calculara el area del triangulo a partir de dos lados y
   el angulo que estos dos forman
   Los valores se introduciran en centimetros los lados y el angulo en grados
   Entradas: lado1, lado2 y angulo
   Salida: area
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std;


int main() // Programa Principal
{
    //Declaracion de variables de entrada
    double lado1, lado2, angulo;

    //Declaracion de constantes y variables de apoyu
    double radianes;
    const double PI = 3.1415927;

    //Declaracion de variables de salida
    double area;

    //Pedimos al usuario que introduzca los datos
    cout << "Introduzca el primer lado: ";
    cin >> lado1;

    cout << "Introduzca el segundo lado: ";
    cin >> lado2;

    cout << "Introduzca el angulo que forman: ";
    cin >> angulo;


    //Pasamos de grados a radianes
    radianes = angulo * ( PI / 180.0 );

    //Calculamos el area
    area = (1/2.0)*lado1*lado2*sin(radianes);
    cout << "El area de nuestro triangulo es: " << area;


    return(0);
}
