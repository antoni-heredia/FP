/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
//
//
/* Programa para ajustar el tiempo

   Entradas: km recorridos, gasolina consumida, gasolina restante
   Salidas:  media de consumo, litros/100km y autonomia

   KmLitro = KmRecorridos/GasolinaConsumida
   LitrosALosCien = (GasolinaConsumida/KmRecorridos)x100
   Autonomia=KmLitros*GasolinaRestante

*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std;


int main() // Programa Principal
{
    double KmRecorridos;               // Declara variables para guardar
    double GasolinaConsumida;               // los dos capital, interes, total
    double GasolinaRestante;
    double KmLitro;
    double LitrosALosCien;
    double Autonomia;
    // Entrada de datos
    cout << "Introduzca los kilometros recorridos: " ;
    cin >> KmRecorridos;
    cout << "Introduzca los litros de gasolina consumida: ";
    cin >> GasolinaConsumida;
    cout << "Introduzca los litros de gasolina restantes: ";
    cin >> GasolinaRestante;

    KmLitro = KmRecorridos/GasolinaConsumida;
    LitrosALosCien = (GasolinaConsumida/KmRecorridos)*100;
    Autonomia=KmLitro*GasolinaRestante;

    cout << "El consumo en kilometros por litro es: " << KmLitro << " Km/Litros" << endl;
    cout << "El consumo en litros por cada 100 km es: " << KmLitro << " Litros/100" << endl;
    cout << "La autonomia en kilometros que queda es de: : " << Autonomia << " Km/Litros" << endl;

    return (0);
}
