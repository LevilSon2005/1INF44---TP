/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 5 de abril de 2025, 10:28
 */

#include "Funciones.hpp"

int main(int argc, char** argv) {
    
    double Coef_Ind;
    double Coef_1;
    double Coef_2;
    double Coef_3;
    double Coef_4;
    
    double x1, x2, x3;
    double Fx1, Fx2;
    
    // esta variable es para ver si Fx1 y Fx2 tienen signos diferentes
    bool funciones_Con_Signo_Diferente;
    double raiz;
    
    
    double epsilon;
    
    cout<<"Escriba los coeficientes de su funcion"<<endl;
    cin >> Coef_4>> Coef_3>>Coef_2>> Coef_1>>Coef_Ind;
    
    
    cout << "Escriba las dos posibles raices (osea el intervalo)"<<endl;
    cin >> x1 >> x2;
    
    
    Fx1 = Calculo_funcion(x1, Coef_4, Coef_3, Coef_2, Coef_1, Coef_Ind);
    Fx2 = Calculo_funcion(x2, Coef_4, Coef_3, Coef_2, Coef_1, Coef_Ind);
    
    funciones_Con_Signo_Diferente = Signos_Diferentes(Fx1, Fx2);
    if ( funciones_Con_Signo_Diferente){
        
        cout <<"Escriba la precision que desea"<<endl;
        cin >> epsilon;
        
        raiz = Hallando_Raiz(Fx1, Fx2, x1, x2, epsilon, Coef_4, Coef_3, Coef_2, Coef_1, Coef_Ind);
        
        cout <<"La raiz de la funcion es: "<<raiz;
    }
    else{
        cout << "Las raices ingresadas no cumplen la condicion. "<<"";
    }
    
    return 0;
}

