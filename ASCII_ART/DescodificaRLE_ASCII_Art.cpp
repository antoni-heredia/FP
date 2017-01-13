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
	Pareja m_codificada[MAX_SECUENCIAS][MAX_DATOS];
	int elemento_m[MAX_SECUENCIAS] = {0};
	// Para leer los datos
	int cant_lecturas = 0;
	string cadena;
	
	bool es_caracter = true;
	while (getline (cin, cadena)) {
		m_codificada[cant_lecturas][0].valor = cadena[0];
		es_caracter = false;
		string numero;	
		for(int i = 1; i < cadena.length(); i++){
		
			if(!es_caracter && cadena[i] != ' ')
			 	numero+= cadena[i];		 				
			else if ( !es_caracter && cadena[i] == ' ')
				es_caracter = true;
			else{
				m_codificada[cant_lecturas][elemento_m[cant_lecturas]].frecuencia = stoi(numero);
				numero = " ";
				elemento_m[cant_lecturas]++;
				m_codificada[cant_lecturas][elemento_m[cant_lecturas]].valor = cadena[i];
				es_caracter = false;
			}
		}
		m_codificada[cant_lecturas][elemento_m[cant_lecturas]].frecuencia = stoi(numero);
		elemento_m[cant_lecturas]++;
	
		cant_lecturas++;
	}
	
	cerr << "La imagen codificada es: " << endl  << endl;
	for(int i = 0; i < cant_lecturas; i++){
		for(int x = 0; x < elemento_m[i]; x++)
			cerr << m_codificada[i][x].valor << m_codificada[i][x].frecuencia << " ";
		cerr << endl;
	}
	
	
	for(int i = 0; i < cant_lecturas; i++){
		for(int x = 0; x < elemento_m[i]; x++){
			Pareja p = m_codificada[i][x];
			for(int j = 0; j<=p.frecuencia;j++)
				cout << p.valor;
		}
		cout << endl;
	}
    return (0);
}
