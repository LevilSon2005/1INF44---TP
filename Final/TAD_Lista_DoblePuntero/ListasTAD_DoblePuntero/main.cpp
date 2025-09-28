/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 4 de julio de 2025, 20:05
 */

#include "Funciones.hpp"
int main(int argc, char** argv) {
    struct ListaCliente lista_cliente;
    leerClientes("Clientes.csv", lista_cliente);
    
    
    cout<<"IMPRESION DE DNIS - NOMBRES:"<<endl;
    struct NodoCliente* recorrido = lista_cliente.inicio;
    while(recorrido){
        cout<<"DNIS "<<recorrido->datoCliente.dni <<" - "<<"NOMBRE: "<<recorrido->datoCliente.nombre<<endl;
        recorrido = recorrido->siguiente;
    }
    cout<<"PARES: "<<lista_cliente.cantPares<<endl;
    cout<<"IMPARES: "<<lista_cliente.cantImpares<<endl;
    cout<<"TOTAL: "<<lista_cliente.cantClientes<<endl;
    return 0;
}

