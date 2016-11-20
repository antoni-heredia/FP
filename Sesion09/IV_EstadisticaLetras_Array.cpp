/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÃ“N
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
	El programa debera leer una serie de caracteres. Estar leyendo datos 
	mientras que el que caracter que metamos sea un *. Finalmente mostrara
	la cantidad de veces que se han repetido cada uno de las letras
	
	Entrada: caracter
	Salida: nº de repeticiones de cada caracter
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S

using namespace std;


int main() // Programa Principal
{
	//La longitud que tendra el array
	const int LONGITUD= 'z'-'a';
	char lectura;
	//array para las repeticiones de cada letra
	int repeticiones[LONGITUD];
	//array donde guardar cada letra
	char letras[LONGITUD];
	
	//Inicializamos el array a 0 para luego ir sumando
	for(int i = 0; i<LONGITUD; i++){
		repeticiones[i] = 0;
	}
	//Guardamos las letras en cada posicion del array para luego  poder comparar
	//y tambien mostrarlas en los resultados
	for(int i = 0; i <= LONGITUD; i++){
		letras[i] = 'A'+i;
	}
	
	//Pedimos al usuario que introduzca los caracteres
	do{
		cout << "Por favor introduzca un caracter: ";
		//El cin.get me esta dando problemas ya que detecta tambien el enter como caracter
		//lectura = cin.get();
		cin >> lectura;
		lectura = toupper(lectura);
		
		//Verificamos que el caracter sea una letra
		if( lectura >= 'A' && lectura <= 'Z' ){
			//Si es una letra lo comprobamos con todas las letras que hay
			//y cuando coincida en esa letra sumos uno en sus repeticiones
			for(int i = 0; i <= LONGITUD; i++){
				if(letras[i] == lectura){
					repeticiones[i]++;
				}
			}
		}
	//La lectura se acaba cuando se introduzca un asterisco
	}while(lectura != '*');
	
	//Mostramos las repeticiones de cada letra si son distintas de 0
	for(int i = 0; i < LONGITUD; i++){
		if(repeticiones[i] != 0)
			cout << "El caracter " << letras[i] << " tiene " << repeticiones[i] << " repeticiones." << endl;
	}
	
	return(0);
}
