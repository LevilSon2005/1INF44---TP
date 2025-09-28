/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 4 de abril de 2025, 11:37
 */

#include "Funciones.hpp"

//Define las instrucciones de cada funcion

//    FECHA      DNI     NOMBRES Y APELLIDOS   HORA     TIPO  DISTANCIA    MONTO    ESTADO
//  07/05/2024 64432010   Gomez/Lopez/Luisa   23:25:17    3      0.68      785.85    0




//------------------------------------------------------------

/*
 En Leer_Y_Procesar: 
 * se llama a la funcion para imprimir el titulo
 * se usa el while para que lea todas las lineas del archivo y que se detenga con eof
 * declaran variables 
 */

//acá solo lee e invoca un funcion que imprime
void Leer_Y_procesarPapeleta(int i){
    
    //aca se lee 
    
    int fecha_Transformada;
    int Hora_Transfroamda;
    int dni;
   
    // lee y transforma la fecha
    fecha_Transformada = obtener_Fecha_Transformada();
    
    //lee  dni
    cin >> dni;
    
    /*PRIMERA OPCION: Ignorar el nombre*/
    
    //Se ignora los nombres y apellidos 
    //leer_E_Ignorar_Nombre();
    
    /*SEGUNDA OPCION:Vamos a modificar el nombre*/
    //Leer, modificar e imprimir el nombre 
    
    Procesar_E_Imprimir_papeletas(fecha_Transformada, dni );
    Hora_Transfroamda = Leer_Y_Transformar_Hora();
    
}


//----------------------------------------------------------------------

/*
 En Processar_papeletas:
 * Imprime la mitad, hasta antes de hora
 * Se invoca otra mitad que imprime la otra mitad: hora, tipo de infraccion,  distancia, monto, estado.
 * Se invoca una funcion para que imprima el resumen al final
 */

void Procesar_E_Imprimir_papeletas(int fecha_Transf, int dni, int Hora_Transformada){
    
    imprimir_fecha(fecha_Transf, dni);
    cout << dni;
    leer_E_Imprimir_Nombre_Modificado();
    Imprimir_Fecha(Hora_Transformada);
    
    
}

//----------------------------------------------------------------------
void leer_E_Imprimir_Nombre_Modificado(){
    
    char c;
    cin >> ws;
    
    while(true){
        c = cin.get();
        
        if(c==' ') break;
        
        if (c == '/'){
            cout<<" ";
        }
        else{
            cout<<c;
        }
    }
    
}


//----------------------------------------------------------------------

void Imprimir_Fecha(int hora){
    
    cout << (hora/3600)<<":"<<(hora%3600)/60<<":"<<(hora%60);
    
}


//----------------------------------------------------------------------
/*
void leer_E_Ignorar_Nombre(){
    
    char c;
    cin>> ws; //para que lea todos los espacios que hay entre entre Dni y nombre y me deje en la primera letra del nombre
    
    while (true){
        c = cin.get();
        
        if (c=' ')break;
    }
}
  */

//----------------------------------------------------------------------
int obtener_Fecha_Transformada(){
    int fecha;
    int dd, mm, aa;
    char slash;
    
    cin>>dd>>slash>>mm>>slash>>aa;
    
    //osea de 07/05/2024 pasa a 20240507 como para realizar comparaciones
    fecha = aa*10000 + mm*100 + dd;
    
    return fecha;
}

void  imprimir_fecha(int fecha_Transf, int dni){
    int dd, mm, aa;
    
    dd = fecha_Transf %100;
    aa = fecha_Transf /10000;
    mm = (fecha_Transf/100)%100;
    
//    cout <<setw(TAM_MAX/NUMB_COLUMNS -13)<<
    cout<<setfill('0')<<setw(2)<<dd<<"/"
                     <<setw(2)<<mm<<"/"
                     <<setw(4)<<aa;
    cout<<setfill(' ');
    
}

//----------------------------------------------------------------------

int Leer_Y_Transformar_Hora(){
    int horas, segundos, minutos;
    char Dos_Puntos;
    
    cin >>horas>>Dos_Puntos>>minutos>>Dos_Puntos>>segundos;
    
//    la hora pasarla a segundos
    int Hora_Transformada;
    
    Hora_Transformada = horas*3600 + minutos*60 + segundos;
    
    return Hora_Transformada;
}

//----------------------------------------------------------------------
/*
void leer_E_Ignorar_Nombre(){
    
    char c;
    cin>> ws; //para que lea todos los espacios que hay entre entre Dni y nombre y me deje en la primera letra del nombre
    
    while (true){
        c = cin.get();
        
        if (c=' ')break;
    }
}
  */