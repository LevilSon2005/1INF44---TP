/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: binny
 *
 * Created on 17 de mayo de 2025, 20:26
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void cargarArregloPacientes(int *codigosPac,int *codigosDist,char *clasificacionesPac,double *descuentosPac,int &cantPac);
void imprimir_arregloPacietes(int *dnisPac,int *codigosDist,char *clasificacionesPac,double *descuentosPac,int &cantidadPac);
void cargarArregoMedicinas(int *codigosMedic,double *preciosMedic, int&cantMedicina);
void leerCitas(int *cantCitas,int *cantMedicinas,double *pagosPacientes,
              int *dnisPac,int *codigosDist,char *clasificacionesPac,double *descuentosPac,int cantidadPac,
              int *codigosMedic,double *preciosMedic, int cantMedicina);
void ordenar_datos(int *dnisPac,int *codigosDist,char *clasificacionesPac,double *descuentosPac,int *cantCitas,int *cantMedicinas,double *pagosPacientes,int cantPac);
void imprimir_reporte(int *dnisPac,int *codigosDist,char *clasificacionesPac,double *descuentosPac,int *cantCitas,int *cantMedicinas,double *pagosPacientes,int cantPac);


#endif /* FUNCIONES_HPP */
