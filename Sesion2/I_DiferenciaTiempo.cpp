/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
//
//
/* Programa para ajustar el tiempo

   Entradas: segundos, minutos, horas
   Salidas:  segundos, minutos, horas

   Veremos la diferencia que hay entre la hora final y la hora inicial
   Y luego convertimos cada unidad a segundos

*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std;


int main() // Programa Principal
{
    int horasI;               // Declara variables para guardar los datos de entrada
    int minutosI;
    int segundosI;
    int horasF;
    int minutosF;
    int segundosF;
    int diferencia;
    // Entrada de datos
    cout << "Introduzca las horas inicial: " ;
    cin >> horasI;
    cout << "Introduzca los minutos inicial ";
    cin >> minutosI;
    cout << "Introduzca los segundos inicial: ";
    cin >> segundosI;
    cout << "Introduzca las horas final: " ;
    cin >> horasF;
    cout << "Introduzca los minutos final ";
    cin >> minutosF;
    cout << "Introduzca los segundos final: ";
    cin >> segundosF;

    diferencia=(horasF-horasI)*3600+(minutosF-minutosI)*60+(segundosF-segundosI);
    cout << "La diferencia entre segundos entre principio y finn es: " << diferencia;
    return (0);
}
