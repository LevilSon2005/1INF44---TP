//a�ado el archivo cabecera

#include "Hello_World.h"
#include <iostream>

	
namespace Hello_World	{
	
	using namespace std;

	void Saludar(){
		cout << "Hello World"<<endl;
	}	
}

/*

	Para el archivo de implementacion
	
	----------------
	
	1. A�ades el archivo de la cabecera "[FileName].h"
	2. Si utilizas algun comando de otra libreria, lo a�ades (iostream, cmath, string,..)
	
	------
	
	namespace [Nombre del espacio dentro de la libreria]  {
		
		[TipoVariable] [NombreFuncion] () {
		
		//c�digo que va aqui
		
		}
	}
	
*/
