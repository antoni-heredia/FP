/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   Programa para cobrar el dinero del parking.
   El usuario intrducira el instante de entrada y el de salida.
   El programa calculara la diferencia entre ambos y en funcion del tiempo
   que haya pasado se le tarifara de una forma u otra
   Entrada: horas,minutos, segundos tanto de entrada como de salida
   Salida: precio del parking
*/
/***************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
using namespace std;

int main()
{
    //Declaramos la  variables de entrada
    int horasI,horasF,minutosI,minutosF,segundosI,segundosF;
    double diferencia,total;

    //Declaramos las constantes de precio
    const double PRIMER_TRAMO = 0.0412;
    const double SEGUNDO_TRAMO = 0.0370;
    const double TERCER_TRAMO = 0.0311;
    const double CUARTO_TRAMO = 0.0305;
    const double DIA_COMPLETO = 31.55;
    const string MENSAJE_ERROR = "Se ha introducido algun valor incorrecto";
    //Pedimos la usuario que introduzca los datos
    cout << "Por favor introduzca la hora, minuto y segundo de entrada"
        "(Separados por un espacio y en ese orden) : ";
    cin >> horasI >> minutosI >> segundosI;
    if( horasI < 0 || horasI > 24 || horasI < 0 ||
        minutosI > 60 || segundosI > 60 ){
        cout << MENSAJE_ERROR << endl;
        return(0);
    }


    cout << "Por favor introduzca la hora, minuto y segundo de salida"
        "(Separados por un espacio y en ese orden) : ";
    cin >> horasF >> minutosF >> segundosF;
    //Comprobamos que las horas introducidas sean correctas
    if( horasF < 0 || horasF > 24 || horasF < 0 || minutosF > 60 ||
        segundosF > 60  || horasF < horasI ){
        cout << MENSAJE_ERROR << endl;
        return(0);
    }
    diferencia=((horasF-horasI)*3600+(minutosF-minutosI)*60
              + (segundosF-segundosI))/60;
    /*
        En los siguientes if se comprobara el tiempo que ha estado el conductor
        dentro del parking. Y segun los minutos se le aplica una tarificación u
        otra.
    */

    if( diferencia <= 30 ){
        total = diferencia * PRIMER_TRAMO;
    }else if ( diferencia <= 90 ){
        total = (diferencia - 30)*SEGUNDO_TRAMO+30*PRIMER_TRAMO;
    }else if ( diferencia <= 120 ){
        total = (diferencia-90)*TERCER_TRAMO+60*SEGUNDO_TRAMO+30*PRIMER_TRAMO;
    }else if( diferencia <= 660 ){
        total = (diferencia-120)*CUARTO_TRAMO+30*TERCER_TRAMO
            +60*SEGUNDO_TRAMO+30*PRIMER_TRAMO;
    }else if ( diferencia <= 24*60 ) {
        total = 31.55+540*CUARTO_TRAMO+30*TERCER_TRAMO
            +60*SEGUNDO_TRAMO+30*PRIMER_TRAMO;
    }

    //Mostramos el precio al conductor
    cout << "El total a pagar es de: " << total;
    return(0);
}
