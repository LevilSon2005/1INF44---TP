/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 5 de abril de 2025, 10:36
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

double Calculo_funcion(double x, double C_4, double C_3, double C_2, double C_1, double C_Ind);
double Potencia (double x, int exponente);
double calcular_x3 (double Fx1, double Fx2, double x1, double x2 );
bool Signos_Diferentes(double Fa, double Fb);
double Hallando_Raiz (double Fx1, double Fx2, double x1, double x2, double epsilon,  double C_4, double C_3, double C_2, double C_1, double C_Ind );

#endif /* FUNCIONES_HPP */
