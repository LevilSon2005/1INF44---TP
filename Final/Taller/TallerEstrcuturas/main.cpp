/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Binny Romero Luna
 * Codigo: 20233905
 * Descripcion: Este programa te procesa una base de datos de alumnos, escalas y sus curso
 * Al final te entrega un reporte con los aluumnos matriculados en un ciclo especifico. Te muestra
 * cada alumno con cada curso matriculado y la cantidad de cresitos junto al monto a pagar
 *
 * Created on 1 de julio de 2025, 19:27
 */

#include "Funciones.hpp"
int main(int argc, char** argv) {
    
    struct Curso*  arrCurso;
    struct Escala* arrEscalas;
    struct Alumno* arrAlumnos;
    int cantCursos=0, cantEscalas=0,cantAlumnos=0, anioPedido=0,cicloPedido=0;
    
    reserva_memoria(arrCurso);
    leerCursos("Cursos.csv", arrCurso, cantCursos);
    imprimir_reporte_cursos("ReportePrueba_Cursos.txt",arrCurso, cantCursos);
    reserva_memoria_escalas(arrEscalas);
    leerEscalas("Escalas.csv",arrEscalas,cantEscalas);
    imprimir_reporte_cursos("ReportePrueba_Escalas.txt",arrEscalas,cantEscalas);
    reserva_memoria_alumnos(arrAlumnos);
    leerAlumnos("Alumnos.csv",arrAlumnos, cantAlumnos);
    emitir_reporte(anioPedido, cicloPedido ,arrCurso, cantCursos,
                    arrEscalas,cantEscalas,
                    arrAlumnos, cantAlumnos);
    solicitarSemestre(anioPedido,cicloPedido);
    leerMatricula("Matricula.txt",anioPedido, cicloPedido,
                arrCurso, cantCursos,
                arrEscalas,cantEscalas,
                arrAlumnos, cantAlumnos);
    emitir_reporte(anioPedido, cicloPedido ,arrCurso, cantCursos,
                    arrEscalas,cantEscalas,
                    arrAlumnos, cantAlumnos);
    return 0;
}

