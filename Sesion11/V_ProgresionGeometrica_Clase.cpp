/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*

    
	
    Entradas: desviacion, esperanza y x
    Salidas:  cdf y el valor de y
*/
/***************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
class Geometrica
{
	private:
	
	double ai, r;
	
	public:
		//Metodos para setear los datos privados
		void SetInicio(double geo_ai){
			ai = geo_ai;
		}
		
		void SetRazon(double geo_razon){
			r = geo_razon;
		}
		
		//Metodos que nos devuelven valores
		double Terminio(int k){
			//Realizamos la suma usando un for para calcular todos los ai hasta
			//que llegamos a k
			for(int x=1; x <= k; x++){
				ai *= r;
			}
			return ai;
		}
		
		double SumaHasta(int k)
		{
			//Realizamos la suma usando un for para calcular todos los ai y sumarlos
			double suma = 0;
			for(int x=1; x <= k; x++){
				suma += ai;
				ai *= r;
			}
			return suma;
		}
		
		//Si el valor absoluto de la razon es menor que cero se calcula la suma
		//si no se devuelve -1 como si fuera un error
		double SumaHastaInfinito(){
			double suma = 0;

			if( abs(r) > 0 && abs(r) < 1 )
				suma = ai/(1-r);
			else
				suma = -1;
				
			return suma;
			
		}
		
		double MultiplicarHasta(int k){
			double ak = Terminio(k);
			
			return sqrt(pow(ai*ak,k));
			
		}
};

 
/***************************************************************************/

int main (void)
{
	Geometrica geo;
	double ai,r,k;
	//Leemos los datos de entrada
	cout << "Por favor introduzca un ai: ";
    cin >> ai;
    geo.SetInicio(ai);
    
   	cout << "Por favor introduzca un r: ";
    cin >> r;
    geo.SetRazon(r);
    
    cout << "Por favor introduzca un k: ";
    cin >> k;
    
    double termino,suma_hasta,suma_infinito, multiplica_hasta;
    
    termino = geo.Terminio(k); 
    cout << endl << "El termino " << k << " es: " << termino << endl;
    
    suma_hasta = geo.SumaHasta(k);
    cout << "La suma hasta el termino " << k << " es: " << suma_hasta << endl;
    
	suma_infinito = geo.SumaHastaInfinito();
	if(suma_infinito == -1)
		cout << "La suma hasta el infinito no se ha podido realizar." << endl;
	else
		cout << "La suma hasta el infinito es: " << suma_infinito << endl;	
	
	
	multiplica_hasta = geo.MultiplicarHasta(k);
	cout << "La multiplicacion hasta el termino " << k << " es: " << multiplica_hasta 
		 << endl;

	
	return(0);
}
 
