/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*

    Entradas: secuencia de enteror
    Salidas: secuencia codificada y decodificada
*/
/***************************************************************************/

#include <iostream>

using namespace std;
/***************************************************************************/
class ConjuntoOrdenado
{
	private:
		static const int TAMANIO = 500;
		int vector_privado[TAMANIO];
		int cant = 0;
	public:
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
		
		bool Existe(int elemento){
			bool existe = false;
			for(int i = 0; i < cant && !existe; i++){
				if(vector_privado[i] == elemento)
					existe = true;
			}
			return existe;
		}
		
		void AniadirElementoSinOrdenacion(int elemento){
			if(!Existe(elemento)){
				vector_privado[cant] = elemento;
				cant++;
			}
		}

		void AniadirElemento(int elemento){
			AniadirElementoSinOrdenacion(elemento);
			OrdenarVector();
		}
		int Elemento(int posicion){
			return vector_privado[posicion];
		}
		
		int Cantidad(void){
			return cant;
		}
		
		ConjuntoOrdenado Union(ConjuntoOrdenado conjunto){
			ConjuntoOrdenado conjunto_union = conjunto;
			for(int i = 0; i < Cantidad();i++){
				conjunto_union.AniadirElementoSinOrdenacion(Elemento(i));
			}
			conjunto_union.OrdenarVector();
			return conjunto_union;
		}
		
		ConjuntoOrdenado Interseccion(ConjuntoOrdenado conjunto){
			ConjuntoOrdenado conjunto_interseccion;
			for(int i = 0; i < conjunto.Cantidad();i++){
				if(Existe(conjunto.Elemento(i)))
					conjunto_interseccion.AniadirElementoSinOrdenacion(Elemento(i));
			}
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
		conjunto_a.AniadirElemento(entero);
	}while(entero!= -1);
	
	cout << "Enteros del conjunto B:" << endl;
	do{
		cout << "Introduzca un entero: ";
		cin >> entero;
		conjunto_b.AniadirElemento(entero);
	}while(entero!= -1);
	
	conjunto_union = conjunto_a.Union(conjunto_b);
	conjunto_interse = conjunto_a.Interseccion(conjunto_b);
	
	cout << endl << "La union es: ";
	for(int i = 0; i<conjunto_union.Cantidad(); i++){
		cout << conjunto_union.Elemento(i) << "-";
	}
	
	cout << endl << "La interseccion es: ";
	for(int i = 0; i<conjunto_interse.Cantidad(); i++){
		cout << conjunto_interse.Elemento(i) << "-";
	}
	//Salimos de la funcion principal
	return(0);
}
