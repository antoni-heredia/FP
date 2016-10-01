/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
//
//
/* Programa para ajustar el tiempo

   Entradas: segundos, minutos, horas
   Salidas:  segundos, minutos, horas, dias
   
   Lo primero que realiza el programa es ver cuantos minutos/horas/dias hemos introducido en los segundos/minutos/horas
   Y luego viendo el modulo del numero sabemos cuantos segundos/minutos/horas nos quedan enteros
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std;


int main() // Programa Principal
{
    int horas;               // Declara variables para guardar
    int minutos;               // los dos capital, interes, total
    int segundos;
    int dias = 0;
    // Entrada de datos
    cout << "Introduzca las horas: " ;
    cin >> horas;
    cout << "Introduzca los minutos: ";
    cin >> minutos;
    cout << "Introduzca los segundos: ";
    cin >> segundos;

    minutos += (segundos-segundos%60)/60;
    horas += (minutos-minutos%60)/60;
    dias += (horas-horas%24)/24;

    segundos = segundos%60;
    minutos = minutos%60;
    horas = horas%24;
    cout << "Son " << dias << " dias, " << horas " horas," << minutos << " minutos, " << segundos << " segundos /n";

    return (0);
}
