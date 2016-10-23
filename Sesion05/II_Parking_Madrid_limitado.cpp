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
   El usuario intrducira el instante de entrada y el dinero que dispone
   y el programa se encargara de saber hasta cuando puede tener el coche
   en el parking
   Salida: precio del parking
*/
/***************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
using namespace std;

int main()
{
    //Declaramos la  variables de entrada
    int horasI,horasF,minutosI,minutosF,segundosI,segundosF,dias;
    double diferencia,dinero_introducido;

    //Declaramos las constantes de precio
    const double PRIMER_TRAMO_DINERO  = 0.0412;
    const double SEGUNDO_TRAMO_DINERO = 0.0370;
    const double TERCER_TRAMO_DINERO  = 0.0311;
    const double CUARTO_TRAMO_DINERO  = 0.0305;
    const double DIA_COMPLETO_DINERO  = 31.55;


    const int PRIMER_TRAMO_MINS  =  30;
    const int SEGUNDO_TRAMO_MINS =  90;
    const int TERCER_TRAMO_MINS  = 120;
    const int CUARTO_TRAMO_MINS  = 660;
    const int DIA_COMPLETO_MINS  = 24*60;

    const string MENSAJE_ERROR = "Se ha introducido algun valor incorrecto";

    bool correcto = false;
    //Pedimos la usuario que introduzca los datos
    //No paramos de pedir los datos hasta que no los escriba bien
    while(!correcto)
    {
        cout << "Por favor introduzca la hora, minuto y segundo de entrada"
             "(Separados por un espacio y en ese orden) : ";
        cin >> horasI >> minutosI >> segundosI;
        if( !(horasI < 0 || horasI > 24 || horasI < 0 ||
                minutosI > 60 || segundosI > 60) )
        {
            correcto=true;
        }
        else
            cout << MENSAJE_ERROR << endl;
    }
    correcto = false;
    while(!correcto)
    {
        cout << "Introduzca cuando dinero tiene para el parking: ";
        cin >> dinero_introducido;
        if(dinero_introducido > 0)
            correcto=true;
        else
            cout << MENSAJE_ERROR << endl;
    }

    segundosF=segundosI;
    minutosF=minutosI;
    horasF=horasI;
    /*
     Ahora empezamos a quitar dineros del dinero introducido segun dos factores
     Primero vemos si el dinero introducido es mayor al de un dia completo,
     Si es asi vemos cuantos dias completos se pueden hacer.
     Una vez que el dinero sea menor que un dia completo empezamos a quitar dinero
     del total empezando desde el pimer tramo. Para cada tramo comprobaremos
     que el tiempo que lleva es menor al de dicho tramo y que el dinero del que disponga
     sea mayor que el que cuesta el minuto en ese tramo.
     */
    dias = 0;
    while(dinero_introducido > DIA_COMPLETO_DINERO){
        dinero_introducido-=DIA_COMPLETO_DINERO;
        dias++;
    }
    int minutos_pasados = 0;
    while(minutos_pasados<= PRIMER_TRAMO_MINS
            && dinero_introducido >= PRIMER_TRAMO_DINERO){
        minutos_pasados++;
        dinero_introducido-=PRIMER_TRAMO_DINERO;
    }
    while(minutos_pasados<=SEGUNDO_TRAMO_MINS
            && dinero_introducido >= SEGUNDO_TRAMO_DINERO){
        minutos_pasados++;
        dinero_introducido-=SEGUNDO_TRAMO_DINERO;
    }
    while(minutos_pasados<=TERCER_TRAMO_MINS
            && dinero_introducido >= TERCER_TRAMO_DINERO){
        minutos_pasados++;
        dinero_introducido-=TERCER_TRAMO_DINERO;
    }
    while(minutos_pasados<=CUARTO_TRAMO_MINS
            && dinero_introducido >= CUARTO_TRAMO_DINERO){
        minutos_pasados++;
        dinero_introducido-=CUARTO_TRAMO_DINERO;
    }
    /*
     * En este momento pasamos los minutos a horas y en caso
     * de que sea un dia nuevo pasaremos tambien las horas a
     * dias
    */
    minutosF += minutos_pasados;
    horasF += (minutosF-minutosF%60)/60;
    minutosF = minutosF%60;
    dias += (horasF-horasF%24)/24;
    if(dias == 0)
        cout << "Puedes estar hasta las "<<horasF<<":"<<minutosF<<":"<<segundosF;
    else
        cout << "Puedes estar hasta +"
                <<dias<<" dias, "<<horasF<<":"<<minutosF<<":"<<segundosF;

    return(0);
}
