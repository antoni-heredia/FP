/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
	Para este programa usare basicamente la distancia entre puntos y con ello
	saber si un punto esta en una circunferencia.
	
	Pediremos los puntos del centro y el radio.
	Cada elemento de la matriz actuara como si fuera un punto, y comprobaremos
	si dicho punto esta dentro del circulo, si esta dentro del circulo se
	pinta, si no no se pinta
	Entrada:  centro y radio de la circunferencia
	
	Salida: dibujo de un circulo con centro y radio el introducido
	
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <string>
#include <cmath>
using namespace std;



//Nos devuelve la distancia entre dos puntos
double DistanciaPuntos(int x_centro, int y_centro, int x_punto, int y_punto){
	return sqrt(((x_centro-x_punto)*(x_centro-x_punto))+((y_centro-y_punto)*(y_centro-y_punto)));
}

//Nos devuelve si el punto esta en la circunferencia o no
bool PuntoEnCircunferencia(int x_centro, int y_centro,int radio, int x_punto, int y_punto){
	double distancia = DistanciaPuntos(x_centro, y_centro, x_punto, y_punto);
	return !(distancia > radio);
}

//Lee solamente enteros positivos
int LeerEnteroPositivo(string mensaje0){
	int numero;
	do {
		cout << mensaje0;
		cin >> numero;
	}while(numero < 0);
	return numero;
}
int main() // Programa Principal
{
	//Varialbes de entrada
	int x_centro, y_centro,  radio;
	string mensaje;
	
	//Tama�o de la matriz
	const int NUM_FILAS = 51;
	const int NUM_COLUMNAS = 51;
	
	//Donde se pinta el circulo
	char lienzo[NUM_FILAS][NUM_COLUMNAS];
	
	//Pedimos al usuario que introduzca los datos del circulo
	cout << "Centro de la circunferencia: " << endl;
	mensaje = "\tx = ";
	x_centro = LeerEnteroPositivo(mensaje);
	
	mensaje = "\ty = ";
	y_centro = LeerEnteroPositivo(mensaje);;
	
	mensaje = "Introduzca el radio: ";
	radio = LeerEnteroPositivo(mensaje);;
    
    
    //Recorremos todos los puntos de la matriz mirando si estan dentro del 
	//circulo
	for(int y = 0; y<NUM_FILAS; y++){
		for(int x = 0; x<NUM_COLUMNAS; x++){
			/*
				Como el [0,0] en realidad es el [50][0], a la hora de ver si 
				el punto esta en la circunferencia tenemos qe poner el numero 
				de filas totales, menos la que estamos comprobando ahora mismo
			*/
			if(PuntoEnCircunferencia(x_centro,y_centro,radio,x,NUM_FILAS-y))
				lienzo[y][x] = '*';
			else
				lienzo[y][x] = ' ';
		}	
	}
	
	//Recorremos todos los elementos de la matriz imprimiendo su contenido
	for(int y = 0; y<NUM_FILAS; y++){
		for(int x = 0; x<NUM_COLUMNAS; x++){
			cout <<	lienzo[y][x] << " ";		
		}
		cout << endl;	
	}

	//Salimos del programa
    return (0);
}
