/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Libreria.hpp
 * Author: Binny
 *
 * Created on 5 de julio de 2025, 12:15
 */

#ifndef LIBRERIA_HPP
#define LIBRERIA_HPP
#include "Venta.hpp"
struct Libreria{
    int codigo;
    struct Venta* ventas; //MAX 10 VENTAS POR LIBRO
    int cantidadVentas;
    double totalVentas;
};

#endif /* LIBRERIA_HPP */

