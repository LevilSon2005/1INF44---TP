/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 18 de mayo de 2025, 22:52
 */

#include "funciones.hpp"

void apertura_lectura(const char* name, ifstream &input){
    input.open(name, ios::in);
    if(not input.is_open())
        cout<<"ERROR: El archivo "<<name<<" no se abre"<<endl;
}
void apertura_escritura(const char* name, ofstream &ouput){
    ouput.open(name, ios::out);
    if(not ouput.is_open())
        cout<<"ERROR: El archivo "<<name<<" no se abre"<<endl;
    else
        cout<<"El reporte se abrio"<<endl;
}

void imprimir_lin(ofstream &ouput,char c){
    ouput<<setw(TAMREPORTE)<<setfill(c)<<""<<setfill(' ')<<endl;
}

void ignorar(ifstream &input, char delimitador){
    while(input.get() != delimitador);
}

void leer_imprimir_nombre(ifstream &inputAlumnos,ofstream &ouput){
    inputAlumnos>>ws;
    char c;
    int i=0,tam=TAMREPORTE/COLUMNAS, cant=0;
    while(true){
        c = inputAlumnos.get();
        if(c==' ') break;
        if(c=='_'){
            c= ' ';
            i=-1;
        }
        if(i>=0 and c>='a' and c<='z') c = c-('a'-'A');
        ouput.put(c);
        i++;
        cant++;
    }
    for(int j=0;j<(2*tam-cant-35);j++)  ouput.put(' ');
}

void imprimir_encabezado(ofstream &ouput,ifstream &inputAlumnos,int codAlumno, char &escalaAlumno){
    ouput<<"ALUMNOS: "<<codAlumno<<" - ";
    leer_imprimir_nombre(inputAlumnos,ouput);
    inputAlumnos>>escalaAlumno;
    ouput<<"ESCALA: "<<escalaAlumno<<endl;
}
void  buscar_imprimir_Cursos_UnAlumno(int n_alumnos,int anio,int ciclo,int codAlumno,char escalaAlumno,
                ifstream &inputCursos, ifstream &inputEsclas, ifstream &inputMatricula,ofstream &ouput,
                double &totalCredAlum,double &montoAlumno){
    inputMatricula.clear();
    inputMatricula.seekg(0, ios::beg);
    int cicloMatric, anioMatric, codigoAlumno;
    char c;
    while(true){
        inputMatricula>>anioMatric>>c>>anioMatric>>codigoAlumno;
        while(true){
            if(inputMatricula.get()=='\n') break;
            inputMatricula>>codigoAlumno;
        }
    }
}

void procesar_alumnos(ifstream &inputAlumnos, ifstream &inputCursos, ifstream &inputEsclas, ifstream &inputMatricula,ofstream &ouput,
                    int anio,int ciclo,
                    int&cantTotalAlumnos,double&montoTotalPagado){
    int codAlumno, tam=TAMREPORTE/COLUMNAS,n_alumnos=1;
    char escalaAlumno;
    int totalCredAlum=0;
    double montoAlumno=0.0;
    while(true){//PARA CADA ALUMNO
        inputAlumnos>>codAlumno;
        if(inputAlumnos.eof()) break;
        imprimir_encabezado(ouput,inputAlumnos,codAlumno, escalaAlumno);
        imprimir_lin(ouput, '-');
        ouput<<setw(tam)<<left<<"CURSO MATRICULADO"<<setw(tam)<<left<<"CREDITOS "<<setw(tam)<<left<<"MONTO PAGADO"<<endl;
        buscar_imprimir_Cursos_UnAlumno(n_alumnos,anio,ciclo,codAlumno,escalaAlumno,
                inputAlumnos, inputCursos, inputEsclas, inputMatricula,ouput,
                totalCredAlum,montoAlumno);
//        imprimir_resumenAlumno(totalCredAlum,montoAlumno,ouput);
        //PARA EL RESUMEN FINAL
        cantTotalAlumnos ++;
        montoTotalPagado += montoAlumno;
    }
    
}

void procesar_reporte(const char* nAlumnos,const char* nCursos,const char* nEscalas,const char* nMatricula,const char* nReporte){
    ifstream inputAlumnos, inputCursos, inputEsclas, inputMatricula;
    ofstream ouput;
    apertura_lectura(nAlumnos, inputAlumnos);
    apertura_lectura(nCursos, inputCursos);
    apertura_lectura(nEscalas, inputEsclas);
    apertura_lectura(nMatricula, inputMatricula);
    apertura_escritura(nReporte, ouput);
    
    int cantTotalAlumnos=0,anio,ciclo;
    double montoTotalPagado =0.0;
    
    cout<<"INGRESE EL ANIO Y CICLO QUE DESEA VER: "<<endl;
    cin>>anio>>ciclo;
    
//    imprimir_titulo(ouput, anio, ciclo);
    imprimir_lin(ouput,'=');
    procesar_alumnos(inputAlumnos, inputCursos, inputEsclas, inputMatricula,ouput,
                    anio,ciclo,
                    cantTotalAlumnos,montoTotalPagado);
//    imprimir_resumenGeneral(cantTotalAlumnos,montoTotalPagado,ouput);
}
