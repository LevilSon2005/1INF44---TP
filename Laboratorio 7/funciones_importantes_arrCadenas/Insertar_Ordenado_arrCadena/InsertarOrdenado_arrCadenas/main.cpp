/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 8 de junio de 2025, 13:00
 */

#include "funciones.hpp"

int main(int argc, char** argv) {
    char* artistas[MAXARTISTAS]{};
    char*canciones[MAXARTISTAS]{};
    int reproducciones[MAXARTISTAS]{}, cantArtistas=0;
    double bailables[MAXARTISTAS]{};
    leer_artistas(artistas,canciones,reproducciones,bailables,cantArtistas);
    imprimir_reporte(artistas,canciones,cantArtistas);
    return 0;
}

