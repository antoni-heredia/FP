/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
	El programa  calculara la suma de los terminos de una serie.
	
	El programa por un lado calculara cada elemento de la serie con una funcion
	y otra funcion se encarga de recorrer los elementos desde el 1 hasta el i
	y los va sumando.
    
    Entradas: i ( final de la serie)
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
double Termino(int i)
{
	//Retorna el i termino de la serie
	return ((pow(-1,i)*((i*i)-1))/(2.0*i));
}
double SumaTerminos(int i)
{
	//Recorremos los terminos desde el 1 hasta el i introducido por el usuario
	double suma = 0;
	for(int x = 1; x <= i; x++){
		//Sumamos cada termino
		suma += Termino(x);
		cout << Termino(x) << endl;
	}
	//Devolvemos la suma
	return suma;
}


int main() // Programa Principal
{
	//Leemos los datos de entrada
	string mensaje = "Por favor introduzca un i entero positivo: ";
    int i = LeerEnteroPositivo(mensaje);
    
	
    
    //Calculamos el resultado y lo mostramos
    double  resultado=SumaTerminos(i);
    cout << "El resultado de la suma es: " << resultado << endl;
	

    return (0);
}
