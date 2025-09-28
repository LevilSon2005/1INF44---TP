/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 23 de junio de 2025, 18:09
 */

#include "Funciones.hpp"
int main(int argc, char** argv) {
    struct EmpresasRegistradas* arrEmpresasRegistradas;
    struct TablaDeInfracciones* arrTablaDeInfracciones;
    int cantInfracciones =0, cantEmpresas=0;
    leerTablaInfracciones("TablaDeInfracciones.csv",arrTablaDeInfracciones,cantInfracciones);
    leerEmpresasregistradas("EmpresasRegistradas.csv",arrEmpresasRegistradas,cantEmpresas);
    leerPlacasRegistradas("PlacasRegistradas.txt",arrEmpresasRegistradas,cantEmpresas);
    leerInfraccionesCometidas("InfraccionesCometidas.csv",arrTablaDeInfracciones,cantInfracciones,
                              arrEmpresasRegistradas,cantEmpresas);
    
    return 0;
}

