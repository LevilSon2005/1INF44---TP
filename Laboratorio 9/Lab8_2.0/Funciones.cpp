/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 23 de junio de 2025, 18:10
 */

#include <random>

#include "Funciones.hpp"


void imprimir_titulo(ofstream &ouput, const char* titulo){
    ouput<<setw((TAMREPORTE+strlen(titulo))/2)<<titulo<<endl;
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

int leer_entero(ifstream &input){
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

void reserva_memoria(struct TablaDeInfracciones* &arrTablaDeInfracciones){
    arrTablaDeInfracciones = new struct TablaDeInfracciones[138];
}

void leerTablaInfracciones(const char* name,struct TablaDeInfracciones* &arrTablaDeInfracciones,int &cantInfracciones){
    ifstream input;
    apertura_lectura(input, name);
    
    char codigo[15];
    reserva_memoria(arrTablaDeInfracciones);
    while(true){
        input.getline(codigo, 15, ',');
        if(input.eof()) break;
        arrTablaDeInfracciones[cantInfracciones].codigo = asignar_cadena(codigo);
        arrTablaDeInfracciones[cantInfracciones].multa = leer_double(input);
        arrTablaDeInfracciones[cantInfracciones].descripcion = leer_cadena(input, '\n');
        cantInfracciones++;
    }
}

void toMayus(char* cadena){
    for(int i=0;cadena[i];i++){
        if(cadena[i]!= ' ' and cadena[i]>='a' and cadena[i]<='z') cadena[i] -= ('a'-'A');
    }
}

void reservar_memoria(struct EmpresasRegistradas* &arrEmpresasRegistradas){
    arrEmpresasRegistradas = new struct EmpresasRegistradas[45]{};
}


void leerEmpresasregistradas(const char* name,struct EmpresasRegistradas* &arrEmpresasRegistradas,int &cantEmpresas){
    ifstream input;
    apertura_lectura(input, name);
    char* nombre, *distrito;
    int dni;
    reservar_memoria(arrEmpresasRegistradas);
    while(true){
        input>>dni;
        if(input.eof()) break;
        input.get();
        nombre = leer_cadena(input, ',');
        distrito = leer_cadena(input, '\n');
        toMayus(nombre);
        toMayus(distrito);
        //ASIGNACION
        arrEmpresasRegistradas[cantEmpresas].dni = dni;
        arrEmpresasRegistradas[cantEmpresas].nombre = asignar_cadena(nombre);
        arrEmpresasRegistradas[cantEmpresas].distrito = asignar_cadena(distrito);
        arrEmpresasRegistradas[cantEmpresas].fechaDeInfraccion.fecha = 99999999;
        arrEmpresasRegistradas[cantEmpresas].fechaDePago.fecha = 0;
        cantEmpresas++;
    }
}

void reservar_memoriaPlacas(struct EmpresasRegistradas* &arrEmpresasRegistradas, int cantEmpresas){
    for(int i=0;i<cantEmpresas;i++){
        arrEmpresasRegistradas[i].placas = new char* [10]{};
    }
}

int buscar(int dni, struct EmpresasRegistradas* arrEmpresasRegistradas, int cantEmpresas){
    for(int i=0;i<cantEmpresas;i++){
        if(dni == arrEmpresasRegistradas[i].dni) return i;
    }
    
    return NO_ENCONTRADO;
}

void leerPlacasRegistradas(const char* name,struct EmpresasRegistradas* &arrEmpresasRegistradas,int cantEmpresas){
    ifstream input;
    apertura_lectura(input, name);
    reservar_memoriaPlacas(arrEmpresasRegistradas, cantEmpresas);
    int dni, posEmpresa, cantPlacas=0;
    char placa[10];
    
    while(true){
        input>>dni;
        if(input.eof()) break;
        input>>placa;
        posEmpresa = buscar(dni, arrEmpresasRegistradas, cantEmpresas);
        if(posEmpresa != NO_ENCONTRADO){
            cantPlacas = arrEmpresasRegistradas[posEmpresa].numPlacas;
            arrEmpresasRegistradas[posEmpresa].placas[cantPlacas] = asignar_cadena(placa);
            arrEmpresasRegistradas[posEmpresa].numPlacas++;
        }
    }
}

int leer_fecha(ifstream &input){
    int d,m,a,fecha=0;
    char c;
    input>>d>>c>>m>>c>>a;
    fecha = a*10000+m*100+d;
    return fecha;
}

int buscar(char* placa, struct EmpresasRegistradas* arrEmpresasRegistradas,int cantEmpresas){
    for(int i=0;i<cantEmpresas;i++){
        for(int k=0;k<arrEmpresasRegistradas[i].numPlacas;k++){
            if(strcmp(placa,arrEmpresasRegistradas[i].placas[k])==0) return i;
        }
    }
    
    return NO_ENCONTRADO;
}

int buscar(char* codInfraccion, struct TablaDeInfracciones* arrEmpresasRegistradas,int cantInfracciones){
    for(int i=0;i<cantInfracciones;i++){
        if(strcmp(codInfraccion,TablaDeInfracciones[i].codigo)==0) return i;
    }
    return NO_ENCONTRADO;
}

void leerInfraccionesCometidas(const char* name,struct TablaDeInfracciones* arrTablaDeInfracciones,int cantInfracciones,
                             struct EmpresasRegistradas* arrEmpresasRegistradas,int cantEmpresas){
    ifstream input;
    apertura_lectura(input, name);
    int fecha=0, fecha_p=0, posEmpresa,posInf;
    char* placa, *codInfraccion, haPagado;
    while(true){
        fecha = leer_fecha(input);
        if(input.eof()) break;
        input.get();
        placa = leer_cadena(input, ',');
        codInfraccion = leer_cadena(input, ',');
        input.get(haPagado);
        if(haPagado =='P'){
            input.get();
            fecha_p = leer_fecha(input);
        }
        posEmpresa = buscar(placa, arrEmpresasRegistradas, cantEmpresas);
        posInf = buscar(codInfraccion, arrTablaDeInfracciones, cantInfracciones);
        if(posEmpresa != NO_ENCONTRADO and posInf != NO_ENCONTRADO){
            
        }
    }
    
}