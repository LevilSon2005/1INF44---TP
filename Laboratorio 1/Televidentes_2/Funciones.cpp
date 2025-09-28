/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 12 de abril de 2025, 23:59
 */

#include "Funciones.hpp"

#include <iostream>
#include <iomanip>
#include "Funciones.hpp"

//En LEER Y PROCESAR_CLIENTE van parametros por referencia para recibir los resultados del resumen
/*En Procesar_Cliente como parametros normales van las lecturas que hicieron y al igual que en leer van 
 parametros normales y devuelven los mismos parametros por referencia que en leer
 * 
 * NOTA:
 * Cada parametro por referencia se trabajara en modulos aparte
 */

using namespace std;


int transformacion_Seg(int h, int m, int s){
    return (h * 3600 + m * 60 + s);
}

void imprimir_linea(int dni, char sexo, int fecha, int seg_i, int seg_f,
                    int canal_1, int canal_2, int canal_3, char compania){
    int seg_duracion = seg_f - seg_i;

    cout << setw(TAM_MAX / NUM_COLUMNAS-4)<< dni;
    imprimir_Sexo(sexo);
    imprimir_categoria(fecha);
    imprimir_hora(seg_i);
    imprimir_hora(seg_f);
    imprimir_hora(seg_duracion);
    cout << setw(TAM_MAX / NUM_COLUMNAS) << (double)seg_duracion / 3600;
    imprimir_canales(canal_1, canal_2, canal_3);
    imprimir_compania(compania);
}

void imprimir_Sexo(char s){
    if (s == 'F') cout << setw(TAM_MAX / NUM_COLUMNAS-2) << "FEMENINO";
    else cout << setw(TAM_MAX / NUM_COLUMNAS-2) << "MASCULINO";
}

void imprimir_categoria(int fecha){
    int aa = fecha / 10000;
    if (aa > 2009) {
        cout << setw(TAM_MAX / NUM_COLUMNAS) << "Menor";
    } else if (aa <= 1988) {
        cout << setw(TAM_MAX / NUM_COLUMNAS) << "Adulto";
    } else {
        cout << setw(TAM_MAX / NUM_COLUMNAS) << "Joven";
    }
}

void imprimir_hora(int s){
    int h = s / 3600;
    int m = (s / 60) % 60;
    int sg = s % 60;
    char c = ':';

    cout << setw(TAM_MAX / NUM_COLUMNAS - 8) << "" <<setfill('0')<<setw(2)<<h << c <<setw(2)<<m << c <<setw(2)<<sg;
    cout<<setfill(' ');
}

void imprimir_canales(int canal_1, int canal_2, int canal_3){
    cout << setw(TAM_MAX / NUM_COLUMNAS - 5) << "";
    int n=0;
    bool primero = true;
    
    if (canal_1 > 0) {
        cout << canal_1;
        primero = false;
        n=n+3;
    }
    if (canal_2 > 0) {
        if (!primero) {
            cout << '/';
            n++;}
        
        cout << canal_2;
        primero = false;
        n=n+3;
    }
    if (canal_3 > 0) {
        if (!primero) {
            cout << '/';
            n++;}
        cout << canal_3;
        n=n+3;
    }
    
    cout<<setw(11-n)<<"";
}

void imprimir_compania(char comp){
    if (comp == 'A') cout <<setw(TAM_MAX / NUM_COLUMNAS ) << "TVPUCP";
    else if (comp == 'B') cout <<setw(TAM_MAX / NUM_COLUMNAS ) << "CableMas";
    else if (comp == 'C') cout <<setw(TAM_MAX / NUM_COLUMNAS ) << "TPVision";
    cout<<endl;
}


void imprimir_titulo(const char* titulo, int long_titulo){
    
    
    cout<<setw((TAM_MAX + long_titulo)/2)<<titulo<<endl;
    imprimir_linea_caracter('=');
    
}

void imprimir_linea_caracter(char c){
    cout<<setfill(c)<<setw(TAM_MAX)<<""<<endl;
    cout<<setfill(' ');
}

void imprimir_header(){
    cout <<setw(TAM_MAX / NUM_COLUMNAS -4)<< "DNI No.";
    cout <<setw(TAM_MAX / NUM_COLUMNAS -4) << "Sexo";
    cout <<setw(TAM_MAX / NUM_COLUMNAS +3 ) << "Categoria";
    cout <<setw(TAM_MAX / NUM_COLUMNAS ) << "Hora(P)";
    cout <<setw(TAM_MAX / NUM_COLUMNAS ) << "Hora(A)";
    cout <<setw(TAM_MAX / NUM_COLUMNAS +4) << "Duracion(H:M:S)";
    cout <<setw(TAM_MAX / NUM_COLUMNAS ) << "Duracion(H)";
    cout <<setw(TAM_MAX / NUM_COLUMNAS ) << "Canales";
    cout <<setw(TAM_MAX / NUM_COLUMNAS +2) << "Companía"<<endl;
    
    imprimir_linea_caracter('-');
    
}


