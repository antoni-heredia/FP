/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
    El programa mostrara un menu y el usuario eligira si calcular el factorial
    de un numero o si desea calcular la potencia de algun numero.
    Para ello tenemos 4 funciones, una que pide enteros positivos, otra que
    culcula el factorial, otra que calcula potencias y otra que muestra un menu
    
    Entradas: opcion, numero, potencia
    Salidas:  resultado
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
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
//Funcion para calcular una exponente
int exponente(int numero, int exponente)
{
    int resultado = 1;
    for(int x = 0; x < exponente; x++){
        resultado *= numero;
    }
    return resultado;
}
//Funcion para calcular un factorial
long long Factorial(int final)
{
    long long numero=1;
    for(int x = 1; x <= final; x++){
        numero *= x;
    }
    return numero;
}
//Funcion que muestra el menu y nos pide que eleijamos
//Lo he hecho para que se quedara el codigo mas limpio
int PedirOpcines(){
    int opcion=-1;
    cout << "----------------------Menu----------------------" << endl;
    cout << "1-Calcular la potencia de un numero" << endl;
    cout << "2-Calcular el factorial de un numero" << endl;
    cout << "Elija una opcion: ";
    cin >> opcion;
    return opcion;
}
int main() // Programa Principal
{
    /*
        Variable salir ->El programa se ejecuta hasta que el usuario diga de 
                         salir
        Variable numero-> Guardar el numero para el factorial o la base para 
                          el exponente
        Variable exponente -> Para guardar el exponente
        Variable mensaje -> El mensaje que se muestra cada vez que se pide
                            un entero positivo
    */
    bool salir = false;
    int numero,exponente, opcion;
    string mensaje;
    //Se ejecuta mientras que el usuario quiera
    while(!salir){
        //Mostramos el menu
        opcion = PedirOpcines();
        //Segun lo elejido hacemos una cosa u otra
        switch(opcion){
            case 1:
                mensaje="Introduzca un numero: ";
                numero = LeerEnteroPositivo(mensaje);
                mensaje = "Introduzca el exponente: ";
                exponente = LeerEnteroPositivo(mensaje);
                cout << "El resultado es: " << exponente(numero,exponente) << endl;
            break;

            case 2:
                mensaje="Introduzca un numero para el factorial: ";
                numero = LeerEnteroPositivo(mensaje);
                cout << "El resultado es: " << Factorial(numero) << endl;
            break;
            default:
                cout << "Opcion incorrecta!" << endl;
            break;
        }
        //Preguntamos si desea continuar
        cout << "Desea continuar (1 no, 0 si): ";
        cin >> salir; 
    }
    
    return (0);
}