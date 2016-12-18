/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÃ“N
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
	El programa recogera dos conjuntos y hara una union y una interssecion
	entre ellos.
	
	Para ello contamos con la clase ConjuntoOrdenado, la cual tiene metodos
	para añadir, ver cuantos elementos tiene, hacer la union y la interseccion
	con otro conjunto ordenado y que nos devuelva un elemnto
    Entradas: elementos de dos conjuntos
    Salidas: union e interseccion de  dos conjuntos
*/
/***************************************************************************/

#include <iostream>

using namespace std;
/***************************************************************************/
//Clase donde vamos guardando almacenando un vector de forma ordenada
class ConjuntoOrdenado
{
	private:
		//Datos y metodo privado
		static const int TAMANIO = 500;
		int vector_privado[TAMANIO];
		int cant = 0;
		
		
		//Metodo que añade sin ordenadar usado solo dentro de la clase
		void AniadirElementoSinOrdenacion(int elemento){
			if(!Existe(elemento)){
				vector_privado[cant] = elemento;
				cant++;
			}
		}
		
		//Metodo que nos ordena el vector
		void OrdenarVector(void){
			bool cambio = true;
			int intercambia;
			for (int izda = 0; izda < cant && cambio; izda++){
				for (int i = cant-1 ; i > izda ; i--){
					if (vector_privado[i] < vector_privado[i-1]){
						cambio = true;
						intercambia = vector_privado[i];
						vector_privado[i] = vector_privado[i-1];
						vector_privado[i-1] = intercambia;
					}
				}
			}
		}
		
	public:
		
		//Mtodo que nos dice si un elemento existe
		bool Existe(int elemento){
			bool existe = false;
			for(int i = 0; i < cant && !existe; i++){
				if(vector_privado[i] == elemento)
					existe = true;
			}
			return existe;
		}
		
		
		//Metodo que añade un elemento sin ordenarlo y luego lo ordena
		void AniadirElemento(int elemento){
			AniadirElementoSinOrdenacion(elemento);
			OrdenarVector();
		}
		
		//Nos devuelve un elemento dado una posicion
		int Elemento(int posicion){
			return vector_privado[posicion];
		}
		
		//Devuelve la cantidad de elementos
		int Cantidad(void){
			return cant;
		}
		
		//Metodo que devuelve la union entre dos conjuntos
		ConjuntoOrdenado Union(ConjuntoOrdenado conjunto){
			//Creamos el conjunto que devolvemos el cual va a ser de primeras
			//uno de los dos conjuntos y los siguientes los iremos añadiendo
			ConjuntoOrdenado conjunto_union = conjunto;
			//Recorremos todos los elemenos del este conjunto y los añadimos
			for(int i = 0; i < Cantidad();i++){
				conjunto_union.AniadirElementoSinOrdenacion(Elemento(i));
			}
			//Lo ordenamos y ya lo devolvemos
			conjunto_union.OrdenarVector();
			return conjunto_union;
		}
		
		//Metodo que devuelve la interseccion entre dos conjuntos
		ConjuntoOrdenado Interseccion(ConjuntoOrdenado conjunto){
			//Conjunto donde guardamos los elementos
			ConjuntoOrdenado conjunto_interseccion;
			for(int i = 0; i < conjunto.Cantidad();i++){
				//Lo guardamos si y solamente si el elemnto existe en este objeto
				if(Existe(conjunto.Elemento(i)))
					conjunto_interseccion.AniadirElementoSinOrdenacion(conjunto.Elemento(i));
			}
			
			//Lo ordenamos y lo devolemos
			conjunto_interseccion.OrdenarVector();
			return conjunto_interseccion;
		}
		
		
};
int main(void)
{
	
	ConjuntoOrdenado conjunto_a, conjunto_b, conjunto_union, conjunto_interse;
	//Leemos los enteros y los introducimos en el objeto
	cout << "Enteros del conjunto A:" << endl;
	int entero;
	
	do{
		cout << "Introduzca un entero: ";
		cin >> entero;
		if(entero != -1)
			conjunto_a.AniadirElemento(entero);
	}while(entero!= -1);
	
	cout << "Enteros del conjunto B:" << endl;
	do{
		cout << "Introduzca un entero: ";
		cin >> entero;
		if(entero != -1)
			conjunto_b.AniadirElemento(entero);
	}while(entero!= -1);
	
	//Creamos los conjuntos de union e interseccion
	conjunto_union = conjunto_a.Union(conjunto_b);
	conjunto_interse = conjunto_a.Interseccion(conjunto_b);
	
	//Mostramos ambos conjuntos
	cout << endl << "La union es: ";
	for(int i = 0; i<conjunto_union.Cantidad(); i++){
		cout << conjunto_union.Elemento(i) << " ";
	}
	
	cout << endl << "La interseccion es: ";
	for(int i = 0; i<conjunto_interse.Cantidad(); i++){
		cout << conjunto_interse.Elemento(i) << " ";
	}
	//Salimos de la funcion principal
	return(0);
}
