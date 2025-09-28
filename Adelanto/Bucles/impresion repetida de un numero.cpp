//impresión repetido de un número

#include <iostream>
using namespace std;


int main(){
	
	int x;
	int num;
	cout << "Ingrese el número: ";
	cin >>  num;
	cout << "Ingrese la cantidad de repeticiones: ";
	cin >> x;
	
	int i;
	for (i=1; i<=x; i++){
		cout << num << endl;
	}
	
	return 0;
}
