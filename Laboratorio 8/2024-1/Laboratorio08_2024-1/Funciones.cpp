/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 16 de junio de 2025, 15:44
 */

#include "Funciones.hpp"

void apertura_lectura(ifstream &input, const char* name){
    input.open(name, ios::in);
    if(not input.is_open())
        cout<<"El archivo "<<name<<" no se abrio"<<endl;
}

void apertura_escritura(ofstream &ouput, const char* name){
    ouput.open(name, ios::out);
    if(not ouput.is_open())
        cout<<"El archivo "<<name<<" no se abrio"<<endl;
    else
        cout<<"El reporte - "<<name<<" se abrio"<<endl;
}

void imprimir_titulo(ofstream &ouput, const char* titulo){
    ouput<<setw((TAMREPORTE+strlen(titulo))/2)<<titulo<<endl;
}

void imprimir_linC(ofstream &ouput,  char c){
    ouput<<setw(TAMREPORTE)<<setfill(c)<<""<<setfill(' ')<<endl;
}

void ignorar(ifstream &input, char del){
    while(input.get() != del);
}

char* leer_cadena_txt(ifstream &input, int tam){
    char* cadena;
    char temporal[tam];
    
    input>>temporal;
    cadena = new char[strlen(temporal)+1];
    strcpy(cadena, temporal);
    
    return cadena;
}

char* leer_cadena_getline(ifstream &input, char del){
    char* cadena;
    char temporal[100];
    
    input.getline(temporal, 100, del);
    cadena = new char[strlen(temporal)+1];
    strcpy(cadena, temporal);
    
    return cadena;
}

int buscarAlumno(int codAlumno,struct Alumno* arrAlumnos, int cantAlumnos){
    for(int i=0;i<cantAlumnos;i++){
        if(codAlumno == arrAlumnos[i].codigo)return i;
    }
    
    return NO_ENCONTRADO;
}

void insertarSinRepeticion(char* codCurso,double creditosCurso, int codAlumno, int nota,
                           struct Alumno* arrAlumnos,int &cantAlumnos){
    int posAlumno;
    posAlumno = buscarAlumno(codAlumno, arrAlumnos, cantAlumnos);
    
    if(posAlumno == NO_ENCONTRADO){//primera vez
        arrAlumnos[cantAlumnos].codigo = codAlumno;
        arrAlumnos[cantAlumnos].creditos = creditosCurso;
        arrAlumnos[cantAlumnos].sumaPonderada = creditosCurso * nota;
        arrAlumnos[cantAlumnos].numCursos = 1;
        cantAlumnos++;
    }
    else{//solo se acumula
        arrAlumnos[posAlumno].creditos += creditosCurso;
        arrAlumnos[posAlumno].sumaPonderada += creditosCurso * nota;
        arrAlumnos[posAlumno].numCursos ++;
    }
}

void leerCalificaciones(const char* name,struct Alumno* arrAlumnos,int &cantAlumnos){
    ifstream input;
    apertura_lectura(input, name);
    
    int  codAlumno, nota;
    double creditosCurso;
    
    char codCurso[20];
    while(true){
        input>>codCurso;
        if(input.eof()) break;
        input>>creditosCurso;
        while(true){
            if(input.get() == '\n') break;
            input>>codAlumno>>nota;
            insertarSinRepeticion(codCurso,creditosCurso, codAlumno, nota,
                                  arrAlumnos,cantAlumnos);
        }
    }
}

void leerAlumno(const char* name,struct Alumno* arrAlumnos,int &cantAlumnos){
    ifstream input;
    apertura_lectura(input, name);
    int codAlumno, posAlumno;
    
    while(true){
        input>>codAlumno;
        if(input.eof()) break;
        input.get();
        posAlumno = buscarAlumno(codAlumno, arrAlumnos, cantAlumnos);
        if(posAlumno != NO_ENCONTRADO){
            arrAlumnos[posAlumno].nombre = leer_cadena_getline(input, ',');
            arrAlumnos[posAlumno].facultad.codigo  = leer_cadena_getline(input, '\n');
        }
        else{
            ignorar(input, '\n');
        }
    }
}

char*  asignar_cadena(const char* buffer){
    char* cadena;
    
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    
    return cadena;
}

void leerFacultades(const char* name, struct Alumno* arrAlumnos,int cantAlumnos){
    ifstream input;
    apertura_lectura(input, name);
    int posAlumno;
    char nombre[MAXNOMBREFACU];
    char codigo[MAXNOMBREFACU];
    while(true){
        input>>nombre;
        if(input.eof()) break;
        input>>codigo;
        
        for(int i=0;i<cantAlumnos;i++){
            if(strcmp(arrAlumnos[i].facultad.codigo,codigo)==0){
                arrAlumnos[i].facultad.nombre = asignar_cadena(nombre);
            }
        }
    }
}


