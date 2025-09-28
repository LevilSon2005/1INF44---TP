/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 18 de julio de 2025, 19:15
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void leerConductores(const char* name,struct Conductor* conductores, int &cantConductores);
void imprimir_prueba_conductores(const char* name, struct Conductor* conductores, int cantConductores);
void leerVehiculos(const char* name, struct Vehiculo* vehiculos, int &cantVehiculos);
void imprimir_prueba_vehiculos(const char* name, struct Vehiculo* vehiculos, int cantVehiculos);
void leerInfracciones(const char* name, struct Infraccion* infracciones, int &cantInfracciones);
void imprimir_prueba_infracciones(const char* name, struct Infraccion* infracciones, int cantInfracciones);
void actualizar_infracciones(struct Conductor* conductores, int cantConductores,
                            struct Vehiculo* vehiculos, int cantVehiculos,
                            struct Infraccion* infracciones, int cantInfracciones);


#endif /* FUNCIONES_HPP */
