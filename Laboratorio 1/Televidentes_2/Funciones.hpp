/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 12 de abril de 2025, 23:59
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

//void procesar_Titulo_General();//
void Leer_Procesar_Repartidores();
void procesar_Cada_Repartidor(int, int &cant_Menores_Entre14Y19H , 
                        int &cant_M_NoVen_Entre9_30_12_45 , int &cant_Jov_Mas3_30Hr ,int &cant_Ven_770_312_577_NoVen_314_555 , 
                        double &tiempoProm_Ven_MenoresYAdultos , double &porcen_M_Ven_TCPUCP , double &porcen_H_Jov_Ven_TPVision,
                        double &porcen_Adultos , double &prom_Canales );
int transformacion_Seg(int h_i,int m_i, int s_i );
void imprimir_linea(int dni,char sexo,int fecha, int seg_i, int seg_f, int canal_1, int canal_2, int canal_3, char compania );
void imprimir_Sexo(char);
void imprimir_categoria(int );
void imprimir_hora(int );
void imprimir_canales(int, int, int);
void imprimir_compania(char );
void  imprimir_titulo(const char*, int);
void imprimir_linea_caracter(char);
void imprimir_header();
void imprimir_resumen(int, int  , int  , int ,int , 
                        double  , double , double ,
                        double  , double  );
void actualizar_resumen();
void actualizar_resumen(int aa,int seg_i,int  seg_f, char sexo,int canal_1, int canal_2, int canal_3, int &cant_Menores_Entre14Y19H , 
                        int &cant_M_NoVen_Entre9_30_12_45 , int &cant_Jov_Mas3_30Hr ,int &cant_Ven_770_312_577_NoVen_314_555 , 
                        int &tiempoProm_Ven_MenoresYAdultos , double &porcen_M_Ven_TCPUCP , double &porcen_H_Jov_Ven_TPVision,
                        double &porcen_Adultos , double &prom_Canales);
void  calcular_cant_Menores_Entre14Y19H(int ,int, int, int&);
void calcular_cant_M_NoVen_Entre9_30_12_45(int, int, int, char, int&);
void calcular_cant_Jov_Mas3_30Hr(char, int ,int, int, int&);
void calcular_cant_Ven_770_312_577_NoVen_314_555(int ,int, int, int&);

bool es_canal_770_312_577(int);
bool noEsCanal314_555(int );
#endif /* FUNCIONES_HPP */

