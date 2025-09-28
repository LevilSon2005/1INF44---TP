/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 18 de julio de 2025, 19:10
 */

#include "Funciones.hpp"
int main(int argc, char** argv) {
    
    struct Conductor* conductores;
    struct Vehiculo*  vehiculos;
    struct Infraccion* infracciones;
    int cantConductores=0, cantVehiculos =0, cantInfracciones=0;
    
    
    conductores = new Conductor[120]{};
    vehiculos = new Vehiculo [160]{};
    infracciones =  new Infraccion[160]{};
    leerConductores("conductores.csv", conductores, cantConductores);
    imprimir_prueba_conductores("conductores.txt",conductores, cantConductores);
    leerVehiculos("vehiculos.csv", vehiculos, cantVehiculos);
    imprimir_prueba_vehiculos("vehiculos.txt", vehiculos, cantVehiculos);
    leerInfracciones("infracciones.csv", infracciones, cantInfracciones);
    imprimir_prueba_infracciones("infracciones.txt", infracciones, cantInfracciones);
    actualizar_infracciones(conductores, cantConductores,
                            vehiculos, cantVehiculos,
                            infracciones, cantInfracciones);
    imprimir_reportes(conductores, cantConductores);
    return 0;
}

