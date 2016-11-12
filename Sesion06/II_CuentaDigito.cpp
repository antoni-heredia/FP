/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   El programa calculara la cantidad de veces que se repite un
   digito en un intervalo

   Para ello crearemos un bucle for para recorrer todos los numeros del
   intervalo. El for comenzara en el minimo del intervalo y terminara
   en el maximo incluido
   Cada numero del intervalo lo descompondremos en sus digitos y lo
   comparamos con la cifra introducida por el usuario y si es igual
   se sumara uno en el contador de repeticiones


   Entradas: cifra, minimo, maximo
   Salidas:  repeticiones de la cifra
*/
/***************************************************************************/


#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matematicos
using namespace std;


int main() // Programa Principal
{
   int cifra,minimo,maximo;
   //Pedimos al usuario que meta los datos
   do{
       cout << "Por favor introduzca que cifra quiere buscar [0-9]: ";
       cin >> cifra;
   }while(cifra < 0 || cifra > 9);

   do{
       cout << "Por favor introduzca el minimo: ";
       cin >> minimo;
   }while(minimo < 0);

   do{
       cout << "Por favor introduzca el maximo: ";
       cin >> maximo;
   }while(maximo <= minimo);

    //Iniciamos la variable donde se va a guardar las repeticiones
    int contador_repeticiones = 0;
    for(int x = minimo; x<maximo ; x++ ){
        
        //Hacemos una copia de la x del for para no perderla ya que es
        //el numero que descompondremos por digitos
        int x_copia = x;
        
        //Recorremos todos los digitos del numero en busca de coincidencias 
        //con la cifra introducida por el usuario
        while( x_copia !=0 ){
            int resto = x_copia%10;
            x_copia /= 10;
            if( resto == cifra )
                contador_repeticiones++;
        }
    }
    //Mostramos el resultado al usuario
    cout << "El digito "<< cifra << " se repite "
         << contador_repeticiones << " veces" << endl;
    
    return (0);
}
