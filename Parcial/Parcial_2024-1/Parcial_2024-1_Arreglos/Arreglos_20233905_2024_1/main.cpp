/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 17 de mayo de 2025, 20:25
 */

#include "funciones.hpp"

int main(int argc, char** argv) {
    
    //para pacientes.txt
    int dnisPac[MAXPACIENTES]{},codigosDist[MAXPACIENTES]{}, cantPac=0;
    char clasificacionesPac[MAXPACIENTES]{};
    double descuentosPac[MAXPACIENTES]{};
    
    //para medicinas.txt
    int codigosMedic[MAXMEDICINAS]{}, cantMedicina=0;
    double preciosMedic[MAXMEDICINAS]{};
    
    int cantCitas[MAXPACIENTES]{}, cantMedicinas[MAXPACIENTES]{};
    double pagosPacientes[MAXPACIENTES]{};
    
    cargarArregloPacientes(dnisPac,codigosDist,clasificacionesPac,descuentosPac,cantPac);
    cargarArregoMedicinas(codigosMedic,preciosMedic,cantMedicina);
//    imprimir_arregloPacietes(dnisPac,codigosDist,clasificacionesPac,descuentosPac,cantPac,
//                                codigosMedic,preciosMedic,cantMedicina);
    leerCitas(cantCitas,cantMedicinas,pagosPacientes,
              dnisPac,codigosDist,clasificacionesPac,descuentosPac,cantPac,
              codigosMedic,preciosMedic,cantMedicina);
    
    ordenar_datos(dnisPac,codigosDist,clasificacionesPac,descuentosPac,cantCitas,cantMedicinas,pagosPacientes,cantPac);
    imprimir_reporte(dnisPac,codigosDist,clasificacionesPac,descuentosPac,cantCitas,cantMedicinas,pagosPacientes,cantPac);
    return 0;
}

