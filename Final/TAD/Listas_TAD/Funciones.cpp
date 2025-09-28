/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 3 de julio de 2025, 16:14
 */

#include <iosfwd>
#include <bits/c++config.h>

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


void inicializar(struct ListaNotas &listaNotas){
    listaNotas.inicio = nullptr;
}

void leerNotas(const char* name ,struct ListaNotas &listaNotas){
    inicializar(listaNotas);
    ifstream input;
    apertura_lectura(input, name);
    
    //se crea un struct aux;
    struct Notas aux;
    
    while(true){
        input>>aux.notaLab;
        if(input.eof()) break;
        input>>aux.notaEx1;
        input>>aux.notaEx2;
        
        //INSERTAMOS EL STRUCT EN EL TAD LISTA
        insertarAlFinal(aux, listaNotas); //con puntero inicio dentro del struct
    }
}

void insertarAlFinal(const struct Notas &aux, struct ListaNotas &listaNotas){
    struct NodoNotas* recorrido = listaNotas.inicio;
    struct NodoNotas* new_nodo;
    
    new_nodo = new struct NodoNotas;
    new_nodo->nota = aux;
    new_nodo->siguiente = nullptr;
    
    if(listaNotas.inicio == nullptr) listaNotas.inicio = new_nodo;
    else {//SI YA HAY AL MENOS UN NODO
        while(recorrido->siguiente != nullptr){
            recorrido = recorrido->siguiente;
        }
        recorrido->siguiente = new_nodo;    
    }
}

void imprimirNotas(const char* name ,const struct ListaNotas &listaNotas){
    struct NodoNotas* recorrido = listaNotas.inicio;
    ofstream ouput;
    apertura_escritura(ouput, name);
    imprimirHeaderStruct(ouput);
    while(recorrido){
        imprimirStructNotas(ouput, recorrido);
        recorrido = recorrido->siguiente;
    }
}

void imprimirHeaderStruct(ofstream &ouput){
    ouput<<setw(39)<<"";
    ouput<<left<<setw(10)<<"LAB"
            <<setw(10)<<"EX1"
            <<setw(10)<<"EX2"<<endl;
}

void imprimirStructNotas(ofstream &ouput, struct NodoNotas* notas){
    ouput<<setw(40)<<"";
    ouput<<left<<setw(10)<<notas->nota.notaLab
            <<setw(10)<<notas->nota.notaEx1
            <<setw(10)<<notas->nota.notaEx2<<endl;
}

//void inicializar_lista_p_final(struct ListaNotas_PFinal &listasNotasFinal_PFinal){
//    listasNotasFinal_PFinal.final = nullptr;
//}
//
//void leerNotas(const char* name ,struct ListaNotas_PFinal &listasNotasFinal_PFinal){
//    inicializar_lista_p_final(listasNotasFinal_PFinal);
//    ifstream input;
//    apertura_lectura(input, name);
//    
//    struct Notas aux;
//    
//    while(true){
//        input>>aux.notaLab;
//        if(input.eof()) break;
//        input>>aux.notaEx1;
//        input>>aux.notaEx2;
//        
//        //INSERTAMOS EL STRUCT EN EL TAD LISTA
//        insertarAlFinal_PFinal(aux, listasNotasFinal_PFinal); //con puntero inicio dentro del struct
//    }
//}
//
//void insertarAlFinal_PFinal(const struct Notas &aux, struct ListaNotas_PFinal & listasNotasFinal_PFinal){
//   
//}

void inicializacion_ordenada(struct ListaNotas & listaOrdenada){
    listaOrdenada.inicio = nullptr;
}

void leerNotasOrdenadas(const char* name , struct ListaNotas &listaOrdenada){
    inicializacion_ordenada(listaOrdenada);
    ifstream input;
    apertura_lectura(input, name);
    //se crea un struct aux;
    struct Notas aux;
    while(true){
        input>>aux.notaLab;
        if(input.eof()) break;
        input>>aux.notaEx1;
        input>>aux.notaEx2;
        
        //INSERTAMOS EL STRUCT EN EL TAD LISTA
        insertarOrdenado(aux, listaOrdenada); //con puntero inicio dentro del struct
    }
}

void insertarOrdenado(struct Notas aux, struct ListaNotas &listaOrdenada){
    struct NodoNotas* new_nodo;
    struct NodoNotas* recorrido = listaOrdenada.inicio;
    struct NodoNotas* anterior = nullptr;
    
    new_nodo = new struct NodoNotas;
    new_nodo->nota = aux;
    new_nodo->siguiente = nullptr;
    
    if(listaOrdenada.inicio == nullptr){ //el primer nodo
        listaOrdenada.inicio = new_nodo;
    }else{//ya tiene al menos un nodo
        
        //para ubicar donde insertar - hay dos posibilidades o es nullptr o el siguiente a donde se debe insertar
        while(recorrido ){
            if(recorrido->nota.notaLab > new_nodo->nota.notaLab) break;
            anterior = recorrido;
            recorrido = recorrido->siguiente;
        }
        if(recorrido== nullptr){//si se debe insertar al final
            anterior->siguiente = new_nodo;
        }
        else if(anterior == nullptr){//si se debe insertar al inicio
            new_nodo->siguiente = listaOrdenada.inicio;
            listaOrdenada.inicio = new_nodo;
        }else{//se inserta al medio - posicion generica
            anterior->siguiente = new_nodo;
            new_nodo->siguiente = recorrido;
        }
    }
}

