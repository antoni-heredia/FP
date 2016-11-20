/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
	El programa nos pide que introduzcamos las cordenadas del centro de una
	circunferencia y el radio de la misma.
	
	Nos mostrara el area y la longitud de la circunferencia
	
	Despues nos dira que introduzcamos cordenadas de puntos para decirnos
	si estan dentro de la circunferencia o no hasta que le introduzcamos FIN
	
	Entrada:  centro y radio de la circunferencia, diferentes puntos
	
	Salida: area, longitud y si las cordenadas estan dentro de la circunferencia
	
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <string>
#include <cmath>
using namespace std;

//Registro de punto
struct Punto2D{
	double x,y;
};

//Registro de circunferencia
struct Circunferencia{
	Punto2D centro;
	double radio;
};

//Nos devuelve un punto en forma de string
string PuntoToString(Punto2D punto){
	return "["+to_string(punto.x)+","+to_string(punto.y)+"]";
}

//Nos calcula el area del circulo
double Area(Circunferencia circunferencia){
	const double PI = 3.14159265359;
	
	return PI*circunferencia.radio*circunferencia.radio;
}

//Nos calcula la longitud de la circunferencia
double Longitud(Circunferencia circunferencia){
	const double PI = 3.14159265359;
	return 2*PI*circunferencia.radio;
}

//Nos devuelve la distancia entre dos puntos
double DistanciaPuntos(Punto2D punto1, Punto2D punto2){
	return sqrt(((punto1.x-punto2.x)*(punto1.x-punto2.x))+((punto1.y-punto2.y)*(punto1.y-punto2.y)));
}

//Nos devuelve si el punto esta en la circunferencia o no
bool PuntoEnCircunferencia(Circunferencia c, Punto2D p){
	double distancia = DistanciaPuntos(c.centro,p);
	if(distancia > c.radio)
		return false;
	else
		return true;
}


int main() // Programa Principal
{
	//Declaro las variables de entrada de datos
	const int TAM_CAD = 100;
	Circunferencia circunferencia;
	Punto2D centro;
	
	
	//Pedimos al usuario que introduzca los datos del circulo
	cout << "Centro de la circunferencia: " << endl;
	cout << "\tx = ";
	cin >> centro.x;
	
	cout << "\ty = ";
	cin >> centro.y;
	
	circunferencia.centro = centro;
	
	cout << "Introduzca el radio: ";
	cin >> circunferencia.radio;

	//Calculo los datos del area y longitud
	double area, longitud;

	area = Area(circunferencia);
	
	longitud = Longitud(circunferencia);
	
	//Muestro los datos
	cout << "El area del ciruclo es: " << area << "cm²" <<endl;
	cout << "La longitud de la circunferencia es: " << longitud << "cm" << endl;
    

	
	
	string cadena; // Para leer coordenada (usando un string)   

	// Extraer del buffer de entrada el salto 	de línea, si lo hubiera    
	cin.ignore (TAM_CAD,'\n');   

	// Lectura adelantada             
	cout << endl;   
	cout << "Introdzca coordenada x: ";   
	getline (cin, cadena);       

	Punto2D p;
	while (cadena != "FIN") {               

		//Pido las diferentes cordenadas 
		p.x = stof(cadena); // string --> double               
		cout << "Introdzca coordenada y: ";       
		getline (cin, cadena);               
		p.y = stof (cadena);  // string --> double               

		//Muestro si el punto esta en la circunferencia o no
		if(PuntoEnCircunferencia(circunferencia, p))
			cout << "El punto " << PuntoToString(p) 
			     << " esta en la circunferencia." << endl;
		else
			cout << "El punto " << PuntoToString(p) 
			     << " no esta en la circunferencia." << endl;                        
		 
		 // Nueva lectura                
		 cout << endl;
		 cout << "Introdzca coordenada x: ";
		 getline (cin, cadena);     
		 
	} // while (cadena != "FIN"
	
	//Salimos del programa
    return (0);
}

