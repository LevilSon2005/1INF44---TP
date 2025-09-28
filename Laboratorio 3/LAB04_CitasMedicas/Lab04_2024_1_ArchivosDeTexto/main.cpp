/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny romero
 * codigo: 202333905
 * descripcion: este programa lee e imprimi registros medicos, dando los respectivos medicamentos de cada paciente. Al final entrega un resumen con estdisticas
 * 
 *
 * Created on 27 de abril de 2025, 21:40
 */

#include "funciones.hpp"
/*
 * 
 */
int main(int argc, char** argv) {

    leer_procesar_registrosMedicos("CitasMedicas_laboratorio4.txt", "Medicinas_laboratorio4.txt", "Medicos_laboratorio4.txt", "reporte.txt");
    return 0;
}

