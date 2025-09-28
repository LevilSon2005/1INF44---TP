/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 13 de mayo de 2025, 14:49
 */

#include "funciones.hpp"

void apertura_lectura(const char* name,ifstream &input){
    input.open(name,ios::in);
    if(not input.is_open()){
        cout <<"ERROR: El archivo "<<name<<" no se abre"<<endl; 
    }
}

void apertura_escritura(const char* name,ofstream &ouput){
    ouput.open(name,ios::out);
    if(not ouput.is_open()){
        cout <<"ERROR: El archivo "<<name<<" no se abre"<<endl; 
    }
    else{
        cout<<"El reporte se abrio"<<endl;
    }
}

void ignorar(ifstream &input, char delimitador){
    while(input.get() != delimitador);
}

void cargarArregloAlumnos(int *arrCodAlumno,int *arrEscalasAlumno,int &cantAlumnos){
    int codAlumno;
    ifstream inputAlumnos;
    apertura_lectura("Alumnos_lab5.txt",inputAlumnos);
    
    while(true){
        inputAlumnos>>codAlumno;
        if(inputAlumnos.eof()) break;
        arrCodAlumno[cantAlumnos] = codAlumno;
        inputAlumnos>>ws;
        ignorar(inputAlumnos, ' ');
        inputAlumnos>>arrEscalasAlumno[cantAlumnos];
        cantAlumnos++;
    }
}

void  cargarArregloCursos(int *arrCodCurso,double *arrCreditoCurso,int &cantCursos){
    int codCurso;
    ifstream inputCursos;
    apertura_lectura("Cursos_lab5.txt",inputCursos);

    while(true){
        inputCursos>>codCurso;
        if(inputCursos.eof()) break;
        arrCodCurso[cantCursos] = codCurso;
        inputCursos>>ws;
        ignorar(inputCursos, ' ');
        inputCursos>>arrCreditoCurso[cantCursos];
        
        cantCursos++;
    }
}

void cargarArregloEscalas(double *arrPreciosEscalas,int &cantEscalas){
    ifstream inputEscalas;
    apertura_lectura("Escalas_lab5.txt", inputEscalas);
    int escala;
    //como esta ordenado la podemos manejar a cual es precio de cada escala con los indices del arreglo
    while(true){
        inputEscalas>>escala;
        if(inputEscalas.eof()) break;
        arrPreciosEscalas[cantEscalas]=escala;
        cantEscalas++;
    }
}

void obtenerPosicionAlumno(int codAlumno, int *arrCodAlumno,int *arrEscalasAlumno,int cantAlumnos){
    
    for (int i=0;i<cantAlumnos;i++){
        if(codAlumno == arrCodAlumno[cantAlumnos]){
            return i;
        }
    }
   
    return NO_ENCONTRADO;
}

void obtenerPosicionCurso(int codCurso,int *arrCodCurso,double *arrCreditoCurso,int cantCursos){
    for(int i=0;i<cantCursos;i++){
        if(codCurso == arrCodCurso[i]){
            return i;
        }
    }
    return NO_ENCONTRADO;
}

void cargarArreglosIntermedios(int codAlumno,int codCurso,
                                int *arrCodAlumno,int *arrEscalasAlumno,int cantAlumnos,
                                int *arrCodCurso,double *arrCreditoCurso,int cantCursos,
                                double *arrPreciosEscalas,int cantEscalas,
                                int *arrEnterosTotalesAlumnos,double *arrDoublesTotalesAlumnos,
                                int *arrEnterosTotalesCursos,double *arrDoublesTotalesCursos){
    int posAlumno,posCurso;
    posAlumno = obtenerPosicionAlumno(codAlumno,arrCodAlumno,arrEscalasAlumno,cantAlumnos);
    posCurso = obtenerPosicionCurso(codCurso,arrCodCurso,arrCreditoCurso,cantCursos);
    
    if(posAlumno != NO_ENCONTRADO ){
//        
//        arrEnterosTotalesAlumnos[3*posAlumno] = codAlumno; //alumno
//        arrEnterosTotalesAlumnos[3*posAlumno+1] = arrEscalasAlumno[posAlumno]; //escala
//        arrEnterosTotalesAlumnos[3*posAlumno+2] = arrEscalasAlumno[posAlumno]; //total de cursos
        
    }
    
}

void LeerMatricula(int *arrCodAlumno,int *arrEscalasAlumno,int cantAlumnos,
                                int *arrCodCurso,double *arrCreditoCurso,int cantCursos,
                                double *arrPreciosEscalas,int cantEscalas,
                                int *arrEnterosTotalesAlumnos,double *arrDoublesTotalesAlumnos,
                                int *arrEnterosTotalesCursos,double *arrDoublesTotalesCursos){
    
    ifstream inputMatricula;
    apertura_lectura("Matricula_lab5.txt",inputMatricula);
    
    int codAlumno, codCurso;
    
    while(true){//leo en cada linea los alumnos matriculos y sus cursos
        inputMatricula>>codAlumno;
        if(inputMatricula.eof()) break;
        inputMatricula>>codCurso;
        
        cargarArreglosIntermedios(codAlumno,codCurso,
                                arrCodAlumno,arrEscalasAlumno,cantAlumnos,
                                 arrCodCurso,arrCreditoCurso,cantCursos,
                                arrPreciosEscalas,cantEscalas,
                arrEnterosTotalesAlumnos,arrDoublesTotalesAlumnos,
            arrEnterosTotalesCursos,arrDoublesTotalesCursos);
    }
    
}