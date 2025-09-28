/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 8 de abril de 2025, 16:39
 */

#include "Funciones.hpp"

/*
 MODELO:
45601937 Justino/Norabuena/Virginia-Karina   18:49:08   42.91   20:07:05   18°36'43"   43.73   21:33:49   154°44'38"   57.89   22:55:49   37°48'51"

 */

void Leer_Procesar_Repartidores(){
    
//    procesar_Titulo_General();
    cout<<"ESTE ES EL NUEVO PORFISS";
     int dni;   
/*TODO ESTO DENTRO DEL WHIEL(TRUE)*/
   
    while(true){
         cin>>dni;
        if (cin.eof()) break;

        cout<<fixed;
        cout<<setprecision(4);

        procesar_Cada_Repartidor(dni);       
    } 

 /* -------------*/   
    
}


void procesar_Cada_Repartidor(int dni){
//    69323674    M    31/03/2013  13:54:27     16:12:37   556    0    0     B
    
    /*LECTURA DE DATOS*/
    char sexo;
    int dd, mm, aa;
    char car;
    int h_i, m_i, s_i;
    int h_f, m_f, s_f;
    int canal_1, canal_2, canal_3;
    char compania;
    
    int fecha;
    int seg_i, seg_f;
    
    cin>>ws;
    cin>>sexo;
    cin>>dd>>car>>mm>>car>>aa;
    cin>>dd>>car>>mm>>car>>aa;
    cin>>h_i>>car>>m_i>>car>>s_i;
    cin>>h_f>>car>>m_f>>car>>s_f;
    cin >>canal_1>>canal_2>>canal_3;
    cin>>compania;
    
    fecha = dd*10000 + mm*100 + aa;
    seg_i = transformacion_Seg(h_i,m_i, s_i );
    seg_f = transformacion_Seg(h_f,m_f, s_f );
    
    
    
    imprimir_linea(dni, sexo,fecha, seg_i, seg_f, canal_1, canal_2, canal_3, compania );
    
    
}

int transformacion_Seg(int h,int m, int s){
    
    return (h*3600 + m*60 + s);
}

//Para imprimir
//DNI   Sexo   Categogria   Hora_I   Hora_f  Duracion(H:M:S)  Duracion(H) Canales Compania

void imprimir_linea(int dni,char sexo,int fecha, int seg_i, int seg_f, int canal_1, int canal_2, int canal_3, char compania ){
    
    double seg_duracion;
    seg_duracion = seg_f - seg_i;
    
    cout<<setw(TAM_MAX/NUM_COLUMNAS)<<dni;
    imprimir_Sexo(sexo);
    imprimir_categoria(fecha);
    imprimir_hora(seg_i);
    imprimir_hora(seg_duracion);
    cout<<setw(TAM_MAX/NUM_COLUMNAS)<<seg_duracion/3600;
    imprimir_canales(canal_1, canal_2, canal_3);
    imprimir_compania(compania);
    
    
}

void imprimir_Sexo(char s){
    if (s =='F') cout<<setw(TAM_MAX/NUM_COLUMNAS)<<"FEMENINO";
    else cout<<setw(TAM_MAX/NUM_COLUMNAS)<<"MASCULINO";
}

void imprimir_categoria(int fecha){
    int aa;
    aa=fecha%10000;
    
    if(aa>2009) {
        cout<<setw(TAM_MAX/NUM_COLUMNAS)<<"Menor";
    }
    else if(aa<1988){
        cout<<setw(TAM_MAX/NUM_COLUMNAS)<<"Adulto";
    }
    else{
        cout<<setw(TAM_MAX/NUM_COLUMNAS)<<"Joven";
    }
    
}

void imprimir_hora(int s){
    int h, m, sg;
    h=s/3600;
    m=(s/60)%60;
    sg = s%60;
    char c = ':';
    
    cout<<setw(TAM_MAX/NUM_COLUMNAS-8)<<""<<h<<c<<m<<c<<sg;
    
}

void imprimir_canales(int canal_1, int canal_2, int canal_3){
    char c;
    c= '/';
    bool primero = true;
    
    cout<<setw(TAM_MAX/NUM_COLUMNAS-10)<<"";
    
    if (canal_1>0){
        cout<<canal_1;
        primero = false;
    } 
    if (canal_2>0){
        if(!primero) cout<<'/';
        cout<<canal_2;
        primero = false; 
    } 
    if (canal_3>0){
        if(!primero) cout<<'/';
        cout<<canal_3;  
    } 
}

void imprimir_compania(char comp){
    if(comp == 'A') cout<<setw(TAM_MAX/NUM_COLUMNAS)<<"TVPUCP";
    if(comp == 'B') cout<<setw(TAM_MAX/NUM_COLUMNAS)<<"CableMas";
    if(comp == 'C') cout<<setw(TAM_MAX/NUM_COLUMNAS)<<"TPVision";
}