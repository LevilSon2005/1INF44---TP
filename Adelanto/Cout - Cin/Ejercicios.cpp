#include <iostream>

/*
 Ejercicio 1: Definir una constante con #define
Instrucciones:

Define una constante llamada TASA_IVA con un valor del 18%.
Calcula el precio final de un producto con IVA incluido.
El usuario ingresa el precio base del producto.
}
*/


/*
#define TASA_IVA 1.18
int main(){
	
	int PrecioInicial;
	double PrecioFinal;
	
	std::cout << "Ingrese el precio base del producto: ";
	std::cin >> PrecioInicial;
	
	//Cálculo del precio final con el IVA incluido
	PrecioFinal = PrecioInicial * TASA_IVA;
	
	std::cout << "El precio final es: "<<PrecioFinal;
	
	return 0;
}
*/

//-----------
#include <limits.h>

int main() {
    
    double x=0;
    double y=0;
    double z=0;
    
    std::cout<<"Ingrese dos números: ";
    std::cin >> x>>y;
    
    z = x+y;
    
    std::cout<<z;
    
    return 0;
}


