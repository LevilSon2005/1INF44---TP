/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 4 de julio de 2025, 20:34
 */

#include "Funciones.hpp"


void apertura_lectura(ifstream &input, const char* name){
    input.open(name, ios::in);
    if(not input.is_open())
        cout<<"El archivo "<<name<< " no se abre"<<endl;
    
}

void apertura_escritura(ofstream &ouput, const char* name){
    ouput.open(name, ios::out);
    if(not ouput.is_open())
        cout<<"El archivo "<<name<< " no se abre"<<endl;
    else
        cout<<"El reporte - "<<name<<" se abre"<<endl;
    
}

void inicilizar_lista_cliente(struct ListaCliente &lista_cliente){
    lista_cliente.inicio = nullptr;
    lista_cliente.final = nullptr;
    lista_cliente.cantPares = 0;
    lista_cliente.cantImpares =0;
    lista_cliente.cantClientes =0;
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

char* leer_cadena(ifstream &input, char del){
    char* cadena;
    char buffer[200];
    
    input.getline(buffer, 200, del);
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

void leerClientes(const char* name,struct ListaCliente & lista_cliente){
    inicilizar_lista_cliente(lista_cliente);
    ifstream input;
    apertura_lectura(input, name);
    int dni;
    struct Cliente c;
    while(true){
        dni = leer_int(input);
        if(input.eof()) break;
        c.dni = dni;
        c.nombre = leer_cadena(input,'\n');
        c.descuentoFuturo =0.0;
        c.montoComprado=0.0;
        if(c.dni %2 ==0){ //PARES
            insercionInicio(c, lista_cliente);
        }else //IMPARES
            insercionFinal(c, lista_cliente);
    }    
}

bool ListaVacia(struct ListaCliente &lista){
    return (lista.inicio==nullptr and lista.final ==nullptr);
}

void insercionInicio(struct Cliente aux, struct ListaCliente &lista_cliente){
    struct NodoCliente* new_nodo;
    
    //armamos new_nodo
    new_nodo = new struct NodoCliente;
    new_nodo->datoCliente = aux;
    new_nodo->siguiente = nullptr;
    
    if(ListaVacia(lista_cliente)){//si es la primera vez. Inicio y final se actualizan y apuntan al primer nodo
        lista_cliente.inicio = new_nodo;
        lista_cliente.final = new_nodo;
    }else{
        new_nodo->siguiente = lista_cliente.inicio;
        lista_cliente.inicio = new_nodo;
    }
    lista_cliente.cantPares++;
    lista_cliente.cantClientes++;
}

void insercionFinal(struct Cliente aux,struct ListaCliente & lista_cliente){
    struct NodoCliente* new_nodo;
    
    new_nodo = new struct NodoCliente;
    new_nodo->datoCliente = aux;
    new_nodo->siguiente = nullptr;
    
    if(ListaVacia(lista_cliente)){
        lista_cliente.inicio = new_nodo;
        lista_cliente.final = new_nodo;
    }else{
        lista_cliente.final->siguiente = new_nodo;
        lista_cliente.final =  new_nodo;
    }
    lista_cliente.cantImpares++;
    lista_cliente.cantClientes++;
}