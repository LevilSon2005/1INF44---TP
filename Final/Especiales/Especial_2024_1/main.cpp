/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 5 de julio de 2025, 12:07
 */

#include "Funciones.hpp"
int main(int argc, char** argv) {
    struct ListaCliente lista_cliente{};
    struct ListaLibro lista_libros{};
    
    leerClientes("Clientes.csv", lista_cliente);
    imprimir_prueba_cliente("PruebaDeClientes.txt", lista_cliente);
    
    leerLibros("Libros.csv",lista_libros);
    imprimir_prueba_libro("PruebaDeLibros.txt", lista_libros);
    
    leerVenta("Ventas.txt", lista_cliente, lista_libros);
    return 0;
}

