/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Alumno.hpp
 * Author: Binny
 *
 * Created on 1 de julio de 2025, 19:40
 */

#ifndef ALUMNO_HPP
#define ALUMNO_HPP
#include "Escala.hpp"
#include "Curso.hpp"
struct Alumno{
    int codAlumn;
    char* nombre;
    struct Escala escAlumno;
    struct Curso* cursos; //MAX 8 CURSOS POR ALUMNO
    int cantidadCursos;
    double totalCreditos;
    double totalPago;
};

#endif /* ALUMNO_HPP */

