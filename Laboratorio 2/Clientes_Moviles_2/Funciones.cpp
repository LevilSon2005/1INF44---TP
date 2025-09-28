/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 21 de abril de 2025, 17:52
 */

#include "Funciones.hpp"

void apertura_lectura(ifstream &input, const char* name_arch){
    input.open(name_arch, ios::in);
    if(not input.is_open()){
        cout<<"ERROR: El archivo "<<name_arch<<" no se puede abrir. "<<endl;
        exit(1);
    }
}

void apertura_escritura(ofstream &ouput, const char* name_arch){
    ouput.open(name_arch, ios::out);
    if(not ouput.is_open()){
        cout<<"ERROR: El archivo "<<name_arch<<" no se puede abrir. "<<endl;
        exit(1);
    }
    else{
        cout<<"El archivo se ha creado correctamente";
    }
}
void leer_procesar_infracciones(const char* name_arch_empresas,const char* name_arch_vehiculos,const char* name_arch_infracciones,const char* name_arch_reporte){
    ifstream input_empresas,input_vehiculos,input_infracciones;
    ofstream ouput_reporte;
    
    apertura_lectura(input_empresas, name_arch_empresas);
    apertura_lectura(input_vehiculos, name_arch_vehiculos);
    apertura_lectura(input_infracciones, name_arch_infracciones);
    apertura_escritura(ouput_reporte, name_arch_reporte);
    
    
}