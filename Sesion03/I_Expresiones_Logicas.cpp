/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   Programa para practicar distintas expresiones logicas
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S

using namespace std;


int main() // Programa Principal
{
    char letra;
    int edad, anio;
    bool primera_expresion,segunda_expresion,tercera_expresion;

    // Expresión lógica que sea verdadera si una variable de tipo carácter
    // llamada letra es una letra minúscula y falso en otro caso

    cout << "Introduzca un solo caracter: ";
    cin >> letra;
    primera_expresion = (letra > 97 && letra < 122);
    cout << endl << "El resultado es: " << primera_expresion;
    // Expresión lógica que sea verdadera si una variable de tipo entero
    // llamada edad es menor de 18 o mayor de 65
    cout << endl << "Introduzca una edad: ";
    cin >> edad;
    segunda_expresion = ( edad < 18 || edad > 65);
    cout << endl << "El resultado es: " << segunda_expresion;

    // Expresión lógica que nos informe cuando un año es bisiesto
    cout << endl << "Introduzca un año: ";
    cin >> anio;
    tercera_expresion = ( (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0);
    cout << endl << "El resultado es: " << tercera_expresion;

}
