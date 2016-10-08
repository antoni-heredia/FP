/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   El programa realiza la media aritmetica y la desviacion tipica de la altura de 3 presonas

   Entradas: altura1,altura2, altura3
   Salidas:  media y desviacionTipica

   La media se calcula como: La suma de todos los datos entre el numero de datos introducidos.
   La desviacion tipica se calcula como : La raiz cuadrada de la suma de todos los datos restandoles la media aritmetica
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std;


int main() // Programa Principal
{
    double altura1, altura2, altura3;
    double media,desviacion;
    // Entrada de datos
    cout << "Intoduzca la altura numero 1 (cm): " ;
    cin >> altura1;
    cout << "Intoduzca la altura numero 2 (cm): " ;
    cin >> altura2;
    cout << "Intoduzca la altura numero 2 (cm): " ;
    cin >> altura3;

    //Calculamos la media
    media = (altura1+altura2+altura3)/3.0;

    //Calculamos la desviacion
    desviacion = sqrt((pow(altura1-media,2)+pow(altura2-media,2)+pow(altura3-media,2))/3.0);

    //Mostrar los datos
    cout << "La media de las alturas es: " << media << endl;
    cout << "La desviacion tipica es: " << desviacion << endl;

    return (0);
}
