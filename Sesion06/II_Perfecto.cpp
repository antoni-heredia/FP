/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   El programa el mayor numero perfecto que hay hasta un numero
   Para ello el programa recorrera todos los numero desde el 0 hasta n.
   Para cada uno de esos numero comprobara si es numero perfecto o no y si 
   lo es lo guarda ya que ese es el mayor encotrado por ahora.
   Para saber si es perfecto recorremos desde 1 hasta n/2 y viendo si es divisor
   o no del numero y si lo es lo sumamos a la variable resultado, que es la 
   que luego comprobaremos is es igual al numero actual.
   
   Entradas: numero
   Salidas:  mayor_perfecto
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matematicos
using namespace std;


int main() // Programa Principal
{
    //Declaramos las variables
    int numero, resultado;
    int mayor_perfecto = 0;
    
    //Pedimos al usuario que introduzca un numero
    do{
        cout << "Por favor introduzca un numero: ";
        cin >> numero;
    }while(numero <= 0);
    
    //Recorremos todos los numero que hay entre 1 y el numero introducido
    for(int x=1; x < numero; x++){
        //Reinicializamos para cada numero el resultado de sumar sus divisores
        resultado = 0;
        //Recorremos hasta la mitad del numero buscando divisores
        for(int y=1; y <= x/2 ;y++){
            //Si es divisor lo sumamos al resultado para luego comprabarlo
            if( x%y == 0)
                resultado += y;
        }
        //Si el resultado  de sumar sus divisores es igual al numero
        //Es que es el mayor perfecto encontrado hasta el momento
        if(resultado == x){
            mayor_perfecto=resultado;
        }
    }
    //Si hemos encontrado algun perfecto en el intervalo lo mostramos
    if( mayor_perfecto != 0 )
        cout << "El mayor encontrado a sido: " << mayor_perfecto;
    else
        cout << "No habia ningun perfecto en el intervalo";

    return (0);
}
