/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: binny
 *
 * Created on 1 de junio de 2025, 17:21
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "utils.hpp"
void leerRepartosARealizar(int* arrCodPlatos,int*arrNumPlatosVendidos,int& cantPlatos);
void leerPlatosOfrecidos(double *arrPrecio,double *arrIngresoBruto,double *arrDescuento,bool *arrTieneDescuento,double *arrTotal,
                         int *arrNumPlatosVendidos,int *arrCodPlatos, int cantPlatos);
void imprimir_reportePrueba(double *arrPrecio,double *arrIngresoBruto,double *arrDescuento,bool *arrTieneDescuento,double *arrTotal,
                         int *arrNumPlatosVendidos,int *arrCodPlatos, int cantPlatos);
void emitirReporte(double *arrPrecio,double *arrIngresoBruto,double *arrDescuento,bool *arrTieneDescuento,double *arrTotal,
                         int *arrNumPlatosVendidos,int *arrCodPlatos, int cantPlatos);


#endif /* FUNCIONES_HPP */
