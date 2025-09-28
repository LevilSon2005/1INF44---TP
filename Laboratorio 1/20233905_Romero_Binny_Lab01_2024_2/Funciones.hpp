/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 8 de abril de 2025, 16:39
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "Utils.hpp"
//void procesar_Titulo_General();//
void Leer_Procesar_Repartidores();
void procesar_Cada_Repartidor(int );
int transformacion_Seg(int h_i,int m_i, int s_i );
void imprimir_linea(int dni,char sexo,int fecha, int seg_i, int seg_f, int canal_1, int canal_2, int canal_3, char compania );
void imprimir_Sexo(char);
void imprimir_categoria(int );
void imprimir_hora(int );
void imprimir_canales(int, int, int);
void imprimir_compania(char );

































#endif /* FUNCIONES_HPP */
