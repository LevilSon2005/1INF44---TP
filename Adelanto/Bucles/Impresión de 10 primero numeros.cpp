#include <iostream>

main(){
	
	int Rinferior;
	const int Rsuperior=100;
	
	std::cout << "Ingrese el limite inferior: " ;
	std::cin >> Rinferior;
	std::cout <<"Ingrese el limite superior: " ;
//	std::cin >> Rsuperior; --> ii quieres que el mismo usuario estableza el  Rsuperior quita la constante
	
	int i;
	int suma =0;
	
	for (i = Rinferior; i<= Rsuperior; i++){
		std::cout <<i<<std::endl;
		suma = suma +i;
	}
	
	std ::cout << "La suma total es: " << suma;
	
	return 0;
}
