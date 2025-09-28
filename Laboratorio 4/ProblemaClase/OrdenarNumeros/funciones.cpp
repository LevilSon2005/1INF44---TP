/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * Descripcion: Este programa ordena los numeros de dos archivos en uno solo de menor a mayor
 * 
 * Created on 1 de mayo de 2025, 12:19
 */

#include "funciones.hpp"

void apertura_lectura(const char* name,ifstream &input ){
    input.open(name, ios::in);
    
    if(input.is_open()){
        cout<<"EROR: El archivo "<<name<<" no se abrio.";
    }
}

void apertura_escritura(const char* name,ofstream &ouput ){
    ouput.open(name, ios::out);
    
    if(ouput.is_open()){
        cout<<"EROR: El archivo "<<name<<" no se abrio.";
    }
    else cout<<"Se abrio correctamente";
}

void leer_arreglo(ifstream &inputNum, int* arreglo, int &cantDatos){
    int num;//cantdatos ya esta inicializado en cero afuera de la funcion
    while(true){
        inputNum>>num;
        if(inputNum.eof()) break;
        arreglo[cantDatos] = num;
        cantDatos++;
    }
}

void combinar_arreglos(ofstream &ouput, int* arr1, int* arr2,int* arrCombinado, int cantDatos1, int cantDatos2, int cantDatos2){
    int i=0,j=0;
    
//    if()
}


void procesar_arreglos(ifstream &inputNum1, ifstream &inputNum2, ifstream &ouput){
    
    int cantDatos1=0, cantDatos2=0, cantDatosFinal=0;
    int arr1[MAX_NUMEROS]{}, arr2[MAX_NUMEROS]{}, arrCombinado[MAX_NUMEROS]{};
    
    leer_arreglo(inputNum1,arr1, cantDatos1);
    leer_arreglo(inputNum2,arr2, cantDatos2);
    
    //combinarlos
    combinar_arreglos(ouput, arr1, arr2,arrCombinado, cantDatos1, cantDatos2, cantDatos2);
    
}


void leer_procesar_numeros(const char* name_registroNum1,const char* name_registroNum2, const char* nameReporte){
    ifstream inputNum1, inputNum2;
    ofstream ouput;
    apertura_lectura(name_registroNum1,inputNum1 );
    apertura_lectura(name_registroNum2,inputNum2 );
    apertura_escritura(nameReporte,ouput);
    
    procesar_arreglos(inputNum1, inputNum2, ouput);
}
