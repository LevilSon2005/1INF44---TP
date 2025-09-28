/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 * Desscripcion: Este programa emite lleva un crontol de los platos que se prepararon y emite un reporte
 * con la especificacion de la cantidad de platos y los montos recuaudados en un reporte
 *
 * Created on 18 de mayo de 2025, 12:53
 */

#include "funciones.hpp"


int main(int argc, char** argv) {

    //para platos
    int codigosPlat[MAXPLATOS]{}, cantidadesPrep[MAXPLATOS]{}, cantidadesPrepAux[MAXPLATOS]{},cantidadPlatos=0;
    double preciosPlat[MAXPLATOS]{}, descuentosPlat[MAXPLATOS]{};
    
    //para clientes
    int dnisClien[MAXCLIENTES]{},cantidadClientes=0;
    double descuentosClien[MAXCLIENTES]{};
//    char vehiculos[MAXCLIENTES]{};
    
    int PlatosAtendidos[MAXPLATOS]{}, PlatosNoAtendidos[MAXPLATOS]{};
    double descuentosTotales[MAXPLATOS]{}, montoEsperado[MAXPLATOS]{}, montoBruto[MAXPLATOS]{}, montoRecibido[MAXPLATOS]{};
    
    leerPlatos(codigosPlat,cantidadesPrep,preciosPlat,descuentosPlat,cantidadesPrepAux,cantidadPlatos);
    leerClientes(dnisClien,descuentosClien,cantidadClientes);
    imprimir_pruebaArreglos(codigosPlat,cantidadesPrep,preciosPlat,descuentosPlat,cantidadPlatos,
                            dnisClien,descuentosClien,cantidadClientes);
    leerRepartos(PlatosAtendidos,PlatosNoAtendidos,
                 descuentosTotales,montoEsperado,montoBruto,montoRecibido,
                codigosPlat,cantidadesPrep,preciosPlat,descuentosPlat,cantidadPlatos,
                 dnisClien,descuentosClien,cantidadClientes);
    odenarArreglos(codigosPlat,preciosPlat,cantidadesPrepAux,PlatosAtendidos,PlatosNoAtendidos,cantidadPlatos,
                   descuentosTotales,montoEsperado,montoBruto,montoRecibido);
    imprimir_reporte(codigosPlat,preciosPlat,cantidadesPrepAux,PlatosAtendidos,PlatosNoAtendidos,cantidadPlatos,
                   descuentosTotales,montoEsperado,montoBruto,montoRecibido, "ReproteDeRelacionesDePlatos.txt");
    eliminarNoAtendidos(codigosPlat,preciosPlat,cantidadesPrepAux,PlatosAtendidos,PlatosNoAtendidos,cantidadPlatos,
                   descuentosTotales,montoEsperado,montoBruto,montoRecibido);
    imprimir_reporte(codigosPlat,preciosPlat,cantidadesPrepAux,PlatosAtendidos,PlatosNoAtendidos,cantidadPlatos,
                   descuentosTotales,montoEsperado,montoBruto,montoRecibido, "ReproteDeDePlatosConDeficit.txt");
    return 0;
}

