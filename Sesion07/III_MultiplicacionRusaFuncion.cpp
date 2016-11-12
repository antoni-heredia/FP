/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
    El programa realizara la multiplicacion rusa de dos numeros
    Para ello tenemos dos funciones, una que pide enteros positivos y otra 
    que realiza la multiplicación rusa. Esta se realiza mientras que m sea distinto
    de 1. m se divide por dos y n se multiplica por 2. Se van sumando los n de las
    iteraciones en las que m es impar

    Entradas: n y m
    Salidas:  resultado de la multiplicacion
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
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

//Con esta funcion se realiza la multiplicacion rusa
int MultiplicacionRusa(int m, int n)
{
    int multiplicacion = 0;
    //Mientras que sea distinto de 0 (ya que el 1 tambien cuenta)
    while(m != 0){
        //Si es impar se suma para el resultado final        
        if( m%2 == 1)
            multiplicacion += n;
        //m se divide entre 2 y n se multiplica por dos
        m /= 2;
        n *= 2;
    }
    return multiplicacion;
}
int main() // Programa Principal
{
    //Declaramos las variables
    int m,n;

    //Pedimos los datos
    string mensaje = "Por favor introduzca un m: ";
    m = LeerEnteroPositivo(mensaje);

    mensaje = "Por favor introduzca un n: ";
    n = LeerEnteroPositivo(mensaje);

    //Mostramos el resultado
    cout << "El resultado es: " << MultiplicacionRusa(m, n) << endl;
    return (0);
}
