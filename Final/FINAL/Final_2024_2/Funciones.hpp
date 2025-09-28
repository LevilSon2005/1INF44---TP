/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 5 de julio de 2025, 18:28
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#define TAMREPORTE 180
#define NO_ENCONTRADO -1

#include "Atencion.hpp"
#include "Comentario.hpp"
#include "Palabras.hpp"
#include "Plato.hpp"


void leerLexicon(const char* name,struct Palabras* lexicon, int&cantLexicon);
void leerPlatos(const char* name,struct Plato* platos, int &cantPlatos);
void leerAtenciones(const char* name,struct Atencion* atenciones,int &cantAtenciones,
                   struct Plato* platos, int cantPlatos);
int leer_hora(ifstream &input);
double buscarPrecio(char* codPlato, struct Plato* platos, int cantPlatos);
void leerComentarios(const char* name,struct Atencion* atenciones,int cantAtenciones,
                    struct Palabras* lexicon, int cantLexicon);
int buscarCodAtencion(char* codAtencion, struct Atencion* atenciones,int cantAtenciones);
void preprocesar(char* &comentario);
void completarCamposComentario(char* comentario, struct Comentario &Struct_comentario,
                               struct Palabras* lexicon, int cantLexicon);
int contarPalabras(char* comentario);
void sacarPalabra(char* comentario, int numPalabra, char* palabra);
int  buscarInicio(char* comentario, int numPalabra);
int buscarPolaridad(char* palabra,struct Palabras* lexicon, int cantLexicon);
void emitirReporte(const char* name,struct Palabras* lexicon, int cantLexicon,
                  struct Atencion* atenciones,int cantAtenciones);
void imprimir_cabecera(ofstream &ouput, int codAtencion, int hora);
int calcularPolaridad(struct Atencion atencion);


#endif /* FUNCIONES_HPP */
