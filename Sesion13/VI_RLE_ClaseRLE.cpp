/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
	El usuario introduce una secuencia de enteros, la cual se guarda en un
	objeto de la clase SEcuenciaEnteros y a partir de un objeto de la clase
	RLE codificara y descodificara la secuencia introducida por el usuario
	
	Contamos con dos clases. Una que guarda una secuencia en un vector y que nos
	proporciona los metodos necesarios para usarla.
	
	La otra clase nos proporciona los metodos para codifica y decodificar
	un objeto de la clase SecuenciaEnteros
	
    Entradas: secuencia de enteror
    Salidas: secuencia codificada y decodificada
*/
/***************************************************************************/

#include <iostream>

using namespace std;
/***************************************************************************/
//Clase donde se guardan secuencias de enteros con sus metodos correspondientes
class SecuenciaEnteros
{
	private:
		//Datos privados en el cual se guarda el vector de la secuencia y su
		//cantidad de datos
		static const int TAMANIO = 500;
		int vector_privado[TAMANIO];
		int cant = 0;
	public:
		//Metodos publicos
		
		//Se añade un elemento y se aumenta la cantidad
		void AniadirElemento(int elemento){
			vector_privado[cant] = elemento;
			cant++;
		}
		
		//Nos devuelve un elemento dada una posicion
		int DevolverElemento(int pos){
			return vector_privado[pos];
		}
		
		//Nos devuelve la cantidad de elmentos que hay
		int Cantidad(void){
			return cant;
		}
		
		// Eliminar el carácter de la posición dada por "indice".
		// Realiza un borrado físico (desplazamiento y sustitución).
		// PRE: 0 <= indice < cant

		void Elimina (int indice)
		{
			//Si el indice es correcto
			if ((indice >= 0) && (indice < cant)) {
				
				//El tope es uno anterior al final
				int tope = cant-1; // posic. del último
				
				//Vamos recorriendo desde donde queremos borrar
				for (int i = indice ; i < tope ; i++)
					vector_privado[i] = vector_privado[i+1];
				
				//disminuimos la cantidad en una unidad
				cant--;
			}
		}
		
		//Metodo que nos compara que dos secuencias son iguales
		bool EsIgualA (SecuenciaEnteros otro){
			//Por defecto decimos que son iguales
			bool iguales = true;
			//Si tienen la misma cantidad seguimos comparando
			if(cant == otro.Cantidad())
				//Recorremos que todos sus elementos sean iguales
				//paramos en el momento que encontremos uno que no lo sea
				for(int i = 0; i < cant && iguales; i++){
					if(DevolverElemento(i) != otro.DevolverElemento(i)){
						iguales = false;
					}
				}
			else
				iguales = false;
			
			//Devolvemos si son iguales
			return iguales;
		}
};
/***************************************************************************/
//Clase con metodos para codificar
class RLE
{
	public:
		//Metodo publico que nos codifica una SecuenciaEnteros y nos
		//Devuelve una SecuenciaEnteror
		SecuenciaEnteros Codifica (SecuenciaEnteros secuencia_descodificada){
			
			//Donde se guarda la secuencia una vez codificada
			SecuenciaEnteros secuencia_codificada;
			
			
			//Los enteror anterior y el numero de veces que se repite
			int n_anterior = secuencia_descodificada.DevolverElemento(0);
			int num_repeticiones = 1;			
			
			for(int i = 1; i <= secuencia_descodificada.Cantidad(); i++){
				//El elemento que se procesa actualmente
				int elemento = secuencia_descodificada.DevolverElemento(i);
				
				
				if(n_anterior == elemento){
					//Si el elemento es igual al anterior se suma uno en el
					//numero de repeticiones
					num_repeticiones++;
				}else{
					//Si no es igual se guarda el numero de repeticiones
					secuencia_codificada.AniadirElemento(num_repeticiones);
					
					//y en la siguiente posicion el valor el int 
					secuencia_codificada.AniadirElemento(n_anterior);
					
					//Se reinicializa las variables
					num_repeticiones = 1;
					n_anterior = elemento;
				}

			}
			
			//Devolvemos la secuencia ya codificada
			return secuencia_codificada;
		}
		
		SecuenciaEnteros Descodifica (SecuenciaEnteros secuencia_codificada){
			//Secuencia donde se guarda la secuencia codificada una vez que la
			//hayamos descodificado
			SecuenciaEnteros secuencia_descodificada;
			
			//Recorremos todos los elementos de la codificada
			//pero de dos en dos
			for (int i=0; i<secuencia_codificada.Cantidad(); i+=2) {
				
				//El elemento siguiente es  el entero
				int elemento = secuencia_codificada.DevolverElemento(i+1);
				//Y el elemento actual es el numero de repeticiones
				//Añadimos el entero tantas veces como nos indique
				for(int x = 0; x<secuencia_codificada.DevolverElemento(i); x++){
					secuencia_descodificada.AniadirElemento(elemento);
				}
			}
			
			//Devolvemos la secuencia descodificada
			return secuencia_descodificada;
		}
		
};
int main(void)
{
	//Creamos la secuencia donde guardamos lo que introduzca el usuario sin
	//codificar
	SecuenciaEnteros original;
	int entero;
	//Leemos los enteros y los introducimos en el objeto
	do{
		cout << "Introduzca un entero: ";
		cin >> entero;
		original.AniadirElemento(entero);
	}while(entero!= -1);
	
	//Eliminamos el ultimo elemento que es un -1
	original.Elimina(original.Cantidad()-1);
	
	cout << endl << endl << "Secuencia original:" << endl;
	//Recorremos el objeto 
	for(int i = 0; i < original.Cantidad(); i++){
		cout << original.DevolverElemento(i);
	}
	
	//Objeto codificador
	RLE codificador;
	//Guardamos la secuencia original codificada en el objeto codificada
	SecuenciaEnteros codificada = codificador.Codifica(original);
	cout << endl << endl << "Secuencia codificada:" << endl;
	for(int i = 0; i < codificada.Cantidad(); i++){
		cout << codificada.DevolverElemento(i);
	}
	
	//Descodificamos la secuencia codificada y la guardamos en el objeto
	//descodificada
	SecuenciaEnteros decodificada = codificador.Descodifica(codificada);
	cout << endl << endl << "Secuencia una vez descodificada:" << endl;
	for(int i = 0; i < decodificada.Cantidad(); i++){
		cout << decodificada.DevolverElemento(i);
	}
	
	//Mostramos si la comparacion es devuelve true y lo mostramos
	cout << endl << endl;
	if(decodificada.EsIgualA(original))
		cout  << "La secuencia una vez decodificada es igual a la original";
	else 
		cout << "La secuencia una vez decodificada es diferente a la original";
	//Salimos de la funcion principal
	return(0);
}
