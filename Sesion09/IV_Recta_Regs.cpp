/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
	El programa recibe los coeficines de la ecuacion general de dos rectas.
	Con esos coeficientes realiza varias operaciones, los principales es a
	partir de los cuales se realizan los demas es calcular la pendiente y 
	la ordenada en el origen para ello hay dos funciones que realizan dichos 
	calculos
	
	Lo primero  que realiza el programa es mostrar varios puntos de las dos
	dos rectas uno variando la x y otros variando y. Para ello existen dos
	funciones que relializan los calculos. Estas son Ordenada y 
	Abcisa
	
	Seguidamente el programa nos devuelve las ecuaciones explicitas de cada una
	de las rectas. Para ello realiza lo mismo de dos formas distintas. Una
	mostrando la ecuacion directamente y otra guardando la ecuacion en un
	string y luego mostrando ese string
	
	Por ultimo nos dice si las rectas son secantes, paralelas o coencidentes
	para ello compara las pendientes y las ordenadas en origen de las dos 
	rectas.
	
	Añadido:
	* Struct para punto y para recta
	* Punto de corte de dos rectas
	* Saber si varios punto pertenecen a la recta.
	* Para ello tenemos tres funciones nuevas, una que nos imprime un punto
	* otra que nos dice si el punto esta en la recta y ora que nos dice 
	* el punto de corte de dos rectas.
    
    Entradas: a1,b1,c1,a2,b2,c2
    Salidas:  Puntos de las rectas, ecuaciones explicitas y como son las 
			  rectas entre si.
*/
/***************************************************************************/


#include <iostream>   // Inclusion de los recursos de E/S
#include <cmath>
#include <string>
using namespace std;

struct Recta{
	double a,b,c;
};
struct Punto2D{
	double x,y;
};

double CalcularPendiente(Recta recta){
	return -recta.a/recta.b;
}


double CalcularOrdenadaOrigen(Recta recta){
	return -recta.c/recta.b;
}


double Ordenada(Recta recta, double abcisa)
{
	//Dada una cordenada de abcisa devuelve una cordenada de las ordenada
	double m = CalcularPendiente(recta);
	double n = CalcularOrdenadaOrigen(recta);
	return m*abcisa+n;
}


double Abcisa(Recta recta, double ordenada)
{
	//Dada una cordeanda de ordenada devuelve una cordenada de las abcisas
	double m = CalcularPendiente(recta);
	double n = CalcularOrdenadaOrigen(recta);
	return (ordenada-n)/m;
}


int ImprimirRectaExplicita(Recta recta)
{
	//Imprime la ecuacion de la recta directamente
	double m = CalcularPendiente(recta);
	double n = CalcularOrdenadaOrigen(recta);
	cout << "y= " << m << "x " << n << endl;
	return 0;
}


string RectaExplicita(Recta recta)
{
	//Devuelve un string con la ecuacion de la recta
	double m = CalcularPendiente(recta);
	double n = CalcularOrdenadaOrigen(recta);
	string str_recta= "y= " + to_string(m) + "x " + to_string(n);
	return str_recta;
}


bool SonSecantes(Recta recta1, Recta recta2)
{
	//Compara las pendientes para ver si son secantes
	double m1 = CalcularPendiente(recta1);
	double m2 = CalcularPendiente(recta2);
	//Si la pendiente son diferentes son secantes
	if(m1 != m2)
		return true;
	else
		return false;
}


bool SonParalelas(Recta recta1, Recta recta2)
{
	//Compara si son paralelas
	double m1 = CalcularPendiente(recta1);
	double m2 = CalcularPendiente(recta2);
	double n1 = CalcularOrdenadaOrigen(recta1);
	double n2 = CalcularOrdenadaOrigen(recta2);
	//Si la pendiente es igual pero la ordenada en el origen distinta son
	//paralelas
	if(m1 == m2 && n1 != n2)
		return true;
	else
		return false;
	
}

Punto2D PuntoDeCorte(Recta recta1, Recta recta2){
	Punto2D punto_corte;
	double m1,m2,n1,n2;
	m1 = CalcularPendiente(recta1);
	m2 = CalcularPendiente(recta2);
	
	n1 = CalcularOrdenadaOrigen(recta1);
	n2 = CalcularOrdenadaOrigen(recta2);
	
	punto_corte.x = (n2-n1)/(m1-m2);
	punto_corte.y = m1*punto_corte.x+n1;
	return punto_corte;
}

bool PuntoEnRecta(Punto2D punto, Recta recta){
	int m,n;
	
	m = CalcularPendiente(recta);
	n = CalcularOrdenadaOrigen(recta);
	
	double y = m*punto.x+n;
	
	if(y == punto.y)
		return true;
	else
		return false;
}

