/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Infraccion.hpp
 * Author: Binny
 *
 * Created on 18 de julio de 2025, 19:13
 */

#ifndef INFRACCION_HPP
#define INFRACCION_HPP
#include "Fecha.hpp"
struct Infraccion{
    struct Fecha fecha_infraccion;
    char * codigo;
    char* descripcion;
    char* gravedad;
    double monto;
    int dni_conductor;
};

#endif /* INFRACCION_HPP */

