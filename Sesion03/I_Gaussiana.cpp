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

   Entradas: esperanza,desviacion, x
   Salidas:  funcion gausiana
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std;


int main() // Programa Principal
{
    double esperanza, desviacion, variableX;
    double resultado;
    const double PI = 3.1415;
    // Entrada de datos
    cout << "Intoduzca la esperanza: " ;
    cin >> esperanza;
    cout << "Intoduzca la desviacion: " ;
    cin >> desviacion;
    cout << "Intoduzca la variable x: " ;
    cin >> variableX;

    //Calculamos la funcion gausiana
    resultado = (1/(desviacion*sqrt(2*PI)))*exp((-1.0/2.0)*(pow((variableX-esperanza)/desviacion,2)));

    //Mostrar los datos
    cout << "El resultado de la media gausiana es: " << resultado << endl;

    return (0);
}
