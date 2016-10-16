/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   Programa que calcula  la diferencia de tiempo entre dos dias distintos
   como maximo.

   Entrada: horas,minutos, segundos.
   Salida:  horas,minutos,segundos
*/
/***************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
using namespace std;

int main()
{
    //Definimos las variables de entrada
    int numero1, numero2;

    int modulo1,modulo2;


    cout << "Por favor intrduzca el primer numero: ";
    cin >> numero1;

    cout << "Por favor intrduzca el segundo numero: ";
    cin >> numero2;

    if( numero1 == 0 || numero2 == 0 )
    {
        cout << "Al ser uno de los dos numeros 0, ninguno divide al otro";
        return(0);
    }
    //Calculamos el modulo de dividir un numero entre el otro
    modulo1 = numero1%numero2;
    modulo2 = numero2%numero1;

    //Comprobamos el resultado y en funcion mostramos un mensaje u otro
    if( modulo1 == 0 ){
        cout << "El " << numero2 << " divide a " << numero1;
    }else if(modulo2 == 0){
        cout << "El " << numero1 << " divide a " << numero2;
    }else{
        cout << "Ninguno de los dos numero se dividen de forma "
             " entera entre ellos";
    }

    return(0);
}
