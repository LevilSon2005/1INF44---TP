/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListaCliente.hpp
 * Author: Binny
 *
 * Created on 4 de julio de 2025, 20:35
 */

#ifndef LISTACLIENTE_HPP
#define LISTACLIENTE_HPP

#include "NodoCliente.hpp"

struct ListaCliente{
    struct NodoCliente* inicio;
    struct NodoCliente* final;
    int cantPares;
    int cantImpares;
    int cantClientes;
};

#endif /* LISTACLIENTE_HPP */

