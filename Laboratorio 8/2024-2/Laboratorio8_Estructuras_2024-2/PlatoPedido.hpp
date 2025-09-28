/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PlatoPedido.hpp
 * Author: Binny
 *
 * Created on 13 de junio de 2025, 15:29
 */

#ifndef PLATOPEDIDO_HPP
#define PLATOPEDIDO_HPP

struct PlatoPedido{
    int codigoPedido;
    char* codigoPlato;
    char* descripcion;
    int cantidad;
    double precio;
    double subtotal;
};

#endif /* PLATOPEDIDO_HPP */

