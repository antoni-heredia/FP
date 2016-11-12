/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
    El programa pedira un numero el cual sera el elemento n de la 
    succesion de fibonacci.
    Para ello usar una funcion que lo calcular, con el siguiente algoritmo.
    El algoritmo necesitara tres variables, una sera suma que es donde se
    guarda el elemento n de la succesion, la variable anterior que es donde
    se guarda el elemento n-1 y la variable anterior_anterior que es donde se
    guarda el elemento n-2.
    Esas tres variables las iniciamos en 1.
    Entradas: elemento n que queremos que se devuelva
    Salidas:  elemento n
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
using namespace std;
//Funcion para calcular el n termino de fibonnaci
int CalcularFibonnaci(int numero)
{
    //Iniciamos las variables auxiliares
    int suma = 1;
    int anterior = 1;
    int anterior_anterior = 1;
    //Recorremos a partir del elemento dos ya que n=1 y n=2 son los dos 1
    for(int x = 2; x<numero; x++){
        //Sumamos n-1 + n-2
        suma = anterior + anterior_anterior;
        //n-2 es igual a n-1
        anterior_anterior = anterior;
        //n-1 es igual a n para el suguiente bucle
        anterior = suma;
    }
    return suma;
}

int main() // Programa Principal
{

    int final, fibonacci;
    //Pedimos el final de la succesion
    do{
        cout << "Por favor introduzca el numero donde quiera acabar: ";
        cin >> final;
    }while(final < 0);
    
    fibonacci = CalcularFibonnaci(final);

    //Mostramos los datos
    cout << "El termino " << final << " es: " << fibonacci << endl;

    //Pedimos el final de la succesion
    do{
        cout << "Por favor introduzca el numero donde quiera acabar: ";
        cin >> final;
    }while(final < 0);

    for(int x = 1; x <= final; x++){
        fibonacci = CalcularFibonnaci(x);
        cout << "Para k = " <<  x << " es: " << fibonacci;    
    }
    
    return (0);
}