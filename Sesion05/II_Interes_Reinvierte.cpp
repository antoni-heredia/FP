/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
    El programa calculara la inversion dado un capital inicial
    y un interes, durante los años que especifica el usuario
    Entrada:capital,interes,años
    Salida:capital cada año
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S

using namespace std;


int main() // Programa Principal
{
    double capital,interes;
    int anios;
    
    //Pedimos al usuario que introduzca los datos con los filtros
    do{
        cout << "Por favor introduzca el capital inicial: ";
        cin >> capital;
    }while(capital <= 0);

    do{
        cout << "Por favor introduzca el interes: ";
        cin >> interes;
    }while(interes <= 0 || interes >10);
    do{
        cout << "Por favor introduzca los años: ";
        cin >> anios;
    }while(anios <= 0 || anios > 20);

    int anios_pasados = 1;
    //Calcularemos el capital hasta que los años pasados sean iguales
    //que los años que nos dijo el usuario
    while ( anios_pasados <= anios){
        capital += capital*(interes/100);
        cout << "El capital al cabo de " << anios_pasados << " es de: "
             << capital<< endl;
        anios_pasados++;
    }

}
