/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Alumno.hpp
 * Author: Binny
 *
 * Created on 7 de julio de 2025, 12:39
 */

#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include "Curso.hpp"
#include "Escala.hpp"

struct Alumno{
    int codAlumno;
    char *nombre;
    struct Escala escAlumno{};
    struct Curso *cursos{};
    int cantidadCursos;
    double totalCreditos;
    double totalPago;
};

#endif /* ALUMNO_HPP */

