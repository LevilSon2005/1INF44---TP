
//creando la libreria HELLO_WORLD_H
#ifndef HELLO_WORLD_h
#define HELLO_WORLD_h
//#include <iostream> --> si es que utilizara cin o cout

//como utilizo string para mi funci�n, a�ado la libreria 
//#include <string>

//Ya verifiqu� que solo se agregar� la librer�a si antes no est� (el archivo no existe)

//se utiliza std, porque no podemos incluir otra libreria cuando estamos creando una libreria
namespace Hello_World {
	void Saludo();
}

#endif
/*

#ifndef [Nombre de libreria] -siempre mayuscula y .h -normalmente coincide con el nombre del archivo
#define [Nombre de libreria]

	namespace [Nombre del espacio dentro de la libreria] {
		
		[TipoVar] [NombreFuncion];
		
	}
	
#endif

*/
 
