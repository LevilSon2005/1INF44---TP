/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 7 de julio de 2025, 0:14
 */

#include "Funciones.hpp"
int main(int argc, char** argv) {
    struct ListaUsuario lista_usuarios;
    
    leerUsuarios("Usuarios.csv", lista_usuarios);
    imprimir_reporte_inicial("ReporteInicial.txt",lista_usuarios);
    leerPrestamos("Prestamos.txt", lista_usuarios);
    return 0;
}

