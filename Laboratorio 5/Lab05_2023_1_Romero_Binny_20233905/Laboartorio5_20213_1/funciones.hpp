/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: binny
 *
 * Created on 11 de mayo de 2025, 10:23
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"
void cargarArreglosStock(int *arrCodProducto_Stock,int *arrCodAlmacen_Stock,int *arrStockInicial_Stock,int &cantProductos);
bool validacionFecha(int fechaInicio, int fechaFinal);
void imprimir_pruebaStock(int *arrCodProducto_Stock,int *arrCodAlmacen_Stock,int *arrStockInicial_Stock,int cantProductos);
void LeerTransacciones(bool*arrProdcutoEncontrado,int* arrStockInicial_Stock,int* arrIngresos_Trans,int* arrSalidas_Trans,
                        int* arrEnvios_Trans,int* arrRecibidos_Trans,int* arrStockFinal_Trans,
                        int fechaInicio, int fechaFinal,int *arrCodProducto_Stock,int *arrCodAlmacen_Stock,int cantProductos);
void imprimirReporte(bool*arrProdcutoEncontrado,int dd_i, int mm_i,int aa_i,int dd_f, int mm_f,int aa_f,int cantProductos,
                    int* arrCodProducto_Stock,int* arrCodAlmacen_Stock,int* arrStockInicial_Stock,
                    int* arrIngresos_Trans,int* arrSalidas_Trans,int* arrEnvios_Trans,int* arrRecibidos_Trans,int* arrStockFinal_Trans);
void ordenarArreglos(int cantProductos,int* arrCodProducto_Stock,int* arrCodAlmacen_Stock,int* arrStockInicial_Stock,
                    int* arrIngresos_Trans,int* arrSalidas_Trans,int* arrEnvios_Trans,int* arrRecibidos_Trans,int* arrStockFinal_Trans);
#endif /* FUNCIONES_HPP */
