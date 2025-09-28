/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 28 de abril de 2025, 17:41
 */

#include "funciones.hpp"

void apertura_lectura(ifstream &input, const char* name_arch){
    input.open(name_arch, ios::in);
    if(not input.is_open()){
        cout<<"ERROR: El archivo "<<name_arch<<" no se puede abrir. "<<endl;
        exit(1);
    }
}

void apertura_escritura(ofstream &ouput, const char* name_arch){
    ouput.open(name_arch, ios::out);
    if(not ouput.is_open()){
        cout<<"ERROR: El archivo "<<name_arch<<" no se puede abrir. "<<endl;
        exit(1);
    }
    else{
        cout<<"El archivo se ha creado correctamente";
    }
}

int busqueda_cantidad_de_un_libro(int codLibro, ifstream &inputVentas){
    inputVentas.clear();
    inputVentas.seekg(0, ios::beg);
    
    int codigoLibro,d, cantidad;
    
    while(true){
        inputVentas>>d;
        if(inputVentas.eof()) break;
        while(inputVentas.get() != ' ');
        inputVentas>>codigoLibro;
        if(codLibro == codigoLibro){
            inputVentas>>cantidad;
            return cantidad;
        }
        else{
            inputVentas.get() != '\n';
        }
    }
    
}

void     imprimir_linCar(char c, ofstream &ouput){
    ouput<<setfill(c)<<setw(TAMMAX)<<""<<setfill(' ')<<endl;
}

int busqueda_descuento(ifstream &inputAutores,int codLibro){
    inputAutores.clear();
    inputAutores.seekg(0, ios::beg);
    
    double descuento;
    int codAutor, codigoLibro;
    while(true){
        inputAutores>>codAutor;
        if(inputAutores.eof()) break;
        inputAutores>>codigoLibro;
        if(codLibro == codigoLibro){
            inputAutores>>descuento;
            return descuento;
        }
        else{
            while(inputAutores.get() != '\n');
        }
    }
    
}

void procesar_un_libro(int n,int codLibro, ifstream &inputAutores, ifstream &inputLibros, ifstream &inputVentas, ofstream &ouput){
    double precio, montoRecaudado=0.0, descuento=0.0, montoAutor=0.0;
    int cantidad=0;
    inputLibros>>ws;
    while(inputLibros.get() != ' ');
    inputLibros>>precio;
    cantidad = busqueda_cantidad_de_un_libro(codLibro, inputVentas);
    montoRecaudado = precio * cantidad;
    
    //imprimir
    ouput<<setfill('0')<<setw(2)<<right<<n<<setfill(' ');
    ouput<<setw(tam)<<left<<"LIBRO"<<setw(tam)<<left<<"CANTIDAD"<<setw(tam)<<left<<"PRECIO"<<setw(tam)<<left<<"MONTO RECAUDADO"<<endl;
    imprimir_linCar(' ', ouput);
    ouput<<setw(tam)<<left<<"AUTORES"<<setw(tam)<<left<<"PORCENTAJE A RECIBIR"<<setw(tam)<<left<<"MONTO A RECIBIR"<<endl;
    
    descuento = busqueda_descuento(inputAutores, codLibro);
    montoAutor = montoRecaudado * (descuento/100);

}

void leer_procesar_libros(const char* nameAutores, const char* nameLibros, const char* nameVentas, const char* nameReporte){
    ifstream inputAutores, inputLibros, inputVentas;
    ofstream ouput;
    
    apertura_lectura(inputAutores,nameAutores );
    apertura_lectura(inputLibros,nameLibros );
    apertura_lectura(inputVentas,nameVentas );
    apertura_escritura(ouput,nameReporte );
    
    //variables de reporte
    ouput<<fixed<<setprecision(2);
    int codLibro, n=1;
    while(true){
        inputLibros>>codLibro;
        if(inputLibros.eof()) break;
        procesar_un_libro(n,codLibro,inputAutores, inputLibros, inputVentas, ouput);
        n++;
    }
    
   
}