/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*

	
	Entrada:  centro y radio de la circunferencia, diferentes puntos
	
	Salida: area, longitud y si las cordenadas estan dentro de la circunferencia
	
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
	
	int x_centro, y_centro,  radio;
	string mensaje;
	
	const int FILAS = 51;
	const int COLUMNAS = 51;
	
	char lienzo[FILAS][COLUMNAS];
	
	//Pedimos al usuario que introduzca los datos del circulo
	cout << "Centro de la circunferencia: " << endl;
	mensaje = "\tx = ";
	x_centro = LeerEnteroPositivo(mensaje);
	
	mensaje = "\ty = ";
	y_centro = LeerEnteroPositivo(mensaje);;
	
	mensaje = "Introduzca el radio: ";
	radio = LeerEnteroPositivo(mensaje);;
    
	for(int y = 0; y<FILAS; y++){
		for(int x = 0; x<COLUMNAS; x++){
			if(PuntoEnCircunferencia(x_centro,y_centro,radio,x,50-y))
				lienzo[y][x] = '*';
			else
				lienzo[y][x] = ' ';
		}	
	}
	
	for(int y = 0; y<FILAS; y++){
		for(int x = 0; x<COLUMNAS; x++){
			cout <<	lienzo[y][x];		
		}
		cout << endl;	
	}

	//Salimos del programa
    return (0);
}
