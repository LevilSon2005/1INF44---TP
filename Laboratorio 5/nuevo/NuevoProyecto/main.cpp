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
 * Created on 12 de mayo de 2025, 11:02
 */

#include "funciones.hpp"
int main(int argc, char** argv) {
    int arrDNIRepartidores[MAXREPARTIDORES]{},arrCodDistrito[MAXREPARTIDORES]{},
            arrCantPlatosPorRepartidor[MAXREPARTIDORES]{};
    double arrMontoPlatosPorRepartidor[MAXREPARTIDORES]{},
            arrDescPlatosPorRepartidor[MAXREPARTIDORES]{},arrDescClientesPorRepartidor[MAXREPARTIDORES]{},
            arrPagoRepartidor[MAXREPARTIDORES]{},arrMontoTotalPorRepartidor[MAXREPARTIDORES]{};
    char  arrTipoVehiculo[MAXREPARTIDORES]{};
    int cantRepartidores=0;
    
    //
    int arrCodPlatos[MAXPLATOS]{}, cantPlatos=0;
    double arrPrecioPlatos[MAXPLATOS]{}, arrDescuentosPlatos[MAXPLATOS]{};
    
    int arrCantVendidoPorPlato[MAXPLATOS]{};
    double arrDescTotalPorPlato[MAXPLATOS]{};
    //
    cargarArreglosRepartidores(arrDNIRepartidores,arrTipoVehiculo,arrCodDistrito, cantRepartidores);
    cargarArreglosPlatos(arrCodPlatos,arrPrecioPlatos,arrDescuentosPlatos,cantPlatos);
    imprimirPruebaArreglos(arrDNIRepartidores,arrTipoVehiculo,arrCodDistrito, cantRepartidores,arrCodPlatos,arrPrecioPlatos,arrDescuentosPlatos,cantPlatos);
    leerArchivoRepartos(arrDNIRepartidores,arrTipoVehiculo,arrCodDistrito, cantRepartidores,
         arrCantPlatosPorRepartidor,arrMontoPlatosPorRepartidor,arrDescPlatosPorRepartidor,arrDescClientesPorRepartidor,arrPagoRepartidor,arrMontoTotalPorRepartidor,
         arrCodPlatos,arrPrecioPlatos,arrDescuentosPlatos,cantPlatos,
         arrCantVendidoPorPlato ,arrDescTotalPorPlato);
    ordenarArreglo(arrDNIRepartidores,arrTipoVehiculo,arrCodDistrito, cantRepartidores,
            arrCantPlatosPorRepartidor,arrMontoPlatosPorRepartidor,arrDescPlatosPorRepartidor,arrDescClientesPorRepartidor,arrPagoRepartidor,arrMontoTotalPorRepartidor);
    imrpimirReporte1(arrDNIRepartidores,arrTipoVehiculo,arrCodDistrito,cantRepartidores,
            arrCantPlatosPorRepartidor,arrMontoPlatosPorRepartidor,arrDescPlatosPorRepartidor,arrDescClientesPorRepartidor,arrPagoRepartidor,arrMontoTotalPorRepartidor);
    return 0;
}

