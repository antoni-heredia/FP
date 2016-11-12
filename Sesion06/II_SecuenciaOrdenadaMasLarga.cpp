/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   El programa leera una serie de numero hasta que el usuario introduzca -1
   El programa devolera la cantidad de temperaturas ascendentes consecutivas

   Entradas: numero
   Salidas:  cantidad
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S

using namespace std;


int main() // Programa Principal
{
    //Iniciamos todas las variables
    double numero;
    int cantidad = 1;
    int contador = 1;
    int posicion = 1;

    //El comparador lo iniciamos a -1 para poder comparar la primera vez
    double comparador = -1;
    do{
        //Pedimos al usuario que introduzca los datos
        cout << "Intoduzca una temperatura: " ;
        cin >> numero;
        //Comprobamos si es la primera vez y si es asi el comparador
        //seria igual al numero introducido
        if( comparador == -1 )
            comparador = numero;
        //En caso de que el numero introducido sea mayor que el
        //comparador la cantidad  de consecutivos sera mas uno
        if( numero > comparador )
            cantidad++;
        else if (numero != -1){
            //Si el numero es menor que el comparador y ademas distinto
            // de -1 se reinicializa la cantidad de consecutivos
            //y la posicion sera el contador
            cantidad = 1;
            posicion = contador;
        }

        //En la siguiente pasa del do-while el comparador es el numero
        comparador = numero;
        //Sumamos uno al contador del do-while
        contador++;
    }while(numero != -1);

    //Mostramos los resultados
    cout << "La subsecuencia empieza en la posición: "
            << posicion << endl;
    cout << "Tiene una longitud de: " << cantidad << endl;


    return (0);
}
