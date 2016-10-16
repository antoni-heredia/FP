/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
   El programa sirve para reajustar la renta bruta segun a partir de los
   criterios de retenciones dados en el guion.
   Para ello pediremos sus datos personales al usuario.
*/
/***************************************************************************/

#include <iostream>   // Inclusión de los recursos de E/S
using namespace std;

int main()
{
    //Declaramos la  variables de entrada
    bool es_autonomo,es_pensionista;
    string estado_civil;
    double renta_bruta,retencion_inicial;

    //Declaramos las variables de salida
    double renta_neta;

    const string MENSAJE_ERROR_DATO = "El tipo de dato introducido"
                                      " es incorrecto";

    const double RETENCION_AUTONOMOS = -0.03;
    const double RETENCION_PENSIONISTAS = 0.01;
    const double RETENCION_NO_AUTONOMOS = 0.01;
    const double RETENCION_MENOS_2000 = 0.02;
    const double RETENCION_CASADO = 0.025;
    const double RETENCION_SOLTEROS = 0.03;

    /*
        Pedimos al usuario que introduzca los datos y cada vez que lo
        intoduce comprobamos si es el dato introducido es correcto
        En caso de no ser asi, mostramos el mensaje de error por defecto y
        salimos del programa
    */
    cout << "Es usted autonomo (0 si es que no, 1 si es que si): ";
    if (!(cin >> es_autonomo))
    {
        cout << MENSAJE_ERROR_DATO;
        return(0);
    }

    cout << "Es usted pensionista (0 si es que no, 1 si es que si): ";
    if (!(cin >> es_pensionista))
    {
        cout << MENSAJE_ERROR_DATO;
        return(0);
    }

    cout << "Cual es su estado civil (soltero o casado): ";
    cin >> estado_civil;
    if( estado_civil != "soltero"  && estado_civil != "casado" )
    {
        cout << MENSAJE_ERROR_DATO;
        return(0);
    }
    cout << "Cual es su renta bruta: ";
    cin >> renta_bruta;
    if( renta_bruta < 0 )
    {
        cout << MENSAJE_ERROR_DATO;
        return(0);
    }

    cout << "Cual es su retencion inicial (tanto por ciento): ";
    cin >> retencion_inicial;


    if(es_autonomo){
        retencion_inicial = retencion_inicial +
                            retencion_inicial*RETENCION_AUTONOMOS;
    }else{
        retencion_inicial = retencion_inicial +
                            retencion_inicial*RETENCION_NO_AUTONOMOS;
        if(es_pensionista){
            retencion_inicial = retencion_inicial +
                                retencion_inicial*RETENCION_PENSIONISTAS;
        }else{
            if(renta_bruta < 20000 ){
                retencion_inicial = retencion_inicial +
                                    retencion_inicial*RETENCION_NO_AUTONOMOS;
            }else{
                if(estado_civil == "casado"){
                    retencion_inicial = retencion_inicial +
                                        retencion_inicial*RETENCION_CASADO;
                }else{
                    retencion_inicial = retencion_inicial +
                                        retencion_inicial*RETENCION_SOLTEROS;
                }
            }
        }
    }
    renta_neta = renta_bruta - renta_bruta*(retencion_inicial/100.0);

    cout << "La renta neta es de: " << renta_neta << endl;
    cout << "La retencion final ha sido de: " << retencion_inicial<< "%";
    return(0);
}
