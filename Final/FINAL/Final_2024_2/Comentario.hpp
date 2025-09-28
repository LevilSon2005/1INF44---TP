/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Comentario.hpp
 * Author: Binny
 *
 * Created on 5 de julio de 2025, 18:23
 */

#ifndef COMENTARIO_HPP
#define COMENTARIO_HPP

#include "Palabras.hpp"
struct Comentario{
    char* texto; //
    char* pre_procesado; //
    struct Palabras palabras[20];
    int cantidad_palabras; //
    int polaridad_total;
};


#endif /* COMENTARIO_HPP */

//13
//10