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
	Este ejercicio contiene las clase Punto, triangulo y rectanglo.
	
	Cada uno de las clases contiene los metodos pedidos en el enunciado del
	ejercicio
	
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
class Triangulo{
	
private:
	//Definimos el triangulo por sus tres vertices
	Punto2D vertice_a, vertice_b, vertice_c;
public:	

	//El contructor recibe sus tres vertices
	Triangulo(Punto2D a, Punto2D b, Punto2D c){
		vertice_a = a;
		vertice_b = b;
		vertice_c = c;
	}
	
	//Metodo que nos devuelve  el perimetro del triangulo	
	double Perimetro(){
		return vertice_a.DistanciaEuclidea(vertice_b)+vertice_b.DistanciaEuclidea(vertice_c)+
				vertice_c.DistanciaEuclidea(vertice_a);
	}
	
	//Metodo que nos dice si el triangulo es rectangulo
	bool EsRectangulo(){
		return ((vertice_a.GetX() == vertice_b.GetX() && vertice_a.GetY() == vertice_c.GetY()) ||
			   (vertice_b.GetX() == vertice_c.GetX() && vertice_b.GetY() == vertice_c.GetY()) ||
			   (vertice_c.GetX() == vertice_a.GetX() && vertice_c.GetY() == vertice_b.GetY()));
	}
};
/////////////////////////////////////////////////////////////////////////////
class Rectangulo{
	
private:
	//Definimos el rectangulo por su cuatro vertices
	Punto2D iz_inf, iz_sup, der_inf, der_sup;

public:	

	//Contructor con sus cuatro vertices
	Rectangulo(Punto2D iz_inf_in, Punto2D iz_sup_in, Punto2D der_inf_in
			  ,Punto2D der_sup_in){
		
		//si se cumplen las premisas del enunciado se ponen los vertices	  	
		if(iz_inf_in.GetY() == der_inf_in.GetY() && 
		   iz_sup_in.GetY() == der_sup_in.GetY() &&
		   iz_inf_in.GetX() == iz_sup_in.GetX() && 
		   der_inf_in.GetX() == der_sup_in.GetX()){
			
			iz_inf = iz_inf_in;
			iz_sup = iz_sup_in;
			der_inf = der_inf_in;
			der_sup = der_sup_in;   	
		}	  	
	}
	
	//Nos devuelve la longitud de la base
	double LongitudBase(){
		return der_inf.GetX()-iz_inf.GetX(); 
	}
	
	//Nos devuelve la longitud de la altura
	double LongitudAltura(){
		return iz_sup.GetY()-iz_inf.GetY();
	}
	
	//Nos devuelve la longitud el area
	double CalcularArea(){
		 return LongitudAltura()*LongitudBase();
	}
	
	//Calcula el perimetro
	double CalcularPerimetro(){
		return 2*LongitudAltura()+2*LongitudBase();
	}
	
	
	//Nos dice si un punto esta dentro
	bool EstaDentro(Punto2D punto){
		return (punto.GetX()>iz_sup.GetX() && punto.GetX()<der_inf.GetX() &&
		 	    punto.GetY()<der_sup.GetY() && punto.GetY() > der_inf.GetY());
	}
	
	//Nos devuelve el triangulo inferior
	Triangulo TrianguloInferior(){
		Punto2D a,b,c;
		a = iz_sup;
		b = iz_inf;
		c = der_inf;
		Triangulo triangulo (a,b,c);
		return triangulo;	
	}
	
	//Nos devuelve el triangulo superior
	Triangulo TrianguloSuperior(){
		Punto2D a,b,c;
		a = der_sup;
		b = der_inf;
		c = iz_sup;
		Triangulo triangulo (a,b,c);
		return triangulo;	
	}
};

int main(void){
	
	
}
