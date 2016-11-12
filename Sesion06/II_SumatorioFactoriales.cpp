/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   El programa calculara la suma de los factoriales hasta un numero
   en concreto. Es decir:
        1+2!+3!+....+n!

   Entradas: numero
   Salidas:  si es narcisista o no y en caso de serlo mostrar la potencia
             con la que lo es
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matematicos
using namespace std;


int main() // Programa Principal
{
    int numero, resultado;
    //Pedimos al usuario que meta los datos
    do{
        cout << "Por favor introduzca un numero: ";
        cin >> numero;
    }while(numero <= 0);

    //Inicializamos el resultado para a la hora de hacer += no de error
    resultado = 0;
    //Recorreremos todos los numero que hay desde el uno hasta el que
    //ha dicho el usuario como final de la succesion
    for(int x = 1; x<=numero ; x++ ){
        //Calculamos el factorial para cada uno
        int factorial = 1;
        for(int y = 1; y<=x; y++){
            factorial *= y;
        }
        //Le sumamos el factorial al resultado final
        resultado += factorial;
    }
    //Mostramos los datos
    cout << "El resultado es: " << resultado << endl;
    return (0);
}
