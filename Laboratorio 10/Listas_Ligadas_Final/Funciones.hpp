/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 29 de junio de 2025, 13:17
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void crearLista(const char* name, struct Nodo *&listaNumeros);
void insertar(int dato, struct Nodo* &listaNumeros);
void  imprimirLista(const char* name,struct Nodo* listaNumeros);
void crearListaOrdenada(const char* name,struct Nodo* &listaNumOrdenados);
void insertarOrdenado(int num, struct Nodo* &listaNumOrdenados);
void  eliminarNum(int num, struct Nodo* &listaNumOrdenados);
void crearListaInicio(const char* name,struct Nodo* &listaNumInicio);
void insertarInicio(int num, struct Nodo* &listaNumInicio);
#endif /* FUNCIONES_HPP */
