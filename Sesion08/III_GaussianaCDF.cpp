/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
    El programa calculara el CDF. Que es el area de la que encierra la 
    gausiana desde el -infinito hasta una variable x.
    
    Para ello el programa utilizara dos funciones principales, una que calcula
    el valor de la gausiana y otra que calcula el CDF dependiendo del valor
    de la gausiana calculado anteriormente
	El programa pedira tres parametros con una funcion LeerPositivo.

    Entradas: esperanza, desviacion,  variable_x
    Salidas:  CDF
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
using namespace std;

int LeerPositivo(string mensaje)
{
    double numero;
    do{
        cout << mensaje;
        cin >> numero;
    }while(numero<1);
    return numero;
}
//Funcion que calcula el valor de la gausiana
double Gausiana(double esperanza, double desviacion, double variable_x)
{
	const double PI = 3.1415;
	return (1/(desviacion*sqrt(2*PI)))*
				exp((-1.0/2.0)*(pow((variable_x-esperanza)/desviacion,2)));
}
//Funcion que calcula el valor del CDF
double GausianaCDF(double esperanza, double desviacion, double variable_x)
{
	//Declaramos las constantes
	const double B0 = 0.2316419;
	const double B1 = 0.319381530;
	const double B2 = -0.356563782;
	const double B3 = 1.781477937;
	const double B4 = -1.821255978;
	const double B5 = 1.330274429;
	//Calculamos el valor de t
	double t=1/(1+(B0*variable_x));
	//Devolvemos el valor de del CDF
	return (1-(Gausiana(esperanza,desviacion ,variable_x)*((t*B1)+(pow(t,2)*B2)+
			(pow(t,3)*B3)+(pow(t,4)*B4)+(pow(t,5)*B5))));
}
int main() // Programa Principal
{
	double esperanza, desviacion, variable_x;
    
    // Entrada de datos
    string mensaje = "Intoduzca la esperanza: " ;
    esperanza = LeerPositivo(mensaje);
    mensaje = "Intoduzca la desviacion: " ;
    desviacion = LeerPositivo(mensaje);
    mensaje = "Intoduzca la variable x: " ;
    variable_x = LeerPositivo(mensaje);
    
    //Calculamos el resultado y lo mostramos
    double resultado=GausianaCDF(desviacion, esperanza, variable_x);
    cout << "El resultado de la CDF es: " << resultado << endl;
	

    return (0);
}
