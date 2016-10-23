/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   El programa calculara la funcion gausiana a partir de los datos
   proporcionados por el usuario.
   El calculo se realiza mientras que la variable x sea menor que
   el maximo introducido por el usuario

   Entradas: esperanza,desviacion, minimo,maximo incremento
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
    int minimo,maximo,incremento;
    const double PI = 3.1415;
    // Entrada de datos
    cout << "Intoduzca la esperanza: " ;
    cin >> esperanza;
    do{
        cout << "Intoduzca la desviacion: " ;
        cin >> desviacion;
    }while(esperanza < 0);


    cout << "Introduzca un minimo: ";
    cin >> minimo;
    do{
        cout << "Introduzca un maximo: ";
        cin >> maximo;
    }while(maximo<=minimo);
    do{
        cout << "Introduzca un incremento: ";
        cin >> incremento;
    }while(incremento<=0);
    variableX=minimo;
    //Calculamos la funcion gausiana mientras la variableX sea menor que el
    //maximo introducido por el usuario
    while(variableX <= maximo){
        resultado = (1/(desviacion*sqrt(2*PI)))*exp((-1.0/2.0)*(pow((variableX-esperanza)/desviacion,2)));
        cout << "El resultado de la media gausiana con X=" << variableX << " es: " << resultado << endl;
        //Incrementamos la variableX en funcion del incromento puesto por el usuario
        variableX+=incremento;
    }

    return (0);
}
