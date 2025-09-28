/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 30 de junio de 2025, 11:21
 */

#include "Funciones.hpp"
int main(int argc, char** argv) {
    struct NodoCliente* listaCliente;
    struct NodoLibro* listaLibro;
    leerClientes("Clientes.csv", listaCliente);
    imprimir_listaClientes("reporte_prueba_clientes.txt", listaCliente);
    leerLibros("Libros.csv",listaLibro);
    imprimir_listLibros("reporteLibros.txt", listaLibro);
//    leerVentas("Ventas.txt", listaCliente, listaLibro);
    return 0;
}

