/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.hpp
 * Author: binny
 *
 * Created on 7 de julio de 2025, 0:14
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include"Utils.hpp"

void leerUsuarios(const char* name,struct ListaUsuario &lista_usuarios);
void inicializar_usuarios(struct ListaUsuario &lista_usuarios);
struct Fecha leer_fecha(ifstream& input);
void insertarOrdenado(struct Usuario aux, struct ListaUsuario &lista_usuarios);
void imprimir_reporte_inicial(const char* name,struct ListaUsuario lista_usuarios);
void leerPrestamos(const char* name,struct ListaUsuario lista_usuarios);
struct NodoUsuario* buscarDni(int dni,struct ListaUsuario lista_usuarios);
void completarOperacion(char* codLibro,char tipoOperacion,struct NodoUsuario*posUsuario, 
                        struct ListaUsuario lista_usuarios);
bool verificarSuMaximo(struct NodoUsuario* posUsuario);
bool verificarSiTieneLibro(char* codLibro,struct LibrosEnSuPoder* libros,
                    int cantidad_libros);
void descuentoCalificacion(struct NodoUsuario* posUsuario);
void agregarLibro(struct NodoUsuario* posUsuario);
void eliminarLibro(char* codLibro, struct NodoUsuario* posUsuario);


#endif /* FUNCIONES_HPP */
