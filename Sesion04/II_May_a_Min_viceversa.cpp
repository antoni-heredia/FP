/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
    El programa dada una letra introducida realizara lo siguiente;

    • Si es una letra mayúscula, almacenaremos en la variable letra_convertida
        la correspondiente letra minúscula.
    • Si es una letra minúscula, almacenaremos en la variable letra_convertida
        la correspondiente letra mayúscula.
    • Si es un carácter no alfabético, almacenaremos el mismo carácter en la variable
        letra_convertid
*/
/***************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std;

int main() // Programa Principal
{
    //Declaramos las variables de entrada
    char letra_introducida;

    //Declaramos las variables de salida
    char letra_convertida;

    string MENSAJE_SALIDA;
    //Pedimos al usuario que introduzca los datos

    cout << "Por favor introduzca una letra: ";
    cin >> letra_introducida;

    //Vemos en cual de las condiciones encaja la letra introducida y realizamos
    //la conversion
    if( letra_introducida  >= 'A' && letra_introducida <= 'Z')
    {
        letra_convertida = letra_introducida - ('A'-'a');
        MENSAJE_SALIDA = "La letra era una mayúscula. Una vez convertida es ";
    }
    else if( letra_introducida  >= 'a' && letra_introducida <= 'z')
    {
        letra_convertida = letra_introducida + ('A'-'a');
        MENSAJE_SALIDA = "La letra era una minúscula. Una vez convertida es ";
    }
    else
    {
        letra_convertida = letra_introducida;
        MENSAJE_SALIDA = "El carácter no era una letra. Era: ";
    }
    //Mostramos el respectivo mensaje y la letra convertida
    cout << MENSAJE_SALIDA << letra_convertida;

    return(0);
}
