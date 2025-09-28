/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: binny
 *
 * Created on 17 de mayo de 2025, 14:45
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void cargarArregloArticulo(char *letras1,char *letras2,char *letras3,int *numsArt,double *precios,double *descs,int &cantArt);
void  imprimir_prueba_articulo(char *letras1,char *letras2,char *letras3,int *numsArt,double *precios,double *descs,int cantArt);
void  procesar_ventas(char *letras1,char *letras2,char *letras3,int *numsArt,double *precios,double *descs,int cantArt,
                    int *arrCodVend,int *arrCantArt,int *arrFechaVentAntig,int *arrFechaVentRec,double *arrIngresosTotalVent,int &cantVendedores,
                    int &TotalCantVendido,double &TotalIngresosVentas); 
void imprimir_reporte(int *arrCodVend,int *arrCantArt,int *arrFechaVentAntig,int *arrFechaVentRec,double *arrIngresosTotalVent,int &cantVendedores,
                        int &TotalCantVendido,double &TotalIngresosVentas);



#endif /* FUNCIONES_HPP */
