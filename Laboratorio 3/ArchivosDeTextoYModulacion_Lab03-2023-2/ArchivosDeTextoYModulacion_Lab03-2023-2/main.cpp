/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Binny Romero
 * Codigo: 20233905
 * Descripcicon: Este programa lee, procesa e imprime los televidentes 
 * y sus datos, que ven cada canal. 
 *
 * Created on 25 de abril de 2025, 09:42 AM
 */

#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    leer_procesar_canales("Canales.txt", "RegistroDePreferencias.txt", "Televidentes.txt", "reporte.txt");
    return 0;
}

