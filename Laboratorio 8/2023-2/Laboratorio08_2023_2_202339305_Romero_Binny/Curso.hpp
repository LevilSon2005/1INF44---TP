/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Curso.hpp
 * Author: Binny
 *
 * Created on 16 de junio de 2025, 11:39
 */

#ifndef CURSO_HPP
#define CURSO_HPP


#define MAXNOMBRECURSO 65
struct Curso{
    int codigo;
    char nombre[MAXNOMBRECURSO]{};
    double creditos;
    double montoPagado;
    int cantidadAlumnos_UnCurso;
};

#endif /* CURSO_HPP */

