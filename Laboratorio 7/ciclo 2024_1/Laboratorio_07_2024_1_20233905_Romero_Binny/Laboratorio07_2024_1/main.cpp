/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny romero luna
 * Codigo: 20233905
 * Descripcion: este programa controla loss promedios ponderados obtenidos por 
 * los alumnos de un colegio durante el ultimo ciclo que cursaron.
 *
 * Created on 4 de junio de 2025, 14:32
 */

#include "funciones.hpp"
int main(int argc, char** argv) {
    //para solicitar codigo de las facultades
    char codFacuPedida_1[NOMBREFACULTAD]{},codFacuPedida_2[NOMBREFACULTAD]{};
    //para llenar arreglos de calificaciones
    int arrCodigoAlumno[MAXALUMNOS]{},arrNumCursos[MAXALUMNOS]{},cantAlumnos=0;
    //para el archivo Alumnos.csv
    char* arrAlumnos[MAXALUMNOS]{}, *arrFacultad[MAXALUMNOS]{};
    double arrSumaPondearada[MAXALUMNOS]{},arrNumCreditos[MAXALUMNOS]{};
    SolicitarCodigosFacultades(codFacuPedida_1, codFacuPedida_2);
    LeerCalificaciones(arrCodigoAlumno,arrNumCursos,arrSumaPondearada,arrNumCreditos,cantAlumnos);
    LeerAlumnos(arrAlumnos,arrFacultad,arrCodigoAlumno,cantAlumnos);
    emitir_reporte(arrCodigoAlumno,arrAlumnos,arrNumCursos,arrSumaPondearada,
                    arrNumCreditos,arrFacultad,cantAlumnos);
    return 0;
}