void  calcular_cant_Menores_Entre14Y19H(int aa,int s_i, int s_f, int &cant){
   
    if(aa>2009){
        if(s_i>=14*3600 and s_f<=19*3600){
            cant++;
        }
    }
}

void calcular_cant_M_NoVen_Entre9_30_12_45(int aa, int s_i, int s_f, char sexo, int &n){
    
    
    bool cumple = (s_i>=(9*3600+30*60) and s_f <=12*3600+45*60);
    
    if(sexo=='F' and aa<=1988){
        if(!cumple){
            n++;
        }
    }
}

void calcular_cant_Jov_Mas3_30Hr(char s,int aa, int s_i, int s_f, int&n){
    int s_duracion = s_f -s_i;
    if(s=='M' and aa>2009 and s_duracion >=(3*3600+30*60)){
        n++;
    }
}

bool es_canal_770_312_577(int canal){
    return canal == 770 or canal == 312 or canal == 577;
}

bool noEsCanal314_555(int canal){
    return canal != 314 and canal != 555;
}

void calcular_cant_Ven_770_312_577_NoVen_314_555(int canal_1, int canal_2, int canal_3,int&n){
    bool cumple1= es_canal_770_312_577(canal_1);
    bool cumple2= es_canal_770_312_577(canal_2);
    bool cumple3= es_canal_770_312_577(canal_3);
    
    bool no_cumple1 = noEsCanal314_555(canal_1);
    bool no_cumple2 = noEsCanal314_555(canal_2);
    bool no_cumple3 = noEsCanal314_555(canal_3);
    
    if((cumple1 or cumple2 or cumple3) and ( no_cumple1 and no_cumple2 and no_cumple3)){
        n++;
    }
}

void calcular_tiempoTotal_Ven_MenoresYAdultos(int aa, int seg_i, int seg_f,int &timeTotal){
    if(aa>2009 or aa<1988){
        int seg_dura = seg_f-seg_i;
        timeTotal++;
    }
}

void actualizar_resumen(int aa,int seg_i,int  seg_f, char sexo,int canal_1, int canal_2, int canal_3, int &cant_Menores_Entre14Y19H , 
                        int &cant_M_NoVen_Entre9_30_12_45 , int &cant_Jov_Mas3_30Hr ,int &cant_Ven_770_312_577_NoVen_314_555 , 
                        int &tiempoTotal_Ven_MenoresYAdultos , double &porcen_M_Ven_TCPUCP , double &porcen_H_Jov_Ven_TPVision,
                        double &porcen_Adultos , double &prom_Canales){
    
    calcular_cant_Menores_Entre14Y19H(aa,seg_i, seg_f, cant_Menores_Entre14Y19H);
    calcular_cant_M_NoVen_Entre9_30_12_45(aa, seg_i, seg_f, sexo, cant_M_NoVen_Entre9_30_12_45);
    calcular_cant_Jov_Mas3_30Hr(sexo, aa, seg_i, seg_f, cant_Jov_Mas3_30Hr);
    calcular_cant_Ven_770_312_577_NoVen_314_555(canal_1, canal_2, canal_3,cant_Ven_770_312_577_NoVen_314_555);
    calcular_tiempoTotal_Ven_MenoresYAdultos(aa, seg_i, seg_f, tiempoTotal_Ven_MenoresYAdultos);
}

void imprimir_resumen(int n, int cant_Menores_Entre14Y19H , int cant_M_NoVen_Entre9_30_12_45 , int cant_Jov_Mas3_30Hr , 
                        int cant_Ven_770_312_577_NoVen_314_555 , int tiempoTotal_Ven_MenoresYAdultos ,  double porcen_M_Ven_TCPUCP , 
                         double porcen_H_Jov_Ven_TPVision,double porcen_Adultos ,  double prom_Canales){
    
    int TimeProm = tiempoTotal_Ven_MenoresYAdultos/n;
    
    imprimir_linea_caracter('=');
    int tam=TAM_MAX* 5/7;
    cout<<setw(TAM_MAX)<<left<<"ESTADISTICAS OBTENIDAS: "<<endl;
    cout<<setw(tam)<<left<<"Cantidad de menores que ven entre las 14:00:00 y las 19:00:00"<<setw(TAM_MAX -tam)<<right<<cant_Menores_Entre14Y19H<<endl;
    cout<<setw(tam)<<left<<"Cantidad de mujeres adultas que no ven Television entre 9:30:00 y las 12:45"<<setw(TAM_MAX -tam)<<right<<cant_M_NoVen_Entre9_30_12_45<<endl;
    cout<<setw(tam)<<left<<"Cantidad de hombres jovenes que ven Televisión más de 3 horas y media"<<setw(TAM_MAX -tam)<<right<< cant_Jov_Mas3_30Hr<<endl;
    cout<<setw(tam)<<left<<"Cantidad de personas que ven 3 canales pero no 2"<<setw(TAM_MAX -tam)<<right<<cant_Ven_770_312_577_NoVen_314_555<<endl;
    cout<<setw(tam)<<left<<"Tiempo promedio que ven jovenes y adultos: "<<setw(TAM_MAX -tam-8)<<right<<"";
            cout<<imprimir_hora(TimeProm)<<endl;
    imprimir_linea_caracter('=');
}

