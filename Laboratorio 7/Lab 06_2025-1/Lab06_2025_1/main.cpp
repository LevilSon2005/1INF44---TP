/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 9 de junio de 2025, 11:40
 */

#include "funciones.hpp"
int main(int argc, char** argv) {
    
    int arrCodigoInfraccion[MAXINF]{}, cantInf =0;
    double arrMultasInfracciones[MAXINF]{};
    char* arrDescripInf[MAXINF]{};
    //para infracciones cometidas
    int arrDNI[MAXDNI]{},arrMasMultaAntigua[MAXDNI]{},arrUltimaPendiente[MAXDNI]{}, cantDni=0;
    double arrTotalMultas[MAXDNI]{}, arrTotalPagadas[MAXDNI]{},arrTotalPendientes[MAXDNI]{};
    leer_TablaInfracciones(arrCodigoInfraccion,arrMultasInfracciones,arrDescripInf,cantInf);
    emitir_ReportePrueba(arrCodigoInfraccion,arrMultasInfracciones,arrDescripInf,cantInf);
    leer_InfraccionesCometidas(arrCodigoInfraccion,arrMultasInfracciones,arrDescripInf,cantInf,
                              arrDNI,arrMasMultaAntigua,arrUltimaPendiente,
                              arrTotalMultas,arrTotalPagadas,arrTotalPendientes,cantDni);
    return 0;
}

