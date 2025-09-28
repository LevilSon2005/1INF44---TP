/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 8 de junio de 2025, 13:00
 */

#include "funciones.hpp"

apertura_lectura(ifstream &input, const char* name){
    input.open(name, ios::in);
    if(not input.is_open()){
        cout<<"El archivo "<<name<<" no se abrio"<<endl; 
    }
}

apertura_escritura(ofstream &ouput, const char* name){
    ouput.open(name, ios::out);
    if(not ouput.is_open()){
        cout<<"El archivo "<<name<<" no se abrio"<<endl; 
    }
    else
        cout<<"El reporte - "<<name<<" se abrio"<<endl;
}

void imprimir_titulo(ofstream &ouput, const char* titulo){
    ouput<<setw((TAMREPORTE+strlen(titulo))/2)<<titulo<<endl;
}

void imprimir_Car(ofstream &ouput, char c){
    ouput<<setfill(c)<<setw(TAMREPORTE)<<""<<setfill(' ')<<endl;
}

void ignorar(ifstream &input, char c){
    while(input.get() != c); 
}

char* leer_cadena(ifstream &input, char del){
    char* cadena;
    char temporal[100];
    input.getline(temporal, 100, del);
    cadena = new char[strlen(temporal)+1];
    strcpy(cadena, temporal);
    return cadena;
}

//asigna espacio y copia
char* asignar_cadena( char*cadena){
    char* cadena_return;
    cadena_return = new char[strlen(cadena)+1];
    strcpy(cadena_return, cadena);
    return cadena_return;
}

void insertarOrdenado(char**artistas,char**canciones,int&cantArtistas,
                      char*artista,char*cancion){
    int pos = cantArtistas-1;
    while(pos>=0 and strcmp(cancion, canciones[pos])<0){
        artistas[pos+1] = asignar_cadena(artistas[pos]);
        canciones[pos+1] = asignar_cadena(canciones[pos]);
        pos--;
    }
    artistas[pos+1] = artista;
    canciones[pos+1] = cancion;
    cantArtistas++;
}

void leer_artistas(char**artistas,char**canciones,int*reproducciones,double*bailables,int&cantArtistas){
    ifstream input;
    apertura_lectura(input, "music_dataset_extended.csv");
    char*artista;
    char*cancion;
    
    while(true){
        artista = leer_cadena(input,',');
        if(input.eof()) break;
        cancion = leer_cadena(input, ',');
        ignorar(input, '\n');
        insertarOrdenado(artistas,canciones,cantArtistas,
                        artista,cancion);
    }
}

void imprimir_reporte(char**artistas,char**canciones,int cantArtistas){
    ofstream ouput;
    apertura_escritura(ouput,  "reporteInsertarOrdenado.txt");
    int tam=TAMREPORTE/2;
    for(int i=0;i<cantArtistas;i++)
        ouput<<setw(tam)<<artistas[i]
              <<setw(tam)<<canciones[i]<<endl;
}


