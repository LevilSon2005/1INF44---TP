/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   InfraccionesCometidas.hpp
 * Author: Binny
 *
 * Created on 30 de junio de 2025, 17:37
 */

#ifndef INFRACCIONESCOMETIDAS_HPP
#define INFRACCIONESCOMETIDAS_HPP
#include "Fecha.hpp"
struct InfraccionesCometidas{
    struct Fecha fechaDeInfraccion;
    char* placa;
    char* codigoDeLaInfraccion;
    bool multaPagada;
    struct Fecha fechaDePago;
};


#endif /* INFRACCIONESCOMETIDAS_HPP */

