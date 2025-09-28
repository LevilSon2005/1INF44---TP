/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny romero luna
 * Codigo: 20233905
 * Descripcion: Este programa procesa y emite un reporte acerca de la realcion de platos vendidos en total
 *
 * Created on 1 de junio de 2025, 17:20
 */

#include "funciones.hpp"

int main(int argc, char** argv) {
    //para Repartos
    int arrCodPlatos[MAXPLATOS]{},arrNumPlatosVendidos[MAXPLATOS]{}, cantPlatos=0;
    //para PlatosOfrecidos
    double arrPrecio[MAXPLATOS]{},arrIngresoBruto[MAXPLATOS]{}, arrDescuento[MAXPLATOS]{},
            arrTotal[MAXPLATOS]{};
    bool arrTieneDescuento[MAXPLATOS]{};
    
    leerRepartosARealizar(arrCodPlatos,arrNumPlatosVendidos,cantPlatos);
    leerPlatosOfrecidos(arrPrecio,arrIngresoBruto,arrDescuento,arrTieneDescuento,arrTotal,
                        arrNumPlatosVendidos,arrCodPlatos,cantPlatos);
    imprimir_reportePrueba(arrPrecio,arrIngresoBruto,arrDescuento,arrTieneDescuento,arrTotal,
                        arrNumPlatosVendidos,arrCodPlatos,cantPlatos);
    emitirReporte(arrPrecio,arrIngresoBruto,arrDescuento,arrTieneDescuento,arrTotal,
                        arrNumPlatosVendidos,arrCodPlatos,cantPlatos);
    return 0;
}

