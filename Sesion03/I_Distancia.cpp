/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   Programa que calcula  la distancia de dos puntos.

   La formula de la distancia entre dos puntos viene definida por:
               ___________________
   distancia= v(x1-x2)²+(y1-y2)²
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>> // Inclusion de los recursos matematicos
using namespace std;


int main() // Programa Principal
{
    //Definimos las variables
    double x1,x2,y1,y2,distancia;

    //Pedimos al usuario que introduzca los datos

    cout << endl << "Introduzca la cordenada x1: ";
    cin >> x1;

    cout << endl << "Introduzca la cordenada y1: ";
    cin >> y1;

    cout << endl << "Introduzca la cordenada x2: ";
    cin >> x2;

    cout << endl << "Introduzca la cordenada y2: ";
    cin >> y2;

    //Realizamos lso calculor para obtener la distancia

    distancia=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    cout << endl << "La distancia entre los puntos es: " << distancia;
}
