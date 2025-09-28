/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 7 de junio de 2025, 16:35
 */

#include "funciones.hpp"
int main(int argc, char** argv) {
    //reseva de espacio al char**
    char* artistas[MAXARTISTAS];
    char* canciones[MAXARTISTAS];
    int reproducciones[MAXARTISTAS], cantArtistas=0;
    double bailable[MAXARTISTAS];
    
    leer_artistas(artistas,canciones,reproducciones,bailable,cantArtistas);
    ordenar_artistas(artistas,canciones,reproducciones,bailable,cantArtistas);
    imprimir_reporte(artistas,canciones,reproducciones,bailable,cantArtistas);
    return 0;
}

