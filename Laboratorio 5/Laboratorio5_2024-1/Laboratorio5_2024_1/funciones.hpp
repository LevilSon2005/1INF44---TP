/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: binny
 *
 * Created on 16 de mayo de 2025, 12:03
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"
void cargarArregloMedicos(int *codMedicos,double *tarifasCita,int &cantMedicos);
void cargarArregloMedicinas(int *codMedicinas,double *preciosMedicinas,int &cantMedicinas);
void leerCitas(int* arrEnterosMedicos,double *arrDoublesMedicos,
                int*arrCantMedicina,double *arrDoublesMedicina,
                int *codMedicos,double *tarifasCita,int cantMedicos,
                int *codMedicinas,double *preciosMedicinas,int cantMedicinas,
                double &ingresoPromedio);
void  imprimir_ReporteIngresos(int *codMedicos,double *tarifasCita,int *arrEnterosMedicos,double *arrDoublesMedicos,int cantMedicos,
                            int *codMedicinas,double *preciosMedicinas,int *arrCantMedicina,double *arrDoublesMedicina,int cantMedicinas);
void eliminar_doctores(int *codMedicos,double*tarifasCita,int *arrEnterosMedicos,double *arrDoublesMedicos,int &cantMedicos,double ingresoPromedio);
void imprimir_MejoresMedicos(int *codMedicos,double*tarifasCita,int *arrEnterosMedicos,double *arrDoublesMedicos,int cantMedicos);



#endif /* FUNCIONES_HPP */
