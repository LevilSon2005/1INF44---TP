/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   EmpresasRegistradas.hpp
 * Author: Binny
 *
 * Created on 30 de junio de 2025, 17:40
 */

#ifndef EMPRESASREGISTRADAS_HPP
#define EMPRESASREGISTRADAS_HPP
#include "InfraccionesCometidas.hpp"
struct EmpresasRegistradas{
    int dni;
    char* nombre;
    char* distrito;
    char* placas[10]{};
    int numPlacas;
    struct InfraccionesCometidas* infraccion;
    int cantidadDeInfracciones;
    double totalPagado;
    double totalAdeudado;
};

#endif /* EMPRESASREGISTRADAS_HPP */

