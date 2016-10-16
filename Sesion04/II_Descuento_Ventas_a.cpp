/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   El programa pedira que se introduzca una cantidad de productos y un precio
   por unidad. Y segun una cantidad o un precio total se tiene un descuento 
   u otro

   Entrada: precio, unidades.
   Salida:  precio_total
*/
/***************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std;

int main() // Programa Principal
{
    //Declaramos las variables de entrada
    double precio;
    int unidades;

    //Declaramos las variables de salida
    double precio_total;

    //Declaro las constantes de los descuentos
    const double DESCUENTO_CANTIDAD = 0.03;
    const double DESCUENTO_PRECIO_TOTAL = 0.02;


    //Uso esta variable por si en algun momento queremos meter algun descuento
    //siempre, sin necesidad  de un nº de uniades minimas o de precio
    double descuento_total = 0;
    //Pedimos al usuario que introduzca los datos

    cout << "Por favor introduzca las unidades del articulo que comprara: ";
    cin >> unidades;

    cout << "Por favor introduzca el precio por unidad: ";
    cin >> precio;

    //Calculamos el precio total antes de descuentos
    precio_total = precio*unidades;

    /*
        Vemos si se puede aplicar el descuento por unidad y el descuento por
        precio. Y como son acumulables se le suma al descuento total.
    */
    if( unidades > 100 )
        descuento_total = descuento_total+DESCUENTO_CANTIDAD;



    if( precio_total > 700 )
        descuento_total = descuento_total+DESCUENTO_PRECIO_TOTAL;


    //Calculamos el precio una vez aplicados los descuentos
    precio_total = precio_total - precio_total*descuento_total;

    //Mostramos al cliente el precio
    cout << "El precio del producto una vez aplicados los descuentos es: ";
    cout << endl << precio_total << "€";

    cout << endl << "El descuento total fue de: " << descuento_total*100 <<
         "%";
    return(0);
}

