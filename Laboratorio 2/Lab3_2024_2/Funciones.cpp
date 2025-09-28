/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 21 de abril de 2025, 14:24
 */

#include <cinttypes>

#include "Funciones.hpp"


void  apertura_lectura(ifstream &input, const char* name_arch){
    input.open(name_arch, ios::in);
    if(not input.is_open()) {
        cout <<"ERROR: El archivo "<<name_arch<<" no se puede abrir";
    }
}

void  apertura_escritura(ofstream &ouput, const char* name_arch){
    ouput.open(name_arch, ios::out);
    if(not ouput.is_open()) {
        cout <<"ERROR: El archivo "<<name_arch<<" no se puede abrir";
    }
    else{
        cout<<"El archivo se abrio correctamente";
    }
}

void imprimir_lin_caracter(char c, ofstream &ouput_reporte){
    ouput_reporte<<setw(TAM_MAX)<<setfill(c)<<""<<setfill(' ')<<endl;
}

void imprimir_titulo(ofstream &ouput_reporte){
    ouput_reporte<<setw((TAM_MAX + TITULO)/2)<<"EMPRESA DE REPARTOS A DOMICILIOS TP S.A."<<endl;
    imprimir_lin_caracter('=', ouput_reporte);
}

void leer_imprimir_nombrePlato(ifstream &input_platos, ofstream &ouput_reporte, int tam){
    char c;
    int cant;
    //leer y transformar el nombre del plato
    input_platos>>ws;
    while(true){//leer caracteres del nombre
        c = input_platos.get();
        if(c==' ' or c=='\n') break;
        if(c=='_') c=' ';
        ouput_reporte.put(c);
        cant++;
    }
    ouput_reporte<<left<<setw(tam*2 -13 - cant)<<"";
}

void procesar_imprimir_cabecera_plato(int codigo_plato, ifstream &input_platos, ofstream &ouput_reporte, double &precio_plato){
    int tam = TAM_MAX/5;
    
    //IMPRESION
    ouput_reporte<<"CODIGO: "<<setw(tam-8)<<left<<codigo_plato;
    ouput_reporte<<"DESCRIPCION: ";
    leer_imprimir_nombrePlato(input_platos, ouput_reporte, tam); //dentro esta el ws
    //SIGO CON LA LECTURA
    input_platos>>precio_plato;
    ouput_reporte<<"PRECIO: "<<setw(tam-8)<<left<<precio_plato;
    ouput_reporte<<"TIPO: ";
    leer_imprimir_nombrePlato(input_platos, ouput_reporte, tam); //sirve igual para imprimir el tipo de plato
    ouput_reporte<<endl;
    ouput_reporte<<"REPARTOS REALIZADOS: "<<endl;
    imprimir_lin_caracter('-', ouput_reporte);
}

void imprimir_hora(int h,int m ,int s, ofstream &ouput_reporte){
    ouput_reporte<<right<<setfill('0')<<setw(2)<<h<<":"<<setw(2)<<m<<":"<<setw(2)<<s<<setfill(' ');
}

void imprimir_linea_datos_entrega(int h, int m ,int s, int dni, int cantidad, ofstream &ouput_reporte, double total_por_repartido){
    int tam = TAM_MAX/COLUMNAS;
    
    ouput_reporte<<left<<setw(tam)<<dni;
    imprimir_hora(h, m ,s, ouput_reporte);
    ouput_reporte<<setw(tam-8)<<"";
    ouput_reporte<<left<<setw(tam)<<cantidad;
    ouput_reporte<<left<<setw(tam)<<total_por_repartido<<endl;
     
}


