/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListaLibro.hpp
 * Author: Binny
 *
 * Created on 5 de julio de 2025, 12:26
 */

#ifndef LISTALIBRO_HPP
#define LISTALIBRO_HPP

#include "NodoLibro.hpp"

//suponiendo que una buena calificacion sea mayor a 50
//ASUMIENDO QUE UN LIBRO BARATO CUESTA MENOS DE 100 Y UNO CARO MAS DE 100
struct ListaLibro{
    struct NodoLibro* inicio;
    struct NodoLibro* final;
    int cantLibroBarato;
    int cantLibroCaro;
};

#endif /* LISTALIBRO_HPP */

