/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Binny Romero Luna
 * Codigo: 20233905
 * Descripcion: Este programa te genera un reporte de los montos que deben pagar los alumsno y
 * los ingresos que recibiran de ellos.
 *
 * Created on 13 de mayo de 2025, 14:47
 */

#include "funciones.hpp"

int main(int argc, char** argv) {
    
   //para Alumnos
    int cantAlumnos=0;
    int arrCodAlumno[MAXALUMNOS]{}, arrEscalasAlumno[MAXALUMNOS]{};
    //para Cursos
    int cantCursos=0;
    int arrCodCurso[MAXCURSOS]{};
    double arrCreditoCurso[MAXCURSOS]{};
    //para escalas
    int cantEscalas=0;
    double arrPreciosEscalas[MAXESCALAS]{};
    //Para arreglos del primer reporte
    int arrEnterosTotalesAlumnos[3*MAXALUMNOS]{};
    double arrDoublesTotalesAlumnos[2*MAXALUMNOS]{};
    //para arreglos del segundo reporte
    int arrEnterosTotalesCursos[2*MAXCURSOS]{};
    double arrDoublesTotalesCursos[2*MAXCURSOS]{};
    cargarArregloAlumnos(arrCodAlumno,arrEscalasAlumno,cantAlumnos);
    cargarArregloCursos(arrCodCurso,arrCreditoCurso,cantCursos);
    cargarArregloEscalas(arrPreciosEscalas,cantEscalas);
    LeerMatricula(arrCodAlumno,arrEscalasAlumno,cantAlumnos,
                            arrCodCurso,arrCreditoCurso,cantCursos,
                            arrPreciosEscalas,cantEscalas,
            arrEnterosTotalesAlumnos,arrDoublesTotalesAlumnos,
            arrEnterosTotalesCursos,arrDoublesTotalesCursos);
    return 0;
}

