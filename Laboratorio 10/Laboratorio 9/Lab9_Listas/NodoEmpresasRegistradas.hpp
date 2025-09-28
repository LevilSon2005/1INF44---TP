/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   NodoEmpresasRegistradas.hpp
 * Author: Binny
 *
 * Created on 30 de junio de 2025, 17:46
 */

#ifndef NODOEMPRESASREGISTRADAS_HPP
#define NODOEMPRESASREGISTRADAS_HPP

#include "EmpresasRegistradas.hpp"

struct NodoEmpresasRegistradas{
    struct EmpresasRegistradas dato;
    struct NodoEmpresasRegistradas* siguiente;
};

#endif /* NODOEMPRESASREGISTRADAS_HPP */

