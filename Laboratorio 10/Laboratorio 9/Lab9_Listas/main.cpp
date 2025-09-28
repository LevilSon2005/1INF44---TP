/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 30 de junio de 2025, 17:05
 */

#include "Funciones.hpp"
int main(int argc, char** argv) {
    struct NodoTablaInfracciones* listaInfracciones;
    struct NodoEmpresasRegistradas* listaEmpresas;
    
    leerTablaDeInfracciones("TablaDeInfracciones.csv", listaInfracciones);
    leerEmpresasRegistradas("EmpresasRegistradas.csv", listaEmpresas);
    leerPlacas("PlacasRegistradas.csv", listaEmpresas);
    return 0;
}

