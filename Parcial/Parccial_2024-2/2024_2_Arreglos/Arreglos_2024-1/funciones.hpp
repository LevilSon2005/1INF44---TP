/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: binny
 *
 * Created on 18 de mayo de 2025, 13:07
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP


#include "utils.hpp"

void leerPlatos(int *codigosPlat,int *cantidadesPrep,double *preciosPlat,double *descuentosPlat,int *cantidadesPrepAux,int &cantidadPlatos);
void leerClientes(int *dnisClien,double *descuentosClien,int &cantidadClientes);
void imprimir_pruebaArreglos(int *codigosPlat,int *cantidadesPrep,double *preciosPlat,double *descuentosPlat,int cantidadPlatos,
                            int *dnisClien,double *descuentosClien,int cantidadClientes);
void leerRepartos(int *PlatosAtendidos,int *PlatosNoAtendidos,
                double *descuentosTotales,double *montoEsperado,double *montoBruto,double *montoRecibido,
                int *codigosPlat,int *cantidadesPrep,double *preciosPlat,double *descuentosPlat,int cantidadPlatos,
                int *dnisClien,double *descuentosClien,int cantidadClientes);
void odenarArreglos(int *codigosPlat,double*preciosPlat,int*cantidadesPrepAux,int*PlatosAtendidos,int*PlatosNoAtendidos,int cantidadPlatos,
                   double *descuentosTotales,double *montoEsperado,double *montoBruto,double *montoRecibido);
void imprimir_reporte(int *codigosPlat,double*preciosPlat,int*cantidadesPrepAux,int*PlatosAtendidos,int*PlatosNoAtendidos,int cantidadPlatos,
                   double *descuentosTotales,double *montoEsperado,double *montoBruto,double *montoRecibido, const char* name);

void eliminarNoAtendidos(int *codigosPlat,double*preciosPlat,int*cantidadesPrepAux,int*PlatosAtendidos,int*PlatosNoAtendidos,int &cantidadPlatos,
                   double *descuentosTotales,double *montoEsperado,double *montoBruto,double *montoRecibido);


#endif /* FUNCIONES_HPP */
