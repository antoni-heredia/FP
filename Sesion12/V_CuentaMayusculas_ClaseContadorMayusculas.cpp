/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
	El programa cuenta con la clase ContadorMayusculas en la cual mantendremos
	un array del numero de repeticiones de cada letra mayuscula.
	La clase como datos privados tienen el susodicho array y ademas una
	costante que indica el numero de letras, que es el numero de posiciones
	de dicho array.
	
	Los metodos publicos es uno que nos incremeta el contador dada una
	mayuscla, otro metodo que nos devuelve cuantas repeticiones de una 
	mayuscala dada hay y ademas un metodo que nos devuelve un string con
	el numero de repeticiones de la letra y la letra.
	
	El programa principal cuenta con una pedida de datos que se realiza con 
	un do-while hata que se introduzca un '.' y ademas muestra los datos de 
	dos formas distintas. La primera es con un for que recorre todas las letras
	y nos muestra su numero de repeticiones con el metodo CuantasHay y la otra
	es mostrando la cadena quenos devuelve el metodo DevolverStringRepeticiones
	
*/
/***************************************************************************/

#include <iostream>
#include <string> 

using namespace std;
class ContadorMayusculas
{
	//Datos privados
	private:
		static const int NUM_LETRAS = 'Z'-'A'+1; 
		int contador[NUM_LETRAS] = {0};
	
	//Metodos publicos
	public:
		//Metodo que nos incrementa un uno el contador de una mayuscula	
		void IncrementaCuenta (char mayuscula){
			//La suma solo se realiza si el usuario introdujo una mayuscula
			if(mayuscula >= 'A' && mayuscula <= 'Z'){
				contador[mayuscula-'A']++;
			}
		}
		
		//Nos devuelve cuantas repeticiones de una mayuscula dada hay
		int CuantasHay (char mayuscula){
			return contador[mayuscula-'A'];
		}
		
		//Nos devuelve la cadena con las repeticiones de cada letra
		string DevolverStringRepeticiones(){
			string cadena;
			//Recorremos todas las letras mayusculas de la A a la Z
			for(int x = 'A'; x <=  'Z';x++){
				char caracter_salida = x;
				//A�adimos las repeticiones de cada letra
				cadena += to_string(CuantasHay(x));
				//A�adimos la letra en cuestion
				cadena += caracter_salida;
			}
			return cadena;
		}
};
/***************************************************************************/

int main (void)
{
	//Declaramos una variable para la introducion de datos
	char caracter;
	
	//inicializamos el objeto contador
	ContadorMayusculas contador;
	do{
		//Pedimos al usuario que introduzca un caracter
		cout << "Introduzca un caracter: ";
		cin >> caracter;
		//Aumentamos el valor de dicha mayuscula
		contador.IncrementaCuenta(caracter);
		//Se repite mientras sea distinto de un punto
	}while( caracter != '.');
	
	
	//Mostramos los resultados 
	cout << "-----------------------MOSTRAR RESULTADOS-----------------------"
		 << endl;
		 
	//Recorremos todas las letras mayusculas
	for(int x = 'A'; x <=  'Z';x++){
		char caracter_salida = x;
		//Mostramos el numero de repeticiones de cada letra mayuscula
		cout << "Del caracter " << caracter_salida << " hay: " 
		     << contador.CuantasHay(x) << endl;
	}
	
	//Otra forma de mostrar los datos es a partir del string que nos devuelve
	//la funcion 
	string cadena = contador.DevolverStringRepeticiones();
	cout << "-----------------------MOSTRAR CADENA-----------------------"
		 << endl << endl;
	
	//Mostramos el string
	cout << cadena;
	return(0);
}
