/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 4 de julio de 2025, 20:34
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void leerClientes(const char* name,struct ListaCliente & lista_cliente);
void inicilizar_lista_cliente(struct ListaCliente &lista_cliente);
void insercionInicio(struct Cliente aux, struct ListaCliente &lista_cliente);
void insercionFinal(struct Cliente aux,struct ListaCliente & lista_cliente);


#endif /* FUNCIONES_HPP */
