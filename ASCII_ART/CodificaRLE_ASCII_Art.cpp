/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*

    Entradas: varias cadenas
    Salidas:  matriz, matriz codificada, matriz recodificada
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <string>
using namespace std;
struct Pareja{
	char valor;
	int frecuencia;
};
int main() // Programa Principal
{

	const int MAX_SECUENCIAS = 200;
	const int MAX_DATOS = 120;
	// Matriz para guardar la copia de la cadena
	char m[MAX_SECUENCIAS][MAX_DATOS];
	int elemento_m[MAX_SECUENCIAS] = {0};
	// Para leer los datos
	int cant_lecturas = 0;
	string cadena;
	while (getline (cin, cadena)) {
		for(int i = 0; i < cadena.length(); i++){
			if(i < MAX_DATOS-1){
				m[cant_lecturas][i] = cadena[i];
				elemento_m[cant_lecturas]++;
			}
		}
		cant_lecturas++;
	}
	
	
	
	cerr << "La imagen real leida ha sido: " << endl  << endl;
	for(int i = 0; i < cant_lecturas; i++){
		for(int x = 0; x < elemento_m[i]; x++)
			cerr << m[i][x];
		cerr << endl;
	}
	
	
	// Matriz de secuencias codificadas
	Pareja m_codificada [MAX_SECUENCIAS][MAX_DATOS];
	int elementos_m_codificada[MAX_SECUENCIAS] = {0};
	// N�mero de parejas de cada secuencia
	int filas_m_codificada = 0; // Num. secuencias codificadas
	
	char c_anterior;
	int num_repeticiones;
	
	//Recorremos todas las lecturas que se hicieron correctamente
	for(int i = 0; i < cant_lecturas; i++){
		Pareja p;
		c_anterior = m[i][0];
		num_repeticiones = 0;
		for(int x = 1; x < elemento_m[i]; x++){
			if(c_anterior == m[i][x])	
				num_repeticiones++;
			else{
				p.frecuencia = num_repeticiones;		
				p.valor = c_anterior;
				m_codificada[filas_m_codificada][elementos_m_codificada[i]] = p;
				c_anterior = m[i][x];
				num_repeticiones = 0;
				elementos_m_codificada[i]++;
			}
				
		}
		p.frecuencia = num_repeticiones;		
		p.valor = c_anterior;
		m_codificada[filas_m_codificada][elementos_m_codificada[i]] = p;
		elementos_m_codificada[i]++;

		filas_m_codificada++;	
	}
	
	for(int i = 0; i < filas_m_codificada; i++){
		for(int x = 0; x < elementos_m_codificada[i]; x++){
			Pareja p = m_codificada[i][x];
			cout << p.valor <<  p.frecuencia <<	' ';
		}
		cout << endl;
	}
	
    return (0);
}
