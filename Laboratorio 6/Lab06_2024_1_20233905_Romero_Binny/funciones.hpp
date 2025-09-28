/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: binny
 *
 * Created on 29 de mayo de 2025, 11:56
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

int Solicitud_Usuario_PedidoDeFacultad();
void leerCalificaciones(int *arrCodigoAlumnos,int *arrNumCursos,double *arrNumCreditos,double *arrSumaPonderada,int &cantAlumnos);
void LeerAlumnosEImpresionDeReporte(int *arrCodigoAlumnos,int *arrNumCursos,double *arrNumCreditos,double *arrSumaPonderada,int cantAlumnos,
                                   int codPedidoFacu);
void LeerFacultadesEImprimirTitulo(ofstream &ouput,ifstream &inputFacultades,int codPedidoFacu);

#endif /* FUNCIONES_HPP */
