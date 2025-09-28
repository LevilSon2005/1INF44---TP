/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 30 de junio de 2025, 17:25
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"
void leerTablaDeInfracciones(const char* name, struct NodoTablaInfracciones*& listaInfracciones);
void leerEmpresasRegistradas(const char* name, struct NodoEmpresasRegistradas* &listaEmpresas);
void leerPlacas(const char* name, struct NodoEmpresasRegistradas* listaEmpresas);

#endif /* FUNCIONES_HPP */
