/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny romero luna 
 * Codigo: 20233905
 * Descripcion: este programa lee e imprime los datos de libros de una liberaria
 * con especificaciones de cada autor y los montos recaudado y por pagar a cada autor
 * 
 *
 * Created on 7 de mayo de 2025, 18:37
 */

#include "funciones.hpp"

int main(int argc, char** argv) {
    int arrCodLibros[MAXLIBROS]{}, arrCodAutores[MAXAUTORES]{}, arregloCodigoLibrosPorAutores[MAXAUTORES]{};
    double arrPrecioLibros[MAXLIBROS]{},arrRegaliasAutores[MAXAUTORES]{} ;
    int cantLibros=0, cantAutores=0;
    

    cargarArreglosLibros(arrCodLibros,arrPrecioLibros,cantLibros);
    cargarArreglosAutores(arrCodAutores,arregloCodigoLibrosPorAutores,arrRegaliasAutores,cantAutores);
    procesar_imprimir_reporte(arrCodLibros,arrPrecioLibros,cantLibros,arrCodAutores,arregloCodigoLibrosPorAutores,arrRegaliasAutores,cantAutores);
    
    return 0;
}

