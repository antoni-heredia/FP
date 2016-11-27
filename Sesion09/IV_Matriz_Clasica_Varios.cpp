/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
	El programa calcula la matriz transpuesta a partir de una matriz data 
	y tambien multiplica dos matrices siempre que se pueda
	
	Pedira las filas las columnas y cada uno de los elementos de una matriz y 
	mostrara su traspuesta.
	
	Luego pedira las filas,columnas y elementos de otra matriz y si es posible
	multiplicara la primera matriz por esta.
	
	Entrada: filas, columnas, coeficientes
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S

using namespace std;

int LeerPositvo(string mensaje){
	int numero;
	do{
		cout << mensaje;
		cin >> numero;
	}while(numero < 1);
	return numero;
}
int main() // Programa Principal
{
	
	int columnas, filas;
	string mensaje;
	
	//Leemos los datos
	mensaje = "Introduzca el numero de columnas de su matriz: ";
	columnas = LeerPositvo(mensaje);
	
	mensaje = "Introduzca el numero de filas de su matriz: ";
	filas = LeerPositvo(mensaje);
	
	//creamos la matriz con los datos dados
	int matriz[filas][columnas];
	
	//Rellenamos la matriz
	for(int i = 0; i < filas; i++){
		for(int x = 0; x < columnas; x++){
			cout << "Por favor introduzca el coeficiente (" << i+1 << "," << x+1 << "): ";
			cin >> matriz[i][x];
		}
	}
	
	//mostramos la matriz traspuesta
	int matriz_traspuesta[columnas][filas];
	for(int i = 0; i < filas; i++){
      for(int x = 0; x < columnas; x++){
      		//Guardamos los datos de la matriz traspuesta
      		matriz_traspuesta[x][i] = matriz[i][x];
        	cout << "El coeficiente de (" << i+1 << "," << x+1 << ") es: " 
			     << matriz[x][i] << endl;
        }
	}
	
	//El codigo para multiplicar matrices no he sido capaz de hacerlo
	int columnas_multi, filas_multi;
	mensaje = "Introduzca el numero de columnas de su matriz: ";
	columnas_multi = LeerPositvo(mensaje);
	
	mensaje = "Introduzca el numero de filas de su matriz: ";
	filas_multi = LeerPositvo(mensaje);
	int matriz_multiplicacion[columnas_multi][filas_multi];
	
	for(int i = 0; i < filas_multi; i++){
		for(int x = 0; x < columnas_multi; x++){
			cout << "Por favor introduzca el coeficiente (" << i+1 << "," << x+1 << "): ";
			cin >> matriz_multiplicacion[i][x];
		}
	}
	if(columnas == filas_multi){
		int matriz_resultado[columnas][filas_multi];
		
		for(int i = 0; i < filas; i++){
			for(int x = 0; x < columnas_multi; x++){
				
				double suma = 0;
	      		for(int i = 0; i < columnas; i++){
	      			suma += matriz_multiplicacion[columnas_multi][filas]*matriz[columnas][filas];
				}
				matriz_resultado[filas][columnas_multi]=suma;
				cout << "El coeficiente de (" << filas+1 << "," << columnas_multi+1 << ") es: " 
			     << suma << endl;
	        }
		}
	}else
		cout << endl << "No se puden multiplicar" << endl;
	return(0);
}
