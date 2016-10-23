/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   El programa dado un numero entero nos calculara todos sus divisores
   El programa usara un bucle para recorrer todos sus posibles divisores.
   Ira calculando el modulo  y si es igual a 0 es que es divisor ya que
   la division es entera.
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S

using namespace std;


int main() // Programa Principal
{
    //Declaramos las variables de entrada
    int numero_introducido;
    cout << "Introduzca un numero entero por favor: ";
    cin >> numero_introducido;

    //Empezamos a contar desde el uno, ya que el 0 no puede dividir a nadie
    int contador = 1;

    //Se hara el while hasta que el contador sea como maximo la mitad
    // para ahorrar calculos inecesarios
    while(contador <= numero_introducido/2 ){
        int modulo = numero_introducido%contador;

        //Comprobamos que el resto sea 0 y si lo es imprimimos que lo es
        if(  modulo == 0 ){
            cout << "El numero " << contador << " es un divisor." << endl;
        }
        //Sumamos uno al contador
        contador++;
    }

    //El propio numero tambien es divisor
    cout << "El numero " << numero_introducido << " es un divisor." << endl;

    return(0);

}
