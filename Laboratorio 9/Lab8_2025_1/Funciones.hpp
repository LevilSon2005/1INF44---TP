/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 20 de junio de 2025, 16:24
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"
void reservar_memoria_arrInfracciones(struct TablaDeInfracciones* &arrTablaDeInfracciones);
void reservar_memoria_arrEmpresas(struct EmpresasRegistradas* &arrEmpresasRegistradas);
void leerTablaInfracciones(const char* name,struct TablaDeInfracciones* arrTablaDeInfracciones,int &cantInfracciones);
void leerEmpresasregistradas(const char* name,struct EmpresasRegistradas* arrEmpresasRegistradas,int &cantEmpresas);
void leerPlacasRegistradas(const char* name,struct EmpresasRegistradas* arrEmpresasRegistradas,int cantEmpresas);
void leerInfraccionesCometidas(const char* name,struct TablaDeInfracciones* arrTablaDeInfracciones,int cantInfracciones,
                             struct EmpresasRegistradas* arrEmpresasRegistradas,int cantEmpresas);
void ordenarEmpresas(struct EmpresasRegistradas* arrEmpresasRegistradas,int cantEmpresas);
void ordenarInfracciones(struct TablaDeInfracciones* arrTablaDeInfracciones,int cantInfracciones);
void  emitir_reporte(const char* name,struct TablaDeInfracciones* arrTablaDeInfracciones,int cantInfracciones,
                       struct EmpresasRegistradas* arrEmpresasRegistradas,int cantEmpresas);

#endif /* FUNCIONES_HPP */
