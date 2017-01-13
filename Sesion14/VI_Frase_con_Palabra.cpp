/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
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
	static const int TAMANIO = 50; // Núm.casillas disponibles
    char vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<=TAMANIO

    int total_utilizados; // Núm.casillas ocupadas
public:
	/***********************************************************************/
    // Constructor sin argumentos

    Palabra (void) : total_utilizados (0)
    {}

    /***********************************************************************/
    // Devuelve el número de casillas ocupadas

    int Longitud (void)
    {
        return (total_utilizados);
    }

    /***********************************************************************/
    // Devuelve el número de casillas disponibles

    int Capacidad (void)
    {
        return (TAMANIO);
    }

    /***********************************************************************/
    // Añade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // PRE: nuevo != ' '
    // 		La adición se realiza si hay alguna casilla disponible.
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
    // Eliminar el carácter de la posición dada por "indice".
    // Realiza un borrado físico (desplazamiento y sustitución).
    // PRE: 0 <= indice < total_utilizados

    void Elimina (int indice)
    {
        if ((indice >= 0) && (indice < total_utilizados)) {

            int tope = total_utilizados-1; // posic. del último

            for (int i = indice ; i < tope ; i++)
                vector_privado[i] = vector_privado[i+1];

            total_utilizados--;
        }
    }


    /***********************************************************************/
	// Inserta el carácter "valor_nuevo" en la posición "pos_insercion".
    // Realiza un desplazamiento de todos los valores desde la posición 
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
    // Compone un string con todos los caracteres que están
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
	static const int TAMANIO = 50; // Núm.casillas disponibles
    Palabra vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<=TAMANIO

    int total_utilizados; // Núm.casillas ocupadas
public:
	
	int NumeroPalabras(){
		
	}
	
	/***********************************************************************/
    // Añade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // PRE: nuevo != ' '
    // 		La adición se realiza si hay alguna casilla disponible.
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
    // Eliminar la palabra de la posición dada por "indice".
    // Realiza un borrado físico (desplazamiento y sustitución).
    // PRE: 0 <= indice < total_utilizados

    void Elimina (int indice)
    {
        if ((indice >= 0) && (indice < total_utilizados)) {

            int tope = total_utilizados-1; // posic. del último

            for (int i = indice ; i < tope ; i++)
                vector_privado[i] = vector_privado[i+1];

            total_utilizados--;
        }
    }


    /***********************************************************************/
	// Inserta  la palabra "valor_nuevo" en la posición "pos_insercion".
    // Realiza un desplazamiento de todos los valores desde la posición 
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
	
	//Añadimos letras a las palabras
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
	
	//Añadimos las palabras a la frase
	frase.Aniade(primera);
	frase.Aniade(segunda);
	
	//Mostramos la frase
	cout << "La frase es: " << frase.ToString();

	return (0);
}

/***************************************************************************/

