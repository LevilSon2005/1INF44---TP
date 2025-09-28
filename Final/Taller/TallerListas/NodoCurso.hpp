/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   NodoCurso.hpp
 * Author: Binny
 *
 * Created on 7 de julio de 2025, 12:45
 */

#ifndef NODOCURSO_HPP
#define NODOCURSO_HPP

#include"Curso.hpp"

struct NodoCurso{
    struct Curso datoCurso;
    struct NodoCurso* siguiente;
};

#endif /* NODOCURSO_HPP */

