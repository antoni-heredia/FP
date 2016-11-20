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
	
	El programa guarda en una matriz las ventas de cada producto en las distintas
	sucursales. Para ello tenemos una matriz, donde la casilla matriz(s,p) muestra
	la cantidad de productos 'p' que se ha vendido en la sucursal 'a'
	
	Tambien tenemos dos vectores que son con los que mostramos los datos, uno es 
	ventas_sucursal que son el total de ventas de las sucursales y otro que es
	ventas_producto que es el total de ventas de un producto en concreto
	
	Entrada: codigo sucursal, codigo producto, cantidad
	Salida: total de unidades vendidas por cada producto, producto mas vendido,
			cantidad de productos diferente vendidos y el total de unidades en 
			todas las sucursales
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S

using namespace std;


int main() // Programa Principal
{
	//Tama�o para las filas y columnas de la matriz ventas y ademas
	// para los vectores 
	const int CANT_SUCURSALES = 100;
	const int CANT_PRODUCTOS = 'k';

	int ventas[CANT_SUCURSALES][CANT_PRODUCTOS];;
	int ventas_sucursal[CANT_SUCURSALES];
	int ventas_producto[CANT_PRODUCTOS];
	
	//Ponemos todos los elementos de los arrays a 0
	for(int i = 0; i < CANT_SUCURSALES; i++){
		ventas_sucursal[i];
		for(int x = 0; x < CANT_PRODUCTOS; x++){
			ventas_producto[x];
			ventas[i][x] = 0;
		}
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
		    	//Guardamos cada dato donde corresponde
				ventas[cod][producto] += unidades;
				ventas_sucursal[cod] += unidades;
				ventas_producto[producto] += unidades;

		}	
	//Se ejecuta mientas que el usuario no introduzca -1
	}while(cod != -1);
	
	cout << endl << "Resumen de datos" << endl << endl;
	
	//Declaramos las variables que usamos para el resumen de datos
	char producto_mas_vendido;
	int mayor_numero_ventas = 0;
	int diferentes_productos = 0;
	int total_productos_vendidos = 0;
	
	//Recorremos solo el vector ventas_producto que con el podemos realizar el resumen de 
	//todos los datos
	for(int x = 'a'; x < CANT_PRODUCTOS; x++){
		if(ventas_producto[x] != 0){
			/*
				Como entramos aqui es que se ha vendido un producto diferente y por eso
				sumamos uno en diferentes_productos
				
				Ademas el total_productos_vendidos se le tiene que sumar las ventas de 
				este producto en concreto 
			*/
			diferentes_productos++;
			total_productos_vendidos += ventas_producto[x];
			//El producto que estamos recorriendo en este caso tiene el valor int de la x
			producto = x;
			
			//Mostramos la cantidad de ventas de un determinado producto
			cout << "Del producto " << producto << " se han vendido " << ventas_producto[x] 
				 << " unidades" << endl;
				 
			//Si es el producto con mas ventas
			if(mayor_numero_ventas < ventas_producto[x])
				producto_mas_vendido  = producto;
		}
	}
	
	//mostramos el resumen de datos
	cout << endl << "El producto mas vendido es: " << producto_mas_vendido << endl;
	cout << endl << "Se han vendido " << diferentes_productos << " productos diferentes" << endl;
	cout << endl << "El total de productos vendidos es " << total_productos_vendidos << endl;

	return(0);
}
