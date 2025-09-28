/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny romero luna
 * Codigo: 220233905
 * Descripcion: 
 *
 * Created on 7 de julio de 2025, 12:35
 */

#include "Funciones.hpp"
int main(int argc, char** argv) {
    struct ListaCurso lista_cursos;
    struct ListaEscala lista_escalas;
    struct ListaAlumno lista_alumnos;
    int ciclo=0, anio=0;
    
    leerCursos("Cursos.csv", lista_cursos);
    leerEscalas("Escalas.csv", lista_escalas);
    leerAlumnos("Alumnos.csv", lista_alumnos);
    emitir_reporte(anio, ciclo, lista_alumnos);
    
//    struct NodoCurso* recorrido = lista_cursos.inicio;
//    while(recorrido){
//        cout<<recorrido->datoCurso.codCurso<<"-"<<recorrido->datoCurso.nombre<<"-"<<recorrido->datoCurso.creditos<<endl;
//        recorrido = recorrido->siguiente;
//    }
    
    
//    struct NodoEscala* recorrido = lista_escalas.inicio;
//    while(recorrido){
//        cout<<recorrido->datoEscala.anho<<"-"<<recorrido->datoEscala.ciclo<<" "
//                <<recorrido->datoEscala.escala<<"-"<<recorrido->datoEscala.valorCred<<endl;
//        recorrido = recorrido->siguiente;
//    }

//    struct NodoAlumno* recorrido = lista_alumnos.inicio;
//    while(recorrido){
//        cout<<recorrido->datoAlumno.codAlumno<<"-"<<recorrido->datoAlumno.nombre<<"-"
//                <<recorrido->datoAlumno.escAlumno.escala<<endl;
//        recorrido = recorrido->siguiente;
//    }
    return 0;
}

