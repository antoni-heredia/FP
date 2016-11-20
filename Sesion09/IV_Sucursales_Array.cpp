/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
	El programa guarda la cantidad de ventes de las diferentes sucursales 
	de una empresa.
	
	Guarda las ventas en un array. Las ventas de cada sucursal se guardan en la
	posicion del array codigo de empresa - 1 ya que nos aprovechamos de que los
	codigos de empresa van desde el 1 hasta el 100
	
	Luego mostraremos un resumen de datos totales.
	
	Entrada: codigo sucursal, codigo producto, cantidad
	Salida: productos por sucursal, sucursal mas ventas, sucursales con ventas
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S

using namespace std;


int main() // Programa Principal
{
	//La cantidad de sucursales que hay
	int const CANT_SUCURSALES = 100;
	
	//Array para el numero de productos vendidos para cada sucursal
	int num_productos[CANT_SUCURSALES];
	//La cantidad de transacciones(ventas) que se ha realizado
	int cant_transacciones = 0;
	
	//Inializamos todos las ventas a 0
	for(int i = 0; i < CANT_SUCURSALES; i++){
		num_productos[i] = 0;
	}
	
	//Variables para la inserccion de datos
	int cod,unidades;
	char producto;
	cout << "Introducion de datos: " << endl;
	do{
		//Pedimos al usuario que introduzca los datos
		cout << endl << "Introduzca los datos de la venta: ";
		cin >> cod >> producto >>  unidades ;
		producto = tolower(producto);
		//Si los datos cumples los requisitos entramos al if
		if( cod > 0 && cod <= CANT_SUCURSALES && unidades > 0 && producto >= 'a' 
		    && producto <= 'j'){
				cant_transacciones++;
				num_productos[cod-1] += unidades; 
		}	
	//Se ejecuta mientas que el usuario no introduzca -1
	}while(cod != -1);
	
	//Variables para el resumen de datos final
	int sucursal_mas_productos = 0;
	int mayor_numero_productos = 0;
	int total_productos = 0;
	int sucursales_con_ventas = 0;
	
	cout << "--------Resumen de ventas--------" << endl; 
	//Recorremos el array de todas las sucursales
	for(int i = 0; i < CANT_SUCURSALES; i++){
		//Si han hecho alguna venta entramos
		if(num_productos[i] > 0){
			//Sumamos uno en las sucursales con ventas
			sucursales_con_ventas++;
			//Al total de productos vendidos le sumamos los de esta sucursal
			total_productos += num_productos[i];
			//Mostramos los datos de ventas de esta sucursal
			cout << "La sucursal " << i+1 << " ha vendido " << num_productos[i]
				 << " productos." << endl;
			//Si es la sucursal con mas ventas guardamos cual es
			if(num_productos[i] > mayor_numero_productos){
				mayor_numero_productos =  num_productos[i];
				sucursal_mas_productos = i;
			}
		}
	}
	//Mostramos el resumen de datos
	cout << endl << " ............................" << endl;
	cout << "La sucursal con mas productos vendidos es la " 
		 << ++sucursal_mas_productos << endl;
	cout << "La cantidad de sucursales con alguna ventas es " 
	     << sucursales_con_ventas << endl;
	cout << "La cantidad total de productos vendidos es " << total_productos
		 << endl; 
}
