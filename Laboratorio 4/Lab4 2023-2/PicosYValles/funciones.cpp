/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 5 de mayo de 2025, 17:41
 */

#include <cinttypes>

#include "funciones.hpp"

void apertura_lectura(const char* name,ifstream &input){
    input.open(name,  ios::in);
    if(not input.is_open()) {
        cout<<"ERROR: El archivo "<< name<<" no se abrio"<<endl;
    }
}
void apertura_escritura(const char* name,ofstream &ouput){
    ouput.open(name,  ios::out);
    if(not ouput.is_open()) {
        cout<<"ERROR: El archivo "<< name<<" no se abrio"<<endl;
    }
    else{
        cout<<"El abrio se abrio"<<endl;
    }
}

void cargarArreglos(int* ArrAniosPico,int* ArrAniosValle,int* ArrGananciasPico,int* ArrGananciasValle,int &cantPeriodos,
                    int &ValleMenor, int &picoMayor, int &aniomenor, int &aniomayor){
    ifstream inputGanancias;
    apertura_lectura("ganancias.txt",inputGanancias);
    char c;
    bool acabo = false;
    int anio, ganancia, gananciaPico, gananciaValle, aniopico =0, anioValle=0;
    ValleMenor=1e9, picoMayor =0, aniomenor, aniomayor;
    while(true){//leercadaPeriodo
        gananciaPico = 0;
        gananciaValle =1e9;
        while(true){
            inputGanancias>>anio;
            if(inputGanancias.eof()){
                acabo = true;
                break;}
            inputGanancias>>ganancia;
            c = inputGanancias.get();            
            if(ganancia >gananciaPico) {gananciaPico = ganancia;
            aniopico = anio;}
            if(ganancia <gananciaValle) {gananciaValle = ganancia;
            anioValle = anio;}
            if(c == '\n') break;
        }
        if(acabo) break;
        if(gananciaValle < ValleMenor) {
            aniomenor = anioValle;
            ValleMenor = gananciaValle;
        }
        if(gananciaPico > picoMayor){
            aniomayor = aniopico;
            picoMayor = gananciaPico;
        }
        ArrAniosPico[cantPeriodos] = aniopico;
        ArrAniosValle[cantPeriodos] = anioValle;
        ArrGananciasPico[cantPeriodos] = gananciaPico;
        ArrGananciasValle[cantPeriodos] = gananciaValle;
        cantPeriodos++;
    }
}   

void imprimir_linCar(ofstream &ouput, char c){
    ouput<<setw(TAMREPORTE)<<setfill(c)<<""<<setfill(' ')<<endl;
}

void procesarEImprimirDatos(int* ArrAniosPico,int* ArrAniosValle,int* ArrGananciasPico,int* ArrGananciasValle,int cantPeriodos,
                            int ValleMenor, int picoMayor, int aniomenor, int aniomayor){
    ofstream ouput;
    apertura_escritura("reporte.txt", ouput);
    int tam = TAMREPORTE/2;
    ouput<<setw(TAMREPORTE)<<"REPORTE DE EMPRESA TP"<<endl;
    imprimir_linCar(ouput, '=');
    ouput<<setw(tam)<<left<<"PERIODO"<<setw(tam)<<left<<"PICO"<<endl;
    imprimir_linCar(ouput, '-');
    //imprimir arreglo
    for (int i=0; i<cantPeriodos;i++){
        ouput<<setw(tam)<<left<<ArrAniosPico[i]<<setw(tam)<<left<<ArrGananciasPico[i]<<endl;
    }
    imprimir_linCar(ouput, '-');
    ouput<<"MAYOR PICO: El mayor fue: "<<aniomayor<< " con "<<picoMayor<<" millones."<<endl;
}