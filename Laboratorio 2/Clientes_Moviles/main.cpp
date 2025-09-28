/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: binny
 *
 * Created on 19 de abril de 2025, 16:13
 */
#include "Funciones.hpp"

int main(int argc, char** argv) {

    /*
 CON CONSTRUCTOR:
 * 
 * ifstream input_nomre("ARCHIVO DE LECTURA", ios::in);
 * 
 SIN CONSTRUCTOR:
 * 
 * ifstream input_nombre; //en el main
 * 
 * input_nombre.open("ARCHIVO DE LECTURA", ios::in); //en otro modulo
 
 */

/*
 ES NECESARIO APERTURA Y VERIFICAR
 * 
 * //EN EL MAIN
 * 
 * int main(){
 * 
 *      Lectura_Y_procesar("codigos.txt", "reporte.txt");
 * 
 * }
 * 
 * void Lectura_Y_Procesar(consta char* name_arch_codigo,
 *                         const char* name_arch_reporte){
 *      ifstream input_codigo; //cin para codigos;
 *      ofstream output_reporte //cout para reporte;
 * 
 *      apertura_lectura(input_codgio,name_arch_codigo);
 *      apertura_ecritura(ouput_reporte, name_arch_reporte);
 * }
 * 
 * void apertura_lectura(const char* name_Arch , ifstream &input){
 *      input_codigo.open(name_Arch, ios::in);
 *      
 *      //validar
 *      if(not input.is_open()){
 *          cout <<"Error en el archivo "<< name_Arch <<" .No se pudo abrir"<<endl;
 *          exit(1);
 *      }
 * }
 * 
 * void apertura_escritur(ofstream &output , const char* name_arch){
 *      ouput.open(name_arch, ios:out);
 * 
 *      if(not ouput.is_open()){
 *      cout<<"ERROR: El archivo "<<name_arch<<"no se puede abrir."<<endl;
 * 
 *      }
 * }
 
 
 */
    
    leer_procesar_infracciones("Empresas_de_transporte.txt",
                                "Informacion_de_vehiculos.txt", 
                                "Infracciones_de_transito.txt",
                                "reporte.txt");
    return 0;
}


