/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 3 de julio de 2025, 13:10
 */

#include "Funciones.hpp"
int main(int argc, char** argv) {
    
    //PARA INSERTAR AL FINAL CON UN PUNTERO DE INICIO EN EL STRUCT LISTA
    struct ListaNotas listaNotas;
    leerNotas("Notas.txt",listaNotas);
    imprimirNotas("ReporteFinalConPunteroInicio.txt", listaNotas);
    
    //PARA INSERTAR AL FINAL CON UN PUNTERO FINAL
//    struct ListaNotas listasNotasFinal_PFinal;
//    leerNotas("Notas.txt",listasNotasFinal_PFinal);
    
    
    //INSERTAR DE MANERA ORDENADA
    struct ListaNotas listaOrdenada;
    leerNotasOrdenadas("Notas.txt",listaOrdenada);
    imprimirNotas("ReporteOrdenado.txt", listaOrdenada);
    
    //ELIMINAR UN DATO
    struct ListaNotas listaElimadaUnDato;
    listaElimadaUnDato.inicio = listaOrdenada.inicio;
    eliminarUnDato(9, listaElimadaUnDato);
    imprimirNotas("ReporteElimandoUnDato.txt", listaElimadaUnDato);
    
    //PARA ELIMINAR UN DATO QUE SE REPITE
    struct ListaNotas listaElimniarRepetidos;
    listaElimniarRepetidos.inicio = listaOrdenada.inicio;
    eliminarDatosRepetidos(7, listaElimniarRepetidos);
    imprimirNotas("ReporteElimandoDatosRepetidos.txt", listaElimadaUnDato);
    
    //PARA ELIMINAR VARIOS DATOS DIFERENTES CON CONDICION
    struct ListaNotas listaEliminadaCondicion;
    leerNotasEliminando("Notas.txt",listaEliminadaCondicion);
    eliminarMenoresQue5(listaEliminadaCondicion);
    imprimirNotas("ReporteEliminadoNotasMenoresQue5.txt", listaEliminadaCondicion);
    return 0;
}

