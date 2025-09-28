/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny romero luna
 *
 * Created on 17 de mayo de 2025, 14:26
 */

#include "funciones.hpp"

int main(int argc, char** argv) {
    char letras1[MAXARTICULOS]{}, letras2[MAXARTICULOS]{}, letras3[MAXARTICULOS]{};
    int numsArt[MAXARTICULOS]{}, cantArt=0;
    double precios[MAXARTICULOS]{},descs[MAXARTICULOS]{};
    
    //para el archivo de ventas
     int arrCodVend[MAXVENDEDORES]{},arrCantArt[MAXVENDEDORES]{}, arrFechaVentAntig[MAXVENDEDORES]{}, arrFechaVentRec[MAXVENDEDORES]{}, cantVendedores=0;
     double arrIngresosTotalVent[MAXVENDEDORES]{};
     //para el resumen
     int TotalCantVendido=0;
     double TotalIngresosVentas =0.0;
     
    cargarArregloArticulo(letras1,letras2,letras3,numsArt,precios,descs,cantArt);
    imprimir_prueba_articulo(letras1,letras2,letras3,numsArt,precios,descs,cantArt);
    procesar_ventas(letras1,letras2,letras3,numsArt,precios,descs,cantArt,
                    arrCodVend,arrCantArt,arrFechaVentAntig,arrFechaVentRec,arrIngresosTotalVent,cantVendedores,
                    TotalCantVendido,TotalIngresosVentas);   
    imprimir_reporte(arrCodVend,arrCantArt,arrFechaVentAntig,arrFechaVentRec,arrIngresosTotalVent,cantVendedores,
                    TotalCantVendido,TotalIngresosVentas);
    return 0;
}

