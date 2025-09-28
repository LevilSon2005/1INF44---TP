/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 13 de junio de 2025, 15:19
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void leerPlatosOfrecidos(const char* name,struct Plato* arrPlatos,int &cantPlatos);
void leerDistritosDeLima(const char* name,struct Distrito* arrDistritos,int &cantDistritos);
void leerClientes(const char* name,struct Cliente* arrClientes, int &cantClientes);
void imprimir_prueba_distrito(const char* name,struct Distrito* arrDistritos,int cantDistritos);
void imprimir_prueba_Platos(const char* name,struct Plato* arrPlatos,int cantPlatos);
void imprimir_prueba_Clientes(const char* name,struct Cliente* arrClientes,int cantClientes);
void leerPedidosRealizados(const char* name,struct Distrito* arrDistritos,int cantDistritos,
                          struct Plato* arrPlatos,int cantPlatos,
                          struct Cliente* arrClientes,int cantClientes);
void ordenar(struct Cliente* arrClientes,int cantClientes);
void ordenar_Platos(struct Cliente* arrClientes,int cantClientes);
void imprimir_reporte(const char* name,struct Cliente*arrClientes,int cantClientes);

#endif /* FUNCIONES_HPP */
