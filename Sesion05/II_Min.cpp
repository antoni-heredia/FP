/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
    El programa devolvera el menor numero de unos introducidos.
    El programa pedira numeros hasta que introduzcamos un 0
    Usaremos una varibale "bandera" para guardar hay el valor
    mas pequeño introducido y poder ir comprobando cual va siendo menor.
*/
/***************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
using namespace std;

int main()
{
    //Declararemos las variables que vamos a usar
    double dato,bandera;

    //Usamos con do while para que al menos pida un dato hasta que sea 0
    do{

        cout << "Por favor introduzca un numero real: ";
        cin  >> dato;
        /*
          Comparamos que el valor de la variable dato sea o mas
          pequeña que la variable bandera o en que la variable bandera
          sea nulo, en ese caso el balor de la variable bandera sera dato
        */
        if( dato < bandera || bandera == NULL){
            bandera=dato;
        }
    }while(dato != 0);
    //Mostramos el valor de la variable bandera ya que es el menor introducido
    cout << "El numero mas bajo introducido es de: " << bandera;
    return(0);
}
