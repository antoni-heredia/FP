/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// Fundamentos de programacion Grupo B2
//
//
/* 
	
*/
/***************************************************************************/


#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

/***************************************************************************/

const double PI = 3.1415926;

/***************************************************************************/
// Función global (asociada a la constante PRECISION_SON_IGUALES) que
// permite que dos números reales muy próximos sean considerados iguales.

const double PRECISION_SON_IGUALES = 1e-6; // 0.000001

bool SonIguales(double uno, double otro)
{
	return (fabs(uno-otro) <= PRECISION_SON_IGUALES);
}


/////////////////////////////////////////////////////////////////////////////

class Punto2D
{
private:

	// La pareja (x,y) son las coordenadas de un punto en un espacio 2D
	double x = 0;
	double y = 0;

public:

	/***********************************************************************/
	// Constructor sin argumentos.

	Punto2D (void)
	{ }

	/***********************************************************************/
	// Constructor con argumentos.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada,
	// respectivamente del punto que se está creando.

	Punto2D (double abscisaPunto, double ordenadaPunto)
	{
		SetCoordenadas (abscisaPunto, ordenadaPunto);
	}

	/***********************************************************************/
	// Método Set para fijar simultaneamente las coordenadas.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada,
	// respectivamente del punto que se está modificando.

	void SetCoordenadas (double abscisaPunto, double ordenadaPunto)
	{
		x = abscisaPunto;
		y = ordenadaPunto;
	}

	/***********************************************************************/
	// Métodos Get para leer las coordenadas

	double GetX (void)
	{
		return (x);
	}
	double GetY (void)
	{
		return (y);
	}

	/***********************************************************************/
	// Calcula si dos puntos son iguales
	//
	// Recibe: otro, el punto que se quiere comparar con el objeto implícito.
	// Devuelve: true, si se consideran iguales los dos objetos.

	bool EsIgual (Punto2D otro)
	{
		return (SonIguales(x,otro.x) && SonIguales(y,otro.y));
	}

	/***********************************************************************/
	// Calcula la distancia Euclídea del punto (objeto implícito) a otro que
	// se recibe como argumento.
	//
	// Recibe: otro, el punto respecto al cual que se quiere calcular la
	// distancia euclídea.
	// Devuelve: la distancia entre los dos puntos.

	double DistanciaEuclidea (Punto2D otro)
	{
		double dif_x = pow (x - otro.x, 2);
		double dif_y = pow (y - otro.y, 2);

		return (sqrt(dif_x + dif_y));
	}

	/***********************************************************************/
	
	string ToString ()
	{
		return ("["+to_string(x)+", "+to_string(y)+"]");
	}
	
	/***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////
class ColeccionPuntos2D{

private:
	static const int TAMANIO = 50; // Num casillas disponibles
    Punto2D vector_privado[TAMANIO];

    // PRE: 0<=total_utilizados<=TAMANIO

    int total_utilizados; // Num casillas ocupadas

public:
	
	//constructor sin argumentos
	ColeccionPuntos2D(void) : total_utilizados(0)
	{}
		
	/***********************************************************************/
    // Devuelve el nÃºmero de casillas ocupadas

    int TotalUtilizados (void)
    {
        return (total_utilizados);
    }

    /***********************************************************************/
    // Devuelve el nÃºmero de casillas disponibles

    int Capacidad (void)
    {
        return (TAMANIO);
    }
	
    /***********************************************************************/
    // Aniade un punto a la coleccion    
   	void Aniade(Punto2D punto){
   		
   		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = punto;
			total_utilizados++;
		}
	}
	
	/***********************************************************************/
	//Devuelve un elemento dado un indice
	
	Punto2D Elemento(int indice){
		return vector_privado[indice];
	}
	
    /***********************************************************************/
    // Elimina un punto de la coleccion dado un indice
    
    //Prec: -1 < indice < TAMANIO 
    void Elimina(int indice){
 	    if ((indice >= 0) && (indice < total_utilizados)) {
    		int tope = total_utilizados-1;
    		for(int i = indice; i < total_utilizados; i++)
    			vector_privado[i] = vector_privado[i+1];
    		total_utilizados--;
		}
	}

};

class Circunferencia{
	
private:
	
	Punto2D centro;
	
	double radio;
	
public:
	
	//Constructor 
	Circunferencia(Punto2D punto, double r) :
		centro(punto),radio(r)
		{}
	
	//Nos devuelve el radio de la circunferencia
	double Radio(void){
		return radio;
	}
	
	//Nos devuelve el centro de la circunferencia
	Punto2D Centro(void){
		return centro;
	}
	
	
	//Nos dice si un punto esta dentro del circulo
	bool PuntoInterior(Punto2D punto){
		return (centro.DistanciaEuclidea(punto) <= radio);
	}
};

int main(void){
	
	// Pertenencia a una recta (2)   
	const int TAM_CAD = 100;
	Punto2D p; // Cada uno de los puntos que se comprobarán
	ColeccionPuntos2D coleccion;
	string cadena; // Para leer coordenada (usando un string)   
	double x,y; 
	
	
	 
	
	// Lectura adelantada             
	
	cout << endl;   
	cout << "Introdzca coordenada x: ";   
	getline (cin, cadena);       
	
	while (cadena != "FIN") {               
	    x = stof(cadena); // string --> double               
	    cout << "Introdzca coordenada y: ";       
	
	    getline (cin, cadena);               
	
	    y = stof (cadena);  // string --> double               
		
		p.SetCoordenadas(x,y);
	 
		coleccion.Aniade(p);
	    // Nueva lectura                
	    cout << endl;
	    cout << "Introdzca coordenada x: ";
	    getline (cin, cadena);     
	} // while (cadena != "FIN"

	//Pedimos los datos para el objeto circunferencia
	double radio;
	Punto2D centro;
	cout << "Datos de la circunferencia: " << endl;
	
	cout << "\t Radio: ";
	getline(cin,cadena);
	radio = stof (cadena);
	
	cout << "\t Centro x: ";
	getline(cin,cadena);
	x = stof (cadena);
	
	cout << "\t Centro y: ";
	getline(cin,cadena);
	y = stof (cadena);
	
	centro.SetCoordenadas(x,y);
	
	//Creamos el objeto circunferencia
	Circunferencia circunferencia(centro, radio);
	
	cout << endl;
	//Recorremos los puntos de la coleccion viendo si estan dentro de la 
	//circunferencia
	for(int i = 0; i < coleccion.TotalUtilizados(); i++){
		if(circunferencia.PuntoInterior(coleccion.Elemento(i)))
			cout << "El punto " << coleccion.Elemento(i).ToString() 
			     << " esta en la circunferencia" << endl;
	}
	
}
