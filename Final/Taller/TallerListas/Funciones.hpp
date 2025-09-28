/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 7 de julio de 2025, 12:39
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"
void leerCursos(const char* name, struct ListaCurso &lista_cursos);
void inicializar_cursos(struct ListaCurso &lista_cursos);
bool lista_curso_vacia(struct ListaCurso lista_cursos);
void insertarFinal(struct Curso aux, struct ListaCurso &lista_cursos);
void leerEscalas(const char* name, struct ListaEscala &lista_escalas);
void inicializar_escalas(struct ListaEscala &lista_escalas);
void insertar(struct Escala aux, struct ListaEscala &lista_escalas); 
void leerAlumnos(const char* name, struct ListaAlumno  & lista_alumnos);
void inicializar_alumnos(struct ListaAlumno  &lista_alumnos);
void inicializar_campos(struct Alumno &aux);
void insertarOrdenado(struct Alumno aux, struct ListaAlumno  &lista_alumnos);
void emitir_reporte(int anio,int ciclo,struct ListaAlumno lista_alumnos);
void formarNombreArch(const char* name_arch, int ciclo, int anio);
void convertir_int_to_cadena(int anio, char* anio_cad);
void   imprimir_datos_alumnos(ofstream& ouput,struct ListaAlumno lista_alumnos);
void imprimirCabecera(ofstream& ouput,struct Alumno alumno);



#endif /* FUNCIONES_HPP */
