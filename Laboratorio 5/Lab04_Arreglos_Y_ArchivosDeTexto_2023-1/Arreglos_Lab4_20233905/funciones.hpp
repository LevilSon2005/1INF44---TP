/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: binny
 *
 * Created on 7 de mayo de 2025, 18:38
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void cargarArreglosLibros(int *arrCodLibros,double *arrPrecioLibros,int &cantLibros);
void cargarArreglosAutores(int *arrCodAutores,int *arregloCodigoLibrosPorAutores,double *arrRegaliasAutores,int &cantAutores);
void procesar_imprimir_reporte(int *arrCodLibros,double *arrPrecioLibros,int cantLibros,int *arrCodAutores,int *arregloCodigoLibrosPorAutores,double *arrRegaliasAutores,int cantAutores);

#endif /* FUNCIONES_HPP */
