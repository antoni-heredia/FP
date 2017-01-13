/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*	
	Cremos la clase palabra que esta compuesta por un vector de char y 
	ademas contiene sus metodos necesarios.
	
	Tambien tenemos la clase frase que esta compuesta por un vector de 
	palabras y contiene metodos necesarios.

*/
/***************************************************************************/

#include <iostream>
#include <cctype>
using namespace std;


/////////////////////////////////////////////////////////////////////////////
class Palabra{
private:
	static const int TAMANIO = 50; // N�m.casillas disponibles
    char vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<=TAMANIO

    int total_utilizados; // N�m.casillas ocupadas
public:
	/***********************************************************************/
    // Constructor sin argumentos

    Palabra (void) : total_utilizados (0)
    {}

    /***********************************************************************/
    // Devuelve el n�mero de casillas ocupadas

    int Longitud (void)
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
    // PRE: nuevo != ' '
    // 		La adici�n se realiza si hay alguna casilla disponible.
    // 		El nuevo elemento se coloca al final del vector.
    // 		Si no hay espacio, no se hace nada.

    void Aniade (char nuevo)
    {
    	if(nuevo != ' ')
	        if (total_utilizados < TAMANIO){
	            vector_privado[total_utilizados] = nuevo;
	            total_utilizados++;
	        }
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
	// Inserta el car�cter "valor_nuevo" en la posici�n "pos_insercion".
    // Realiza un desplazamiento de todos los valores desde la posici�n 
	// "pos_insercion".
    // PRE: 0 <= pos_insercion <= total_utilizados
    // PRE: total_utilizados < TAMANIO
    
    void Inserta(int pos_insercion, char valor_nuevo)
    {
        if ((pos_insercion >= 0) && (pos_insercion <= total_utilizados) && 
		    (total_utilizados < TAMANIO) && valor_nuevo != ' ') {
		    	
            for (int i = total_utilizados ; i>pos_insercion ; i--)
                vector_privado[i] = vector_privado[i-1];

			vector_privado[pos_insercion] = valor_nuevo;
            total_utilizados++;
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
};

/***************************************************************************/

class Frase{
private:
	static const int TAMANIO = 50; // N�m.casillas disponibles
    Palabra vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<=TAMANIO

    int total_utilizados; // N�m.casillas ocupadas
public:
	
	int NumeroPalabras(){
		
	}
	
	/***********************************************************************/
    // A�ade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // PRE: nuevo != ' '
    // 		La adici�n se realiza si hay alguna casilla disponible.
    // 		El nuevo elemento se coloca al final del vector.
    // 		Si no hay espacio, no se hace nada.

    void Aniade (Palabra nuevo)
    {
    
	    if (total_utilizados < TAMANIO){
	        vector_privado[total_utilizados] = nuevo;
	        total_utilizados++;
		}
    }

    /***********************************************************************/
    // Eliminar la palabra de la posici�n dada por "indice".
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
	// Inserta  la palabra "valor_nuevo" en la posici�n "pos_insercion".
    // Realiza un desplazamiento de todos los valores desde la posici�n 
	// "pos_insercion".
    // PRE: 0 <= pos_insercion <= total_utilizados
    // PRE: total_utilizados < TAMANIO
    
    void Inserta(int pos_insercion, Palabra valor_nuevo)
    {
        if ((pos_insercion >= 0) && (pos_insercion <= total_utilizados) && 
		    (total_utilizados < TAMANIO) ) {
		    	
            for (int i = total_utilizados ; i>pos_insercion ; i--)
                vector_privado[i] = vector_privado[i-1];

			vector_privado[pos_insercion] = valor_nuevo;
            total_utilizados++;
        }
    }
    
    /***********************************************************************/
	// Genera un string a partir de las palabras por los que esta compuesto
	// el objeto 
	
    string ToString(void){
    	string cadena;
    	for(int i = 0; i < total_utilizados; i++){
    		cadena = cadena + vector_privado[i].ToString();
    		cadena = cadena + " ";
		}
    	return cadena;
	}
};
int main (void)
{
	Palabra primera, segunda;
	
	//A�adimos letras a las palabras
	primera.Aniade('H');
	primera.Aniade('o');
	primera.Aniade('l');
	primera.Aniade('a');
	
	segunda.Aniade('J');
	segunda.Aniade('u');
	segunda.Aniade(' ');
	segunda.Aniade('a');
	segunda.Aniade('n');
	
	Frase frase;
	
	//A�adimos las palabras a la frase
	frase.Aniade(primera);
	frase.Aniade(segunda);
	
	//Mostramos la frase
	cout << "La frase es: " << frase.ToString();

	return (0);
}

/***************************************************************************/

