/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 16 de junio de 2025, 11:25
 */

#include <random>
#include <cinttypes>

#include "Funciones.hpp"


void apertura_lectura(ifstream &input,const char* name ){
    input.open(name, ios::in);
    if(not input.is_open()){
        cout <<" El archivo "<<name<<" no se abrio"<<endl;
    }
}

void apertura_escrtitura(ofstream &ouput,const char* name ){
    ouput.open(name, ios::out);
    if(not ouput.is_open()){
        cout <<" El archivo "<<name<<" no se abrio"<<endl;
    }
    else
        cout <<" El reporte - "<<name<<" se abrio"<<endl;
}

void imprimir_titulo(ofstream &ouput, const char* titulo){
    ouput<<setw((TAMREPORTE + strlen(titulo))/2)<<titulo<<endl;
}

void imprimir_linC(ofstream &ouput, char c ){
    ouput<<setw(TAMREPORTE)<<setfill(c)<<""<<setfill(' ')<<endl;
}

void ignorar(ifstream &input, char del){
    while(input.get() != del);
}

void solicitarAnio_Ciclo(int &anioPedido,int & cicloPedido){
    anioPedido = 2023;
    cicloPedido = 1;
}


void leerAlumnos(const char* name,struct Alumno* arrAlumnos, int &cantAlumnos){
    ifstream input;
    apertura_lectura(input, name);
    
    int codigo;
    
    while(true){
        input>>codigo;
        if(input.eof()) break;
        input.get();
        arrAlumnos[cantAlumnos].codigo = codigo;
        input.getline(arrAlumnos[cantAlumnos].nombre, MAXNOMBRE, ',');
        input>>arrAlumnos[cantAlumnos].escala;
        cantAlumnos++;   
       
    }
}

void leerCursos(const char* name,struct Curso* arrCursos,int &cantCursos){
    ifstream input;
    apertura_lectura(input, name);
    int codigo;
    
    while(true){
        input>>codigo;
        if(input.eof()) break;
        input.get();
        arrCursos[cantCursos].codigo = codigo;
        input.getline(arrCursos[cantCursos].nombre, MAXNOMBRECURSO, ',');
        input>>arrCursos[cantCursos].creditos;
        cantCursos++;
    }
}

void leerEscalas(const char* name,struct Escala* arrEscalas,int &cantEscalas, int anioPedido, int cicloPedido){
    ifstream input;
    apertura_lectura(input, name);
    
    int ciclo, anio;
    char c;
    
    while(true){
        input>>anio;
        if(input.eof()) break;
        input>>c>>ciclo>>c;
        if(anio == anioPedido and ciclo == cicloPedido){
            arrEscalas[cantEscalas].anio = anio;
            arrEscalas[cantEscalas].ciclo = ciclo;

            input>>arrEscalas[cantEscalas].escala>>c;
            input>>arrEscalas[cantEscalas].precioCredEscala;
            cantEscalas++; 
        }
        else{
            ignorar(input, '\n');
        }
    }
}

int buscar_alumno(int codAlumno, struct Alumno* arrAlumnos, int cantAlumnos){
    for(int i=0;i<cantAlumnos;i++){
        if(codAlumno == arrAlumnos[i].codigo) return i;
    }
    return NO_ENCONTRADO;
}

int buscar_cursos(int codCurso, struct Curso* arrCursos, int cantCursos){
    for(int i=0;i<cantCursos;i++){
        if(codCurso == arrCursos[i].codigo) return i;
    }
    return NO_ENCONTRADO;
}

int buscar_escala(char escala, struct Escala* arrEscalas, int cantEscalas){
    for(int i=0;i<cantEscalas;i++){
        if(escala == arrEscalas[i].escala) return i;
    }
    return NO_ENCONTRADO;
}

