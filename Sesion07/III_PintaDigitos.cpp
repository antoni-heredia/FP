/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   El programa dado un numero entero nos devolvera todos sus digitos por
   separado y dentro de un string

   Para ello usamos dos funciones una que devuelve la longitud de un numero
   y otra que convierte el numero en un string con numeros separados por 
   espacios


   Entradas: int_numero
   Salida: str_numero
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>
#include <string>

using namespace std;
int cantidadDigitos(int numero)
{
    int longitud = 1;
    while ( numero /= 10 )
       longitud++;
    return longitud;
}

string Entero2String(int numero)
{
	string str_digito = "";
	if(numero<0)
    	str_digito +="- ";
    //El numero introducido le aplicamos el valor absoluto
    numero=abs(numero);


    /*
        El primer divisor sera 10 elevado al numero de digitos menos uno
        para que al dividir el numero entre el nos de la cifra
        mas significativa
    */
    int longitud = cantidadDigitos(numero);
    int divisor = pow(10,longitud-1);

    /*
        Mientras que el numero con el que dividimos sea distinto de 0
        todavia quedan cifras significativas y por lo tanto
        tenemos que seguir calculando
    */
    while( divisor != 0 ){
        //Añadimos la cifra significativa que toca en esta pasada
        str_digito += to_string(numero/divisor);
        //Añadimos el espacio
        str_digito += " ";
        /*
            El numero con el que trabajamos ahora sera el resto para
            eliminar el digito que hemos mostrado antes
        */
        numero = numero%divisor;
        /*
            Para la siguiente pasada el numero con el que diviremos sera
            el anterior entre 10
        */
        divisor /= 10;
    }
    return str_digito;
}

int main() // Programa Principal
{
    //Declaramos las variables de entrada
    int numero_introducido;
    
    cout << "Por favor introduzca un numero entero: ";
    cin >> numero_introducido;

    string salida = Entero2String(numero_introducido);
    cout << "El resultado es: " << salida << endl;

    return(0);
}
