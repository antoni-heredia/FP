/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   El programa sirve para probar varias funciones matematicas en c++
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath> //Incluimos los recursos matematicos
using namespace std;


int main() // Programa Principal
{
    //Declaramos las variables de entrada
    double x, y, h;
    //Declaramos las variables de salida
    double a, b, c;
    cout << "Por favor introduzca las variables de "
         << "entrada en el siguiente orden: "
         << endl;

    cout << "x = ";
    cin >> x;

    cout  << "y = ";
    cin >> y;

    cout  << "h = ";
    cin >> h;

    //Apartado a
    a = (1+(pow(x,2)/y))/((pow(x,3)/(1+y)));

    //Apartado b
    b = (1+((1/3.0)*sin(h))-((1/7.0)*cos(h)))/(2*h);

    //Apartado c
    c=sqrt((1)+pow(exp(x)/pow(x,2),2));

    //Mostrar los resultados
    cout << endl << "El resultado del apartado a es: "
         << a;
    cout << endl << "El resultado del apartado b es: "
         << b;
    cout << endl << "El resultado del apartado c es: "
         << c;

    return(0);
}
