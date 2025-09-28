/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Alumnos.hpp
 * Author: Binny
 *
 * Created on 16 de junio de 2025, 15:47
 */

#ifndef ALUMNOS_HPP
#define ALUMNOS_HPP

#include "Facultad.hpp"

struct Alumno{
    int codigo;
    char* nombre;
    int numCursos;
    double sumaPonderada;
    double creditos;
    double promPonderado;
    struct Facultad facultad;
};

#endif /* ALUMNOS_HPP */

