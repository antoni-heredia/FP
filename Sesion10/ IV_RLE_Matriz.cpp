/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
	Leeremos varias cadenas seguidas, las cuales siempre que cumplan los 
	requisitos que nos dan el enunciado, se guardaran en una matriz. La matriz
	donde las guardamos tendra como dimension MAX_LECTURASxMAX_DATOS. La matriz
	estara inicializada a *
	
	Luego el programa ira fila por fila para codificar cada fila y guardarla en
	la misma fila pero en otra matriz, la cual tendra una dimension de
	MAX_LECTURASx(MAX_DATOSx2). Para codificar cada fila se usara el mismo
	metodo que para el RLE con vectores.
	
	El programa para recodificar cada cada fila usa el mismo metodo que para el
	RLE. El resultado se guarda en otra matriz.

    Entradas: varias cadenas
    Salidas:  matriz, matriz codificada, matriz recodificada
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <string>
using namespace std;

int main() // Programa Principal
{

	const int MAX_DATOS = 50;
	const int MAX_LECTURAS = 20;
	// Matriz para guardar la copia de la cadena
	char m[MAX_LECTURAS][MAX_DATOS];
	//Inicializamos la matriz a * para que luego no nos de error
	//al imprimirlo
	for(int i = 0; i < MAX_LECTURAS; i++){
		for(int x = 0; x<MAX_DATOS; x++){
			m[i][x]='*';
		}
	}

	string cadena;		// Para leer los datos
	int long_cadena;
	int cant_lecturas = 0;

	// Lectura: No se admite la cadena vacía, ni cadenas demasiado largas
	// (recuerde que su contenido se va a copiar a una fila de la matriz m)
	//Realiazmoa como maximo MAX_LECTURAS lecturas
	for(int i = 0; i < MAX_LECTURAS && cadena != "FIN"; i++){
		cadena = "";
		do {
			cout << "Introduzca una cadena: ";
			getline (cin, cadena);
			long_cadena = cadena.length(); // Longitud de la cadena
		} while ((long_cadena==0) || (long_cadena>MAX_DATOS));

		// Copiar desde "cadena" a "m[i]"
		if(cadena != "FIN"){
			for (int x=0; x<long_cadena; x++) {
				m[i][x] = cadena[x];
			}
			//Guardamos las lecturas correctas que se han hecho
			cant_lecturas++;
		}
	}
	
	//Mostramos la composicion de la matriz
	cout << "La matriz esta compuesta por: " << endl;
	for(int x = 0; x < cant_lecturas; x++){
		cout << "\t";
		for (int i=0; i<MAX_DATOS; i++) {
			if(m[x][i] != '*')

				cout << m[x][i];
		}
		cout << endl;
	}

/*****************************************************************************/

	//Codificamos la matriz m
	//La longitud de long_codificada es el mayor numero de datos por dos debido
	// a que puede ser que todos los caracteres se repitan una sola vez
	int long_codificada = MAX_DATOS*2;
	int m_codificada[MAX_LECTURAS][long_codificada];

	//Iniciallizamos todos los elementos de la matriz codificada a -1
	for(int x = 0; x < MAX_LECTURAS; x++){
		for (int i=0; i<long_codificada; i++) {
			m_codificada[x][i] = -1;
		}
	}

	char c_anterior;
	int num_repeticiones;

	//Recorremos todas las lecturas que se hicieron correctamente
	for(int x = 0; x < cant_lecturas;x++){
		int utilizados_s = 0;
		//Recorremos cada columna de una fila
		for(int i = 0; i <= MAX_DATOS; i++){
			//Comprobamos si es la primera pasada para inicializar las variables
			if(i==0){
				c_anterior =  m[x][i];
				num_repeticiones = 1;
			}else if(c_anterior == m[x][i]){
				//Si la letra de esta posicion es igual a la anterior se suma las
				//repeticiones
				num_repeticiones++;
			}else{
				//Si no es el caracter inicializador de la matriz
				if(c_anterior != '*'){
					//Si no es igual se guarda el numero de repeticiones
					m_codificada[x][utilizados_s] = num_repeticiones;
					utilizados_s++;
					//y en la siguiente posicion el valor en int del caracter
					m_codificada[x][utilizados_s] = c_anterior;
					utilizados_s++;
					//Se reinicializa las variables
					num_repeticiones = 1;
					c_anterior = m[x][i];
				}
			}
		}
	}
	
	//Mostramos la matriz codificada
	cout << "La matriz codificada es: " << endl;
	//Recorremos todas las lecturas que hemos hecho
	for(int x = 0; x < cant_lecturas; x++){
		bool continuar = true;
		cout << "\t";
		for (int i=0; i<long_codificada && continuar; i++) {
			//Si tiene un valor correcto procesamos esta posicion
			if(m_codificada[x][i] != -1){
				//Si es una posicion par esta el numero de repeticiones
				if(i%2==0)
					cout << m_codificada[x][i];
				else{
					//Si es una posicion impar esta el char que lo tenemos que pasar
					//de int a char
					char caracter = m_codificada[x][i];
					cout << caracter;
				}
			}else
				continuar = false;
			//Una vez que encontremos una poscion sin un valor adecuado podemos
			//salir ya que no hay mas codificacion
		}
		cout << endl;
	}

/*****************************************************************************/
	//Inicializamos el vector a un caracter que se usara para poder diferencias
	//posicion inicializada con otras que si lo esten
	char m_recodificada[MAX_LECTURAS][MAX_DATOS];
	for(int x = 0; x< MAX_LECTURAS; x++){
		for(int i = 0; i<MAX_DATOS; i++){
			m_recodificada[x][i] = '*';
		}
	}
	bool continuar;
	for(int h = 0; h< MAX_LECTURAS;h++){
		continuar = true;
		for (int i=0; i<long_codificada && continuar; i++) {
			//Si la posicion esta inicializada procemos a recodificar esa posicion
			if(m_codificada[h][i] != -1){
				if(i%2==0){
					//Cuando es par encontramos el numero de repeticiones
					//y en la siguiente el caracter que se repite tantas veces
					int pos_caracter = i+1;
					//Recorremos el numero de repeticiones
					for(int x = 0; x<m_codificada[h][i]; x++){
						bool continuar_buscando = true;
						//y colocaremos el caracter donde haya un * ya que es el
						//caracter que usamos de inicializacion
						for(int y = 0; y<MAX_DATOS && continuar_buscando; y++){
							if(m_recodificada[h][y] == '*'){
								m_recodificada[h][y]=m_codificada[h][pos_caracter];
								//cuando hayamos puesto el caracter podemos salir
								continuar_buscando = false;
							}
						}
					}
				}
			}else
				continuar = false;
		}
	}
	//Mostramos la cadena recodificada

	cout << "Las cadenas originales en la matriz m_recodificada son: " << endl;
	for(int x = 0; x < cant_lecturas; x++){
		continuar = true;
		cout << "\t";
        for(int i = 0; i<MAX_DATOS && continuar;i++){
            if(m_recodificada[x][i] != '*')
                cout << m_recodificada[x][i];
            else
                continuar=false;
        }
    	cout << endl;
	}



	//Comparamos los vectores
	if(m == m_recodificada)
		cout << "Las matrices son iguales";
    else
		cout << "Las matrices son diferentes";

    return (0);
}
