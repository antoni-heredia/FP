/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   El programa calculara si un numero es narcisista

   Para ello ira descomponiendo el numero por cada uno de sus digitos
   e ira probando a sumarlos cada vez con una potencia mayor

   La realizaremos con un bucle for y compararemos si el ciclo es
   par o impar para resultador o restar dado el caso.

   Entradas: numero
   Salidas:  si es narcisista o no y en caso de serlo mostrar la potencia
             con la que lo es
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matematicos
using namespace std;


int main() // Programa Principal
{
    //Declaramos las variablesde entrada
    int numero;

    //Pedimos al usuario que el numero que quiera saber si es narcista
    do{
        cout << "Por favor introduzca un numero mayor que 0: ";
        cin >> numero;
    }while(numero <= 0 );


    /*
     *La variable digito_menos_significativo es para descomponer
     * el numero introducido por el usuario
     *numero_copia es para no perder el numero introducido por el usuario
     *numero_narcisista donde iremos sumando las enesimas potencias de los
     * digitos del numero introducido
     */
    int digito_menos_significativo,numero_copia;
    int contador = 1;
    int numero_narcisista = 0;

    /*
     * El bucle se hara hasta que numero_narcisista sea distinto de numero
     * ya que el numero seria narcisita o hasta que la suma de su n-ésimas
     * potencias sea mayor que el numero introducido ya que nos habremos
     * pasado
     */
    while(numero_narcisista < numero && numero_narcisista != numero){

        int potencia=1;
        /*
         * Iremos descoponiendo el numero y sumando sus digitos cada vez
         * elevados a una potencia mayor.
         * Cada vez inicializamos numero_narcisista a 0 para que empieze a
         * calcular desde 0
         */
         numero_copia=numero;
        numero_narcisista = 0;
        while(numero_copia != 0){
            int divisor = pow(10,potencia);
            digito_menos_significativo=numero_copia%divisor;
            numero_copia /= divisor;
            numero_narcisista += pow(digito_menos_significativo, contador);
        }
        //Sumamos uno al contador para que la potencia por la que probamos
        //sea cada vez mayor
        contador++;
    }

    //Si numero_narcisista es igual a numero el numero es narcisista y ademas mostramos la potencia
    //Si no diremos que no lo es
    if(numero_narcisista == numero){
        cout << "El numero es narcisista." << endl;
        cout << "La potencia usada es: " << --contador << endl;;
    }else{
        cout << "El numero no es narcisista." << endl;
    }


    return (0);
}
