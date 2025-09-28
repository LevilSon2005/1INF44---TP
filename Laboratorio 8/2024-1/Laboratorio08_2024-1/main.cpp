/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 16 de junio de 2025, 15:36
 */

#include "Funciones.hpp"
int main(int argc, char** argv) {
    struct Facultad arrFacultades[MAXFACULTADES]{};
    struct Alumno arrAlumnos[MAXALUMNOS]{};
    int cantAlumnos=0, cantFacultades=0;
    
    leerCalificaciones("Calificaciones.txt",arrAlumnos,cantAlumnos);
    leerAlumno("Alumnos.csv",arrAlumnos,cantAlumnos);
    leerFacultades("Facultades.txt",arrAlumnos,cantAlumnos);
//    emitir_reporte("Facultades.txt",arrAlumnos,cantAlumnos);
    
    for(int i=0;i<cantAlumnos;i++){
        cout<<i+1<<endl;
        cout<<arrAlumnos[i].codigo<<endl;
        cout<<arrAlumnos[i].nombre<<endl;
        cout<<arrAlumnos[i].numCursos<<endl;
        cout<<arrAlumnos[i].sumaPonderada<<endl;
        cout<<arrAlumnos[i].creditos<<endl;
        cout<<(arrAlumnos[i].sumaPonderada)/(arrAlumnos[i].creditos)<<endl;
        cout<<arrAlumnos[i].facultad.nombre<<endl;
        cout<<"--------------------"<<endl;
    }
    return 0;
}

