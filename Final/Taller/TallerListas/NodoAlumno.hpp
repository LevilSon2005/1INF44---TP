/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   NodoAlumno.hpp
 * Author: Binny
 *
 * Created on 7 de julio de 2025, 12:51
 */

#ifndef NODOALUMNO_HPP
#define NODOALUMNO_HPP

#include "Alumno.hpp"

struct NodoAlumno{
    struct Alumno datoAlumno;
    struct NodoAlumno* siguiente;
};

#endif /* NODOALUMNO_HPP */

