/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 16 de mayo de 2025, 11:41
 */

#include "funciones.hpp"
int main(int argc, char** argv) {
    double ingresoPromedio =0.0;
    //para medicos
    int cantMedicos=0, codMedicos[MAXMEDICOS]{};
    double tarifasCita[MAXMEDICOS]{};
    
    //para medicinas
    int cantMedicinas=0,codMedicinas[MAXMEDICINAS]{};
    double preciosMedicinas[MAXMEDICINAS]{};
    
    //para el reporte por medico
    int arrEnterosMedicos[3*MAXMEDICOS]{};
    double arrDoublesMedicos[3*MAXMEDICOS]{};
    //para reporte por medicina
    int arrCantMedicina[MAXMEDICINAS]{};
    double arrDoublesMedicina[3*MAXMEDICINAS]{}; //ingresos , descuento y total
    
    cargarArregloMedicos(codMedicos,tarifasCita,cantMedicos);
    cargarArregloMedicinas(codMedicinas,preciosMedicinas,cantMedicinas);
    leerCitas(arrEnterosMedicos,arrDoublesMedicos,
                arrCantMedicina,arrDoublesMedicina,
                codMedicos,tarifasCita,cantMedicos,
                codMedicinas,preciosMedicinas,cantMedicinas,ingresoPromedio);
    imprimir_ReporteIngresos(codMedicos,tarifasCita,arrEnterosMedicos,arrDoublesMedicos,cantMedicos,
                            codMedicinas,preciosMedicinas,arrCantMedicina,arrDoublesMedicina,cantMedicinas);
    eliminar_doctores(codMedicos,tarifasCita,arrEnterosMedicos,arrDoublesMedicos,cantMedicos,ingresoPromedio);
    imprimir_MejoresMedicos(codMedicos,tarifasCita,arrEnterosMedicos,arrDoublesMedicos,cantMedicos);
    return 0;
}

