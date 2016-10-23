/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   El programa dado un numero entero nos devolvera todos sus digitos por
   separado

   Para ello primero calcularemos el numero de digitos que tiene.
   Y con ello iremos calculuando desde el primero digito mas significativo
   hasta el ultimo. Dentro del codigo esta mejor explicado por partes.
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>

using namespace std;


int main() // Programa Principal
{
    //Declaramos las variables de entrada
    int numero_introducido;

    cout << "Por favor introduzca un numero entero: ";
    cin >> numero_introducido;

    //El numero introducido le aplicamos el valor absoluto
    numero_introducido=abs(numero_introducido);

    //Vemos la cantidad de digitos que tiene el entero
    int longitud = 1;
    int numero_aux = numero_introducido;
    while ( numero_aux /= 10 )
       longitud++;

    /*
        El primer divisor sera 10 elevado al numero de digitos menos uno
        para que al dividir el numero entre el nos de la cifra
        mas significativa
    */
    int divisor = pow(10,longitud-1);

    /*
        Mientras que el numero con el que dividimos sea distinto de 0
        todavia quedan cifras significativas y por lo tanto
        tenemos que seguir calculando
    */

    while( divisor != 0 ){
        //Mostramos la cifra significativa que toca en esta pasada
        cout << numero_introducido/divisor << " ";
        /*
            El numero con el que trabajamos ahora sera el resto para
            eliminar el digito que hemos mostrado antes
        */
        numero_introducido = numero_introducido%divisor;
        /*
            Para la siguiente pasada el numero con el que diviremos sera
            el anterior entre 10
        */
        divisor /= 10;
    }

    return(0);
}
