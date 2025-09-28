/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: binny
 *
 * Created on 9 de junio de 2025, 11:40
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "utils.hpp"

void leer_TablaInfracciones(int*arrCodigoInfraccion,double*arrMultasInfracciones,char**arrDescripInf,
                            int&cantInf);
void  emitir_ReportePrueba(int*arrCodigoInfraccion,double*arrMultasInfracciones,char**arrDescripInf,int cantInf);
void leer_InfraccionesCometidas(int*arrCodigoInfraccion,double*arrMultasInfracciones,char**arrDescripInf,int cantInf,
                            int *arrDNI,int* arrMasMultaAntigua,int*arrUltimaPendiente,
                          double* arrTotalMultas,double* arrTotalPagadas,double* arrTotalPendientes,int &cantDni);


#endif /* FUNCIONES_HPP */
