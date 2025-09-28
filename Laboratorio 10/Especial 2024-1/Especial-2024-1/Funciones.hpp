/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 30 de junio de 2025, 11:22
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"
void leerClientes(const char* name, struct NodoCliente* &listaCliente);
void insertarOrdenadoCliente(int dni, char* nombre, struct NodoCliente* &listaCliente);
void imprimir_listaClientes(const char* name, struct NodoCliente* listaCliente);
void leerLibros(const char* name,struct NodoLibro* &listaLibro);
void insertarFinal(char* codigo, char* titulo, char* autor, double precio, struct NodoLibro* &listaLibro);
void imprimir_listLibros(const char* name,struct NodoLibro* listaLibro);
void leerVentas(const char* name, struct NodoCliente* listaCliente,struct NodoLibro* listaLibro);
void completarListas(int codLibreria, int fechaVenta,char* codLibro, int dni, int calificacion,
                     struct NodoCliente* listaCliente, struct NodoLibro* listaLibro);


#endif /* FUNCIONES_HPP */
