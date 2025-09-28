/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   EmpresasRegistradas.hpp
 * Author: Binny
 *
 * Created on 23 de junio de 2025, 18:12
 */

#ifndef EMPRESASREGISTRADAS_HPP
#define EMPRESASREGISTRADAS_HPP

#include "Fecha.hpp"
struct EmpresasRegistradas{
    int dni;
    char* nombre;
    char* distrito;
    char** placas;
    int numPlacas = 0;
    struct Fecha fechaDeInfraccion;
    struct Fecha fechaDePago;
    double totalPagado = 0.0;
    double totalAdeudado = 0.0;
    int cantidadDeFaltas = 0;
};

#endif /* EMPRESASREGISTRADAS_HPP */

