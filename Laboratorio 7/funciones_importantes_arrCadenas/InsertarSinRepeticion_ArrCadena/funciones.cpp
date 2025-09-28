/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 7 de junio de 2025, 19:38
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

int busquedaCadena(char* cadena,char** arrCadena ,int cant){
    for(int i=0;i<cant;i++){
        if(strcmp(cadena,arrCadena[i])==0)return i;
    }
    return NO_ENCONTRADO;
}

char* leer_cadena(ifstream &input, char del){
    char* cadena;
    char temporal [100];
    input.getline(temporal, 100, del);
    cadena = new char[strlen(temporal)+1];
    strcpy(cadena, temporal);
    return cadena;
}

void  reservar_memoria_fija(char** generos){
    for(int i=0;i<MAXCANTANTES;i++){
        generos[i] = new char[200];
    }
}


void procesar_generos(char*genero,char**generos,int posArtista){
    
    char* pos = strstr(generos[posArtista], genero);
    
    if(pos == nullptr ){//el nuevo genero no estaba en la cadena, se le debe agregar
        strcat(generos[posArtista], "/");
        strcat(generos[posArtista], genero);
    }
    //si es diferente a nullptr entonces signifca que ya estaba en generos, como ya estaba
    //no se concatena nada
    
}

void insertarSinRepeticion(char* artista,int reproduccion,double bailable,char*genero,
                char** artistas,char**generos,int*reproducciones,double*bailables,int&cantCantantes){
    int posArtista = busquedaCadena(artista,artistas,cantCantantes);
    if(posArtista == NO_ENCONTRADO){
        artistas[cantCantantes] = artista;
        reproducciones[cantCantantes] = reproduccion;
        bailables[cantCantantes] = bailable;
        //para los que se va a concatenar
        strcpy(generos[cantCantantes],genero);
        cantCantantes++;
    }
    else{
        reproducciones[posArtista] += reproduccion;
        bailables[posArtista] += bailable;
        procesar_generos(genero,generos,posArtista);
    }
}

void leer_canciones(char**artistas,char**generos,int* reproducciones,double* bailables,int& cantCantantes){
    ifstream input;
    apertura_lectura(input, "music_dataset_extended.csv");
    char* artista, *genero;
    int reproduccion;
    double bailable;
    
    //para los que se va a concatenar
    reservar_memoria_fija(generos);
    
    while(true){
        artista = leer_cadena(input, ',');
        if(input.eof()) break;
        ignorar(input, ',');
        input>>reproduccion;
        input.get();
        input>>bailable;
        input.get();
        genero = leer_cadena(input, '\n');
        insertarSinRepeticion(artista,reproduccion,bailable,genero,
                             artistas,generos,reproducciones,bailables,cantCantantes);
    }
}

void imprimir_reporte(char**artistas,char**generos,int*reproducciones,double*bailables,int&cantCantantes){
    ofstream ouput;
    apertura_escritura(ouput, "reporte.txt");
    int tam= TAMREPORTE/3;     
    imprimir_titulo(ouput, "REPORTE DE CANTANTES SIN REPETIR");
    
    ouput<<setw(tam)<<"NOMBRE DEL ARTISTA"
            <<setw(tam)<<"NUMERO DE REPRODUCCIONES"
            <<setw(tam)<<"BAILABLE"<<endl;
    
    for(int i=0;i<cantCantantes;i++){
        ouput<<setw(10)<<right<<i+1<<") ";
        ouput<<setw(tam)<<left<<artistas[i]
            <<setw(tam)<<reproducciones[i]
            <<setw(tam)<<bailables[i]<<endl;
        ouput<<setw(10)<<"Generos: "<<generos[i]<<endl;
    }
}