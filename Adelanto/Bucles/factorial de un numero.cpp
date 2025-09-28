//factorial de un número

#include <iostream>
using namespace std;

int main(){
	
	long num;
	
	cout << "Ingrese el numero: ";
	cin >> num;
	
	long producto=1;
	long i;
	
	for (i=1;i<=num;i++){
		producto = producto*i;
	}
	
	cout << "El factorial de "<< num<< " es: "<< producto;
	
	return 0;
}
