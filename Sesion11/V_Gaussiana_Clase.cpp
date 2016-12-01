/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÃ“N
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*

    Hemos creado la clase Gaussiana cuyos datos publicos son esperanza y 
	desviacion y los metodos de la clase son Gauss y CDF calculando cada uno
	lo que indican.
	
    Entradas: desviacion, esperanza y x
    Salidas:  cdf y el valor de y
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Clase gaussiana
class Gaussiana
{
	private:
		double esperanza;
		double desviacion;
	
	
	public: 
	
	//Seteamos los valores de la esperanza y la desviacion
	void SetEsperanza(double gaussiana_esperanza){
		esperanza = gaussiana_esperanza;
	}
	
	void SetDesviacion(double gaussiana_desviacion){
		if(gaussiana_desviacion > 0)
			desviacion = gaussiana_desviacion;
	}
	
	
	
	/***************************************************************************/
	// Calcula el valor de g(x) donde g -> N (esperanza, desviacion)
	//
	// Entradas: 
	//		x: valor de la abscisa o término independiente
	//		esperanza: parámetro de la gaussiana --> media 
	//		desviacion: parámetro de la gaussiana --> desviación típica
	// 
	// Devuelve: 
	//		g(x), ordenada o término dependiente
	
	double CalcularGauss (double x)
	{
		const double PI = 3.14159265358979323846; 
	
		return (exp (-0.5 * pow ((x - esperanza)/desviacion, 2)) / 
			        (desviacion * sqrt(2*PI)));
	}
	
	
	/***************************************************************************/
	// Calcula CDF (x) = Integral_{-infty}^{x} {g(x) d(x)}
	// donde g -> N (esperanza, desviacion)
	//
	// Entradas: 
	//		x: valor de la abscisa o término independiente
	//		esperanza: parámetro de la gaussiana --> media 
	//		desviacion: parámetro de la gaussiana --> desviación típica
	// 
	// Devuelve: 
	//		CDF (x) = Integral_{-infty}^{x} {g(x) d(x)}
	
	double CalcularCDF (double x)
	{
			const double B0 =  0.231641900;
			const double B1 =  0.319381530;
			const double B2 = -0.356563782;
			const double B3 =  1.781477937;
			const double B4 = -1.821255978;
			const double B5 =  1.330274429;
	
			double t = 1.0 / (1 + B0*fabs(x));
			double t2 = t*t;
			double t3 = t2*t; // t*t*t
			double t4 = t3*t; // t*t*t*t
			double t5 = t4*t; // t*t*t*t*t
	
			double gauss_x =  CalcularGauss(fabs(x));
			double w =  1.0 - gauss_x * (B1*t + B2*t2 + B3*t3 + B4*t4 + B5*t5);
		
			return (x>=0.0 ? w : 1.0 - w);
	}	
};
 
/***************************************************************************/

int main (void)
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

	double desviacion, esperanza;
	double x; // Entrada
	double y;	// Salida
	double cdf;	// Salida
   	Gaussiana f_gaussiana;
   
	// Lectura
	
	cout << "Parametros de la gaussiana." << endl;
	cout << "\tEsperanza = ";
	cin >> esperanza;
	f_gaussiana.SetEsperanza(esperanza);
	
	
	do {
		cout << "\tDesviacion tipica = ";
		cin >> desviacion;
	} while (desviacion<=0);
	f_gaussiana.SetDesviacion(desviacion);
	
	cout << endl;
	cout << "Valor de la abscisa: ";
	cin >> x;

	// Cálculos

	y = f_gaussiana.CalcularGauss(x);
	cdf = f_gaussiana.CalcularCDF(x);

	// Presentación de resultados

	cout << endl << endl;
	cout << "El valor de la funcion gaussiana en "
		 << setw(10) << setprecision(7) << x << " es " 
		 << setw(10) << setprecision(7) << y << endl;
	cout << "El valor de CDF(" << setw(10) << setprecision(7) << x << ") es " 
		 << setw(10) << setprecision(7) << cdf;
	cout << endl;
	
	return(0);
}
 
