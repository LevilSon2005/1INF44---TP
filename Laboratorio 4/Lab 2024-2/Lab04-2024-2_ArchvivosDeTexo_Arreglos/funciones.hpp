/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: binny
 *
 * Created on 4 de mayo de 2025, 15:53
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void cargarDatosDePlatos(const char* namePlatos,int *ArrcodigoPlatos, double *ArrprecioPlatos,int &cantPlatos);
void cargarDatosVehiculosyDistritos(const char* nameRepartos,char *ArrtipoVehiculo,int *ArrcodigoDistritos,int &cantRepartos );
void procesarImprimirRepartos(int *codigoPlatos, int* codigoDistritos,double *precioPlatos, char *tipoVehiculo, int cantPlatos, int cantRepartos);



#endif /* FUNCIONES_HPP */