//NOTA: Recorrido deberia parar en la posicion del dato, 
//si el dato no está recorrido se detiene en el siguiente mayor
void eliminarUnDato(int datoEliminar, struct ListaNotas &listaElimadaUnDato){
    struct NodoNotas* recorrido = listaElimadaUnDato.inicio;
    struct NodoNotas* anterior = nullptr;
    
    //ubicamos la posicion exacta o sino no está la siguiente 
    while(recorrido){
        if(recorrido->nota.notaLab >= datoEliminar) break;
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    //validamos si está o no está el dato a eliminar
    if(recorrido==nullptr or recorrido->nota.notaLab != datoEliminar)
        cout<<"El dato no se encuentra en la lista"<<endl;
    
    //EL ELEMENTO SE ENCUENTRA EN LA LISTA
    else{
        if(anterior == nullptr)//se elimina el primer dato
            listaElimadaUnDato.inicio = recorrido->siguiente;
        else if(recorrido->siguiente == nullptr)//si se elimina el ultimo elemento
            anterior->siguiente = nullptr;
        else //para un elemento en pos generico
            anterior->siguiente = recorrido->siguiente;

        delete recorrido;
    }
    
}

int contarRepeticiones(int datoEliminar,const struct ListaNotas &listaElimniarRepetidos){
    struct NodoNotas* recorrido = listaElimniarRepetidos.inicio;
    int cant =0;
    while(recorrido){
        if(datoEliminar == recorrido->nota.notaLab) cant++;
        recorrido = recorrido->siguiente;
    }
    return cant;
}

void eliminarDatosRepetidos(int datoEliminar,struct ListaNotas &listaElimniarRepetidos){
    int contador = 0;
    contador = contarRepeticiones(datoEliminar, listaElimniarRepetidos);
    
    for(int i=0;i<contador;i++){
        eliminarUnDato(datoEliminar, listaElimniarRepetidos);
    }
}

void inicializar_listaEliminando(struct ListaNotas &listaEliminadaCondicion){
    listaEliminadaCondicion.inicio = nullptr;
}

void leerNotasEliminando(const char* name,struct ListaNotas &listaEliminadaCondicion){
    inicializar_listaEliminando(listaEliminadaCondicion);
    ifstream input;
    apertura_lectura(input, name);
    //se crea un struct aux;
    struct Notas aux;
    while(true){
        input>>aux.notaLab;
        if(input.eof()) break;
        input>>aux.notaEx1;
        input>>aux.notaEx2;
        
        //INSERTAMOS EL STRUCT EN EL TAD LISTA
        insertarAlFinal(aux, listaEliminadaCondicion); //con puntero inicio dentro del struct
    }
}

//void eliminarMenoresQue5(struct ListaNotas &listaEliminadaCondicion){
//    struct NodoNotas* recorrido = listaEliminadaCondicion.inicio;
//    struct NodoNotas* anterior = nullptr;
//    struct NodoNotas* NodoAEliminar;
//    
//    while(recorrido){
//        //EL DATO CUMPLE LA CONDICION PARA ELIMINARSE
//        if(recorrido->nota.notaLab > 5){ 
//            NodoAEliminar = recorrido;
//            if(anterior==nullptr){
//                listaEliminadaCondicion.inicio = recorrido->siguiente;
//                recorrido =recorrido->siguiente;
//            }else{ //para pos media o final
//                anterior->siguiente = recorrido->siguiente;
//                recorrido = recorrido->siguiente;
//            }
//            delete NodoAEliminar;
//        }else{
//           anterior = recorrido;
//           recorrido = recorrido->siguiente; 
//        }
//    }
//}


//void eliminarDesaprobados(struct Node *&listaAlumnos) {
//    struct Node *recorrido = listaAlumnos, *anterior = nullptr, *nodoAEliminar;
//    
//    while(recorrido) {
//        if(recorrido->alumno.promedi0 < 11.0) {
//            nodoAEliminar = recorrido; // Guardamos el nodo a eliminar
//            
//            if(anterior == nullptr) { // Caso: primer nodo
//                listaAlumnos = recorrido->siguiente;
//                recorrido = listaAlumnos;
//            }
//            else { // Caso: nodo medio o final
//                anterior->siguiente = recorrido->siguiente;
//                recorrido = anterior->siguiente;
//            }
//            
//            delete nodoAEliminar; // Liberamos memoria
//        }
//        else {
//            anterior = recorrido;
//            recorrido = recorrido->siguiente;
//        }
//    }
//}

void eliminarMenoresQue5(struct ListaNotas &lista){
    struct NodoNotas* recorrido = lista.inicio;
    struct NodoNotas* anterior = nullptr;
    struct NodoNotas* nodoAEliminar;
    
    while(recorrido){
        if(recorrido->nota.notaLab == 5){
            nodoAEliminar = recorrido;
            if(anterior==nullptr){
                lista.inicio = nodoAEliminar->siguiente;
                recorrido = recorrido->siguiente;
            }
            else{
                anterior->siguiente = nodoAEliminar->siguiente;
                recorrido = recorrido->siguiente;
            }
            delete nodoAEliminar;
        }else{
            anterior = recorrido;
            recorrido = recorrido->siguiente;
        }
    }
            
    
}