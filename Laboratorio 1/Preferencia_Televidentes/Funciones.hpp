/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 9 de abril de 2025, 20:43
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

//declaraciones de funciones

void leer_Y_Procesar();
void imprimir_Titulos(const char*, const char* );
void imprimir_linea(char);
void imprimir_header(); //falta acomodar la alineacion

void procesar_Televidentes(int, int& , int& , int& , int& , int& , int& , double& , double& , double& , double&);

void  imprimir_linea(int , char , int, int,int ,int ,int ,int ,int ,int ,int ,int ,int ,int );
void  contar_E_Imprimir_sexo(char/*, int&, int&*/);

//para categoria
void calcular_categoria(int, int , int);
void Determinar_e_imprimir_categoria(int);

#endif /* FUNCIONES_HPP */
