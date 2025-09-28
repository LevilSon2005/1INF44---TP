/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 12 de mayo de 2025, 11:10
 */

#include "funciones.hpp"
void  apetura_lectura(const char * name,ifstream &input){
    input.open(name, ios::in);
    if(not input.is_open()){
        cout<<"ERROR: El archivo "<<name <<" no se abrio"<<endl;
    }
}

void  apetura_esccritura(const char * name,ofstream &ouput){
    ouput.open(name, ios::out);
    if(not ouput.is_open()){
        cout<<"ERROR: El archivo "<<name <<" no se abrio"<<endl;
    }
    else{
        cout<<"El reporte se arbrio"<<endl;
    }
}



void  cargarArreglosRepartidores(int *arrDNIRepartidores,int *arrTipoVehiculo,int *arrCodDistrito, int &cantRepartidores){
    int dniRepatidor, codDistrito;
    char tipoVeh;
    ifstream inputRepartidores;
    apetura_lectura("Repartidores.txt", inputRepartidores);
//    while(true){
//        inputRepartidores>>dniRepatidor;
//        if(inputRepartidores.eof()) break;
//        arrDNIRepartidores[cantRepartidores] = dniRepatidor;
//        inputRepartidores>>arrTipoVehiculo[cantRepartidores];
//        ignorar(inputRepartidores, ' ');
//        inputRepartidores>>arrCodDistrito[cantRepartidores];
//        ignorar(inputRepartidores, '\n');
//        cantRepartidores++;
//    }
}