/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2

// RELACI�N DE PROBLEMAS 5
// EJERCICIO 21
//
/*	
	En este ejercico ampl�a la clase SecuenciaCaracteres con el m�todo:
	
		bool Palindromo (void) 
		
	para ver si la secuencia es un palindromo

*/
/***************************************************************************/

#include <iostream>
#include <cctype>
using namespace std;


/////////////////////////////////////////////////////////////////////////////

class SecuenciaCaracteres {

private:

    static const int TAMANIO = 50; // N�m.casillas disponibles
    char vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<TAMANIO

    int total_utilizados; // N�m.casillas ocupadas

public:

    /***********************************************************************/
    // Constructor sin argumentos

    SecuenciaCaracteres (void) : total_utilizados (0)
    {}

    /***********************************************************************/
    // Devuelve el n�mero de casillas ocupadas

    int TotalUtilizados (void)
    {
        return (total_utilizados);
    }

    /***********************************************************************/
    // Devuelve el n�mero de casillas disponibles

    int Capacidad (void)
    {
        return (TAMANIO);
    }

    /***********************************************************************/
    // A�ade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // 		La adici�n se realiza si hay alguna casilla disponible.
    // 		El nuevo elemento se coloca al final del vector.
    // 		Si no hay espacio, no se hace nada.

    void Aniade (char nuevo)
    {
        if (total_utilizados < TAMANIO){
            vector_privado[total_utilizados] = nuevo;
            total_utilizados++;
        }
    }

    /***********************************************************************/
    // Devuelve el elemento de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados

    char Elemento (int indice)
    {
        return (vector_privado[indice]);
    }

    /***********************************************************************/
    // Eliminar el car�cter de la posici�n dada por "indice".
    // Realiza un borrado f�sico (desplazamiento y sustituci�n).
    // PRE: 0 <= indice < total_utilizados

    void Elimina (int indice)
    {
        if ((indice >= 0) && (indice < total_utilizados)) {

            int tope = total_utilizados-1; // posic. del �ltimo

            for (int i = indice ; i < tope ; i++)
                vector_privado[i] = vector_privado[i+1];

            total_utilizados--;
        }
    }

    /***********************************************************************/
    // Compone un string con todos los caracteres que est�n
    // almacenados en la secuencia y lo devuelve.

    string ToString()
    {
        string cadena;

        for (int i=0; i<total_utilizados; i++)
            cadena = cadena + vector_privado[i];

        return (cadena);
    }
    
   

	/***********************************************************************/
	//Comprueba que la secuencia almacenada es un palindromo
	
	bool Palindromo(void){
		
		//El ultimo elemento es el total que tenemos  menos uno
		int final=total_utilizados-1;
		
		//Por defecto decimos que es un palindromo
		bool palindromo = true;
		//Se recorre unicamente hasta la mitad de los elementos o hasta que
		//se vea que no es un palindromo
		for(int inicio = 0; inicio <= (total_utilizados-1)/2 
		                    && palindromo; inicio++){
		    
			/*
				comparamos si las posiciones son iguales
		    	de no ser iguales diremos que no es un palindromo
		    	pasamos los dos a minuscula ya que no es algo que 
				nos importe en este caso
			*/
			
			if( tolower(vector_privado[final])  != 
			    tolower(vector_privado[inicio]))
				palindromo = false;
			
			//El elemento a comparar es uno menos
			final--;
		}
		
		//Devolvemos si es un palindromo
		return palindromo;
	}


};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/

int main (void)
{
	//Creamos una instancia del objeto secuenciacaracteres
	SecuenciaCaracteres sec;

	//creamos la variable caracter, donde iremos guardando los caracteres
	//introducidos por el usuario
	char caracter;
	
	do{
		//Pedimos al usuario que introduzca un caracter
		cout << "Introduzca otro caracter por favor: ";
		
		//Lo recogemos
		caracter = cin.get();
		
		//A�adimos el caracter al vector
		sec.Aniade(caracter);
		//ignoramos el /n
		cin.ignore();
		
	//Se ejecuta mientras sea distinto de #
	}while(caracter != '#');
	
	//Ignoramos el ultimo elemento que es el #
	sec.Elimina(sec.TotalUtilizados()-1);
	
	//Comprobamos si es un palindromo
	if(sec.Palindromo())
		cout << "Es un palindromo";
	else
		cout << "No es un palindromo";
		
	return (0);
}

/***************************************************************************/
