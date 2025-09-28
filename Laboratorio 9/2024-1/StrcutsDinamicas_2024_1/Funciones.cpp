/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 23 de junio de 2025, 15:57
 */

#include <random>

#include "Funciones.hpp"
#include "Cliente.hpp"
#include "Libro.hpp"
#include "Venta.hpp"
#include "Fecha.hpp"

void apertura_lectura(ifstream &input, const char* name){
    input.open(name, ios::in);
    if( not input.is_open())
        cout<<"El archivo "<<name<<" no se abre"<<endl;
}

void apertura_escritura(ofstream &ouput, const char* name){
    ouput.open(name, ios::out);
    if( not ouput.is_open())
        cout<<"El archivo "<<name<<" no se abre"<<endl;
    else
        cout<<"El reporte - "<<name<<" se abre"<<endl;
}

void ignorar(ifstream &input, char del){
    while(input.get() != del);
}

void imprimir_titulo(ofstream &ouput, const char* titulo){
    ouput<<setw((TAMREPORTE + strlen(titulo))/2)<<titulo<<endl;
}

void imprimir_linC(ofstream &ouput, char c){
    ouput<<setfill(c)<<setw(TAMREPORTE)<<""<<setfill(' ')<<endl;
}

void reservar_memoria_cliente(struct Cliente* &arrClientes){
    arrClientes = new struct Cliente [65];
}

int leer_int(ifstream &input){
    int num;
    input>>num;
    input.get();
    return num;
}

double leer_double(ifstream &input){
    double num;
    input>>num;
    input.get();
    return num;
}

char* leer_cadena(ifstream &input, char del){
    char* cadena;
    char buffer[200];
    input.getline(buffer, 200, del);
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

char* asignar_cadena(const char* buffer){
    char* cadena;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

void leerClientes(const char* name,struct Cliente* &arrClientes, int &cantClientes){
    ifstream input;
    apertura_lectura(input, name);
    int dni;
    reservar_memoria_cliente(arrClientes);
    while(true){
        input>>dni;
        if(input.eof()) break;
        input.get();
        arrClientes[cantClientes].dni = dni;
        arrClientes[cantClientes].nombre = leer_cadena(input, '\n');
        cantClientes++;
    }
}

void  reserva_memoria_libros(struct Libro* &arrLibros){
    arrLibros = new struct Libro[275];
}

void leerLibros(const char* name,struct Libro* &arrLibros,int &cantLibros){
    ifstream input;
    apertura_lectura(input, name);
    char codigo[10];
    reserva_memoria_libros(arrLibros);
    while(true){
        input.getline(codigo,10, ',');
        if(input.eof()) break;
        arrLibros[cantLibros].codigo = asignar_cadena(codigo);
        arrLibros[cantLibros].titulo = leer_cadena(input, ',');
        arrLibros[cantLibros].autor = leer_cadena(input, ',');
        arrLibros[cantLibros].precio = leer_double(input);
        cantLibros++;
    }
}

void reservar_memoria_ventas(struct Libro* &arrLibros, int cantLibros){
    for(int i=0;i<cantLibros;i++){
        //para cada libro 10 struct Venta 
        arrLibros[i].arrVentasLibros = new struct Venta[50];
    }
}

struct Fecha leerFecha(ifstream &input){
    struct Fecha fecha;
    int d,m,a;
    char c;
    
    input>>d>>c>>m>>c>>a>>c;
    fecha.dd = d;
    fecha.mm = m;
    fecha.aa = a;
    fecha.fecha = a*10000+m*100+d;
    
    return fecha;
}

int buscar(char* codigo,struct Libro* arrLibros, int cantLibros){
    for(int i=0;i<cantLibros;i++){
        if(strcmp(codigo, arrLibros[i].codigo)==0) return i;
    }
    return NO_ENCONTRADO;
}

void leerVentas(const char* name,struct Libro* &arrLibros,int cantLibros){
    ifstream input;
    apertura_lectura(input, name);
    int posLibro=0,cantLibrosVendidos=0, califTotal=0, calificacion;
    char codigo[10];
    reservar_memoria_ventas(arrLibros,cantLibros); //para el arreglo de Ventas
    
    while(true){
        input.getline(codigo, 10, ',');
        if(input.eof()) break;
        posLibro = buscar(codigo, arrLibros, cantLibros);
        if(posLibro != NO_ENCONTRADO){
            cantLibrosVendidos = arrLibros[posLibro].cantLibrosVendidos;
            arrLibros[posLibro].arrVentasLibros[cantLibrosVendidos].dni = leer_int(input);
            arrLibros[posLibro].arrVentasLibros[cantLibrosVendidos].fechaCompra = leerFecha(input);
            calificacion = leer_int(input);
            arrLibros[posLibro].arrVentasLibros[cantLibrosVendidos].calificacion = calificacion;
            arrLibros[posLibro].sumaDeCalificiaciones += calificacion;
            arrLibros[posLibro].cantLibrosVendidos++;
        }else
            ignorar(input, '\n');
    }
    
    
    
}

void completarLibros(struct Libro* arrLibros,int cantLibros){
    double prom=0.0;
    for(int i=0;i<cantLibros;i++){
        prom = double (arrLibros[i].sumaDeCalificiaciones)/arrLibros[i].cantLibrosVendidos;
        if(prom>= 75) arrLibros[i].ranking = 5;
        else{
            if(prom>= 50) arrLibros[i].ranking = 3;
            else{
                if(prom>= 25) arrLibros[i].ranking = 2;
                else{
                    arrLibros[i].ranking = 1;
                }
            }
        }
    }
}

void imprimir_reporte(const char* name,struct Libro* arrLibros,int cantLibros,
                    struct Cliente* &arrClientes, int cantClientes){
    
    ofstream ouput;
    apertura_escritura(ouput, name);
     for(int i=0;i<cantLibros;i++){
        ouput<<"num: "<<i+1<<endl;
        ouput<<"codigo: "<<arrLibros[i].codigo<<endl;
        ouput<<"titulo: "<<arrLibros[i].titulo<<endl;
        ouput<<"autor: "<<arrLibros[i].autor<<endl;
        ouput<<"cantLibrosVendidos: "<<arrLibros[i].cantLibrosVendidos<<endl;
        ouput<<"ranking: "<<arrLibros[i].ranking<<endl;
        ouput<<"suma: "<<arrLibros[i].sumaDeCalificiaciones<<endl;
        for(int k=0;k<arrLibros[i].cantLibrosVendidos;k++){
            ouput<<"calificacion: "<<"-"<<k<<": "<<arrLibros[i].arrVentasLibros[k].calificacion<<endl;
            ouput<<"dni: "<<"-"<<k<<": "<<arrLibros[i].arrVentasLibros[k].dni<<endl;
            ouput<<"fecha: "<<"-"<<k<<": "<<arrLibros[i].arrVentasLibros[k].fechaCompra.fecha<<endl;
        }
        ouput<<"-----"<<endl;
    }
}