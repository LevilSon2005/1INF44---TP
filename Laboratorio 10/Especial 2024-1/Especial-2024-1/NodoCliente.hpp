/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   NodoCliente.hpp
 * Author: Binny
 *
 * Created on 30 de junio de 2025, 11:39
 */

#ifndef NODOCLIENTE_HPP
#define NODOCLIENTE_HPP

#include "Cliente.hpp"

struct NodoCliente{
    struct Cliente datoCliente;
    struct NodoCliente* siguiente;
    
};

#endif /* NODOCLIENTE_HPP */

