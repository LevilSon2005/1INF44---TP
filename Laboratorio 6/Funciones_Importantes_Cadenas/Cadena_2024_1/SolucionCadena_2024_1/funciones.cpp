/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: aml
 * 
 * Created on 2 de junio de 2025, 04:47 PM
 */

#include "funciones.hpp"

void apertura_lectura(const char* name, ifstream &input){
    input.open(name, ios::in);
    if(not input.is_open()){
        cout<<"El archivo "<<name<<" no se abrio"<<endl;
    }
}

void apertura_esritura(const char* name, ofstream &ouput){
    ouput.open(name, ios::out);
    if(not ouput.is_open()){
        cout<<"El archivo "<<name<<" no se abrio"<<endl;
    }
    else
        cout<<"El reporte se abrio"<<endl;
}

void imprimir_linC(ofstream &ouput, char c){
    ouput<<setw(TAMREPORTE)<<setfill(c)<<""<<setfill(' ')<<endl;
}

void ignorar(ifstream& input, char delimitador){
    while(input.get() != delimitador);
}

int hallarCantidadTokens(char* cadena){
    int cant=0;
    for(int i=0; cadena[i];i++){
        if(cadena[i] == '/' or cadena[i] == '-' ) cant++;
    }
    return cant+1;
}

int buscarInicio(const char* cadena,int n){
    int current=1;
    for(int i=0; cadena[i];i++){
        if(current == n) return i;
        if(cadena[i] == '/' or cadena[i] == '-') current++;
    }
    return -1;
}

int buscarFinal(const char* cadena, int star){
    int i=star;
    while(true){
        if(cadena[i] == '/' or cadena[i]=='-') return i-1;
        i++;
    }
    
}

void formarToken(const char* cadena,int star, int end,char* aux){
    int k=0;
    for(int i=star;i<=end;i++){
       aux[k++]  = cadena[i];
    }
    aux[k]='\0';
}

void sacarToken(const char* cadena,int n,char*token){
   
    int star = buscarInicio(cadena,n);
    if(star<0) return ;
    int end = buscarFinal(cadena,star);
    formarToken(cadena,star,end,token);
}

int my_strlen(const char* cadena){
    int i;
    for(i=0;cadena[i];i++);
    return i;
}

void my_strcpy(char* cadena1, const char* source){
    int i;
    for(i=0;source[i];i++){
        cadena1[i] = source[i];
    }
    cadena1[i] ='\0';
}

void my_strcat(char* cadena1, const char* cadena2){
    int pos=my_strlen(cadena1);
    my_strcpy(&cadena1[pos], cadena2);
}

void formatearNombre(char* apellidos,char*nombres,int n,char* token){
    
  
    if(n=1)my_strcpy(apellidos,token);
    else if(n=2){
        my_strcat(apellidos, " ");
        my_strcat(apellidos,token);
    }
    else if(n=3){
        my_strcpy(nombres,token);
    }
    else{
        my_strcat(nombres, " ");
        my_strcat(nombres, token);
    }
    
}

void juntar(char* apellidos,char*nombres,char* nombreCompleto){
    char aux[MAXNOMBRE]{};
    
    my_strcpy(aux, nombres);
    my_strcat(aux, " ");
    my_strcat(aux, apellidos);
    my_strcpy(nombreCompleto,aux);
}

void imprimeNombre(char* nombreCompleto){
    int n;
    char token[MAXNOMBRE]{};
    char apellidos[MAXNOMBRE]{};
    char nombres[MAXNOMBRE]{};
    int canTokens=hallarCantidadTokens(nombreCompleto);
    for(int i=0;i<canTokens;i++){
        n=i+1;
        sacarToken(nombreCompleto,n,token);
        formatearNombre(apellidos, nombres,n,token);
        juntar(apellidos,nombres,nombreCompleto);
    }
}

void leeAlumnos(){
    ifstream inputAlumnos;
    apertura_lectura("Alumnos (1).txt", inputAlumnos);
    int codAlumno,num;
    char nombreCompleto[MAXNOMBRE]{};
    
    while(true){
        inputAlumnos>>codAlumno;
        if(inputAlumnos.eof()) break;
        inputAlumnos>>nombreCompleto>>num;
        cout<<"Nombre Completo: "<<nombreCompleto<<endl;
        imprimeNombre(nombreCompleto);
    }
    
}