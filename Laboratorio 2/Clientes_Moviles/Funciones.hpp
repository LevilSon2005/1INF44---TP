/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 19 de abril de 2025, 16:14
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"


void leer_procesar_infracciones(const char*, const char*,const char*,const char*);
void imprimir_multa_por_persona(ifstream &input_infracciones,ifstream &input_vehiculos, ifstream &input_empresas,ofstream &ouput_reporte);
void imprimir_lin_caracter(char c, ofstream&);
#endif /* FUNCIONES_HPP */

