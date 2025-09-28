
//creando la libreria HELLO_WORLD_H
#ifndef HELLO_WORLD_h
#define HELLO_WORLD_h
//#include <iostream> --> si es que utilizara cin o cout

//como utilizo string para mi función, añado la libreria 
//#include <string>

//Ya verifiqué que solo se agregará la librería si antes no está (el archivo no existe)

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
 
