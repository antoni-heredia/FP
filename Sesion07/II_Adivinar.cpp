/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
    El programa generara un numero pseudo-aleatorio.
    El usuario ira introduciendo numeros e ira diciendo si el numero
    introducido es mayor o menor que el generado por la maquina
    El juego terminara cuando el usuario introduzca un -1.
    Una vez terminado el juego el programa pedira si quiere volvera jugar.

    El juego es una funcion que se ejecuta cada vez que el usuario quiera volver
    a jugar
    Entradas: numero
    Salidas:  si ha acertado o no
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include<ctime>
#include<cstdlib>

using namespace std;
bool juego(){
    // Queremos generar valores aleatorios entre MIN y MAX
    const int MIN = 1, MAX = 100;
    const int NUM_VALORES = MAX-MIN + 1; // Número de valores posibles
    // con el reloj del sistema (hora actual)
    int incognita; // número aleatoria a generar
    // Generación de incognita (MIN <= incognita <= MAX)
    incognita = (rand() % NUM_VALORES) + MIN;

    int numero;
    do{
        //Pedimos al usuario que introduzca los datos
        cout << "Por favor introduzca un numero: ";
        cin >> numero;

        //Comparamos si el numeor es mayor o menor que la incongnita
        //y damos un mensaje
        if(numero > incognita)
            cout << "El numero introducido es mayor que el buscado" << endl;
        if(numero < incognita)
            cout << "El numero introducido es menor que el buscado" << endl;
        //No terminamos mientras el numero sea distinto de -1 o a la incongnita
    }while(numero != -1 && numero != incognita);
    bool es_Correcto = false;
    //Si le juego termino porque el jugador acerto cambiamos la variable es correcto
    if( numero == incognita )
        es_correcto=true;
    //Retornamos el valor de es_correcto
    return es_correcto;
}

int main() // Programa Principal
{
    time_t t;
    srand(time(&t)); // Inicializa el generador de núms. aleatorios

    bool continuar = true;
    //El juego se hara mientra el jugador quiera.
    while(continuar){
        //Comprobamos si acerto el juego o si salio antes
        if(juego())
            cout << "Enhorabuena, ha acertado!!!"<< endl;
        else
            cout << "Ha salido sin terminar el juego,"<< endl;

        //Preguntamos si quiere volver a jugar
        cout << "¿Desea jugar de nuevo?(1 si, 0 no) ";
        cin >> continuar;

    }

    //Mensaje final
    cout << "Saliendo del programa."<< endl;

    return (0);
}
