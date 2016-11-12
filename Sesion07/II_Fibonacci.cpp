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


int main() // Programa Principal
{

    int final;
    //Pedimos el final de la succesion
    do{
        cout << "Por favor introduzca el numero donde quiera acabar: ";
        cin >> final;
    }while(final < 0);
    //Iniciamos las variables auxiliares
    int suma = 1;
    int anterior = 1;
    int anterior_anterior = 1;
    //Recorremos a partir del elemento dos ya que n=1 y n=2 son los dos 1
    for(int x = 2; x<final; x++){
        //Sumamos n-1 + n-2
        suma = anterior + anterior_anterior;
        //n-2 es igual a n-1
        anterior_anterior = anterior;
        //n-1 es igual a n para el suguiente bucle
        anterior = suma;
    }
    //Mostramos los datos
    cout << "El termino " << final << " es: " << suma << endl;

    
    do{
        cout << "Por favor introduzca un k donde quiera acabar: ";
        cin >> final;
    }while(final < 0);
    //Iniciamos las variables auxiliares
    suma = 1;
    anterior = 1;
    anterior_anterior = 1;
    cout << "El k 1 es: 1" << endl;
    if(final != 1)
        cout << "El k 2 es: 1" << endl;
    //Recorremos a partir del elemento dos ya que n=1 y n=2 son los dos 1
    for(int x = 2; x<final; x++){
        //Sumamos n-1 + n-2
        suma = anterior + anterior_anterior;
        //n-2 es igual a n-1
        anterior_anterior = anterior;
        //n-1 es igual a n para el suguiente bucle
        anterior = suma;
        cout << "El k "<< x+1 <<" es: " << suma << endl;
    }

    return (0);
}
