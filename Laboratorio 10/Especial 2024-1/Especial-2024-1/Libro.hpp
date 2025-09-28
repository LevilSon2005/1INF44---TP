/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Libro.hpp
 * Author: Binny
 *
 * Created on 30 de junio de 2025, 11:33
 */

#ifndef LIBRO_HPP
#define LIBRO_HPP

#include "Libreria.hpp"
struct Libro{
    char* codigo;
    char* titulo;
    char* autor;
    double valor;
    struct Libreria* librerias; //MAX 5 LIBRERIAS
    int cantidadLibrerias;
    double totalVentas;
    int unidadesVendidas;
    int cantidadBuenasCalificaciones;
    double sumaBuenasCalificaciones;
};


#endif /* LIBRO_HPP */

