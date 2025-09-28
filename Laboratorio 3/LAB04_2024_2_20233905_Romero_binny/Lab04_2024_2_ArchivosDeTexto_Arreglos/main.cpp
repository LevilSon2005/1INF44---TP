/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny romero
 * Codigo: 20233905
 * Descripcion: Este programa lee y analiza platos entregados por cada repartidor
 * con descripcion de cada pedido con su precio y cuanto recuardo el repartidor y con 
 * un reporte al final
 */

#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {

    leer_y_procesar_repartidores("PlatosOfrecidos.txt", "RepartosARealizar.txt", "Repartidores.txt", "reporte.txt");
    return 0;
}

