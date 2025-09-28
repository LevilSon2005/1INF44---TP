/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 3 de julio de 2025, 16:14
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"
void leerNotas(const char* name ,struct ListaNotas &listaNotas);
void insertarAlFinal(const struct Notas &aux, struct ListaNotas &listaNotas);
void imprimirNotas(const char* name ,const struct ListaNotas &listaNotas);
void imprimirStructNotas(ofstream &ouput, struct NodoNotas* notas);
void imprimirHeaderStruct(ofstream &ouput);
void leerNotas(const char* name ,struct ListaNotas_PFinal &listasNotasFinal_PFinal);
void inicializar_lista_p_final(struct ListaNotas_PFinal &listasNotasFinal_PFinal);
void leerNotasOrdenadas(const char* name , struct ListaNotas &listaOrdenada);
void insertarOrdenado(struct Notas aux, struct ListaNotas &listaOrdenada);
void eliminarUnDato(int datoEliminar, struct ListaNotas &listaElimadaUnDato);
void eliminarDatosRepetidos(int datoEliminar,struct ListaNotas &listaElimniarRepetidos);
void leerNotasEliminando(const char* name,struct ListaNotas &listaEliminadaCondicion);
void eliminarMenoresQue5(struct ListaNotas &listaEliminadaCondicion);

#endif /* FUNCIONES_HPP */