void busqueda_codigo_plato(int codigo_plato, ifstream &input_repartos, ofstream &ouput_reporte, double precio_plato, double &total_por_plato, int &cantidad_total){//se busca el codigo en el achivo de repartos
    int dni,dni_registro, h, m ,s, cantidad, codigo_registro, total_por_repartidor=0.0;
            total_por_plato=0.0, cantidad_total=0.0;
    char car,c;
    input_repartos.clear();
    input_repartos.seekg(0, ios::beg);
    while(true){
        input_repartos>>dni_registro;
        if(input_repartos.eof()) break;
        input_repartos>>ws; 
        while(input_repartos.get() !=' '); //se salta hasta llegar al espacio
        input_repartos>>h>>car>>m>>car>>s;
        //SE LEE LOS DATOS DE CADA ENTREGA POR UN REPARTIDOR PARA BUSCAR SI UNO DE ELLOS TIENE CODIGO
        while(true){//Osea se lee la cantidad - codigo varias veces 
            input_repartos>>cantidad>> codigo_registro;
            c=input_repartos.get();
            if(codigo_plato == codigo_registro){
                dni = dni_registro;
                total_por_repartidor=cantidad*precio_plato;
                total_por_plato += total_por_repartidor;
                cantidad_total+=cantidad;
                imprimir_linea_datos_entrega(h, m ,s, dni, cantidad, ouput_reporte, total_por_repartidor);
                
            }
            if(c=='\n') break;
            
        }
    }
    
}

//void busqueda_impresion_datos_entrega(int dni_repartidor, ifstream &input_repartos, ofstream &ouput_reporte){
//    
//}
void imprimir_mini_reporte(double total_por_plato,ofstream &ouput_reporte, int cantidad_total){
    ouput_reporte<<"TOTAL: ";
    ouput_reporte<<right<<setw(DISTANCIA1)<<cantidad_total;
    ouput_reporte<<setw(DISTANCIA2)<<total_por_plato<<endl;
    imprimir_lin_caracter('=', ouput_reporte);
}

void imprimir_titulo_columna(ofstream &ouput_reporte){
    ouput_reporte<<setw(TAM_MAX/COLUMNAS-3)<<"REPARTIDOR";
    ouput_reporte<<setw(TAM_MAX/COLUMNAS)<<"HORA DE PARTIDA";
    ouput_reporte<<setw(TAM_MAX/COLUMNAS)<<"CANTIDAD";
    ouput_reporte<<setw(TAM_MAX/COLUMNAS)<<"TOTAL A PAGAR"<<endl;
}

void procesar_imprimir_repartidores_por_cada_plato(int codigo_plato, ifstream &input_repartos, ofstream &ouput_reporte, double precio_plato, double &total_por_plato){
    int dni_repartidor, cantidad_total;
         //va a encontrar el codigo, ya va dar el dni, internamente se imprime la linea
    //while(true){
        imprimir_titulo_columna(ouput_reporte);
        busqueda_codigo_plato(codigo_plato, input_repartos, ouput_reporte, precio_plato, total_por_plato, cantidad_total);
        imprimir_lin_caracter('-', ouput_reporte);
        imprimir_mini_reporte(total_por_plato,ouput_reporte, cantidad_total);
//  }
    
}

void procesar_cada_plato(ifstream &input_platos, ifstream &input_repartos, ofstream &ouput_reporte){
    int codigo_plato;
    double precio_plato, total_por_plato;
    while(true){//imprime cada plato, incluido header y repartidores
        input_platos>>codigo_plato;
        if(input_platos.eof()) break;
        procesar_imprimir_cabecera_plato(codigo_plato, input_platos, ouput_reporte, precio_plato); //solo necesito archivo de platos
        //ACA VA PROCESAR_IMPRIMIR_REPARTIDORES A PARTIR DEL CODIGO DEL PLATO
        procesar_imprimir_repartidores_por_cada_plato(codigo_plato, input_repartos, ouput_reporte, precio_plato, total_por_plato);
    }
}

void lectura_procesamiento(const char* name_arch_platos,const char* name_arch_repartos,const char* name_arch_reporte){
    ifstream input_platos, input_repartos;
    ofstream ouput_reporte;
    apertura_lectura(input_platos, name_arch_platos);
    apertura_lectura(input_repartos, name_arch_repartos);
    apertura_escritura(ouput_reporte, name_arch_reporte);
    imprimir_titulo(ouput_reporte);
    ouput_reporte<<fixed<<setprecision(2);
    procesar_cada_plato(input_platos, input_repartos, ouput_reporte);
    
}