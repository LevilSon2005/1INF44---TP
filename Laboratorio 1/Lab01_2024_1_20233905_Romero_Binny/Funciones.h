/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.h
 * Author: binny
 *
 * Created on 14 de abril de 2025, 15:39
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Utils.h"
//declara las funciones

void Leer_Y_Procesar();
int leer_Y_transformar_fecha();//
void procesar_Cada_Paciente(int , double&);
void imprimir_fecha(int );
int transformar_Hora(int , int , int );
void imprimir_linea(int , int , int, int , int , char ,
                    char , double , double );
void imprimir_hora(int);
void  imprimir_especialidad(char );
void imprimir_pago(double , double );
void imprimir_titulo(const char*, int );
void imprimir_linea_caracter(char );
void imprimir_header();
void actualizar_resumen(double ,double , double& );
void calcular_montoTotal(double ,double, double&); 

void imprimir_resumen(double);
#endif /* FUNCIONES_H */
