/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny romero luna
 * Codigo: 20233905
 * Descripcion: este programa lee y procesa los prdouctos de cada almacen y su movimiento a traves de los almacenes incluyenfo ganacias y perdidas con un resumen
 * 
 *
 * Created on 11 de mayo de 2025, 10:23
 */

#include "funciones.hpp"
int main(int argc, char** argv) {
    int arrCodProducto_Stock[MAXPRODUCTOS]{}, arrCodAlmacen_Stock[MAXPRODUCTOS]{}, arrStockInicial_Stock[MAXPRODUCTOS]{};
    int cantProductos=0;
    int fechaInicio, fechaFinal;
    char c; //para que lea el '/' de la fecha
    int dd_i, mm_i,aa_i,dd_f, mm_f,aa_f;
    int arrIngresos_Trans[MAXPRODUCTOS]{},arrSalidas_Trans[MAXPRODUCTOS]{},
            arrEnvios_Trans[MAXPRODUCTOS]{},arrRecibidos_Trans[MAXPRODUCTOS]{},
            arrStockFinal_Trans[MAXPRODUCTOS]{};
    bool arrProdcutoEncontrado[MAXPRODUCTOS]{};
    cargarArreglosStock(arrCodProducto_Stock,arrCodAlmacen_Stock,arrStockInicial_Stock,cantProductos);
    imprimir_pruebaStock(arrCodProducto_Stock,arrCodAlmacen_Stock,arrStockInicial_Stock,cantProductos);
    //validacion de fecha
    do{
//        cout<<"Ingresa la fecha de inicio : (dd/mm/aa)"<<endl;
//        cin>>dd_i>>c>>mm_i>>c>>aa_i;
//        cout<<"Ingresa la fecha final : (dd/mm/aa)"<<endl;
//        cin>>dd_f>>c>>mm_f>>c>>aa_f;
        dd_i =1;
        mm_i=1;
        aa_i=2023;
        dd_f=30;
        mm_f=5;
        aa_f=2023;
        fechaInicio= aa_i*10000+mm_i*100+dd_i;
        fechaFinal= aa_f*10000+mm_f*100+dd_f;
    }while(not validacionFecha(fechaInicio,fechaFinal));
    
    LeerTransacciones(arrProdcutoEncontrado,arrStockInicial_Stock,arrIngresos_Trans,arrSalidas_Trans,
            arrEnvios_Trans,arrRecibidos_Trans,arrStockFinal_Trans,
            fechaInicio,fechaFinal,arrCodProducto_Stock,arrCodAlmacen_Stock,cantProductos);
    
    ordenarArreglos(cantProductos,arrCodProducto_Stock,arrCodAlmacen_Stock,arrStockInicial_Stock,
                    arrIngresos_Trans,arrSalidas_Trans,arrEnvios_Trans,arrRecibidos_Trans,arrStockFinal_Trans);
    imprimirReporte(arrProdcutoEncontrado,dd_i, mm_i,aa_i,dd_f, mm_f,aa_f,cantProductos,
                    arrCodProducto_Stock,arrCodAlmacen_Stock,arrStockInicial_Stock,
                    arrIngresos_Trans,arrSalidas_Trans,arrEnvios_Trans,arrRecibidos_Trans,arrStockFinal_Trans);
    return 0;
}

