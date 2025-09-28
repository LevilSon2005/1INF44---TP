/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   NodoNotas.hpp
 * Author: Binny
 *
 * Created on 3 de julio de 2025, 13:13
 */

#ifndef NODONOTAS_HPP
#define NODONOTAS_HPP

#include "Notas.hpp"

struct NodoNotas{
    struct Notas nota;
    struct NodoNotas* siguiente;
};

#endif /* NODONOTAS_HPP */

