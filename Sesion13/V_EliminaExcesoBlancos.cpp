/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÃ“N
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2

// RELACIÓN DE PROBLEMAS 5
// EJERCICIO 21
//
/*	
	En este ejercico amplía la clase SecuenciaCaracteres con el método:
	
		void EliminaEspacios (void) 
		
	para ver si la secuencia es un palindromo

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

    // PRE: 0<=total_utilizados<TAMANIO

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
	//Elimina los espacios consecutivos
	//Cuando hay varios espacios seguidos, deja solamente uno
	
	void EliminaEspacios(void){
		
		//El vector donde guardamos  los caractereres que no son mayusculas
		char sin_espacios[TAMANIO];
		//El contador de los caracteres que no son mayuscula
		int contador = 0;
		
		bool anterior_espacio = false;
		//Recorremos el vector_privado
		for(int i = 0; i <total_utilizados; i++){
			//Comprobamos si si no es un espacio
			//en cuyo caso lo unico que hacemos es guardarlo y ya esta			
			if(vector_privado[i] != ' '){
					sin_espacios[contador] = vector_privado[i];
					contador++;
					anterior_espacio = false;
			}else{
				//Si es un espacio comprobamos que el anterior no lo era
				if(!anterior_espacio){
					//En este caso metemos el espacio 
					sin_espacios[contador] = vector_privado[i];
					contador++;
				}
				//Si no no hacemos nada
				
				//En cualquier caso decimos que es un espacio
				anterior_espacio = true;
			}
		}
		
		//El total de utilizados ahora es la cantidad de minusculas
		total_utilizados = contador;
		//Guardamos el vector sin_mayusculas en el vector privado
		for(int i = 0; i <total_utilizados; i++){
			vector_privado[i] = sin_espacios[i];
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
		
		//Añadimos el caracter al vector
		sec.Aniade(caracter);
		//ignoramos el /n
		cin.ignore();
		
	//Se ejecuta mientras sea distinto de #
	}while(caracter != '#');
	
	//Ignoramos el ultimo elemento que es el #
	sec.Elimina(sec.TotalUtilizados()-1);
	
	//Eliminamos los espacios en blanco
	sec.EliminaEspacios();
	
	//Mostramos la secuencia resultante
	cout << endl << "La cadena eliminando las mayusculas es: " << endl;
	for(int i = 0; i < sec.TotalUtilizados(); i++){
		cout << sec.Elemento(i);
	}
		
	return (0);
}

/***************************************************************************/
