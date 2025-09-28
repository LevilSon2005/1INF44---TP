/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   NodoLibro.hpp
 * Author: Binny
 *
 * Created on 5 de julio de 2025, 12:24
 */

#ifndef NODOLIBRO_HPP
#define NODOLIBRO_HPP

#include "Libro.hpp"

struct NodoLibro{
    struct Libro datoLibro;
    struct NodoLibro* siguiente;
};

#endif /* NODOLIBRO_HPP */

