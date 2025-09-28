/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 29 de junio de 2025, 13:17
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

void crearLista(const char* name, struct Nodo *&listaNumeros){
    ifstream input;
    apertura_lectura(input, name);
    int num;
    
    //siempre se inicializa la lista
    listaNumeros= nullptr;
    
    while(true){
        input>>num;
        if(input.eof()) break;
        insertar(num, listaNumeros);
    }
}



// TIENE & PORQUE SE CAMBIA HACIA DONDE APUNTA
void insertar(int num, struct Nodo* &listaNumeros){
    //creamos new_nodo
    struct Nodo* new_nodo;
    new_nodo = new struct Nodo;
    new_nodo->dato = num;
    new_nodo->siguiente = nullptr;
    
    //lista apunta al primer nodo;
    if(listaNumeros == nullptr){
        listaNumeros = new_nodo;
    }else{
        struct Nodo* recorrido;
        recorrido= listaNumeros;
        
        //este bucle te lleva al ultimo nodo. Se detiene cuando el siguiente sea diferente a nullptr
        while(recorrido->siguiente){
            recorrido = recorrido->siguiente;
        }
        //ahora recorrido se encuentra en el ultimo nodo
        recorrido->siguiente=new_nodo;
    }
}


void  imprimirLista(const char* name,struct Nodo* listaNumeros){
    struct Nodo* recorrido;
    recorrido=listaNumeros;
    
    ofstream ouput;
    apertura_escritura(ouput, name);
    
    imprimir_titulo(ouput, "PRUEBA DE LISTA LIGADAS AL FINAL");
    
    //no es recorrido->siguiente porque sino no imprimiria el ultimo nodo, este llega hasta ser recorrido = nullptr, pero va a imprimir todos
    while(recorrido){
       ouput<<recorrido->dato<<endl; 
       recorrido = recorrido->siguiente;         
    }
}

void crearListaOrdenada(const char* name,struct Nodo* &listaNumOrdenados){
    listaNumOrdenados=nullptr;
    
    ifstream input;
    apertura_lectura(input, name);
    int num;
    while(true){
        input>>num;
        if(input.eof()) break;
        insertarOrdenado(num, listaNumOrdenados);
    }
}

void insertarOrdenado(int num, struct Nodo* &listaNumOrdenados){
    
    //creamos el new_nodo;
    struct Nodo* new_nodo;
    new_nodo = new struct Nodo;
    new_nodo->dato = num;
    new_nodo->siguiente = nullptr;
    
    //creamos recorrido que apunta al inicio de lista y si esta vacia tambien es nullptr
    struct Nodo* recorrido = listaNumOrdenados;
    struct Nodo* anterior = nullptr;
    while(recorrido){
        if(recorrido->dato > num) break;
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    
    new_nodo->siguiente = recorrido;
    if(anterior == nullptr) listaNumOrdenados = new_nodo;
    else anterior->siguiente = new_nodo;
            
}

void  eliminarNum(int num, struct Nodo* &listaNumOrdenados){
    struct Nodo* recorrido=listaNumOrdenados;
    struct Nodo* anterior=nullptr;
    //se detiene si es nullptr(vacio o llego al final) - se detiene en el dato a eliminar, o sino se encuentra en el mayor más cercano
    while(recorrido and recorrido->dato < num){
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    
    //una vez ya detenido en 1. nullptr  2. en el dato a elimninar  3. en el siguiente mayor
    if(recorrido == nullptr or recorrido->dato!=num){
        cout<<"No se encontró el numero a eliminar"<<endl;
    }//si es que su existe el dato a eliminar
    else{
        //si es el primero en la lista
        if(anterior==nullptr) listaNumOrdenados = recorrido->siguiente;
        else anterior->siguiente = recorrido->siguiente;
        
        delete recorrido;
    }
}

void crearListaInicio(const char* name,struct Nodo* &listaNumInicio){
    listaNumInicio = nullptr;
    
    ifstream input;
    apertura_lectura(input, name);
    int num;
    while(true){
        input>>num;
        if(input.eof()) break;
        insertarInicio(num, listaNumInicio);
    }
}


void insertarInicio(int num, struct Nodo* &listaNumInicio){
    struct Nodo* new_nodo;
    
    //armamos new_nodo
    new_nodo = new struct Nodo;
    new_nodo->dato = num;
    new_nodo->siguiente = nullptr ;
    
    new_nodo->siguiente = listaNumInicio;
    listaNumInicio = new_nodo;
    
}
