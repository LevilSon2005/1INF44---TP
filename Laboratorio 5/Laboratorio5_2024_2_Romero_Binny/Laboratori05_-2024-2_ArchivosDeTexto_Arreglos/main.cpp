/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny romero luna
 * Codigo: 20233905
 * Descripcion: Este programa lee, guarda en arreglos e imprime las infracciones de transito por empresa 
 * mostrando un resumen al final
 * 
 *
 * Created on 12 de mayo de 2025, 11:02
 */

#include "funciones.hpp"
int main(int argc, char** argv) {
    int arrDNIRepartidores[MAXREPARTIDORES]{},arrCodDistrito[MAXREPARTIDORES]{},
            arrCantPlatosPorRepartidor[MAXREPARTIDORES]{};
    double arrMontoPlatosPorRepartidor[MAXREPARTIDORES]{},
            arrDescPlatosPorRepartidor[MAXREPARTIDORES]{},arrDescClientesPorRepartidor[MAXREPARTIDORES]{},
            arrPagoRepartidor,arrMontoTotalPorRepartidor[MAXREPARTIDORES]{};
    char  arrTipoVehiculo[MAXREPARTIDORES]{};
    int cantRepartidores=0;
    
    
    cargarArreglosRepartidores(arrDNIRepartidores,arrTipoVehiculo,arrCodDistrito, cantRepartidores);
    
    return 0;
}

