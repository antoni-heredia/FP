/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
	
    Entradas: millas iniciales, aumento y disminucion
    Salidas:  millas y kilometros
*/
/***************************************************************************/

#include <iostream>
using namespace std;
class Fibbonnaci
{
	private:
	
		static const int TAMANIO = 500; 
		int elementos[TAMANIO];
		
		int n,k,tope;
	public:
		Fibbonnaci(int n_intr){
			n = n_intr;
			elementos[0] = 1;
			elementos[1] = 1;
			tope = 2;
		}
		
		int GetOrden(){
			return n;
		}
		
		void CalculaPrimeros(int k_intr){
			tope = k_intr;
			for(int x = 2; x < tope; x++){
				int numero_x = 0;
				int y_introducir;
				
				if(x<n)
					y_introducir = 0;
				else
					y_introducir = x-n;
				
				for(int y = y_introducir; y < x; y++){
					numero_x += elementos[y];
				}
				elementos[x] = numero_x;
			}
		}
		
		int TotalCalculados(){
			return tope;
		}
};
/***************************************************************************/

int main (void)
{
	return(0);
}
