/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
    El programa calculara una inversion mostrando por pantalla
    los años que necesarios para doblar la inversion inicial dado un interes
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S

using namespace std;


int main() // Programa Principal
{
    double capital,interes;
    
    //Pedimos al usuario que introduzca el capital inicial
    do{
        cout << "Por favor introduzca el capital inicial: ";
        cin >> capital;
    }while(capital <= 0);
    //Calculamos cuando se dobla el capital inicial
    double capital_final = capital*2;
    //Pedimos al usuario que introduzca el interes que debe ser
    // entre 0 y 10
    do{
        cout << "Por favor introduzca el interes: ";
        cin >> interes;
    }while(interes <= 0 || interes >10);

    //Iniciamos la variable años pasados para saber cuantos años son
    //necesarios para doblar el capital
    int anios_pasados = 1;
    while ( capital <= capital_final){
        //Calculamos el capital para dicho año
        capital += capital*(interes/100);
        cout << "El capital al cabo de " << anios_pasados << " es de: "
             << capital<< endl;
        anios_pasados++;
    }

}
