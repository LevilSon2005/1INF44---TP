/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 30 de junio de 2025, 17:25
 */

#include "Funciones.hpp"

void imprimir_titulo(ofstream &ouput, const char* titulo){
    ouput<<setw((TAMREPORTE +strlen(titulo))/2)<<titulo<<endl;
}

void imprimir_linC(ofstream &ouput, char del){
    ouput<<setw(TAMREPORTE)<<setfill(del)<<""<<setfill(' ')<<endl;
}

void apertura_lectura(ifstream &input, const char* name){
    input.open(name, ios::in);
    if(not input.is_open())
        cout<<"El archivo "<<name<< " no se abre"<<endl;
}

void imprimir_indice(ofstream &ouput, int num){
    ouput<<setw(2)<<right<<num<<") ";
}

void apertura_escritura(ofstream &ouput, const char* name){
    ouput.open(name, ios::out);
    if(not ouput.is_open())
        cout<<"El archivo "<<name<< " no se abre"<<endl;
    else
        cout<<"El reporte - "<<name<<" se abre"<<endl;
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

void  insertarAlFinal(char* codInf, double precioInf, char* descripcion,struct NodoTablaInfracciones*& listaInfracciones){
    struct NodoTablaInfracciones* new_nodo;
    struct NodoTablaInfracciones* recorrido = listaInfracciones;
    
    new_nodo = new struct NodoTablaInfracciones;
    new_nodo->dato.codigo = asignar_cadena(codInf);
    new_nodo->dato.multa = precioInf;
    new_nodo->dato.descripcion = asignar_cadena(descripcion);
    new_nodo->siguiente = nullptr;
    
    if(listaInfracciones == nullptr) listaInfracciones = new_nodo;
    else{
        while(recorrido->siguiente){
            recorrido = recorrido->siguiente;
        }
        recorrido->siguiente =  new_nodo;
    }
}

void leerTablaDeInfracciones(const char* name, struct NodoTablaInfracciones*& listaInfracciones){
    listaInfracciones= nullptr;
    ifstream input;
    apertura_lectura(input, name);
    char *codInf, * descripcion;
    double precioInf;
    
    while(true){
        codInf = leer_cadena(input, ',');
        if(input.eof()) break;
        precioInf = leer_double(input);
        descripcion = leer_cadena(input, '\n');
        insertarAlFinal(codInf, precioInf, descripcion, listaInfracciones);
    }
}

void insertarOrdenadoEmpresas(int dni, char* nombre, char* distrito, struct NodoEmpresasRegistradas* &listaEmpresas){
    struct NodoEmpresasRegistradas* new_nodo;
    struct NodoEmpresasRegistradas* recorrido = listaEmpresas;
    struct NodoEmpresasRegistradas* anterior = nullptr;
    
    new_nodo = new struct NodoEmpresasRegistradas;
    new_nodo->dato.dni = dni;
    new_nodo->dato.nombre = asignar_cadena(nombre);
    new_nodo->dato.distrito = asignar_cadena(distrito);
    new_nodo->dato.numPlacas =0;
    new_nodo->dato.infraccion = new struct InfraccionesCometidas[40]{};
    new_nodo->dato.cantidadDeInfracciones =0;
    new_nodo->dato.totalPagado =0.0;
    new_nodo->dato.totalAdeudado=0.0;
    new_nodo->siguiente = nullptr;
    
    while(recorrido){
        if(strcmp(recorrido->dato.distrito, distrito)>0) break;
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    
    if(anterior == nullptr) listaEmpresas = new_nodo;
    else{
        anterior->siguiente =  new_nodo;
        new_nodo->siguiente = recorrido;
    }
}

void leerEmpresasRegistradas(const char* name, struct NodoEmpresasRegistradas* &listaEmpresas){
    listaEmpresas = nullptr;
    
    ifstream input;
    apertura_lectura(input, name);
    int dni;
    char* nombre, *distrito;
    
    while(true){
        input>>dni;
        if(input.eof()) break;
        input.get();
        nombre = leer_cadena(input, ',');
        distrito = leer_cadena(input, '\n');
        insertarOrdenadoEmpresas(dni, nombre, distrito, listaEmpresas);
    }
    
}

struct NodoEmpresasRegistradas* buscarDni(int dni,struct NodoEmpresasRegistradas* listaEmpresas){
    struct NodoEmpresasRegistradas* recorrido = listaEmpresas;
    
    while(recorrido){
        if(dni == recorrido->dato.dni) return recorrido;
        recorrido = recorrido->siguiente;
    }
    return nullptr;
}

void insertarPlaca(char* placa, int dni, struct NodoEmpresasRegistradas* listaEmpresas){
    struct NodoEmpresasRegistradas* posEmpresa = buscarDni(dni, listaEmpresas);
    int cantPlacas=0;
    if(posEmpresa != nullptr){
        cantPlacas=posEmpresa->dato.numPlacas;
        posEmpresa->dato.placas[cantPlacas] = asignar_cadena(placa);
        posEmpresa->dato.numPlacas++;
    }
}

void leerPlacas(const char* name, struct NodoEmpresasRegistradas* listaEmpresas){

    
    ifstream input;
    apertura_lectura(input, name);
    int dni;
    char* placa;
    while(true){
        input>>dni;
        if(input.eof()) break;
        input.get();
        placa = leer_cadena(input, '\n');
        insertarPlaca(placa, dni, listaEmpresas);
    }
}