void completarDatosCursos(int codAlumno,int codCurso,int anio, int ciclo,
                          struct Alumno* arrAlumnos, int cantAlumnos,
                          struct Escala* arrEscalas,int cantEscalas,
                          struct Curso* arrCursos,int cantCursos){
    int posAlumno = buscar_alumno(codAlumno, arrAlumnos, cantAlumnos);
    int posCurso = buscar_cursos(codCurso, arrCursos, cantCursos);
    
    double monto=0;
    double costoCredito;
    if(posAlumno != NO_ENCONTRADO and posCurso != NO_ENCONTRADO){
        int posEscala = buscar_escala(arrAlumnos[posAlumno].escala, arrEscalas, cantEscalas);
        (posEscala!=NO_ENCONTRADO)?(costoCredito = arrEscalas[posEscala].precioCredEscala):(costoCredito = 0.0);
        if(posEscala != NO_ENCONTRADO){
           arrCursos[posCurso].cantidadAlumnos_UnCurso++;
           monto  = (costoCredito* (arrCursos[posCurso].creditos));
           arrCursos[posCurso].montoPagado += monto; 
           
           cout<<arrCursos[posCurso].cantidadAlumnos_UnCurso<<endl;
           cout<<arrCursos[posCurso].montoPagado<<endl;
           cout<<monto<<endl;
        }
    }
}

void leerMatricula(const char* name, int anioPedido,int cicloPedido,
                  struct Alumno* arrAlumnos, int cantAlumnos,
                  struct Escala* arrEscalas,int cantEscalas,
                  struct Curso* arrCursos,int cantCursos){
    ifstream input;
    apertura_lectura(input, name);
    
    int ciclo, anio, codAlumno, codCurso;
    char c;
    
    while(true){
        input>>anio;
        if(input.eof()) break;
        input>>c>>ciclo>>c;
        if(anioPedido == anio and ciclo == cicloPedido){
            input>>codAlumno;
            while(true){
                if(input.get() == '\n') break;
                input>>codCurso;
//                cout<<"CodAlumno: "<<codAlumno<<endl;
//                cout<<"CodCurso: "<<codCurso<<endl;
                completarDatosCursos(codAlumno,codCurso,anio, ciclo,
                                    arrAlumnos, cantAlumnos,
                                    arrEscalas,cantEscalas,
                                    arrCursos,cantCursos);
            }
        }
        else
            ignorar(input, '\n');
    } 
}

void cambiar_struct(struct Curso&a, struct Curso&b){
    struct Curso aux;
    aux=a;
    a=b;
    b=aux;
}

void ordenar(struct Curso* arrCursos,int cantCursos){
    int cant1, cant2;
    for(int i=0;i<cantCursos-1;i++){
        for(int k=i+1;k<cantCursos;k++){
            cant1= arrCursos[i].cantidadAlumnos_UnCurso;
            cant2= arrCursos[k].cantidadAlumnos_UnCurso;
            if((strcmp(arrCursos[i].nombre, arrCursos[k].nombre)<0 )or (strcmp(arrCursos[i].nombre, arrCursos[k].nombre)==0 and cant1>cant2 )){
                cambiar_struct(arrCursos[i], arrCursos[k]);
            }
        }
    }
}

void imprimir_titulo(ofstream &ouput){
    imprimir_titulo(ouput, "INSTITUCION EDUCATIVA_TP");
    imprimir_titulo(ouput, "DETALLE DE PAGOS REALIZADOS POR CICLO");
    imprimir_titulo(ouput, "CICLO: 2023-1");
    
}

void imprimir_header(ofstream &ouput){
    ouput<<setw(4)<<left<<"No. ";
    ouput<<setw(67)<<"CURSO"
         <<setw(15)<<"CREDITOS"
         <<setw(15)<<"ALUMNOS MAT."
         <<setw(15)<<"MONTO PAGADO"<<endl;
}

void imprimir_reporte(const char* name,struct Curso* arrCursos,int cantCursos){
    ofstream ouput;
    apertura_escrtitura(ouput, name);
    double montoTotal = 0;
    
    imprimir_titulo(ouput);
    imprimir_linC(ouput, '=');
    imprimir_header(ouput);
    imprimir_linC(ouput, '-');
    
    ouput<<fixed<<setprecision(2);
    
    for(int i=0;i<cantCursos;i++){
        ouput<<setw(2)<<right<<setfill('0')<<i+1<<setfill(' ')<<") ";
        ouput<<arrCursos[i].codigo<<" - "
             <<setw(60)<<left<<arrCursos[i].nombre
             <<setw(15)<<arrCursos[i].creditos
             <<setw(15)<<arrCursos[i].cantidadAlumnos_UnCurso
             <<setw(15)<<arrCursos[i].montoPagado<<endl;
        montoTotal += arrCursos[i].montoPagado;
    }
    imprimir_linC(ouput, '-');
    ouput<<" MONTO TOTAL PAGADO: "<<setw(82)<<left<<""<<montoTotal<<endl;
    imprimir_linC(ouput, '=');
    
}