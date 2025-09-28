/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 17 de abril de 2025, 16:26
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
}

void imprimpir_titulo(int d_i,int m_i, int a_i,int d_f, int m_f, int a_f, ofstream &ouput_reporte){
    ouput_reporte<<setw( 30/*(TAM_MAX + TITULO1)/2*/)<<"MINISTERIO DE TRASNPORTE"<<endl;
    ouput_reporte<<setw(10/*(TAM_MAX - TITULO3) /2*/)<<""<<"RANGO DE FECHAS A CONSUsssLTAR: DEL "<<d_i<<"/"<<m_i<<"/"<<a_i<<" AL "<<d_f<<"/"<<m_f<<"/"<<a_f<<endl;
    ouput_reporte<<"DEBERIA IMPRIMIRSE ESTO SI ES QUE FUNCIONA";
    
}

void Leer_multas(ifstream &input_infracciones){
    while(input_infracciones.get() != '\n');//decartar hasta el salto de linea
}

//void imprimir_header(int dni,int n, ifstream &input_infracciones, ifstream &input_empresas, ofstream ouput_reporte ){
//    
//}

void leer_procesar_infracciones(const char* name_arch_empresas,
                                const char* name_arch_vehiculos,
                                const char* name_arch_infracciones,
                                const char* name_arch_reporte){
    
    ifstream input_empresas;
    ifstream input_vehiculos;
    ifstream input_infracciones;
    ofstream ouput_reporte;
    
    apertura_lectura(input_empresas, name_arch_empresas);
    apertura_lectura(input_vehiculos, name_arch_vehiculos);
    apertura_lectura(input_infracciones, name_arch_infracciones);
    apertura_escritura(ouput_reporte, name_arch_reporte);
    
    int d_i, m_i, a_i, d_f, m_f, a_f, dni;
    char slash;
    input_infracciones>>d_i >>slash>> m_i >>slash>>a_i >>d_f >>slash>> m_f >>slash>> a_f;
    
    imprimpir_titulo(d_i, m_i, a_i, d_f, m_f, a_f, ouput_reporte);
    
    int n=1;
    while(true){
        input_infracciones>>dni;
//        imprimir_header(dni,n, input_infracciones, input_empresas, ouput_reporte ) ;
        Leer_multas(input_infracciones);
        n++;
    }
}




