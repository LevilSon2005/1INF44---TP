#include <iostream>
#include <string>

using namespace std;

void mandandoSaludos( string Nombre);

int main(){
	
	string UserName;
	
	cout << "Escriba su nombre: ";
	cin >> UserName;
	
	mandandoSaludos(UserName);
	
	return 0;
}

void mandandoSaludos(string Nombre){
	
	cout << "HOLIS, " << Nombre << "!" << endl;
	
}


