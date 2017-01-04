/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*	
	Se amplía la clase SecuenciaCaracteres con los métodos 
	
		bool ExisteCaracter(char caracter)
	que nos dice si un caracter existe en la secuencia y con
	
		void EliminaRepetidos_SecuenciaLocal(){
	que nos eiminia los caracteres que hay repetidos en la secuencia

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
	// Nos devuelve sin un caracter existe en la secuencia o no
    // Recorre todos los elementos del vector privado
	// una vez encuentre una coincidencia para el while y nos devuelve que
    // true, en caso contrario devolvera false
    
	bool ExisteCaracter(char caracter){
		int i = 0;
		bool existe = false;
		
		while (i<total_utilizados && !existe){
			if(vector_privado[i] ==  caracter)
				existe = !existe;
			i++;
		}
		
		return existe;  	
	}

	/***********************************************************************/
	// Elimina los caracteres repetidos del vector_privado usando como
    // dato auxiliar otra secuencia de caracteres.
	// El caracter se añade a la secuencia auxiliar si este no existe en la
	// misma. Una vez añadidos todos, copiamos los datos en esta secuencia
    // y el total_utilizados pasa a ser el total_utilizados de la secuencia
    //auxiliar
    
    void EliminaRepetidos_SecuenciaLocal(){
    	SecuenciaCaracteres secuencia_aux; // Secuencia axuliar
    	
    	secuencia_aux.Aniade(vector_privado[0]);//El primer caracter se añade
		//Recoremos a patir de la segunda posicion
		for(int i = 1; i < total_utilizados;i++){ 
			//SI el caracter no exist en la secuencia axuiliar se aniade
			if(!secuencia_aux.ExisteCaracter(vector_privado[i]))
				secuencia_aux.Aniade(vector_privado[i]);
		}
		
		//El total de caracteres no repetidos es la cantidad añadida en la
		//secuencia auxiliar
		total_utilizados = secuencia_aux.TotalUtilizados();
		
		//Copiamos la secuencia axuilar en esta secuencia
		for(int i = 0; i < total_utilizados;i++){
			vector_privado[i] = secuencia_aux.Elemento(i);
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
 
};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/

int main (void)
{

	SecuenciaCaracteres sec;

	// Añadir datos al vector

	sec.Aniade('o');
	sec.Aniade('a');
	sec.Aniade('a');
	sec.Aniade('f');
	sec.Aniade('f');
	sec.Aniade('p');

	// Mostrar el contenido de la secuencia
	
	cout  << "Secuencia original: " << sec.ToString() << endl;
	cout  << "Tiene " << sec.TotalUtilizados() << " elementos." << endl;
	cout << endl;
	
	
	//Eliminamos los caracteres repetidos
	sec.EliminaRepetidos_SecuenciaLocal();
	
	// Mostrar el contenido de la secuencia una vez eliminados los repetidos
	
	cout  << "Secuencia eliminado los repetidos: " << sec.ToString() << endl;
	cout  << "Tiene " << sec.TotalUtilizados() << " elementos." << endl;
	cout << endl;


	return (0);
}

/***************************************************************************/

