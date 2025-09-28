/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Venta.hpp
 * Author: Binny
 *
 * Created on 23 de junio de 2025, 16:05
 */

#ifndef VENTA_HPP
#define VENTA_HPP

#include "Fecha.hpp"

struct Venta{
    int dni;
    struct Fecha fechaCompra{};
    int calificacion;
};

#endif /* VENTA_HPP */

