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
    int minutos;            
    int segundos;
    int dias = 0;
    // Entrada de datos
    cout << "Introduzca las horas: " ;
    cin >> horas;
    cout << "Introduzca los minutos: ";
    cin >> minutos;
    cout << "Introduzca los segundos: ";
    cin >> segundos;

    //Ver la cantidad de sobra que hay en cada 
    minutos += (segundos-segundos%60)/60;
    horas += (minutos-minutos%60)/60;
    dias += (horas-horas%24)/24;
    //Ver la cantidad de cada que hay
    segundos = segundos%60;
    minutos = minutos%60;
    horas = horas%24;
    //Mostrar los datos
    cout << "Son " << dias << " dias, " << horas << " horas, " << minutos << " minutos, " << segundos << " segundos ";

    return (0);
}
