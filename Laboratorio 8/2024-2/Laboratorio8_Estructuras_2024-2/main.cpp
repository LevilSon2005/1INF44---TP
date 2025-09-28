/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 13 de junio de 2025, 15:18
 */

#include "Funciones.hpp"
#include "Cliente.hpp"
#include "Distrito.hpp"
#include "Plato.hpp"


int main(int argc, char** argv) {
    struct Distrito arrDistritos[MAXDISTRITOS]{};
    struct Plato arrPlatos[MAXPLATOS]{};
    struct Cliente arrClientes[MAXCLIENTES]{};
    int cantDistritos=0, cantPlatos=0, cantClientes=0;
    
    leerPlatosOfrecidos("PlatosOfrecidos.csv",arrPlatos,cantPlatos);
    leerDistritosDeLima("Distritos.csv",arrDistritos,cantDistritos);
    leerClientes("Clientes.csv",arrClientes, cantClientes);
    imprimir_prueba_distrito("prueba_distrito.txt",arrDistritos,cantDistritos);
    //struct Plato* arrPlatos,int cantPlatos,
    //  struct Cliente* arrClientes,int cantClientes
    imprimir_prueba_Platos("prueba_plato.txt",arrPlatos,cantPlatos);
    imprimir_prueba_Clientes("prueba_cliente.txt",arrClientes,cantClientes);
    leerPedidosRealizados("PedidosRealizados.txt",arrDistritos,cantDistritos,
                          arrPlatos,cantPlatos,
                          arrClientes,cantClientes);
    ordenar(arrClientes,cantClientes);
    ordenar_Platos(arrClientes,cantClientes);
    imprimir_reporte("reporte.txt",arrClientes,cantClientes);
    return 0;
}

