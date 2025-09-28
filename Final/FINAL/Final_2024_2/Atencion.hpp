/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Atencion.hpp
 * Author: Binny
 *
 * Created on 5 de julio de 2025, 18:26
 */

#ifndef ATENCION_HPP
#define ATENCION_HPP
#include "Plato.hpp"
#include "Comentario.hpp"
struct Atencion{
    int codigo;//
    struct Plato* platos_atendidos; //20 max
    int cantidad_platos; //
    double total_ventas;
    int hora; //
    struct Comentario* comentarios; //20 max
    int cantidad_comentarios;
};

#endif /* ATENCION_HPP */

