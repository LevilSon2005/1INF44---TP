/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   EmpresasRegistradas.hpp
 * Author: Binny
 *
 * Created on 20 de junio de 2025, 16:29
 */

#ifndef EMPRESASREGISTRADAS_HPP
#define EMPRESASREGISTRADAS_HPP

#include "Fecha.hpp"

struct EmpresasRegistradas{
    int dni;
    char* nombre;
    char* distrito;
    char** placas;
    int numPlaca;
    struct Fecha fechaDeInfraccion{}; //fecha mas antigua de infracciones
    struct Fecha fechaDePago{}; //fecha del último pago realizado
    double totalPagado=0.0;
    double totalAdeudado=0.0;
    int cantidadDeFaltas;
};

#endif /* EMPRESASREGISTRADAS_HPP */

