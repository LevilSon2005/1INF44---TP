/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   NodoTablaInfracciones.hpp
 * Author: Binny
 *
 * Created on 30 de junio de 2025, 17:45
 */

#ifndef NODOTABLAINFRACCIONES_HPP
#define NODOTABLAINFRACCIONES_HPP
#include "TablaDeInfracciones.hpp"

struct NodoTablaInfracciones{
    struct TablaDeInfracciones dato;
    struct NodoTablaInfracciones* siguiente;
};

#endif /* NODOTABLAINFRACCIONES_HPP */

