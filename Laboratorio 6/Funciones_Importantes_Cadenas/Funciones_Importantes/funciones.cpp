/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 1 de junio de 2025, 12:25
 */

#include "funciones.hpp"

void apertura_lectura(const char* name,ifstream &input){
    input.open(name,ios::in);
    if(not input.is_open()){
        cout<<"ERROR: El archivo "<<name<<" no se abrio correctamente"<<endl;
    }
}

void apertura_escritura(const char* name,ofstream &ouput){
    ouput.open(name,ios::out);
    if(not ouput.is_open()){
        cout<<"ERROR: El archivo "<<name<<" no se abrio correctamente"<<endl;
    }
    else{
        cout<<"Se abrio correctamente"<<endl;
    }
}

void imprimir_linCar( ofstream &ouput,char c){
    ouput<<setw(TAMREPORTE)<<setfill(c)<<""<<setfill(' ')<<endl;
}

int hallarIndInicial(char* ListasMusicas,int n){
    if(n<1) return NO_ENCONTRADO; //por si la cantidad de tokens era cero
    int current=1;
    for(int i=0;ListasMusicas[i];i++){
        if(current == n) return i; 
        if(ListasMusicas[i] == '/') current++;
    }
    
    return NO_ENCONTRADO; //es por si el numero de token que quiero sea mayor a los tokens que hay
}

int hallarCantidadTokens(char* ListasMusicas){
    int i=0;
    int cant=0;
    if(ListasMusicas[i]=='\0') return 0;
    for(int i=0;ListasMusicas[i];i++){
        if(ListasMusicas[i] == '/') cant++;
    }
    
    return cant+1;
}

int hallarIndFinal(char* ListasMusicas,int n, int star){
    int i=star;
    for( ; ListasMusicas[i] != '/' and ListasMusicas[i] != '\0' ;i++);
    return i-1;//el i de la ultima letra del token
    
}


void formarUnToken(char *ListasMusicas,int star,int end,char* UnaMusica){
    int k=0;
    for(int i=star; i<=end;i++){
        UnaMusica[k++]=ListasMusicas[i];
    }
    UnaMusica[k] = '\0';
}

void sacarToken(char *ListasMusicas,int n_Token,char *UnaMusica){
    int star = hallarIndInicial(ListasMusicas,n_Token);
    if(star ==NO_ENCONTRADO) return;
    int end = hallarIndFinal(ListasMusicas,n_Token, star);
    cout<<star<<"-"<<end<<endl;
    formarUnToken(ListasMusicas,star,end,UnaMusica);
}

void ImprimirTokens(char* ListasMusicas, ofstream &ouput){
    int cantTokens = hallarCantidadTokens(ListasMusicas);
    char UnaMusica[MAXMUSICA]{};
    for(int i=0;i<cantTokens;i++){
        int n_Token=i+1; //el numero de musica dentro del arreglo que quiero sacar
        sacarToken(ListasMusicas,n_Token,UnaMusica);
        ouput<<UnaMusica<<endl;
    }
}

void procesar_Musica(const char* nameArh, const char* nameReporte){
    ifstream input;
    ofstream ouput;
    apertura_lectura(nameArh, input);
    apertura_escritura(nameReporte,ouput);
    int codigo;
    char ListasMusicas[MAXMUSICA]{};
    
    while(true){
        input>>codigo;
        if(input.eof()) break;
        input>>ListasMusicas;
        ImprimirTokens(ListasMusicas, ouput);
        input.get(); //para leer el caracter de '\n'
    }
}
