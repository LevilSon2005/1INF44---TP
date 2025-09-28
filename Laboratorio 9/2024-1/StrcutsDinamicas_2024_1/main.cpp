/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny romero luna
 * Codigo: 20233905
 *
 * Created on 23 de junio de 2025, 15:56
 */

#include "Funciones.hpp"
int main(int argc, char** argv) {
    //reservo memoria en las funciones de lectura de los archivos
    struct Cliente* arrClientes;
    struct Libro* arrLibros;
    int cantClientes=0, cantLibros=0;
    leerClientes("Clientes.csv",arrClientes, cantClientes );
    leerLibros("Libros.csv",arrLibros,cantLibros);
    leerVentas("Ventas.csv",arrLibros,cantLibros);
    completarLibros(arrLibros,cantLibros);
    
    imprimir_reporte("reporte.txt",arrLibros,cantLibros,
                    arrClientes, cantClientes);
   
    return 0;
}

