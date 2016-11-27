/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
	El programa realiza la criba de Eratostenes.
	* 
	* Para ello por defecto decimos que todos los numeros son primos.
	* Luego con un ciclo for comprobaremos todos los numeros y si esta marcado
	* como primo comprobamos si lo es de verdad, y entonces marcamos como 
	* no primos todos sus multiplos, ademas si el numero es primo lo guardamos
	* en un vector de primos y pasamos al siguiente numero.
    
    Entradas: numero hasta donde queremos ver los primos
    Salidas:  Todos los primos hastta el numero introducido
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <string>
using namespace std;

//Funcion que lee un numero entero positivo menor que el maximo introducido
//Prec: maximo >= 1
double LeerNumeroHasta(int maximo, string mensaje)
{
	double numero;
	do{
		cout << mensaje;
		cin >> numero;
	}while(numero < 1 || numero > maximo);
	return numero;
}




int main() // Programa Principal
{
	//Declaramos las constantes de tamaños maximo
	const int MAX_PRIMO = 1000;
	const int MAX_DATOS = 300;
	//Declaramos el vector donde se guardan los numeros primos
	int primos[MAX_DATOS];
	//Pedimos al usuario que introduzca hasta que numero desea ver los primos
	string mensaje = "Hasta que numero desea buscar los primos (max:"
					 +to_string(MAX_PRIMO)+"): ";
	int final = LeerNumeroHasta(MAX_PRIMO, mensaje);
	//El vector para saber si es primo o no un numero
	bool es_primo[final];
	
	//Por defecto voy a dar que todos los numeros son primos y luego ire
	//tachando los que no sean
	for(int i = 2; i <= final; i++){
		es_primo[i] = true;
	}	
	//Donde guardamos los primos lo inicializamos a -1
	for(int i = 0; i < MAX_DATOS; i++){
		primos[i] = -1;
	}
	
	//Como el uno no lo vamos a contabilizar a la hora de tachar lo ponemos como
	//primo manualmente
	es_primo[1] = true;
	primos[0] = 1;
	
	
	//Empezamos por el 2 hasta que lleguemos al final
	for(int i = 2 ; i <= final; i++){
		if(es_primo[i]){
			//Guardamos que es primo
			bool guardado = false;
			for(int x = 0; x < MAX_DATOS && !guardado; x++){
				//Buscamos el primer hueco en primos que este vacio
				if(primos[x] == -1){
					guardado = true;
					primos[x] = i;
				}
			}
			//En caso de ser primo tachamos como no primos todos su
			//multiplos
			for(int x = i+1; x<= final;x++){
				if( x%i == 0 )
					es_primo[x] = false;
			}
		}
	}
	
	bool continuar = true;
	for(int x = 0; x < MAX_DATOS && continuar; x++){
		//Imprimios donde haya numeros primos guardados
		if(primos[x] != -1){
			cout << primos[x] << " es un primo" << endl;
		}else
			continuar = false;
	}
	
	
    return (0);
}
