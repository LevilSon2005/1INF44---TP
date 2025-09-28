/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Libro.hpp
 * Author: Binny
 *
 * Created on 5 de julio de 2025, 12:15
 */

#ifndef LIBRO_HPP
#define LIBRO_HPP
#include "Libreria.hpp"
struct Libro{
    char* codigo;
    char* titulo;
    char* autor;
    double precio;
    struct Libreria* librerias; //MAX DE 5 LBRERIAS POR LIBRO
    int cantidadLibrerias;
    double totalVentas;
    int unidadesVendidas;
    int cantidadBuenasCalificaciones;
    double sumaBuenasCalificaciones;
    int cantidadMalasCalificaciones;
    double sumaMalasCalificaciones;
};

#endif /* LIBRO_HPP */

