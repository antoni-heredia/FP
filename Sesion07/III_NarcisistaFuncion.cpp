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
#include <string>
using namespace std;

//Funcion para leer un entero positivo
int LeerEnteroPositivo(string mensaje)
{
    int numero;
    do{
        cout << mensaje;
        cin >> numero;
    }while(numero<1);
    return numero;
}
bool EsNarcisita(int numero)
{
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
            digito_menos_significativo = numero_copia%divisor;
            numero_copia /= divisor;
            numero_narcisista += pow(digito_menos_significativo, contador);
        }
        //Sumamos uno al contador para que la potencia por la que probamos
        //sea cada vez mayor
        contador++;
    }
    bool es_narcisita = false;
    if(numero_narcisista == numero)
        es_narcisita = true;
    
    return es_narcisita;
}

int main() // Programa Principal
{
    //Declaramos las variablesde entrada
    int numero;
    string mensaje = "Por favor introduzca un numero mayor que 0: ";;
    //Pedimos al usuario que el numero que quiera saber si es narcista
    numero = LeerEnteroPositivo(mensaje);

    if(EsNarcisita(numero))
        cout << "Es narcisista el numero" << endl;
    else
        cout << "No es narcisista" << endl;
        
    return (0);
}