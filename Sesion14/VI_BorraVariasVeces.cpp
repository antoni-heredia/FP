/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*	
	Usamos como base la clase Secuencia de caracteres a la cual le añadimos
	dos metodos:
		BorraUnaPareja(Pareja_ValorFrecuencia pareja);
		Borra(SecuenciaParejas_ValorFrecuencia sec_borra);
	
	Tambien añadimos la clase SecuenciaParejas_ValorFrecuencia la cual
	contiene un vector_privado que tiene datos del tipo Pareja_ValorFrecuencia
	que es un structur que contiene un caracter y el numero de repeticiones

*/
/***************************************************************************/

#include <iostream>
#include <cctype>
using namespace std;


/////////////////////////////////////////////////////////////////////////////

struct Pareja_ValorFrecuencia{
	char valor;
	int frecuencia;
};
class SecuenciaParejas_ValorFrecuencia{
	
private:
    static const int TAMANIO = 50; // Núm.casillas disponibles
  	Pareja_ValorFrecuencia vector_privado[TAMANIO];
    // PRE: 0<=total_utilizados<=TAMANIO
    int total_utilizados; // Núm.casillas ocupadas

public:
	/***********************************************************************/
    // Constructor sin argumentos

    SecuenciaParejas_ValorFrecuencia (void) : total_utilizados (0)
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

    void Aniade (Pareja_ValorFrecuencia nuevo)
    {
        if (total_utilizados < TAMANIO){
            vector_privado[total_utilizados] = nuevo;
            total_utilizados++;
        }
    }
    
    //Sobrecarga del metodo añade para añadir a partir de el valor
    //y la repeticion
    void Aniade (char valor, int repeticion)
    {
    	Pareja_ValorFrecuencia pareja;
    	pareja.valor = valor;
    	pareja.frecuencia = repeticion;
		Aniade(pareja);    
    }
    
    /***********************************************************************/
    // Devuelve el elemento de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados

    Pareja_ValorFrecuencia Elemento (int indice)
    {
        return (vector_privado[indice]);
    }
};

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
	// Borra una cantidad determinada de un caracter.
    // La cantidad de veces que se elimina y el caracter que es viene en el
	// structur Pareja_ValorFrecuencia

    void BorraUnaPareja(Pareja_ValorFrecuencia pareja){
    	//La secuencia auxiliar donde guardamos los caracteres eliminando
    	//los indicados
    	SecuenciaCaracteres sec_aux;
    	//Cantidad de carateres borrados
		int borrados = 0;
		
		for(int x = 0; x < total_utilizados; x++){
			//Si el caracter actual es distinto del inidicado o ya se han 
			//borrado los suficientes caracteres, se añade
			if(vector_privado[x] != pareja.valor 
			   || borrados >= pareja.frecuencia)
			   	sec_aux.Aniade(vector_privado[x]);
			else
				borrados++;
		}
		
		//Copiamos al secuencia auxiliar a la secuencia local
		total_utilizados = sec_aux.TotalUtilizados();
		for(int x = 0; x < total_utilizados;x++)
			vector_privado[x]=sec_aux.Elemento(x);
	}
	
	/***********************************************************************/
	// Borra todas una cantidad determinada de caracteres dada por una 
    // Secuencia de Parejas_ValorFrecuencia
	
    void Borra(SecuenciaParejas_ValorFrecuencia sec_borra){
		
		//Recorremos la secuencia de parejas a borrar
    	for(int i = 0; i < sec_borra.TotalUtilizados(); i++){
	    	//Borramos la pareja que estamos recorriendo actualmente
	    	BorraUnaPareja(sec_borra.Elemento(i););
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

/***************************************************************************/

int main (void)
{

	SecuenciaCaracteres sec_c;
	SecuenciaParejas_ValorFrecuencia sec_p; 
	
	// Añadir datos a la secuencia de caracteres

	sec_c.Aniade('o');
	sec_c.Aniade('a');
	sec_c.Aniade('a');
	sec_c.Aniade('f');
	sec_c.Aniade('p');
	sec_c.Aniade('f');
	
	// Añadir datos a la secuencia de parejas
	sec_p.Aniade('a',2);
	sec_p.Aniade('f',1);

	// Mostrar el contenido de la secuencia
	
	cout  << "Secuencia original: " << sec_c.ToString() << endl;
	cout  << "Tiene " << sec_c.TotalUtilizados() << " elementos." << endl;
	cout << endl;
	
	
	//Eliminamos la cantidad de caracteres que aparece en la secuencia de 
	//parejas
	sec_c.Borra(sec_p);
	
	// Mostrar el contenido de la secuencia una vez eliminados 
	cout  << "Secuencia eliminado los repetidos: " << sec_c.ToString() << endl;
	cout  << "Tiene " << sec_c.TotalUtilizados() << " elementos." << endl;
	cout << endl;


	return (0);
}

/***************************************************************************/

