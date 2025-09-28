/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 15 de abril de 2025, 16:00
 */

#include "Funciones.hpp"

void Leer_Y_Procesar(){
    int dni, n=1;
    char D, N, I;
    imprimir_titulo();
    while(true){
        cin>>dni;
        if(cin.eof()) break;
        n++;
        cin>>D>>N>>I>>dni;
        cin>>ws;
        imprimir_cabecera( dni,n);
    }
}

void imprimir_cabecera(int dni, int n){
    int tam= TAM_MAX/4;
    cout<<"CLIENTE N° " << n<<endl;
    cout<<"DNI: "<<dni<<setw(tam- DNI)<<"";
    cout<<"NOMBRE: ";
    Leer_Imprimir_nombre();
    cout<<endl;
    imprimir_linea_caract('-');
}

void imprimir_linea_caract(char c){
    cout<<setw(TAM_MAX)<<setfill(c)<<""<<endl;
}

void imprimir_titulo(){
    imprimir_linea_caract('=');
    cout<<setw(TAM_MAX + TITULO1 /2)<< "CLIENTES MOVILES 2025"<<endl;
    imprimir_linea_caract('=');
    cout<<setw(TAM_MAX + TITULO1 /2)<< "EMPRESA DE SERVICIOS: MOVISTAR S.A."<<endl;
    imprimir_linea_caract('=');
}

void Leer_Imprimir_nombre(){
    //Escalona-Zurita-Estela --> Escalona Zurita, Estela
    char c;
    int guion = 0;
    
    while(true){
        c = cin.get();
        if(c=='-') {
            c=' ';
            guion++;
        }
        if(guion == 2) c = ',';
        if(c==' ')break;
        cout.put(c);
        
    }
    
    
}