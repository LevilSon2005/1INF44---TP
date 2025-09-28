/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 16 de junio de 2025, 11:25
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void solicitarAnio_Ciclo(int &anioPedido,int & cicloPedido);
void leerAlumnos(const char* name,struct Alumno* arrAlumnos, int &cantAlumnos);
void leerCursos(const char* name,struct Curso* arrCursos,int &cantCursos);
void leerEscalas(const char* name,struct Escala* arrEscalas,int &cantEscalas, int anioPedido, int cicloPedido);
void leerMatricula(const char* name, int anioPedido,int cicloPedido,
                  struct Alumno* arrAlumnos, int cantAlumnos,
                  struct Escala* arrEscalas,int cantEscalas,
                  struct Curso* arrCursos,int cantCursos);
void ordenar(struct Curso* arrCursos,int cantCursos);
void imprimir_reporte(const char* name,struct Curso* arrCursos,int cantCursos);


#endif /* FUNCIONES_HPP */
