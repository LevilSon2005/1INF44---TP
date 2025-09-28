/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 21 de abril de 2025, 16:52
 */

#include "Funciones.hpp"

void apertura_lectura(ifstream &input,const char* name_arch){
    input.open( name_arch, ios::in);
    if(not input.is_open()) {
        cout<<"ERROR: El archivo "<<name_arch<<" no se pudo abrir";
    }
}

void apertura_escritura(ofstream &ouput,const char* name_arch){
    ouput.open( name_arch, ios::out);
    if(not ouput.is_open()) {
        cout<<"ERROR: El archivo "<<name_arch<<" no se pudo abrir";
    }
    else{
        cout<<"El archivo se abrio correctamente";
    }
}

void leer_imprimir_nombre(ifstream &input_repartos, ofstream &ouput){
    input_repartos>>ws;
    char c;
    while(true){
        c = input_repartos.get();
        if(c==' ') break;
        if (c=='/') c=' ';
        ouput.put(c);
    }
}

void impresion_busqueda_codigo_en_repartos(int codigo_platos, ifstream &input_repartos, ofstream &ouput){
    input_repartos.clear();
    input_repartos.seekg(0, ios::beg);
    int codigo_repartos, dni;
    char c;

    while (true) {
        input_repartos >> codigo_repartos;
        if (input_repartos.eof()) break;

        if (codigo_platos == codigo_repartos) {
            input_repartos >> dni;
            // Imprimimos DNI y nombre
            ouput << "DNI: " << dni << endl;
            ouput << "Nombre: ";
            leer_imprimir_nombre(input_repartos, ouput);
            ouput << endl;

            // Limpiar hasta fin de línea
            while (input_repartos.get(c)) {
                if (c == '\n') break;
            }
        } else {
            // Saltar línea entera si no coincide el código
            while (input_repartos.get(c)) {
                if (c == '\n') break;
            }
        }
    }
}


void procesar_cada_platos(ifstream &input_platos, ifstream &input_repartos, ofstream &ouput){
    int codigo_platos;
    while(true){//bloque de un plato en especifico
        //para cada plato (codigo)
        input_platos>>codigo_platos;
        
        if(input_platos.eof()) break;
        while(input_platos.get() != '\n');
        ouput<<"Para el codigo: "<<codigo_platos<<endl;
         ouput<<"---------------------------- "<<endl;    
        impresion_busqueda_codigo_en_repartos(codigo_platos,input_repartos, ouput); 
    }
    
}

void procesar(const char* name_arch_repartos, const char* name_arch_platos, const char*name_arch_reporte){
    ifstream input_repartos, input_platos;
    ofstream ouput;
    
    apertura_lectura(input_repartos, name_arch_repartos);
    apertura_lectura(input_platos, name_arch_platos);
    apertura_escritura(ouput, name_arch_reporte);
    
    procesar_cada_platos(input_platos, input_repartos, ouput);
}