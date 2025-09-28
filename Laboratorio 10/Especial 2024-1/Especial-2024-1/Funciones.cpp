/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 30 de junio de 2025, 11:22
 */

#include <cinttypes>
#include <valarray>

#include "Funciones.hpp"
#include "NodoLibro.hpp"

void apertura_lectura(ifstream &input, const char* name){
    input.open(name, ios::in);
    if(not input.is_open()){
        cout<<"El archivo "<<name<<" no se abrio"<<endl;
    }
}

void apertura_escritura(ofstream &ouput, const char* name){
    ouput.open(name, ios::out);
    if(not ouput.is_open()){
        cout<<"El archivo "<<name<<" no se abrio"<<endl;
    }else
        cout<<"El reporte - "<<name<<" se abrio"<<endl;
}

void imprimirTitulo(ofstream &ouput, const char* titulo){
    ouput<<setw((TAMREPORTE + strlen(titulo))/2)<<titulo<<endl;
}

void imprimir_linC(ofstream &ouput, char c){
    ouput<<setfill(c)<<setw(TAMREPORTE)<<""<<setfill(' ')<<endl;
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


int leer_int(ifstream &input){
    int dato;
    
    input>>dato;
    input.get();
    
    return dato;
}

double leer_double(ifstream &input){
    double dato;
    
    input>>dato;
    input.get();
    
    return dato;
} 

char leer_char(ifstream &input){
    char dato;
    
    input>>dato;
    input.get();
    
    return dato;
} 


void leerClientes(const char* name, struct NodoCliente* &listaCliente){
    
    listaCliente =  nullptr;
    ifstream input;
    apertura_lectura(input, name);
    int dni;
    char* nombre;
    while(true){
        input>>dni;
        if(input.eof()) break;
        input.get();
        nombre = leer_cadena(input, '\n');
        insertarOrdenadoCliente(dni, nombre, listaCliente);
    }
}

void insertarOrdenadoCliente(int dni, char* nombre, struct NodoCliente* &listaCliente){
    struct NodoCliente* new_nodo;
    struct NodoCliente* recorrido=listaCliente;
    struct NodoCliente* anterior=nullptr;
    
    //asignamos e inicializamos new_nodo
    new_nodo = new struct NodoCliente;
    new_nodo->datoCliente.dni = dni;
    new_nodo->datoCliente.nombre = asignar_cadena(nombre);
    new_nodo->datoCliente.montoComprado = 0.0;
    new_nodo->datoCliente.descuentoFuturo =0.0;
    
    //hallamos la posicion siguiente a insertar
    while(recorrido){
        if(strcmp(recorrido->datoCliente.nombre,nombre)>0 ) break;
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    
    if(anterior == nullptr) listaCliente = new_nodo;
    else anterior->siguiente = new_nodo;
    new_nodo->siguiente = recorrido;
    
}

void imprimir_listaClientes(const char* name, struct NodoCliente* listaCliente){
    struct NodoCliente* recorrido = listaCliente;
    
    ofstream ouput;
    apertura_escritura(ouput, name);
    int n=1;
    ouput<<fixed<<setprecision(2);
    while(recorrido){
        ouput<<"CLIENTE - "<<n<<": "<<recorrido->datoCliente.dni<<" - "<<recorrido->datoCliente.nombre<<endl;
        ouput<<"Montos: "<< recorrido->datoCliente.montoComprado <<" - "<<recorrido->datoCliente.descuentoFuturo<<endl;
        imprimir_linC(ouput, '-');
        recorrido = recorrido->siguiente;
        n++;
    }
}

void leerLibros(const char* name,struct NodoLibro* &listaLibro){
    listaLibro = nullptr;
    ifstream input;
    apertura_lectura(input, name);
    
    char codigo[15], *titulo, *autor;
    double precio;
    
    while(true){
        input.getline(codigo, 15, ',');
        if(input.eof()) break;
        titulo = leer_cadena(input, ',');
        autor = leer_cadena(input, ',');
        precio = leer_double(input);
        insertarFinal(codigo, titulo, autor, precio, listaLibro);
    }     
}

void insertarFinal(char* codigo, char* titulo, char* autor, double precio, struct NodoLibro* &listaLibro){
    struct NodoLibro* new_nodo;
    struct NodoLibro* recorrido=listaLibro;
    
    new_nodo = new struct NodoLibro;
    new_nodo->datoLibro.codigo = asignar_cadena(codigo);
    new_nodo->datoLibro.titulo = asignar_cadena(titulo);
    new_nodo->datoLibro.autor = asignar_cadena(autor);
    new_nodo->datoLibro.valor = precio;
    new_nodo->datoLibro.librerias = new struct Libreria[5]{};
    new_nodo->datoLibro.librerias->ventas = new struct Venta[10]{};
    new_nodo->datoLibro.cantidadLibrerias =0;
    new_nodo->datoLibro.totalVentas = 0.0;
    new_nodo->datoLibro.unidadesVendidas =0;
    new_nodo->datoLibro.cantidadBuenasCalificaciones =0;
    new_nodo->datoLibro.sumaBuenasCalificaciones =0.0;
    new_nodo->siguiente = nullptr; //   ES IMPORTANTE
    
    if(listaLibro == nullptr){
        listaLibro = new_nodo;
    }else{//si la lista no esta vacia
        while(recorrido->siguiente != nullptr){
            recorrido = recorrido->siguiente;
        }
        recorrido->siguiente = new_nodo;
    }        
}

void imprimir_listLibros(const char* name,struct NodoLibro* listaLibro){
    struct NodoLibro* recorrido = listaLibro;
    
    ofstream ouput;
    apertura_escritura(ouput, name);
    int n=1;
    ouput<<fixed<<setprecision(2);
    while(recorrido){
        ouput<<"LIBRO N° "<<n<<": "<<endl;
        ouput<<"Nombre: "<<recorrido->datoLibro.codigo<<endl;
        ouput<<"Titulo: "<<recorrido->datoLibro.titulo<<endl;
        ouput<<"Autor: "<<recorrido->datoLibro.autor<<endl;
        ouput<<"Precio: "<<recorrido->datoLibro.valor<<endl;
        imprimir_linC(ouput, '-');
        
        recorrido = recorrido->siguiente;
        n++;
    }
}

int leerFecha(ifstream& input){
    int d,m,a;
    char c;
    input>>d>>c>>m>>c>>a;
    
    return a*10000+m*100+d;
}

void leerVentas(const char* name, struct NodoCliente* listaCliente,struct NodoLibro* listaLibro){
    ifstream input;
    apertura_lectura(input, name);
    
    char codLibro[10];
    int codLibreria, fechaVenta, dni, calificacion;
    
    while(true){
        input>>codLibreria;
        if(input.eof()) break;
        fechaVenta = leerFecha(input);
        
        while(true){
            if(input.get() == '\n') break;
            input>>codLibro;
            input>>dni>>calificacion;
            completarListas(codLibreria, fechaVenta, codLibro, dni, calificacion,
                            listaCliente, listaLibro);
        }
    }
}

struct NodoLibro* buscarCodLibro(char* codLibro, struct NodoLibro* listaLibro){
    struct NodoLibro* recorrido = listaLibro;
    
    while(recorrido){
        if(strcmp(recorrido->datoLibro.codigo, codLibro)==0) return recorrido;
        recorrido = recorrido->siguiente;
    }
    return nullptr;
} 


void completarListas(int codLibreria, int fechaVenta,char* codLibro, int dni, int calificacion,
                     struct NodoCliente* listaCliente, struct NodoLibro* listaLibro){
    struct NodoCliente* posCliente;
    struct NodoLibro* posLibro;
    int cantLibrerias=0;
    posLibro = buscarCodLibro(codLibro, listaLibro);
//    posCliente = buscarDni(dni, listaCliente);
    if(posLibro != nullptr){
        cantLibrerias = posLibro->datoLibro.cantidadLibrerias;
        //falta completar librerias sin repetir
        posLibro->datoLibro.cantidadLibrerias++;
    }
}