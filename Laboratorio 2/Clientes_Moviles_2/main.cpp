/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 21 de abril de 2025, 17:52
 */

#include "Funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {

    leer_procesar_infracciones("Empresas_de_transporte.txt",
                                "Informacion_de_vehiculos.txt", 
                                "Infracciones_de_transito.txt",
                                "reporte.txt");
    
    
    return 0;
}

