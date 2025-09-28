/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 20 de junio de 2025, 16:13
 */

#include "Funciones.hpp"
int main(int argc, char** argv) {

    struct TablaDeInfracciones* arrTablaDeInfracciones{};
    struct EmpresasRegistradas* arrEmpresasRegistradas{};
    int cantInfracciones = 0, cantEmpresas=0;
    reservar_memoria_arrInfracciones(arrTablaDeInfracciones); //new struct [cant]
    reservar_memoria_arrEmpresas(arrEmpresasRegistradas); 
    leerTablaInfracciones("TablaDeInfracciones.csv",arrTablaDeInfracciones,cantInfracciones);
    leerEmpresasregistradas("EmpresasRegistradas.csv",arrEmpresasRegistradas,cantEmpresas);
    leerPlacasRegistradas("PlacasRegistradas.txt",arrEmpresasRegistradas,cantEmpresas);
    leerInfraccionesCometidas("InfraccionesCometidas.csv",arrTablaDeInfracciones,cantInfracciones,
                              arrEmpresasRegistradas,cantEmpresas);
    ordenarEmpresas(arrEmpresasRegistradas,cantEmpresas);
    ordenarInfracciones(arrTablaDeInfracciones,cantInfracciones);
    emitir_reporte("reprote.txt",arrTablaDeInfracciones,cantInfracciones,
                              arrEmpresasRegistradas,cantEmpresas);
    
//    for(int i=0;i<cantEmpresas;i++){
//        cout<<i<<endl;
//        cout<<"dd: "<<arrEmpresasRegistradas[i].fechaDeInfraccion.dd<<endl;
//        cout<<"mm: "<<arrEmpresasRegistradas[i].fechaDeInfraccion.mm<<endl;
//        cout<<"aa: "<<arrEmpresasRegistradas[i].fechaDeInfraccion.aa<<endl;
//        cout<<"fecha: "<<arrEmpresasRegistradas[i].fechaDeInfraccion.fecha<<endl;
//        cout<<"---"<<endl;
//        cout<<"dd: "<<arrEmpresasRegistradas[i].fechaDePago.dd<<endl;
//        cout<<"mm: "<<arrEmpresasRegistradas[i].fechaDePago.mm<<endl;
//        cout<<"aa: "<<arrEmpresasRegistradas[i].fechaDePago.aa<<endl;
//        cout<<"fecha: "<<arrEmpresasRegistradas[i].fechaDePago.fecha<<endl;
//        cout<<"total´Pagado: "<<arrEmpresasRegistradas[i].totalPagado<<endl;
//        cout<<"totalAdeudado: "<<arrEmpresasRegistradas[i].totalAdeudado<<endl;
//        cout<<"========="<<endl;
//    }
    return 0;
}

