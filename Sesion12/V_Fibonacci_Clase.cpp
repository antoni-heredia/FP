/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÃ“N
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
	Tenemos la clase Fibonacci que tiene como datos privados un array
	donde guardamos los elementos de la sucesion de fibonnaci de orden n.
	Tambien guardamos el orden y el numero de elementos calculados
	
	Como metodos publicos tenemos el constructor de la clase el cual inicializa
	las primeras posiciones del vector y ademas pone el numero de elementos 
	calculados a dos. Tambien tenemos uno que nos devuelve el orden que tiene, 
	el total de calculados y ademas elemento de una posicion dada.
	
	El metodo publico principal es el que nos calcula los k numeros de la 
	succesion. El metodo esta explicado mas exhaustivamente en el codigo.
	
	La funcion main tiene un funcionamiento muy basico, en el que solo se calcula
	los k numeros en el orden n, que estan como variable. Y luego mostramos
	cada uno de los elementos con un for.
	
    Entradas: ninguna
    Salidas:  k elementos de la serie de fibonnaci
*/
/***************************************************************************/

#include <iostream>
using namespace std;
class Fibonacci
{
	private:
	
		//Declaramos el array de elementos de la serie de fibonacci
		static const int TAMANIO = 500; 
		long long elementos[TAMANIO];
		
		//Declaramaos el tope y el orden que tiene la sucesion
		int n,tope;
	public:
		//Declaramos el constructor de la clase al cual se le pasa el orden
		Fibonacci(int n_intr){
			n = n_intr;
			//El primer y el segundo elemento ya damos por hecho que son 1
			elementos[0] = 1;
			elementos[1] = 1;
			//Y por tanto el tope por lo mino es dos
			tope = 2;
		}
		
		//Metodo que devuelve el orden d
		int GetOrden(){
			return n;
		}
		
		//Metodo que nos calcula hasta un k pasado por el usuario
		void CalculaPrimeros(int k_intr){
			tope = k_intr;
			//empezamos el bucle en la posicion 2 del vector (la 3º)
			for(int x = 2; x < tope; x++){
				long long numero_x = 0;
				int y_introducir;
				/*
					Si el x que estamos procesando es menor que el orden
					El numero que calculamos empezara  a crearse sumando desde 
					la posicion 0, si empezara en la posicion x-n, ya que 
					tendra que empezar a sumar desde esa posicion hasta la x
					para contruir el numero 
				*/
				if(x<n)
					y_introducir = 0;
				else
					y_introducir = x-n;
				
				//Recorremos desde el y que hemos calculado anteriormente hasta
				//la posicion que nos toca ahora
				for(int y = y_introducir; y < x; y++){
					numero_x += elementos[y];
				}
				//añadimos el numero al array de elementos
				elementos[x] = numero_x;
			}
		}
		
		//Devolvemos la cantidad de elementos que hemos calculado
		int TotalCalculados(){
			return tope;
		}
		//Devolvemos elemento que esta en la posicion pasada
		long long Elemento(int indice){
			return elementos[indice];
		}
};
/***************************************************************************/

int main (void)
{
	//Declaramos los valores del numero de elementos a calcular y el orden
	int k = 50; 
	int n = 4;
	
	//Donde guardamos el numero elementos que ha calculado
	int tope;
	
	//Creamos el objeto fibonacci de orden n
	Fibonacci fibonacci(n);
	
	//Calculamos los k primeros numeros
	fibonacci.CalculaPrimeros(k);
	
	//Guardamos el numero de elementos calculados
	tope = fibonacci.TotalCalculados(); // tope = k
	
	//Mostramos todos los elementos calculados
	for (int i=0; i<tope; i++)
		cout << fibonacci.Elemento(i) << endl;
	return(0);
}