string PuntoToString(Punto2D punto){
	return "["+to_string(punto.x)+","+to_string(punto.y)+"]";
}

int main() // Programa Principal
{
	const int TAM_CAD = 100;
	//Leemos los datos de entrada
	Recta recta1,recta2;
	
	cout << "Por favor introduzca A1: ";
	cin >> recta1.a;
	
	cout << "Por favor introduzca B1: ";
	cin >> recta1.b;
	cout << "Por favor introduzca C1: ";
	cin >> recta1.c;
	
	cout << "Por favor introduzca A2: ";
	cin >> recta2.a;
    cout << "Por favor introduzca B2: ";
	cin >> recta2.b;
	cout << "Por favor introduzca C2: ";
	cin >> recta2.c;
	
	int iteracion = 1;
	cout << "------------------Valores de la recta para Δx------------------"
		 << endl;
	//Mostramos los puntos de las rectas con la variacion de x entre los valores
	//dados por el ejercicio	 
	for(double x = -10; x <= 10; x++){
		cout << "----------Iteraccion " << iteracion << "----------" << endl;
		iteracion++;
		
		double ordenada=Ordenada(recta1,x);
		cout << "(x1,y1)=("<<x<<","<<ordenada<<")"<<endl;
		ordenada=Ordenada(recta2,x);
		cout << "(x2,y2)=("<<x<<","<<ordenada<<")"<<endl;
	}
    iteracion = 1;
	cout << "------------------Valores de la recta para Δy------------------"
		 << endl;
	//Mostramos los puntos de las rectas con la variacion de y entre los valores
	//dados por el ejercicio
	for(double y = -5; y <= 5; y += 0.5){
		cout << "----------Iteraccion " << iteracion << "----------" << endl;
		iteracion++;
		
		double abcisa=Abcisa(recta1,y);
		cout << "(x1,y1)=("<<abcisa<<","<<y<<")"<<endl;
		
		abcisa=Abcisa(recta2,y);
		cout << "(x2,y2)=("<<abcisa<<","<<y<<")"<<endl;
	}
	
	//Mostramos las ecuaciones de la recta
	cout << "------------------Recta explicita------------------" << endl;
	cout << "Usando funcion con cout" << endl;
	//Mostrandolos directamente
	cout << "----------Recta 1----------" << endl;
	ImprimirRectaExplicita(recta1);
	cout << "----------Recta 2----------" << endl;
	ImprimirRectaExplicita(recta2);
	
	cout << "Usando funcion con string" << endl;
	//Mostrandolos a partir de un string devuelto por una funcion
	string recta;
	cout << "----------Recta 1----------" << endl;
	recta = RectaExplicita(recta1);
	cout << "Ecuacion de la recta explicita: " << recta << endl;
	cout << "----------Recta 2----------" << endl;
    recta = RectaExplicita(recta2);
	cout << "Ecuacion de la recta explicita: " << recta << endl;
	
	//Comprobamos si son paralelas, si no lo son, son secantes o coincidentes
	if(SonParalelas(recta1,recta2))
		cout << "Las rectas son paralelas" << endl;
	else
		if(SonSecantes(recta1,recta2)){
			cout << "Las rectas son secantes" << endl;
			Punto2D punto_corte = PuntoDeCorte(recta1, recta2);
			cout << "Las rectas se cortan "<< PuntoToString(punto_corte)
			     << endl;
		}else //Si no son secantes son coincidentes
			cout << "Las rectas son coincidentes" << endl;
	

	//Parte del codigo propuesta por el profesor
	
	string cadena; // Para leer coordenada (usando un string)   

	// Extraer del buffer de entrada el salto 	de línea, si lo hubiera    
	cin.ignore (TAM_CAD,'\n');   

	// Lectura adelantada             
	cout << endl;   
	cout << "Introdzca coordenada x: ";   
	getline (cin, cadena);       

	Punto2D p;
	while (cadena != "FIN") {               

		 p.x = stof(cadena); // string --> double               
		 cout << "Introdzca coordenada y: ";       
		 getline (cin, cadena);               
		 p.y = stof (cadena);  // string --> double               

	 

		 if (PuntoEnRecta(p, recta1))        
			  cout << "El punto " <<  PuntoToString(p) << " pertenece a la recta r1" << endl;       
		 else            
			  cout << "El punto " <<  PuntoToString(p) << " NO pertenece a la recta r1" << endl;                            

	 
		 // Nueva lectura                
		 cout << endl;
		 cout << "Introdzca coordenada x: ";
		 getline (cin, cadena);     
	} // while (cadena != "FIN"
		
	
	
	//Fin del programa	
    return (0);
}
