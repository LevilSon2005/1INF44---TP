/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Libreria.hpp
 * Author: Binny
 *
 * Created on 30 de junio de 2025, 11:31
 */

#ifndef LIBRERIA_HPP
#define LIBRERIA_HPP

#include "Venta.hpp"

struct Libreria{
    int codigo;
    struct Venta *ventas; //maximo 10 ventas
    int cantidadVentas;
    double totalVentas;
};

#endif /* LIBRERIA_HPP */

