/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Cliente.hpp
 * Author: Binny
 *
 * Created on 13 de junio de 2025, 15:30
 */

#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "PlatoPedido.hpp"
#include "Distrito.hpp"
#include "Utils.hpp"

struct Cliente{
    int dni;
    char* nombre;
    struct Distrito distrito;
    struct PlatoPedido pedidos[MAXPLATOSPEDIDOS];
    int cantidadDePedidos;
    double montoTotal;
};


#endif /* CLIENTE_HPP */

