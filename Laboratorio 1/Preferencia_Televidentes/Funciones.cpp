/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 9 de abril de 2025, 20:43
 */

#include "Funciones.hpp"

//sabemos como lo vamos a leer 
//sabemos como lo vamos a imprimir


//DEFINCION DE MODULOS

void leer_Y_Procesar(){
    
    imprimir_Titulos("EMPRESA DE OPINION DE MERCADO S. A.", "REGISTRO DE PREFERERENCIA DE LOS TELEVIDENTES");
    imprimir_header();
    
    //aqui empieza el proceso del bucle
    int cant_televidentes =0;
    /*while(true){ */
        //varaibles para el resumen
        int cant_televidentes_registrados = 0;
        int cant_menores_14_19 =0;
        int cant_M_adul_No_930_1245 = 0;
        int cant_H_Joven_Mas_3horasMedia = 0;
        int cant_televidentes_Ven_770_312O570_NO_314_NO_555 =0;
        int tiempo_prom_Menores_Adultos; //recomiendo convetirlo en segundos y luego en H:M:
        double porcen_M_Tevepucp = 0.0;
        double porcen_H_joven_TPVision = 0.0 ;
        double porcen_adultosRegistrados = 0.0 ;
        double promedio_CanalesQueVenTelevidentes = 0.0 ;
  
        int dni;
        cin>>dni;
        //esto se coloca siempre en la primera lectura del bucle
       /* if(cin.eof()) break;*/
        
        procesar_Televidentes(dni, cant_televidentes_registrados, cant_menores_14_19, cant_M_adul_No_930_1245,
                              cant_H_Joven_Mas_3horasMedia, cant_televidentes_Ven_770_312O570_NO_314_NO_555,
                              tiempo_prom_Menores_Adultos, porcen_M_Tevepucp, porcen_H_joven_TPVision,
                              porcen_adultosRegistrados, promedio_CanalesQueVenTelevidentes);
        cant_televidentes++;        
   /* } */
    
    
    
}


void imprimir_Titulos(const char* titulo, const char* subtitulo){
    
    cout<<setw((TAM_REPORTE + TITULO) /2 )<<titulo<<endl;
    imprimir_linea('=');
    cout<<setw((TAM_REPORTE + SUBTITULO) /2 )<<subtitulo<<endl;
    imprimir_linea('=');
}

void imprimir_linea(char c){
    cout<<setw(TAM_REPORTE)<<setfill(c)<<""<<endl;
    cout<<setfill(' ');
}

void imprimir_header(){
    cout<<setw( TAM_REPORTE/COLUMNAS )<< "DNI No.";
    cout<<setw( TAM_REPORTE/COLUMNAS )<< "Sexo";
    cout<<setw( TAM_REPORTE/COLUMNAS )<< "Categoria";
    cout<<setw( TAM_REPORTE/COLUMNAS )<< "Hora(P)";
    cout<<setw( TAM_REPORTE/COLUMNAS )<< "Hora(A)";
    cout<<setw( TAM_REPORTE/COLUMNAS )<< "Duracion(H:M:S)";
    cout<<setw( TAM_REPORTE/COLUMNAS )<< "Duracion(H)";
    cout<<setw( TAM_REPORTE/COLUMNAS )<< "Canales";
    cout<<setw( TAM_REPORTE/COLUMNAS )<< "Companía"<<endl;
    
    imprimir_linea('-');
    
}

void procesar_Televidentes(int dni,int &cant_televidentes_registrados,int  &cant_menores_14_19, int &cant_M_adul_No_930_1245,
                           int &cant_H_Joven_Mas_3horasMedia, int &cant_televidentes_Ven_770_312O570_NO_314_NO_555,
                           int &tiempo_prom_Menores_Adultos, double &porcen_M_Tevepucp, double &porcen_H_joven_TPVision,
                           double &porcen_adultosRegistrados, double &promedio_CanalesQueVenTelevidentes){

    //aca se lee y transforma. Al final se agrega la funcion imprime_linea
    
    char sexo;
    int dd, mm, aa; //para fecha
    char car;
    int hh_i, mm_i, ss_i; //hora prendido
    int hh_f, mm_f, ss_f; //hora apagado
    int canal_1, canal_2, canal_3;
    
    cin>>sexo>>dd>>car>>mm>>car>>aa;
    cin>>hh_i>>car>>mm_i>>car>>ss_i;
    cin>>hh_f>>car>>mm_f>>car>>ss_f;
    
    calcular_categoria(dd, mm, aa);
    
    imprimir_linea(dni, sexo, dd, mm,aa,hh_i,mm_i,ss_i,hh_f,mm_f,ss_f,canal_1,canal_2,canal_3);
    
    
    
}

void calcular_categoria(int dd,int  mm, int aa){
    //aqui determinas si es joven, adulto o menor
    //tambien inlcuye contador para luego ponerlo en el reporte
}

void imprimir_linea(int dni, char sexo, int dd, int mm,int aa,
                    int hh_i,int mm_i,int ss_i,int hh_f,int mm_f,
                    int ss_f,int canal_1,int canal_2,int canal_3){
    
    cout<<setw( TAM_REPORTE/COLUMNAS )<< dni;
    contar_E_Imprimir_sexo(sexo); //AQUI HAY UN CONTADOR
    Determinar_e_imprimir_categoria(aa);
//    Impimir_Hora()
}

void contar_E_Imprimir_sexo(char s/*, int &cant_M, int &cant_H*/){
    //NO OLVDES EL CONTADOR
    
    int cant_M=0;
    int cant_H=0;
    
    if(s=='F'){
        cout<<setw( TAM_REPORTE/COLUMNAS )<< "Femenino";
        cant_M++;
    }
    else{
        cout<<setw( TAM_REPORTE/COLUMNAS )<< "Masculino";
        cant_H++;
    }
}

void Determinar_e_imprimir_categoria(int aa){
   //
    if(aa>2009){
        cout<<setw( TAM_REPORTE/COLUMNAS )<< "Menor";
    }
    else{
       if(2009>aa and aa>1988){
           cout<<setw( TAM_REPORTE/COLUMNAS )<< "Joven";
       } 
       else{
           cout<<setw( TAM_REPORTE/COLUMNAS )<< "Adulto";
       }
    }
}

//void Imprimir_hora(int hh, int mm, int ss){
//    cout<<()
//}
