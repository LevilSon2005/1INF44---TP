//suma de cuadrados de los n primeros numeros naurales

//INSTRUCCIONES

/*
- n debe ser mayor a cero
- verificar si la suma de cuadrados de todos los numeros hatsa n es igual a el valor resultado de la fomrula notable
, es decir,  si la formula es correcta

*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	int num;
	
	cout << "Ingrese el valor del numero: ";
	cin >> num;
	
	if (num>0){
		//declaracion ed variables locales
		
		//calculo de la suma por iterativa
		int i;
		int suma=0;
		for (i=1; i<=num;i++){
			
			suma = suma + (pow(i,2));
//			cout << "La suma es :" << suma;  --> para verficar como la susma progresa
		}
		cout << "La suma de los cuadrados (iteracion) es:" << suma << endl;
		
		
		//calculo de la suma por formula
		int suma2;
		int x=num;
		
		suma2= (x*(x+1)*(2*x+1))/6;
		
		cout <<"La suma de los cuadrados (fórmula) es: "<<suma2<<endl;
		
		if (suma == suma2){
			cout <<"La formula es correcta";
		}
		else{
			cout << "chales, que salio mal";
		}
		
	}
	
	else{
		cout << "El numero ingresado debe ser mayor a cero";
	}
	
	return 0;
}
