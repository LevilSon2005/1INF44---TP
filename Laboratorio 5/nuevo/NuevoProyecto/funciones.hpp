/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: binny
 *
 * Created on 12 de mayo de 2025, 11:10
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void  cargarArreglosRepartidores(int *arrDNIRepartidores,char *arrTipoVehiculo,int *arrCodDistrito, int &cantRepartidores);
void cargarArreglosPlatos(int *arrCodPlatos,double *arrPrecioPlatos,double *arrDescuentosPlatos,int &cantPlatos);
void imprimirPruebaArreglos(int *arrDNIRepartidores,char *arrTipoVehiculo,int *arrCodDistrito, int cantRepartidores,
                             int *arrCodPlatos,double *arrPrecioPlatos,double *arrDescuentosPlatos,int cantPlatos);
void leerArchivoRepartos(int *arrDNIRepartidores,char *arrTipoVehiculo,int *arrCodDistrito, int cantRepartidores,
                         int *arrCantPlatosPorRepartidor,double *arrMontoPlatosPorRepartidor,double *arrDescPlatosPorRepartidor,double *arrDescClientesPorRepartidor,double *arrPagoRepartidor,double *arrMontoTotalPorRepartidor,
                         int *arrCodPlatos,double *arrPrecioPlatos,double *arrDescuentosPlatos,int cantPlatos,
                         int* arrCantVendidoPorPlato,double *arrDescPorPlato);
void ordenarArreglo(int *arrDNIRepartidores,char *arrTipoVehiculo,int *arrCodDistrito, int cantRepartidores,
               int *arrCantPlatosPorRepartidor,double *arrMontoPlatosPorRepartidor,double *arrDescPlatosPorRepartidor,double *arrDescClientesPorRepartidor,double *arrPagoRepartidor,double *arrMontoTotalPorRepartidor);
void imrpimirReporte1(int *arrDNIRepartidores,char *arrTipoVehiculo,int *arrCodDistrito, int cantRepartidores,
            int *arrCantPlatosPorRepartidor,double *arrMontoPlatosPorRepartidor,double *arrDescPlatosPorRepartidor,double *arrDescClientesPorRepartidor,double *arrPagoRepartidor,double *arrMontoTotalPorRepartidor);


#endif /* FUNCIONES_HPP */
