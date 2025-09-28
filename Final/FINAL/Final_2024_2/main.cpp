/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 5 de julio de 2025, 18:23
 */

#include "Funciones.hpp"
int main(int argc, char** argv) {
    struct Palabras* lexicon;
    lexicon = new struct Palabras[100]{};
    struct Plato* platos;
    platos = new struct Plato[200]{};
    
    struct Atencion atenciones[100]{};
    int cantLexicon=0, cantPlatos=0, cantAtenciones=0;
    
    leerLexicon("lexicon.csv",lexicon,cantLexicon);
    leerPlatos("platos.csv", platos, cantPlatos);
    leerAtenciones("atenciones.txt",atenciones,cantAtenciones,
                   platos,cantPlatos);
    leerComentarios("comentarios.csv",atenciones,cantAtenciones,
                    lexicon,cantLexicon);
    emitirReporte("reporte.txt",lexicon,cantLexicon,
                  atenciones,cantAtenciones);
    
//    for(int i=0;i<cantLexicon;i++){
//        cout<<lexicon[i].texto<<" : "<<lexicon[i].polaridad<<endl;
//    }
    return 0;
}

