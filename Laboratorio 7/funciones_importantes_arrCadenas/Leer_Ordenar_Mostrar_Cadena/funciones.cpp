/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 7 de junio de 2025, 16:36
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

//ya lee el char delimitador
char* leer_cadena(ifstream &input, char del){
    char temporal[60];
    char* cadena;
    input.getline(temporal, 60, del);
    cadena = new char[strlen(temporal)+1];
    strcpy(cadena, temporal);
    
    return cadena;
}

void leer_artistas(char**artistas,char**canciones,int*reproducciones,double*bailable,int&cantArtistas){
    ifstream input;
    apertura_lectura(input, "music_dataset.csv");
    
    char *artista,c; 
    while(true){
        artista = leer_cadena(input, ',');
        if(input.eof()) break;
        artistas[cantArtistas] = artista;
        canciones[cantArtistas] = leer_cadena(input,',');
        input>>reproducciones[cantArtistas]>>c>>bailable[cantArtistas];
        input.get();
        cantArtistas++;
    }
}

void intercambiar_i(int &a,int &b){
    int aux;
    aux = a;
    a = b;
    b=aux;
}

void intercambiar_d(double &a,double &b){
    double aux;
    aux = a;
    a = b;
    b=aux;
}

void intercambiar_cadena(char* &a, char* &b){
    char* aux;
    aux= a;
    a=b;
    b=aux;
    
}


void ordenar_artistas(char**artistas,char**canciones,int*reproducciones,double*bailable,int cantArtistas){
    for(int i=0;i<cantArtistas-1;i++){
        for(int k=i+1; k<cantArtistas;k++){
            if(strcmp(artistas[k],artistas[i])<0){
                intercambiar_cadena(artistas[k],artistas[i]);
                intercambiar_cadena(canciones[k],canciones[i]);
                intercambiar_i(reproducciones[k],reproducciones[i]);
                intercambiar_d(bailable[k],bailable[i]);
            }
        }
    }
}

void imprimir_reporte(char**artistas,char**canciones,int*reproducciones,double*bailable,int cantArtistas){
    ofstream ouput;
    apertura_escritura(ouput,"reporte.txt" );
    imprimir_titulo(ouput, "LISTAS DE REPRODUCCION DE SPOTIFY");
    int tam=TAMREPORTE/5;
    ouput<<setw(tam)<<"ARTISTA"
         <<setw(tam)<<"CANCION"
         <<setw(tam)<<"REPRODUCCIONES"
         <<setw(tam)<<"BAILABLE"<<endl;
    
    for(int i=0;i<cantArtistas;i++)
        ouput<<setw(tam)<<artistas[i]
         <<setw(tam)<<canciones[i]
         <<setw(tam)<<reproducciones[i]
         <<setw(tam)<<bailable[i]<<endl;
}
