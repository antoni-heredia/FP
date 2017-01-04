/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*	


*/
/***************************************************************************/

#include <iostream>
#include <cctype>
using namespace std;



/////////////////////////////////////////////////////////////////////////////

class SecuenciaCaracteres {

private:

    static const int TAMANIO = 50; // Núm.casillas disponibles
    char vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<=TAMANIO

    int total_utilizados; // Núm.casillas ocupadas

public:

    /***********************************************************************/
    // Constructor sin argumentos

    SecuenciaCaracteres (void) : total_utilizados (0)
    {}

    /***********************************************************************/
    // Devuelve el número de casillas ocupadas

    int TotalUtilizados (void)
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
    // 		La adición se realiza si hay alguna casilla disponible.
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
		    (total_utilizados < TAMANIO) ) {
		    	
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
        string cadena = "|";

        for (int i=0; i<total_utilizados; i++)
            cadena = cadena + vector_privado[i];
		cadena += "|";
		
        return (cadena);
    }
    
   /***********************************************************************/
	void InsertaSecuenciaCaracteres(int pos_insercion, 
	SecuenciaCaracteres nueva){
		if ((pos_insercion >= 0) && (pos_insercion <= total_utilizados) && 
		    (total_utilizados+nueva.TotalUtilizados()< TAMANIO) ) {
		    	
		    for (int i = total_utilizados+nueva.TotalUtilizados() ; i>pos_insercion ; i--)
                vector_privado[i] = vector_privado[i-nueva.TotalUtilizados()];
          	
		    for (int i = 0; i < nueva.TotalUtilizados();i++){
            	vector_privado[pos_insercion] = nueva.Elemento(i);
            	pos_insercion++;
			}
			total_utilizados+=nueva.TotalUtilizados();
		}
	}
};

/***************************************************************************/

int main (void)
{

	SecuenciaCaracteres sec_c;
	SecuenciaCaracteres sec_aniade;
	// Añadir datos a la secuencia de caracteres

	sec_c.Aniade('o');
	sec_c.Aniade('a');
	sec_c.Aniade('a');
	sec_c.Aniade('f');
	sec_c.Aniade('p');
	sec_c.Aniade('f');
	
	sec_aniade.Aniade('o');
	sec_aniade.Aniade('o');
	sec_aniade.Aniade('b');
	

	// Mostrar el contenido de la secuencia
	
	cout  << "Secuencia original: " << sec_c.ToString() << endl;
	cout  << "Tiene " << sec_c.TotalUtilizados() << " elementos." << endl;
	cout << endl;
	
	
	sec_c.InsertaSecuenciaCaracteres(1,sec_aniade);

	// Mostrar el contenido de la secuencia una vez eliminados 
	cout  << "Secuencia eliminado los repetidos: " << sec_c.ToString() << endl;
	cout  << "Tiene " << sec_c.TotalUtilizados() << " elementos." << endl;
	cout << endl;


	return (0);
}

/***************************************************************************/

