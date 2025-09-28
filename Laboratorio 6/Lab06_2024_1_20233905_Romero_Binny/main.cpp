/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny romero luna
 * Descripcion: Este programa procesa los promedios de los alumnos de determinada facultad. Esta faucltad
 * será dada por el usuario.
 *
 * Created on 29 de mayo de 2025, 11:55
 */

#include "funciones.hpp"

int main(int argc, char** argv) {
    int codPedidoFacu=0;
    
    //para calificaciones
    int arrCodigoAlumnos[MAXALUMNOS]{}, arrNumCursos[MAXALUMNOS]{}, cantAlumnos=0;
    double arrSumaPonderada[MAXALUMNOS]{},arrNumCreditos[MAXALUMNOS]{};
    
    codPedidoFacu = Solicitud_Usuario_PedidoDeFacultad();
    leerCalificaciones(arrCodigoAlumnos,arrNumCursos,arrNumCreditos,arrSumaPonderada,cantAlumnos);
    LeerAlumnosEImpresionDeReporte(arrCodigoAlumnos,arrNumCursos,arrNumCreditos,arrSumaPonderada,cantAlumnos,
                                   codPedidoFacu);
    return 0;
}

