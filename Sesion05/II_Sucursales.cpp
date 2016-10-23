/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
    El programa leera sucursal producto y ventas
    Devolvera la sucursal con mas ventas
    Iremos guardando la cantidad de ventas de cada sucursal y luego
    comprobaremos que sucursal vendio mas
*/
/***************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
using namespace std;

int main()
{
    //Declararemos las variables que vamos a usar
    double cantidad1=0;
    double cantidad2=0;
    double cantidad3=0;
    double cantidad_entrada;
    int sucursal;
    char producto;

    const int SUCURSAL1 = 1;
    const int SUCURSAL2 = 2;
    const int SUCURSAL3 = 3;

    const char PRODUCTOA = 'a';
    const char PRODUCTOB = 'b';
    const char PRODUCTOC = 'c';

    //Usamos con do while para que al menos pida un dato hasta que sea -1
    do{

        cout << "Por favor introduzca los datos sucursal producto cantidad: ";
        cin  >> sucursal >> producto >> cantidad_entrada;
	//Comprobamos que el producto y la cantidad sean correctas
        if((producto==PRODUCTOA || producto == PRODUCTOB
           || producto == PRODUCTOC) && cantidad_entrada > 0){
	    //Guardamos en cada sucursal la catidad correspondiente
            if( sucursal == SUCURSAL1)
                cantidad1+=cantidad_entrada;
            else if( sucursal == SUCURSAL2)
                cantidad2+=cantidad_entrada;
            else if( sucursal == SUCURSAL3)
                cantidad2+=cantidad_entrada;
            else
                cout << "Sucursal incorrecta" << endl;
	    //Si no existe la sucursal devolvemos un error
        }else
            if(cantidad_entrada <= 0)
                cout << "La cantidad debe ser superior a 0 " << endl;
            else
                cout << "El producto es incorrecto" << endl;
    }while( sucursal != -1);

    int sucursal_mas_ventas;
    cout << "Todos los datos han sido leidos."<<endl;
    //Comprobamos que sucursal ha vendido mas
    if(cantidad1 > cantidad2)
        if(cantidad2>cantidad3)
            sucursal_mas_ventas = SUCURSAL1;
    else
        if(cantidad2>cantidad3)
            sucursal_mas_ventas = SUCURSAL2;
        else
            sucursal_mas_ventas = SUCURSAL3;

    //Mostamos la sucursal de mas ventas
    cout << "La sucursal con mas ventas es: "<<sucursal_mas_ventas;
}
