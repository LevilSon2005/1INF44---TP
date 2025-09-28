/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 1 de julio de 2025, 19:29
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void reserva_memoria(struct Curso* &arrCurso);
void leerCursos(const char* name, struct Curso* arrCurso, int &cantCursos);
void imprimir_reporte_cursos(const char* name, struct Curso* arrCurso, int cantCursos);
void reserva_memoria_escalas(struct Escala* &arrEscalas);
void leerEscalas(const char* name, struct Escala* arrEscalas, int &cantEscalas);
void imprimir_reporte_cursos(const char* name, struct Escala* arrEscalas, int cantEscalas);
void  leerMatricula(const char* name, int anioPedido, int cicloPedido,
                struct Curso* arrCurso, int cantCursos,
                struct Escala* arrEscalas, int cantEscalas,
                struct Alumno* arrAlumnos, int cantAlumnos);
void leerAlumnos(const char* name, struct Alumno* arrAlumnos, int &cantAlumnos);
void reserva_memoria_alumnos( struct Alumno* &arrAlumnos);
void emitir_reporte(int anioPedido, int cicloPedido, struct Curso* arrCurso, int cantCursos,
                    struct Escala* arrEscalas, int cantEscalas,
                    struct Alumno* arrAlumnos, int cantAlumnos);
void solicitarSemestre(int &anioPedido,int &cicloPedido);


#endif /* FUNCIONES_HPP */
