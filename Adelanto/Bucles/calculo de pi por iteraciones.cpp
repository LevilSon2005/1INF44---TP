//calculo del valor de PI con iterativas

#include <iostream>
#include <cmath>
#define PI 3.141592
using namespace std;

int main(){
	
	int cant;
	cout << "Ingrese la canrtidad de terminos: ";
	cin >> cant;
	
	if (cant>0){
		int i;
		double producto=1;
		
		for (i=1; i<=cant;i++){
			double numerador =(4.0 * i) * (4.0 * i);
			double denominador = (4*i-1)*(4*i+1);
			 
			double division = (numerador/denominador);
			
			producto = producto * division;
			cout << "El valor aproximado de pi es: " << producto<<endl;
		}
		
		double pi = 2*sqrt(2)*producto;
		cout << "El valor aproximado de pi es: " << pi<<endl;
		
//		const double PI=3.141592;
		int margen = fabs(PI-pi)<0.005;
		double error;
		error = fabs(PI-pi);
		if (margen == 1){
			cout <<"El error calculado no es considerable (<0. 005): "<< error;
		}
		else{
			cout << "Olvidalo, está mal. El margen de error es demasiado (>=0. 005): "<<error;
		}
		
	}
	else{
		cout<<"La cantidad de terminos debe ser mayor a cero";
	}
	
	
	return 0;
}
