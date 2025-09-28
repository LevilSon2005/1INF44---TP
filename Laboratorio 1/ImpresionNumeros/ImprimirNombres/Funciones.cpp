/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 3 de abril de 2025, 11:11
 */

#include "Funciones.h"
//acá defino funciones

void LeerEImprimirNombres(char name[]) {
    do {
        cout << "Por favor, diga un nombre para saludar: ";
        cin.getline(name, 20);
        
        if(name[0] != '\0'){
            cout << "Buenos días, " << name << endl;
        }
        else{
            cout << "Se acabó los saludos :'(";
        }
        
    } while (name[0] != '\0');
}
