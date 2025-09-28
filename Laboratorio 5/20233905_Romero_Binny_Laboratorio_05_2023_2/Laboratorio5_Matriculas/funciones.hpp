/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: binny
 *
 * Created on 13 de mayo de 2025, 14:49
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void cargarArregloAlumnos(int *arrCodAlumno,int *arrEscalasAlumno,int &cantAlumnos);
void  cargarArregloCursos(int *arrCodCurso,double *arrCreditoCurso,int &cantCursos);
void cargarArregloEscalas(double *arrPreciosEscalas,int &cantEscalas);
void LeerMatricula(int *arrCodAlumno,int *arrEscalasAlumno,int cantAlumnos,
                                int *arrCodCurso,double *arrCreditoCurso,int cantCursos,
                                double *arrPreciosEscalas,int cantEscalas,
                                int *arrEnterosTotalesAlumnos,double *arrDoublesTotalesAlumnos,
                                int *arrEnterosTotalesCursos,double *arrDoublesTotalesCursos);


#endif /* FUNCIONES_HPP */
