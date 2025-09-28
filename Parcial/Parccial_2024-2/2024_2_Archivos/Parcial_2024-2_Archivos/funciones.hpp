/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: binny
 *
 * Created on 18 de mayo de 2025, 22:52
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "utils.hpp"
void procesar_reporte(const char* nAlumnos,const char* nCursos,const char* nEscalas,const char* nMatricula,const char* nReporte);
void procesar_alumnos(ifstream &inputAlumnos, ifstream &inputCursos, ifstream &inputEsclas, ifstream &inputMatricula,ofstream &ouput,
                    int anio,int ciclo,
                    int&cantTotalAlumnos,double&montoTotalPagado);
void  buscar_imprimir_Cursos_UnAlumno(int n_alumnos,int anio,int ciclo,int codAlumno,char escalaAlumno,
                ifstream &inputAlumnos, ifstream &inputCursos, ifstream &inputEsclas, ifstream &inputMatricula,ofstream &ouput,
                int &totalCredAlum,double &montoAlumno);


#endif /* FUNCIONES_HPP */
