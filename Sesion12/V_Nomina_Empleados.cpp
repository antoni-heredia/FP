	/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// CURSO 2016-2017
// (C) Antonio Jesus Heredia Castillo
// GRUPO B GRUPO DE PRACTICAS B2
//
//
/*
	El programa tiene una clase Nomina_empleado en la cual estan como constantes
	los salarios bases de cada tipo de trabajador y tambien el valor de sus
	horas extras. El contructor de la clase necesita la categoria a la que
	pertenece el trabjador, ademas de las horas. Luego tenemos los metodos
	tipicos para devolver el valor de cada dato y ademas el de poner un valor
	a la horas extras.
	
	Como funcion tenemos la de leer un entero positivo.
	
	En el cuerpo de la funcion principal tenemos la pedida de datos y la
	creacion de los objetos trabajadores, cada uno con su categoria.
	Mostrando su salario neto para cada uno.
	
	Despues tenemos que poner las horas extras del operario y del ejecutivo a 0
	ya que iremos comparando cuantas horas extras necesita el operario para 
	superar el sueldo del ejecutivo. Para ello realizamos un bucle while el cual
	se repetira hasta que el sueldo sea mayor y en cada pasada aumentaremos en
	una hora, las horas extras del operario.
	 
    Entradas: horas y años de antiguedad
    Salidas: sueldos
*/
/***************************************************************************/

#include <iostream>
using namespace std;

//Clase Nomina_Empleado
class Nomina_Empleado
{
private:
	//Declaramos las constantes de los salarios de cada uno
	//Son doubles ya que puede tener decimales aunque en este caso no
	const double base_operario = 900.0;
	const double base_base = 1100.0;
	const double base_administrativo = 1200.0;
	const double base_ejecutivo = 2000.0;
	
	//Declaramos las constantes de los precios de las horas extras
	//Son doubles ya que puede tener decimales aunque en este caso no
	const double hora_operario = 16;
	const double hora_base = 23;
	const double hora_administrativo = 25;
	const double hora_ejecutivo = 30;
	
	//Declaramos las variables donde guardaremos los datos una vez nos pase
	//los datos el contructor
	double salario_base;
	double precio_hora;
	int horas_extras = 0;
	int anios = 0;
	char categoria;

public:
	//El constructor de la clase
	Nomina_Empleado (char categoria_intr, int horas, int anios_intr){
		categoria = categoria_intr;
		switch (categoria){  
			case 'O':  
				salario_base = base_operario;
				precio_hora = hora_operario;
				break;  
			case 'B':  
				salario_base = base_base;
				precio_hora = hora_base;
				break;
			case 'A':  
				salario_base = base_administrativo;
				precio_hora = hora_administrativo;
				break;
			case 'E':  
				salario_base = base_ejecutivo;
				precio_hora = hora_ejecutivo; 
				break;
		}
		horas_extras = horas;
		anios = anios_intr;
	}
	//Los metodos para obtener los datos privados de la clase
	double GetSalarioBase(){
		return salario_base;
	}
	
	double GetPrecioHora(){
		return salario_base;
	}
	
	double GetSalarioHoras(){
		//Calculamos cuanto cobra en funcion de las horas extras
		double salario_horas = horas_extras * precio_hora;
		//Y le sumamos lo que cobra en funcion de los años trabajados
		salario_horas += salario_horas * anios / 100.0;
		return salario_horas;
	}
	
	double GetSalarioNeto(){
		return salario_base + GetSalarioHoras();
	}
	
	//Para estrablecer las horas extras trabajadas
	void SetHorasExtras(int horas){
		horas_extras = horas;
	}
};
/***************************************************************************/

/*
Metodo no usado al final pero que se usaba para la introducion de una categoria
salarial

char PedirCategoria(){
	char categoria;
	do{
		cout << "Las categorias son: ";
		cout << "\tOperario (o/O)";
		cout << "\tBase (b/B)";
		cout << "\tAdministrativo (a/A)";
		cout << "\tEjecutiva (e/E)";
		cout << "Por favor introduzca una categoria: ";
		cin >> categoria;
		categoria = toupper(categoria);
	}while(categoria != 'A' && categoria != 'B' && categoria != 'O' 
		   && categoria != 'E' );
		   
	return categoria;
}
* */
//Funcion que pide un entero positivo
int PedirPositivo(string mensaje){
	int numero;
	do{
		cout << mensaje;
		cin >> numero;
	}while(numero < 1);
	return numero;
};

//Programa principal
int main (void)
{
	//Pedimos al usuario que introduzca los datos de años y horas extras
	string mensaje = "Introduzca los años de antiguedad: ";

	int anios = PedirPositivo(mensaje);
	mensaje = "Introduzca las horas extras: ";
	int horas = PedirPositivo(mensaje);
	
	//Creamos un objeto de cada tipo de trabajador
	Nomina_Empleado operario ('O', horas, anios);
	Nomina_Empleado base ('B', horas, anios);
	Nomina_Empleado administrativo ('A', horas, anios);
	Nomina_Empleado ejecutivo ('E', horas, anios);
	
	//Mostramos su salario neto para cada uno
	cout << endl;
	cout << "El sueldo neto del operario es de: " 
	     << operario.GetSalarioNeto() << endl;
	
	cout << "El sueldo neto del base es de: " 
	     << base.GetSalarioNeto() << endl;
	
	cout << "El sueldo neto del administrativo es de: " 
		 << administrativo.GetSalarioNeto() << endl;
	
	cout << "El sueldo neto del ejecutivo es de: " 
		 << ejecutivo.GetSalarioNeto() << endl;
	
	//Establecemos que el ejecutivo no tiene horas extras y que el operario
	//tampoco
	ejecutivo.SetHorasExtras(0);
	operario.SetHorasExtras(0);
	horas = 0;
	//Se ejecuta mientras que el ejecutivo cobre mas que el operario
	while( ejecutivo.GetSalarioNeto() > operario.GetSalarioNeto() ){
		//Añadimos una hora extra mas al operario
		horas++;
		operario.SetHorasExtras(horas);
	}
	//Mostramos cuantas horas extras necesito
	cout << endl << "Con " << horas << " extras se iguala o supera el sueldo " 
		 << " del operario al del ejecutivo" << endl;
	
	//Mostramos el sueldo de cada uno
	cout << "Sueldo neto operario: "  << operario.GetSalarioNeto() 
	     << endl;
	cout << "Sueldo neto ejecutivo: " << ejecutivo.GetSalarioNeto();
		 
	//Salimos de la funcion principal
	return(0);
}
