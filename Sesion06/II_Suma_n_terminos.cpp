/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   
   Entradas: final_sucesion
   Salidas:  resultado
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S

using namespace std;


int main() // Programa Principal
{
    //Declaramos las variables
    int final;
    double resultado=1;
    
    //Pedimos al usuario que introduzca el final de la serie
    //Que debe ser mayor que 0
    do{
        cout << "Por favor introduzca un numero mayor que 0: ";
        cin >> final;
    }while(final <= 0 );
    
    //Realizamos la succesion hasta que se llege al numero indicado
    //por el usuario
    for(int x = 1; x <= final; x++){
        //Comparamos si el ciclo es par o impar para sumar o restar
        if(x%2 == 0)
            resultado=resultado+(1.0/(2*x));
        else
            resultado=resultado-(1.0/(2*x));
    }
    
    //Mostramos los resultados
    cout << "El resultado de la succesion es: " << resultado << endl;

    
    return (0);
}
