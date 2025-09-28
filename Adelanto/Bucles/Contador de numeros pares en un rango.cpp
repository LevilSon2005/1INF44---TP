#include <iostream>
using namespace std;

//programa que calcula cuantos números son pares en un rango establecido por el usuario

int main(){
	
	int Rinferior;
	int Rsuperior;
	
	cout << "Escribe el primer numero: ";
	cin >> Rinferior;
	cout << "Escribe eñ ultimp numero: ";
	cin >> Rsuperior;
	
	cout << "Los numeros pares en el rango son:" << endl;
	
	int i;
	
	for(i=Rinferior; i<= Rsuperior;i++){
		if (i%2==0){
			cout << i<< endl;
		}
	}
	
	
	return 0;
}