void procesar_Cada_Repartidor(int dni, int &cant_Menores_Entre14Y19H , 
                        int &cant_M_NoVen_Entre9_30_12_45 , int &cant_Jov_Mas3_30Hr ,int &cant_Ven_770_312_577_NoVen_314_555 , 
                        double &tiempoProm_Ven_MenoresYAdultos , double &porcen_M_Ven_TCPUCP , double &porcen_H_Jov_Ven_TPVision,
                        double &porcen_Adultos , double &prom_Canales){
    char sexo;
    int dd, mm, aa;
    char car;
    int h_i, m_i, s_i;
    int h_f, m_f, s_f;
    int canal_1, canal_2, canal_3;
    char compania;
    int fecha;
    int seg_i, seg_f;

    cin >> ws;
    cin >> sexo;
    cin >> dd >> car >> mm >> car >> aa;
    cin >> h_i >> car >> m_i >> car >> s_i;
    cin >> h_f >> car >> m_f >> car >> s_f;
    cin >> canal_1 >> canal_2 >> canal_3;
    cin >> compania;

    fecha = aa * 10000 + mm * 100 + dd;
    seg_i = transformacion_Seg(h_i, m_i, s_i);
    seg_f = transformacion_Seg(h_f, m_f, s_f);

    //Aca tambien lo paso como REFERENCIA porque quiero que me devuelvan mas de un valor
    actualizar_resumen(aa,seg_i, seg_f, sexo,canal_1, canal_2, canal_3, cant_Menores_Entre14Y19H , cant_M_NoVen_Entre9_30_12_45 , cant_Jov_Mas3_30Hr , 
                        cant_Ven_770_312_577_NoVen_314_555 , tiempoProm_Ven_MenoresYAdultos , porcen_M_Ven_TCPUCP , porcen_H_Jov_Ven_TPVision,
                        porcen_Adultos , prom_Canales);
    imprimir_linea(dni, sexo, fecha, seg_i, seg_f, canal_1, canal_2, canal_3, compania);
}


void Leer_Procesar_Repartidores(){
    imprimir_titulo("EMPRESA DE OPINIOIN DE MERCADO S. A.", TITULO);
    imprimir_titulo("REGISTRO DE PREFERENCIA DE LOS TELEVIDENTES", SUBTITULO);
    imprimir_header();
    
    int dni;
    int n=0;   
    int cant_Menores_Entre14Y19H =0;
    int cant_M_NoVen_Entre9_30_12_45=0;
    int cant_Jov_Mas3_30Hr=0;
    int cant_Ven_770_312_577_NoVen_314_555=0;
    double tiempoTotal_Ven_MenoresYAdultos=0.0;
    double porcen_M_Ven_TCPUCP=0.0;
    double porcen_H_Jov_Ven_TPVision=0.0;
    double porcen_Adultos=0.0;
    double prom_Canales=0.0;
    
    while(true){
        cin >> dni;
        if(cin.eof()) break;
        n++;
        cout << fixed << setprecision(4);
        //te devuelve parametro por referencia. porque quiero devolver mas de un valor
        procesar_Cada_Repartidor(dni, cant_Menores_Entre14Y19H , cant_M_NoVen_Entre9_30_12_45 , cant_Jov_Mas3_30Hr , 
                        cant_Ven_770_312_577_NoVen_314_555 , tiempoProm_Ven_MenoresYAdultos , porcen_M_Ven_TCPUCP , porcen_H_Jov_Ven_TPVision,
                        porcen_Adultos , prom_Canales); 
        //como ya devolvio, el resultado ya está solo uso como parametro por valor
        
    }
    
    imprimir_resumen(n, cant_Menores_Entre14Y19H , cant_M_NoVen_Entre9_30_12_45 , cant_Jov_Mas3_30Hr , 
                        cant_Ven_770_312_577_NoVen_314_555 , tiempoProm_Ven_MenoresYAdultos , porcen_M_Ven_TCPUCP , porcen_H_Jov_Ven_TPVision,
                        porcen_Adultos , prom_Canales);
}


