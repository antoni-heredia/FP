/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
    El programa calculara el resultado de la suma de los k terminios de
    una progresion geometrica. El elemento i de la progresion es a*r^î
	El resultado sera la sumatoria de a*r^î desde i=0 hasta i=k

	Para ello usaremos dos funciones una que pida un entero y otra 
	que realice el sumatorio. 
	El ejercicio incluye dos funciones SumarHasta, una para el apartado a y
	otra para el b
    Entradas: k ( final de la progresion), r (razon) y ai ( elemento inicial)
    Salidas:  restulado
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
#include <string>
using namespace std;

int LeerEnteroPositivo(string mensaje)
{
    int numero;
    do{
        cout << mensaje;
        cin >> numero;
    }while(numero<1);
    return numero;
}
int SumaHastaApartadoA(int r, int k, int ai)
{
	//Realizamos la suma usando un for para calcular todos los ai y sumarlos
	int suma = 0;
	for(int x=1; x <= k; x++){
		suma += ai;
		ai *= r;
	}
	return suma;
}



int SumaHastaApartadoB(int r, int k, int ai)
{
	//Realizamos la suma con la funcion dada en el enunciado
	return ai*((pow(r*1.0,k)-1)/(r-1));
}
int main() // Programa Principal
{
	//Leemos los datos de entrada
	string mensaje = "Por favor introduzca un ai entero positivo: ";
    int ai = LeerEnteroPositivo(mensaje);
    
	mensaje = "Por favor introduzca un k entero positivo: ";
    int k = LeerEnteroPositivo(mensaje);
    
    mensaje = "Por favor introduzca un r entero positivo: ";
    int r = LeerEnteroPositivo(mensaje);
    
    //Calculamos el resultado y lo mostramos
    int resultado=SumaHastaApartadoB(r, k , ai);
    
    cout << "El resultado de la suma es: " << resultado << endl;
	

    return (0);
}
