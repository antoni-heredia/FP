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
	
		void EliminaMayusculas (void) 
		
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
	//Elimina las mayusculas de forma eficiente
	
	void EliminaMayusculas(void){
		
		//El vector donde guardamos  los caractereres que no son mayusculas
		char sin_mayusculas[TAMANIO];
		//El contador de los caracteres que no son mayuscula
		int contador_minusculas = 0;
		
		//Recorremos el vector_privado
		for(int i = 0; i <total_utilizados; i++){
			//Comprobamos si no es una mayuscula
			if(vector_privado[i] < 'A' || vector_privado[i] > 'Z'){
				//En caso afirmativo lo a�adimos al vector
				sin_mayusculas[contador_minusculas] = vector_privado[i];
				//Y contamos una minuscula mas
				contador_minusculas++;
			}
		}
		
		//El total de utilizados ahora es la cantidad de minusculas
		total_utilizados = contador_minusculas;
		//Guardamos el vector sin_mayusculas en el vector privado
		for(int i = 0; i <total_utilizados; i++){
			vector_privado[i] = sin_mayusculas[i];
		}
		
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
	
	//Eliminamos las mayusculas
	sec.EliminaMayusculas();
	
	//Mostramos la secuencia resultante
	cout << endl << "La cadena eliminando las mayusculas es: " << endl;
	for(int i = 0; i < sec.TotalUtilizados(); i++){
		cout << sec.Elemento(i);
	}
		
	return (0);
}

/***************************************************************************/
