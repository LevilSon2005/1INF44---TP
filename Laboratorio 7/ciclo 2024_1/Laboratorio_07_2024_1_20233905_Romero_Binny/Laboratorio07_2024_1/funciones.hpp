/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: binny
 *
 * Created on 4 de junio de 2025, 14:36
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "utils.hpp"
void SolicitarCodigosFacultades(char* codFacuPedida_1,char* codFacuPedida_2);
void LeerCalificaciones(int*arrCodigoAlumno,int*arrNumCursos,double*arrSumaPondearada,double*arrNumCreditos,int&cantAlumnos);
void LeerAlumnos(char**arrAlumnos,char**arrFacultad,int*arrCodigoAlumno,int cantAlumnos);
void emitir_reporte(int*arrCodigoAlumno,char**arrAlumnos,int*arrNumCursos,
                    double*arrSumaPondearada,double*arrNumCreditos,char**arrFacultad,int cantAlumnos);


#endif /* FUNCIONES_HPP */
