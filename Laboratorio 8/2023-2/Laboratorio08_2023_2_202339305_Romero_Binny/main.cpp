/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 16 de junio de 2025, 11:24
 */

#include "Funciones.hpp"
int main(int argc, char** argv) {
    int anioPedido, cicloPedido;
    struct Alumno arrAlumnos[MAXALUMNOS]{}; 
    struct Curso arrCursos[MAXCURSOS]{};
    struct Escala arrEscalas[MAXESCALAS]{};
    int cantAlumnos=0, cantCursos=0, cantEscalas=0;
    
    solicitarAnio_Ciclo(anioPedido, cicloPedido);
    leerAlumnos("Alumnos.csv",arrAlumnos, cantAlumnos);
    leerCursos("Cursos.csv", arrCursos,cantCursos);
    leerEscalas("Escalas.csv", arrEscalas,cantEscalas,anioPedido, cicloPedido);
    leerMatricula("Matricula.csv",anioPedido,cicloPedido,
                  arrAlumnos, cantAlumnos,
                  arrEscalas,cantEscalas,
                  arrCursos,cantCursos);
    ordenar(arrCursos,cantCursos);
    imprimir_reporte("reporte.txt",arrCursos,cantCursos );
    return 0;
}

