/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   NodoUsuario.hpp
 * Author: Binny
 *
 * Created on 7 de julio de 2025, 0:52
 */

#ifndef NODOUSUARIO_HPP
#define NODOUSUARIO_HPP

#include "NodoUsuario.hpp"

struct NodoUsuario{
    struct Usuario datoUsuario;
    struct NodoUsuario* siguiente;
};


#endif /* NODOUSUARIO_HPP */

