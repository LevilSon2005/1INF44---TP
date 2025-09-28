/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Binny Romero Luna
 * Codigo: 20233905
 * Descripcion: Este programa lee y ordena los picos y valles de ganancia de una empresa
 * a lo largo de los años y entrega un reporte
 * Created on 5 de mayo de 2025, 04:49 PM
 */

#include "funciones.hpp"
int main(int argc, char** argv) {
    int ArrAniosPico[MAXPERIODOS]{},ArrAniosValle[MAXPERIODOS]{}, ArrGananciasPico[MAXPERIODOS]{}, ArrGananciasValle[MAXPERIODOS]{};
    int cantPeriodos=0;
    int ValleMenor=1e9, picoMayor =0, aniomenor, aniomayor;
    cargarArreglos(ArrAniosPico,ArrAniosValle,ArrGananciasPico,ArrGananciasValle,cantPeriodos, ValleMenor, picoMayor, aniomenor, aniomayor);
//    imprimir_prueba(ArrAnios,ArrGanancias,cantPeriodos)
    procesarEImprimirDatos(ArrAniosPico,ArrAniosValle,ArrGananciasPico,ArrGananciasValle,cantPeriodos, ValleMenor, picoMayor, aniomenor, aniomayor);
    
    return 0;
}
