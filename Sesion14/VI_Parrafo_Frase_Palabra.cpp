/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*	
	En este ejercicio nos pedia que contruyeremos la clase parrafo a partir
	de la clase frase que a su vez esta compuesta por la clase palabra

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
    // Devuelveel tama�o de la palabra

    int Longitud (void)
    {
        return (total_utilizados);
    }

    /***********************************************************************/
    // A�ade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // PRE: nuevo != ' '
    // 		La adici�n se realiza si hay alguna casilla disponible y ademas
    //      no es un espacio
    // 		El nuevo elemento se coloca al final del vector.
    // 		Si no hay espacio, no se hace nada.

    void Aniade (char nuevo)
    {
	    if (total_utilizados < TAMANIO && nuevo != ' '){
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
    // PRE: valor_nuevo != ' '
    
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
		return total_utilizados;
	}
	
	/***********************************************************************/
    // A�ade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
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
	// Inserta la palabra "valor_nuevo" en la posici�n "pos_insercion".
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
	// Nos devuelve un string con la frase completa
    
    string ToString(void){
    	string cadena;
    	for(int i = 0; i < total_utilizados; i++){
    		cadena = cadena + " ";
    		cadena = cadena + vector_privado[i].ToString();	
		}
    	return cadena;
	}
};

class Parrafo{
	private:
	static const int TAMANIO = 50; // N�m.casillas disponibles
    Frase vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<=TAMANIO

    int total_utilizados; // N�m.casillas ocupadas
public:
	//Constructor sin argumentos
	Parrafo(void) : total_utilizados(0)
	{}
	
	//Nos dice el numero de frases del parrafo
	int NumeroFrases(){
		return total_utilizados;
	}
	
	/***********************************************************************/
    // A�ade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // PRE: nuevo != ' '
    // 		La adici�n se realiza si hay alguna casilla disponible.
    // 		El nuevo elemento se coloca al final del vector.
    // 		Si no hay espacio, no se hace nada.

    void Aniade (Frase nuevo)
    {
    
	    if (total_utilizados < TAMANIO){
	        vector_privado[total_utilizados] = nuevo;
	        total_utilizados++;
		}
    }

    /***********************************************************************/
    // Eliminar la frase de la posici�n dada por "indice".
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
	// Inserta la frase "valor_nuevo" en la posici�n "pos_insercion".
    // Realiza un desplazamiento de todos los valores desde la posici�n 
	// "pos_insercion".
    // PRE: 0 <= pos_insercion <= total_utilizados
    // PRE: total_utilizados < TAMANIO
    
    void Inserta(int pos_insercion, Frase valor_nuevo)
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
	// Nos devuelve un string con todas las frases del objeto
    
    string ToString(void){
    	string cadena;
    	for(int i = 0; i < total_utilizados; i++){
    		cadena = cadena + vector_privado[i].ToString();
    		cadena += ".";
		}
    	return cadena;
	}
	
};
int main (void)
{
	//Las palabras que tenemos
	Palabra primera, segunda, tercera, cuarta;
	
	//Creamos unas palabras
	primera.Aniade('H');
	primera.Aniade('o');
	primera.Aniade('l');
	primera.Aniade('a');
	
	segunda.Aniade('J');
	segunda.Aniade('u');
	segunda.Aniade(' ');
	segunda.Aniade('a');
	segunda.Aniade('n');
	
	Frase frase1,frase2;
	
	//Las aniadimos en la frase
	frase1.Aniade(primera);
	frase1.Aniade(segunda);
	
	tercera.Aniade('Q');
	tercera.Aniade('u');
	tercera.Aniade('e');
	
	cuarta.Aniade('t');
	cuarta.Aniade('a');
	cuarta.Aniade('l');
	cuarta.Aniade('?');

	frase2.Aniade(tercera);
	frase2.Aniade(cuarta);
	
	Parrafo parrafo;
	//Aniadimos las frases al parrafo
	parrafo.Aniade(frase1);
	parrafo.Aniade(frase2);

	//mostramos la frase
	cout << "La frase es:" << parrafo.ToString();

	return (0);
}

/***************************************************************************/
