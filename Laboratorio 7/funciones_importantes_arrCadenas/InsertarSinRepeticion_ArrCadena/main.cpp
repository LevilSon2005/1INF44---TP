/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 7 de junio de 2025, 19:38
 */

#include "funciones.hpp"

int main(int argc, char** argv) {
    char* artistas[MAXCANTANTES]{}, *generos[MAXCANTANTES]{};
    int reproducciones[MAXCANTANTES]{}, cantCantantes=0;
    double bailables[MAXCANTANTES]{};
    
    leer_canciones(artistas,generos,reproducciones,bailables,cantCantantes);
    imprimir_reporte(artistas,generos,reproducciones,bailables,cantCantantes);
    return 0;
}

