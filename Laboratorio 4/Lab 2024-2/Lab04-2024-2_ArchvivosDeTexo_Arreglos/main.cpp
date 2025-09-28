/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny romero luna
 * Codigo:20233905
 *Descripcion: este porgrama lee y procesa los pedidos hechos por cada repartidor y sus especifcaciones con un reporte al final
 * 
 * Created on 4 de mayo de 2025, 15:52
 */

#include "funciones.hpp"

int main(int argc, char** argv) {
    
    int ArrcodigoPlatos[PLATOSMAX]{}, ArrcodigoDistritos[REPARTOSMAX]{};
    double ArrprecioPlatos[PLATOSMAX]{};
    char ArrtipoVehiculo[REPARTOSMAX]{};
    //cantPlatos es para codigoPlatos y precioPlatos
    // cantRepartos es para codigoDistritos y     char tipoVehiculo{};

    int cantPlatos = 0, cantRepartos=0;
    
    cargarDatosDePlatos("PlatosOfrecidos.txt",ArrcodigoPlatos, ArrprecioPlatos,cantPlatos);
    cargarDatosVehiculosyDistritos("RepartosARealizar.txt",ArrtipoVehiculo,ArrcodigoDistritos,cantRepartos );
    procesarImprimirRepartos(ArrcodigoPlatos, ArrcodigoDistritos,ArrprecioPlatos, ArrtipoVehiculo, cantPlatos, cantRepartos);
    
    return 0;
    
    
}

