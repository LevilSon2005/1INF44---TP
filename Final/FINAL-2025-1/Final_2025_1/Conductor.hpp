/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Conductor.hpp
 * Author: Binny
 *
 * Created on 18 de julio de 2025, 19:14
 */

#ifndef CONDUCTOR_HPP
#define CONDUCTOR_HPP
#include "Vehiculo.hpp"
#include "Infraccion.hpp"
struct Conductor{
    int dni;
    char* nombre;
    char* apellido;
    char* licencia; //
    struct Vehiculo vehiculo;
    struct Infraccion* infracciones; //10 max
    int cantidad_infracciones;
};

#endif /* CONDUCTOR_HPP */

