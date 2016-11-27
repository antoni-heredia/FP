/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
	Lo primero que hacemos es guardar el string en un vector.
	Despues ese vector lo codificamos, la codificacion consiste en ver cuantas
	veces se repite una letra y guardar en otro vector en una posicion el numero
	de repeticiones y en la siguiente el caracter que se repite.
	Para ello he tenido que usar un vector de int. Para poder guardar las
	repeticiones en formato numerico.
	
	Luego para hacer la recodificacion primero veo cuantas veces se repite el
	caracter y el caracter que es para guardar el caracter repetido tantas veces 
	como nos indicaba en otro vector.
	
	El codigo esta explicado paso a paso posteriormente, ya que es mas facil
	entenderlo asi.
	
    Entradas: una cadena
    Salidas:  vector, vector codificado, vector recodificado
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <string>
using namespace std;

int main() // Programa Principal
{
	
	const int MAX_DATOS = 50;
	
	// Vector para guardar la copia de la cadena 
	char s[MAX_DATOS]; 	
	
	string cadena;		// Para leer los datos
	int long_cadena; 	
		
			
	// Lectura: No se admite la cadena vacía, ni cadenas demasiado largas 
	// (recuerde que su contenido se va a copiar al vector v)
	
	do {
		cout << "Introduzca una cadena: ";
		getline (cin, cadena); 
		long_cadena = cadena.length(); // Longitud de la cadena
	} while ((long_cadena==0) || (long_cadena>MAX_DATOS));
	
	// Copiar desde "cadena" a "v"
	
	for (int i=0; i<long_cadena; i++) {
		s[i] = cadena[i];
	}
	cout << "La cadena original en el vector s es: ";
	for (int i=0; i<long_cadena; i++) {
		cout << s[i];
	}
	cout << endl;

/***************************************************************************/

	//Codificamos el vector s
	//La longitud de s_codificada es el mayor numero de datos por dos debido a 
	//que puede ser que todos los caracteres se repitan una sola vez
	int long_codificada = MAX_DATOS*2;
	int s_codificada[long_codificada];
	
	//Iniciallizamos el vector codificado a -1
	for (int i=0; i<long_codificada; i++) {
		s_codificada[i] = -1;
	}
	
	char c_anterior;
	int num_repeticiones;
	int utilizados_s = 0;
	
	for(int i = 0; i <= long_cadena; i++){
		//Comprobamos si es la primera pasada para inicializar las variables
		if(i==0){
			c_anterior =  s[i];
			num_repeticiones = 1;
		}else if(c_anterior == s[i]){
			//Si la letra de esta posicion es igual a la anterior se suma las 
			//repeticiones
			num_repeticiones++;
		}else{
			//Si no es igual se guarda el numero de repeticiones
			s_codificada[utilizados_s] = num_repeticiones;
			utilizados_s++;
			//y en la siguiente posicion el valor en int del caracter
			s_codificada[utilizados_s] = c_anterior;
			utilizados_s++;
			//Se reinicializa las variables
			num_repeticiones = 1;
			c_anterior = s[i];
		}

	}
	
	//Mostramos el vector codificado
	bool continuar = true;
	cout << "La cadena original en el vector s_codificada es: ";
	for (int i=0; i<long_codificada && continuar; i++) {
		//Si tiene un valor correcto procesamos esta posicion
		if(s_codificada[i] != -1){
			//Si es una posicion par esta el numero de repeticiones
			if(i%2==0)
				cout << s_codificada[i];
			else{
				//Si es una posicion impar esta el char que lo tenemos que pasar
				//de int a char
				char caracter = s_codificada[i];
				cout << caracter;
			}
		}else
			continuar = false;
		//Una vez que encontremos una poscion sin un valor adecuado podemos 
		//salir ya que no hay mas codificacion
	}
	cout << endl;
	
/***************************************************************************/
	
	//Inicializamos el vector a un caracter que se usara para poder diferencias
	//posicion inicializada con otras que si lo esten
	char s_recodificada[MAX_DATOS];
	for(int i = 0; i<MAX_DATOS; i++){
		s_recodificada[i] = '*';
	}
	
	continuar = true;
	for (int i=0; i<long_codificada && continuar; i++) {
		//Si la posicion esta inicializada procemos a recodificar esa posicion
		if(s_codificada[i] != -1){
			if(i%2==0){
				//Cuando es par encontramos el numero de repeticiones
				//y en la siguiente el caracter que se repite tantas veces
				int pos_caracter = i+1;
				//Recorremos el numero de repeticiones
				for(int x = 0; x<s_codificada[i]; x++){
					bool continuar_buscando = true;
					//y colocaremos el caracter donde haya un * ya que es el
					//caracter que usamos de inicializacion
					for(int y = 0; y<MAX_DATOS && continuar_buscando; y++){
						if(s_recodificada[y] == '*'){
							s_recodificada[y]=s_codificada[pos_caracter];
							//cuando hayamos puesto el caracter podemos salir
							continuar_buscando = false;
						}
					}
				}
			}
		}else
			continuar = false;
	}

	//Mostramos la cadena recodificada
	
	cout << "La cadena original en el vector s_recodificada es: ";	
	continuar = true;
	for(int i = 0; i<MAX_DATOS && continuar;i++){
		if(s_recodificada[i] != '*')
			cout << s_recodificada[i];
		else
			continuar=false;
	}
	cout << endl;
/***************************************************************************/
	
	//Comparamos los vectores
	if(s == s_recodificada)
		cout << "Los vectores son iguales";
    else
		cout << "Los vectores son diferentes";
    return (0);
}

