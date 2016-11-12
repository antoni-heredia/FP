/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
    El programa pedira un delta, que sera el valor para la diferencia entre
    el numero aureo y la aproximacion
    
    El algoritmo realizara una aproximacion del numero aureo cada vez con un
    n de la succesion de fibonnaci, y lo repetira hasta que que el valor 
    absoluto de la diferencia sea igual o menor al dado por el usuario

    Entradas: delta
    Salidas:  elemento n de la succesion
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

double fibonacci(int final)
{
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
    return suma;
}
int main() // Programa Principal
{
    //Declaramos la constante del numero aureo
    const double AUREO=(1 + sqrt(5)) / 2; 
    double delta;

    //Pedimos el final de la succesion
    do{
        cout << "Por favor introduzca el valor DELTA para la aproximacion: ";
        cin >> delta;
    }while(delta < 0 && delta >= 1);
    //Iniciamos las variables auxiliares
    
    double aproximacion;
    int contador = 0;
    double diferencia;
    do{
        contador++;
        //Calcularemos la proximacion para un n determinado
        aproximacion = (fibonacci(contador+1))/(fibonacci(contador));
        //Calculamos el valor absoluto de la diferencia ya que una veces es positivo
        //y otras negativo
        diferencia = abs(AUREO - aproximacion);
        //Realizamos esto mientras que la diferencia sea mayor que la delta introducida
        // por el usuario
    }while( diferencia > delta);

    //Mostramos los datos
    cout << "El n mas bajo para delta="<<delta<<" es : "<<contador << endl;
    
    return (0);
}
