/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// Fundamentos de programacion Grupo B@
//
//
/*	

*/
/***************************************************************************/


#include <iostream>
#include <iomanip>
#include <string>
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

class RLE
{ 

// La clase RLE no tiene campos.
// Los objetos de la clase sieven para ejecutar los métodos "Codifica"
// y "Descodifica" (esta implementación se diferencia muy poco de escribir
// los dos métodos como funciones globales).

private: 

public:
	
	/***********************************************************************/
	// Codifica una secuencia de enteros según el código RLE y devuelve 
	// otra secuencia de enteros codificada.
	//
	// Recibe: secuencia_descodificada, la secuencia que se va a codificar.
	// Devuelve: una nueva secuencia, resultado de codificar según RLE 
	// la secuencia recibida "secuencia_descodificada". 
	
	SecuenciaParejas_ValorFrecuencia Codifica (SecuenciaParejas_ValorFrecuencia secuencia_descodificada)
	{
		// Secuencia resultado de la codificación
		SecuenciaParejas_ValorFrecuencia secuencia_codificada; 

		int tope, actual, anterior, iguales_hasta_ahora;

		// Registrar la longitud de la secuencia
		tope = secuencia_descodificada.TotalUtilizados();

		// Guardar el primer valor de la secuencia
		actual = secuencia_descodificada.Elemento(0).valor;

		iguales_hasta_ahora = secuencia_descodificada.Elemento(0).frecuencia;

		for (int pos=1; pos<tope; pos++) {

			anterior = actual;
			actual = secuencia_descodificada.Elemento(pos).valor;

			if (anterior == actual)

				iguales_hasta_ahora += secuencia_descodificada.Elemento(pos).frecuencia; // Continua la serie

			else {

				// Añade la pareja (valor, num.repeticiones)
				secuencia_codificada.Aniade(anterior,iguales_hasta_ahora);
				
				iguales_hasta_ahora = secuencia_descodificada.Elemento(pos).frecuencia; // empezar una nueva serie				
			}
		} // for (int pos=1; pos<tope; pos++)

		// Añade la última pareja (valor, num.repeticiones)
		secuencia_codificada.Aniade(actual,iguales_hasta_ahora);

		return (secuencia_codificada); 
	}   

	/***********************************************************************/
	// Descodifica una secuencia de enteros según el código RLE y devuelve 
	// otra secuencia de enteros descodificada.
	//
	// Recibe: secuencia_codificada, la secuencia que se va a descodificar.
	// Devuelve: una nueva secuencia, resultado de descodificar según RLE 
	// la secuencia recibida "secuencia_codificada". 
	
	SecuenciaParejas_ValorFrecuencia Descodifica (SecuenciaParejas_ValorFrecuencia secuencia_codificada)
	{
		// Secuencia resultado de la descodificación
		
		SecuenciaParejas_ValorFrecuencia secuencia_descodificada; 

		// Registrar el número de elementos de la secuencia codificada. 

		int tope = secuencia_codificada.TotalUtilizados();

		// Ciclo que recorre la secuencia codificada. 
		// La longitud de la secuencia es par (está formada por parejas) así 
		// que el número de parejas es justo la mitad del número de elementos. 
		// Observad que el salto se realiza de 2 en 2 porque en cada iteración 
		// se procesa una pareja. 

		for (int pos=0; pos<tope; pos++) {

			int num_repeticiones = secuencia_codificada.Elemento(pos).frecuencia;
			int valor = secuencia_codificada.Elemento(pos).valor;
	
			// Cada pareja es (num_repeticiones, valor). Se trata de escribir
			// "valor" en la secuencia descodificada "num_repeticiones" veces.  

			for (int i=0; i<num_repeticiones; i++) 
				secuencia_descodificada.Aniade(valor,1);
		}
		
		return (secuencia_descodificada);
	}

	/***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/

int main (void)
{


	SecuenciaParejas_ValorFrecuencia secuencia_original; // Vector a codificar 


	secuencia_original.Aniade('a',3);
	secuencia_original.Aniade('a',1);
	secuencia_original.Aniade('b',4);
	secuencia_original.Aniade('b',2);
	secuencia_original.Aniade('c',1);

	// Se muestra el vector original 

	cout << endl;
	cout << "Secuencia original:" << endl;

	int tope = secuencia_original.TotalUtilizados();

	for (int i=0; i<tope; i++) {
		Pareja_ValorFrecuencia pareja = secuencia_original.Elemento(i);
		cout << pareja.frecuencia << pareja.valor;
	}
	cout << endl << endl;



	// Prueba de los métodos Codifica() y Desodifica() 
	// 
	// Declararemos un objeto de la clase RLE al que llamaremos "gestor_RLE" 
	// que emplearemos para codificar/descodificar una secuencia.

	RLE gestor_RLE; // Objeto codificador/descodificador

	SecuenciaParejas_ValorFrecuencia secuencia_codificada;		// Serie codificada 
	SecuenciaParejas_ValorFrecuencia secuencia_descodificada;	// Serie descodificada

	// Codificación--> gestor_RLE.Codifica() 
	secuencia_codificada = gestor_RLE.Codifica(secuencia_original);

	// Descodificación--> gestor_RLE.Descodifica() 
	secuencia_descodificada = gestor_RLE.Descodifica(secuencia_codificada);


	// Presentación de resultados

	// Secuencia codificada 

	cout << endl;
	cout << "Secuencia codificada:";
	cout << endl;

	tope = secuencia_codificada.TotalUtilizados();


	for (int i=0; i<tope; i++) {
		Pareja_ValorFrecuencia pareja = secuencia_codificada.Elemento(i);
		cout << pareja.frecuencia << pareja.valor;
	}
	cout << endl << endl;
	cout << endl << endl;


	// Secuencia descodificada 

	cout << endl;
	cout << "Secuencia descodificada:";
	cout << endl;

	tope = secuencia_descodificada.TotalUtilizados();


	for (int i=0; i<tope; i++) {
		Pareja_ValorFrecuencia pareja = secuencia_descodificada.Elemento(i);
		cout << pareja.frecuencia << pareja.valor;

	}
	cout << endl << endl;


	return (0);
}
