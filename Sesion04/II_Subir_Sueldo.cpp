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
    //Declaramos las variables de entrada
    int edad;
    double salario;

    //Declaramos las constantes
    const double PORCENTAJE_SUBIDA = 0.05;
    const string MENSAJE_SALARIO = "El salario actual es de: ";
    //Pedimos al usuario que introduzca los datos
    cout << "Por favor introduzca la edad: ";
    cin >> edad;

    cout << "Por favor introduzca el salario: ";
    cin >> salario;

    if( edad > 55 && salario < 750 ){
        salario = salario + salario*0.05;
    } else{
        cout << "No es aplicable la subida." << endl;
    }

    cout << MENSAJE_SALARIO << salario;


    /*
        Desde mi punto de vista es mejor usar la misma variable salario.
        Por dos motivos. Uno es para mostrar el mismo mensaje para mostrar
        el salari y otra razon es por si quisieramos posteriormente
        subir el sueldo otra vez en un bucle por ejemplo.
    */
    return(0);
}
