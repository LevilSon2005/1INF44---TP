/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   NodoEscala.hpp
 * Author: Binny
 *
 * Created on 7 de julio de 2025, 12:47
 */

#ifndef NODOESCALA_HPP
#define NODOESCALA_HPP

#include"Escala.hpp"

struct NodoEscala{
    struct Escala datoEscala;
    struct NodoEscala* siguiente;
};

#endif /* NODOESCALA_HPP */

