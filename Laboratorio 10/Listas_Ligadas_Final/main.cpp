/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny romero luna
 * Codigo: 20233905
 *
 * Created on 29 de junio de 2025, 13:06
 */

#include "Funciones.hpp"
int main(int argc, char** argv) {
    struct Nodo* listaNumeros;
    struct Nodo* listaNumOrdenados;
    struct Nodo* listaNumInicio;
    //PARA INSERTAR EL DATO AL FINAL DE LA LISTA
    crearLista("datos.txt",listaNumeros);
    imprimirLista("reporte.txt",listaNumeros);
    
    //PARA INSERTAR AL FINAL DE MANERA ORDENADA
    crearListaOrdenada("datos.txt",listaNumOrdenados);
    imprimirLista("ReporteOrdenado.txt", listaNumOrdenados);
    
    //PARA ELIMINAR UN DATO DE UNA LISTA
    eliminarNum(23, listaNumOrdenados);
    imprimirLista("ReporteEliminado.txt",listaNumOrdenados);
    
    //PARA INSERTAR AL INICIO DE LA LISTA
    crearListaInicio("datos.txt", listaNumInicio);
    imprimirLista("ReporteInicio.txt",listaNumInicio);
    return 0;
}

