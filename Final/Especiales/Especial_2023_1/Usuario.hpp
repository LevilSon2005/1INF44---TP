/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Usuario.hpp
 * Author: Binny
 *
 * Created on 7 de julio de 2025, 0:40
 */

#ifndef USUARIO_HPP
#define USUARIO_HPP

#include"LibrosEnSuPoder.hpp"

struct Usuario{
    int dni;
    char* nombre;
    char categoria;
    double calificacion;
    struct LibrosEnSuPoder* libros; // MAX 6 LIBROS
    int cantidad_libros;
};

#endif /* USUARIO_HPP */

