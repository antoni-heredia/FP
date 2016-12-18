/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
	El programa leera una permutaicon de numeros y nos devolvera el numero
	de lecturas necesarias para leer sus elementos en orden creciente.
	
	Para ello usamos dos clases, una que es SecuenciaEnteros explicada en el
	ejercicio VI_RLE_ClaseRLE.cpp
	
	En este ejercicio a�adimos la clase Permutacion la cual tiene el dato
	privado vector_privado y la cantidad de elementos de dicho vector, 
	ademas tiene como metodos privados el que nos devuelve el maximo y el
	minimo de dichos elementos. El constructor de la clase recibe una
	SecuenciaEnteros y con ella se forma el vector_privado.
	
	El metodo publico, a parte del constructor es el que nos devuelve el
	numero de lecturas de dicha permutacion
	
    Entradas: secuencia de enteros
    Salidas: numero de lecturas de la permutacion
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
		
		//Se aniade un elemento y se aumenta la cantidad
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
class Permutacion
{
	private:
		//Datos privados
		static const int TAMANIO = 500;
		int vector_privado[TAMANIO];
		int cant;
		
		//Metodo que nos devuelve el minimo de los elementos
		int Minimo(void){
			int minimo;
			minimo= vector_privado[0];
			for(int i = 1; i < cant; i++ ){
				if(vector_privado[i]<minimo)
					minimo=vector_privado[i];
			}
			return minimo;
		}
		
		//Metodo que nos devuelve el maximo de los elementos
		int Maximo(void){
			int maximo;
			maximo= vector_privado[0];
			for(int i = 1; i < cant; i++ ){
				if(vector_privado[i]>maximo)
					maximo=vector_privado[i];
			}
			return maximo;

		}
		
	public:
		//Prec: Que se encuentre todos los elementos desde el minimo
		//al maximo
		Permutacion (SecuenciaEnteros secuencia ){
			cant = 0;
			for(int i = 0; i < secuencia.Cantidad(); i++){
				vector_privado[i]=secuencia.DevolverElemento(i);
				cant++;			
			}

		}	
		
		//Nos devuelve el numero de lecturas posibles de dicha permutacion
		int NumeroLecturas(void){
			//El minimo, por el que empezamos buscando
			int minimo = Minimo();
			//Hasta que estamos buscando
			int maximo = Maximo();
			//El numero de lecturas realizadas
			int num_lecturas = 0;
			//Cuando hemos terminado de buscar
			int final = false;
			
			//Empezamos buscando a paritr del primero
			for(int i = 0; i < cant && !final; i++){
				//Buscamos en todos los demas
				for(int x = 0; x < cant; x++){
					//El siguiente que buscamos es uno mas que el minimo
					//actual
					int siguiente = minimo+1;
					//Una vez que lo hemos encontrado ese pasa a ser el minimo
					if(vector_privado[x] == siguiente){
						minimo = vector_privado[x];
					}
				}
				//Hemos hehco una lectura completa
				num_lecturas++;
				//Si el minimo es igual al maximo es que ya hemos terminado
				if(minimo == maximo)
					final = true;
			}
			//Devolvemos el numero de lecturas
			return num_lecturas;
		}
};
int main(void)
{
	//Creamos la secuencia de enteros para la permutacion
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
	
	//Contruimos la permutacion a partir de la secuencia
	//de enteros
	Permutacion permutacion(original);
	
	//Mostramos como es la configuracion de la permutacion
	cout << "La permutacion es:(";
	for(int i = 0; i<original.Cantidad();i++ )
		cout << original.DevolverElemento(i) << " ";
	cout << ")"<< endl;
	
	//Calculamos el numero de lecturas que han sido necesarias
	int num_lecturas = permutacion.NumeroLecturas();
	
	//Mostramos el numero de lecturas necesarais
	cout << "El numero de lecturas diferentes es: " << num_lecturas;
	
	//Salimos del programa principal
	return(0);
}
