/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 5 de abril de 2025, 10:36
 */

#include "Funciones.hpp"



double calcular_x3 (double Fx1, double Fx2, double x1, double x2 ){
    
    double pendiente;
        
    pendiente = (x1-x2)/(Fx1-Fx2);
    

// y - Fx2 = m (x - x2)    y=0 -->x=x3 
    double x3;
    x3 = x2 - (Fx2/pendiente);
    
    return x3;
}

double Potencia(double x, int exponente){
    
    double potencia = 1.0;
    
    for (int i=1; i<=exponente; i++){
        potencia *= x;  
    }    
    return potencia;
}


double Calculo_funcion(double x, double C_4, double C_3, double C_2, double C_1, double C_Ind){

    double F;
    
    F = C_4 * Potencia(x,4) + C_3 * Potencia(x,3) + C_2 * Potencia(x,2) + C_1 * x + C_Ind;
    
    return F;
}


//esta funcion va a validar que F(a) y F(b) tienen signos diferentes 
bool Signos_Diferentes(double Fa, double Fb){
        
    return ( (Fa<0 and Fb>0) or (Fa>0 and Fb<0) );
}

double Hallando_Raiz (double Fx1, double Fx2, double x1, double x2, double epsilon,  double C_4, double C_3, double C_2, double C_1, double C_Ind ){
    
    double x3;
    double Fx3;
    bool podemos_Seguir = true;
    
    while (podemos_Seguir){
    
        bool cumple;
        x3 = calcular_x3(Fx1, Fx2, x1, x2);
        Fx3 = Calculo_funcion(x3, C_4, C_3, C_2, C_1, C_Ind);
        cumple=Signos_Diferentes(Fx3, Fx1);
        
        if(cumple){
            x2=x3;
            Fx2=Calculo_funcion(x2, C_4, C_3, C_2, C_1, C_Ind);
        }
        else{
            x1=x3;
            Fx1 = Calculo_funcion(x1, C_4, C_3, C_2, C_1, C_Ind);
        }
       
        podemos_Seguir = (fabs(Fx3)>= epsilon);
    }
    
    return x3;
}