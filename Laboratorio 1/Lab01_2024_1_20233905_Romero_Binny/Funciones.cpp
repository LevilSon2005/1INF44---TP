/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 14 de abril de 2025, 15:39
 */

#include "Funciones.h"




// FECHA         DNI         HORA_I   HORA_F    TARIFA  ESPECIALID   RECETARON  MONTO_MEDIC   
//  9/9/2023   94683380   11:17:52   12:35:20   124.34      C             S       317.86
void Leer_Y_Procesar(){
    int fecha;
    
    double montoTotal=0.0;
    
    
    imprimir_titulo("EMPRESA DE SALUD S.A.", TITULO);
    imprimir_titulo("EREGISTRO DE CITAS DE LAS CONSULTAS MEDICAS", SUBTITULO);
    imprimir_header();
    
    while(true){
        fecha = leer_Y_transformar_fecha();
        if(cin.eof()) break;
        cout<<fixed<<setprecision(4);
        procesar_Cada_Paciente(fecha, montoTotal);
    }
    imprimir_resumen(montoTotal );
}

void procesar_Cada_Paciente(int fecha, double &montoTotal ){
    //se lee cada paciente y funcion imprimir linea
    
    int dni;
    int hh_i, mm_i, ss_i;
    int hh_f, mm_f, ss_f;
    int seg_i, seg_f;
    char car, especialidad, Si_Recetaron_Med;
    double tarifa, monto_Med=0;
    
    cin>>dni;
    cin >> hh_i>>car>>mm_i>>car>>ss_i;
    cin >> hh_f>>car>>mm_f>>car>>ss_f;
    cin>>tarifa>>especialidad>>Si_Recetaron_Med;
    
    if(Si_Recetaron_Med == 'S'){
        cin>>monto_Med;
    }
    
    seg_i = transformar_Hora( hh_i,  mm_i, ss_i);
    seg_f = transformar_Hora( hh_f,  mm_f, ss_f);
    
    int s_duracion=0;
    s_duracion= seg_f - seg_i;
    
    imprimir_linea(fecha, dni,seg_i, seg_f,s_duracion,especialidad, Si_Recetaron_Med, 
                    tarifa, monto_Med);
    
    actualizar_resumen(tarifa,monto_Med, montoTotal );
    
    
}

void imprimir_resumen(double montoTotal ){
    
    imprimir_linea_caracter('=');
    cout<<"Total de ingresos: "<<montoTotal;
    imprimir_linea_caracter('=');
    cout<<"ESTADISTICAS GENERALES"<<endl;
    
}

void actualizar_resumen(double tarifa,double monto_Med, double& montoTotal ){
    
    calcular_montoTotal(tarifa,monto_Med, montoTotal);
}

void calcular_montoTotal(double tarifa,double monto_Med, double &n){
    double monto;
    monto = tarifa + monto_Med;
    n = n+monto;
}

void imprimir_hora(int s){
    int h, m,sg;
    char c;
    c=':';
    h=s/3600;
    sg = s%60;
    m = (s/60)%60;
    
    cout<<setw(TAM_MAX/COLUMNAS-9)<<""<<setfill('0')<<setw(2)<<h<<c<<setw(2)<<m<<c<<setw(2)<<sg;
    cout<<setfill(' ');
}


int transformar_Hora(int h, int m, int s){
    return (h*3600 + m*60+ s);
}


void imprimir_especialidad(char esp){
    cout<<setw(2)<<"";
    if (esp=='C') cout<<setw(TAM_MAX/COLUMNAS)<<"cardiologia";
    if (esp=='D') cout<<setw(TAM_MAX/COLUMNAS)<<"dermatologia";
    if (esp=='P') cout<<setw(TAM_MAX/COLUMNAS)<<"pediatria";
}

void imprimir_fecha(int fecha){
    //20230909
    int d, m, a;
    
    d = fecha%100;
    a = fecha/10000;
    m = (fecha/100)%100;
    
    cout<<setw(TAM_MAX/COLUMNAS-14)<<""<<setfill('0')<<setw(2)<<d<<"/"<<
            setw(2)<<m<<"/"<<setw(2)<<a;
    cout<<setfill(' ');
}

int leer_Y_transformar_fecha(){
    int dd, mm, aa;
    char c;
    int fecha;
    cin>>dd>>c>>mm>>c>>aa;
    
    fecha = aa*10000 + mm*100+dd;
    return fecha;
}


void imprimir_pago(double tarifa, double monto_Med){
    
    cout<<setw(TAM_MAX/COLUMNAS)<< setprecision(2)<<(tarifa + monto_Med)<<endl;
}

void imprimir_titulo(const char* texto, int tamano){
    
    
    cout<<setw((TAM_MAX + tamano) / 2)<< texto<<endl;
    imprimir_linea_caracter('=');
}

void imprimir_linea_caracter(char c){
    cout<<setw(TAM_MAX)<<setfill(c)<<""<<endl;
    cout<<setfill(' ');
}

void imprimir_linea(int fecha, int dni, int seg_i, int seg_f, int s_duracion, char especialidad,
                    char Si_Recetaron_Med, double tarifa, double monto_Med){
    
    
    // FECHA DNI INCIO FIN DURAC(H:M:S) DURAC(H)  ESPECIALIDAD PAGO(CITA + MED)
    imprimir_fecha(fecha);
    cout<<setw(TAM_MAX/COLUMNAS)<<dni;
    imprimir_hora(seg_i);
    imprimir_hora(seg_f);
    imprimir_hora(s_duracion);
    cout<<setw(TAM_MAX/COLUMNAS)<<(double)s_duracion/3600;
    imprimir_especialidad(especialidad);
    imprimir_pago(tarifa, monto_Med);
    
}

void imprimir_header(){
    cout<<setw(TAM_MAX/COLUMNAS-5)<<"Fecha";
    cout<<setw(TAM_MAX/COLUMNAS)<<"Paciente";
    cout<<setw(TAM_MAX/COLUMNAS)<<"Inicio";
    cout<<setw(TAM_MAX/COLUMNAS-2)<<"Fin"<<setw(4)<<"";
    cout<<setw(TAM_MAX/COLUMNAS)<<"Duracion(H:M:S)";
    cout<<setw(TAM_MAX/COLUMNAS)<<"Duracion(H)";
    cout<<setw(TAM_MAX/COLUMNAS)<<"Especialidad"<<setw(6)<<"";
    cout<<setw(TAM_MAX/COLUMNAS)<<"Pago(cita+medicinas)"<<endl;
    imprimir_linea_caracter('-');
}