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

int main() // Programa Principal
{
    // Declara variables para guardar los datos de entrada
    int horasI,minutosI,segundosI,horasF,minutosF,segundosF;

    int diferecia; // Declara variables de salida de datos

    //Declaramos las constantes que vamos a usar
    const string MENSAJE_ERROR = "Sean superado el minimo o el maximo "
                                 "o el inicial es mayor que el final"
                                 " o no es un numero";
    // Entrada de datos
    cout << "Introduzca las horas inicial y la final (min 0 y max 48h): " ;
    cin >> horasI >> horasF;
    /*
        En cada if siguiente iremos comprobando varias cosas.
        Lo primero que ni la hora inicial y la final no superen los maximos
        Y lo segundo que el inicial no sea superior al final.
    */
    if( horasI < 0 || horasI > 48 || horasF > 48 || horasF < 0
        || horasI > horasF ){
        cout << MENSAJE_ERROR;
             return(0);
    }

    cout << "Introduzca los minutos inicial y final (min 0 y max 60m): ";
    cin >> minutosI >> minutosF;
    if( minutosI < 0 || minutosI > 60 || minutosF > 60 || minutosF < 0 ){
        cout << MENSAJE_ERROR;
             return(0);
    }

    cout << "Introduzca los segundos inicial y final (min 0 y max 60m): ";
    cin >> segundosI >> segundosF ;
    if( segundosI < 0 || segundosI > 60 || segundosF > 60 || segundosF < 0){
        cout << MENSAJE_ERROR;
             return(0);
    }

    //Ya aqui calculamos la diferencia en segundos
    diferecia=(horasF-horasI)*3600+(minutosF-minutosI)*60
              + (segundosF-segundosI);
    cout << "La diferencia en segundos entre principio y fin es: "
         << diferecia;

    return (0);
}
