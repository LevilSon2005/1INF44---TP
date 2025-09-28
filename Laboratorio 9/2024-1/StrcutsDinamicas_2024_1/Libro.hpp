/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Libro.hpp
 * Author: Binny
 *
 * Created on 23 de junio de 2025, 16:06
 */

#ifndef LIBRO_HPP
#define LIBRO_HPP

struct Libro{
    char* codigo; //
    char* titulo; //
    char* autor; //
    double precio; //
    struct Venta* arrVentasLibros;
    int cantLibrosVendidos=0;
    int sumaDeCalificiaciones;
    int ranking=0;
};

#endif /* LIBRO_HPP */

