/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 23 de junio de 2025, 15:57
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"
void leerClientes(const char* name,struct Cliente* &arrClientes, int &cantClientes);
void leerLibros(const char* name,struct Libro* &arrLibros,int &cantLibros);
void leerVentas(const char* name,struct Libro* &arrLibros,int cantLibros);
void completarLibros(struct Libro* arrLibros,int cantLibros);
void imprimir_reporte(const char* name,struct Libro* arrLibros,int cantLibros,
                    struct Cliente* &arrClientes, int cantClientes);

#endif /* FUNCIONES_HPP */
