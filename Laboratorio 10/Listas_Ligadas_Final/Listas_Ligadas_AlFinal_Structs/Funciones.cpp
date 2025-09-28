/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 29 de junio de 2025, 17:47
 */

#include "Funciones.hpp"

void imprimir_titulo(ofstream &ouput, const char* titulo){
    ouput<<setw((TAMREPORTE +strlen(titulo))/2)<<titulo<<endl;
}

void imprimir_linC(ofstream &ouput, char del){
    ouput<<setw(TAMREPORTE)<<setfill(del)<<""<<setfill(' ')<<endl;
}

void apertura_lectura(ifstream &input, const char* name){
    input.open(name, ios::in);
    if(not input.is_open())
        cout<<"El archivo "<<name<< " no se abre"<<endl;
}

void imprimir_indice(ofstream &ouput, int num){
    ouput<<setw(2)<<right<<num<<") ";
}

void apertura_escritura(ofstream &ouput, const char* name){
    ouput.open(name, ios::out);
    if(not ouput.is_open())
        cout<<"El archivo "<<name<< " no se abre"<<endl;
    else
        cout<<"El reporte - "<<name<<" se abre"<<endl;
}


