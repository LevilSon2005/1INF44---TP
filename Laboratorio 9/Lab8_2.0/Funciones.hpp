/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 23 de junio de 2025, 18:10
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"
void leerTablaInfracciones(const char* name,struct TablaDeInfracciones* &arrTablaDeInfracciones,int &cantInfracciones);
void leerEmpresasregistradas(const char* name,struct EmpresasRegistradas* &arrEmpresasRegistradas,int &cantEmpresas);
void leerPlacasRegistradas(const char* name,struct EmpresasRegistradas* &arrEmpresasRegistradas,int cantEmpresas);
void leerInfraccionesCometidas(const char* name,struct TablaDeInfracciones* arrTablaDeInfracciones,int cantInfracciones,
                             struct EmpresasRegistradas* arrEmpresasRegistradas,int cantEmpresas);

#endif /* FUNCIONES_HPP */
