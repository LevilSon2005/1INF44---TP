/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: binny
 *
 * Created on 5 de mayo de 2025, 17:41
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void cargarArreglos(int* ArrAniosPico,int* ArrAniosValle,int* ArrGananciasPico,int* ArrGananciasValle,int &cantPeriodos,
                    int &ValleMenor, int &picoMayor, int &aniomenor, int &aniomayor);
void procesarEImprimirDatos(int* ArrAniosPico,int* ArrAniosValle,int* ArrGananciasPico,int* ArrGananciasValle,int cantPeriodos,
                            int ValleMenor, int picoMayor, int aniomenor, int aniomayor);

#endif /* FUNCIONES_HPP */
