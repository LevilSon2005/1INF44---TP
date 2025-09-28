/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 5 de julio de 2025, 12:14
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"

void apertura_lectura(ifstream &input, const char* name);
void apertura_ecritura(ofstream &ouput, const char* name);
char* leer_cadena(ifstream &input, char del);
char* asignar_cadena(const char* buffer);
int leer_int(ifstream &input);
double leer_double(ifstream &input);
char leer_char(ifstream &input);
void imprimir_titulo(ofstream &ouput, const char* titulo);
void imprimir_linC(ofstream &ouput, char c);
void leerClientes(const char* name, struct ListaCliente &lista_cliente);
void inicializar_listaCliente(struct ListaCliente &lista_cliente);
void insertar(struct Cliente c,struct ListaCliente &lista_cliente);
void imprimir_prueba_cliente(const char* name, struct ListaCliente lista_cliente);
void leerLibros(const char* name, struct ListaLibro &lista_libros);
void inicializar_listaLibro(struct ListaLibro &lista_libros);
void inicializamos(struct Libro &l);
void insertarInicio(struct Libro libro, struct ListaLibro &lista_libros);
void insertarFinal(struct Libro libro, struct ListaLibro &lista_libros);
bool listaLibroVacia(struct ListaLibro l);
void imprimir_prueba_libro(const char* name, struct ListaLibro lista_libros);
void leerVenta(const char* name, struct ListaCliente &lista_cliente, struct ListaLibro &lista_libros);
int leer_fecha(ifstream &input);


#endif /* FUNCIONES_HPP */
