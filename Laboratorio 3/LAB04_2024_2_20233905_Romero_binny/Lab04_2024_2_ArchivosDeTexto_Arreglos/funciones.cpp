/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 27 de abril de 2025, 15:52
 */



#include "funciones.hpp"


void apertura_lectura(const char* name_arch, ifstream &input){
    input.open(name_arch, ios::in);
    if(not input.is_open()){
        cout <<"ERROR: El archivo "<<name_arch<<"no se pudo abrir";
    }
}

void apertura_escritura(const char* name_arch, ofstream &ouput){
    ouput.open(name_arch, ios::out);
    if(not ouput.is_open()){
        cout <<"ERROR: El archivo "<<name_arch<<"no se pudo abrir";
    }
    else{
        cout<<"El archivo se abrio correctamnete";
    }
}

void imprimir_linCaracter(char c, ofstream &ouput){
    ouput<<setw(TAMMAX)<<setfill(c)<<""<<setfill(' ')<<endl;
}

void imprimir_titulo( ofstream &ouput){
    
    ouput<<setw((TAMMAX + TITULO1) /2)<<"EMPRESA DE REPARTOS A DOMICILIOS TP S.A."<<endl;
    ouput<<setw((TAMMAX + TITULO2) /2)<<"ENTREGAS QUE DEBEN REALIZAR LOS REPARTIDORES"<<endl;
    
    imprimir_linCaracter('=', ouput);
}

void imprimir_obtener_letra_vehiculo(ifstream &inputRepartidores, ofstream &ouput, char &vehiculo){
    inputRepartidores>>vehiculo;
    ouput<<vehiculo;
    char c;
    int cant=0, tam=TAMMAX/COLUMNAS_REPARTIDOR -2;
    while(true){
        inputRepartidores.get(c);
        if(c== ' ') break;
        if(c>='a' and c<='z') c= c- ('a' - 'A');
        ouput.put(c);
        cant++;
    }
    for (int j=0; j<=tam-cant;j++) ouput.put(' ');
}

void imprimir_distrito(ifstream &inputRepartidores, ofstream &ouput){
    inputRepartidores>>ws;
    char c;
    int cant=0, tam=TAMMAX/COLUMNAS_REPARTIDOR -2;
    while(true){
        inputRepartidores.get(c);
        if(c== '\n' or c== ']') break;
        
        ouput.put(c);
        cant++;
    }
    for (int j=0; j<=tam-cant;j++) ouput.put(' ');
    ouput<<endl;
}

void busqueda_impresion_cabecera(ifstream &inputRepartidores, ofstream &ouput, int dni, char &vehiculo, int &codDistrito){
    //tener en cuenta que ya lei dni fuera del bucle
    inputRepartidores>>ws;
    char c, letra;
    int i=0, cant=0, tam=TAMMAX/COLUMNAS_REPARTIDOR -2;
    //para imprimir nombre
    while(true){
        c=inputRepartidores.get();
        if(c==' ') break;
        if(c=='/' or c=='-') {
            c=' ';
            i=0;
        }
        if(i >0  and c>='a' and c<='z'){
            c= c - 'a'-'A';
        }
        ouput.put(c);
        cant++;
    }
    for (int j=0; j<=tam-cant;j++) ouput.put(' ');
    
    ouput<<left<<setw(tam)<<dni;
    imprimir_obtener_letra_vehiculo(inputRepartidores, ouput, vehiculo);
    inputRepartidores>>codDistrito;
    ouput<<codDistrito<<setw(4)<<"";
    imprimir_distrito(inputRepartidores, ouput);
    
    
    
}

void imprimir_cabecera_repartidor(int n, int dni,ifstream &inputRepartidores, ofstream &ouput, char &vehiculo, int &codDistrito){
    int tam=TAMMAX/COLUMNAS_REPARTIDOR -2;
    ouput<<setw(2)<<setfill('0')<<right<<n<<" REPARTIDOR:"<<setfill(' ')<<endl;
    ouput<<setw(2)<<""<<setw(tam+1)<<left<<"NOMBRE";
    ouput<<setw(tam)<<left<<"DNI";
    ouput<<setw(tam)<<left<<"VEHICULO";
    ouput<<setw(tam)<<left<<"DSITRITO A ATENDER"<<endl;
    
    //tener en cuenta que ya lei dni
    ouput<<setw(2)<<"";
    busqueda_impresion_cabecera(inputRepartidores,ouput,dni, vehiculo, codDistrito);
    imprimir_linCaracter('-', ouput);
   
}

void busqueda_impresion_precio(int cantidad, int n_platos,char vehiculo,int codPlato, ifstream &inputPlatos, ofstream &ouput, double &subtotal, double &pagorepartidor ){
    //pagorepartidor, depende del tipo de vehiculo
    inputPlatos.clear();
    inputPlatos.seekg(0, ios::beg);
    double pago, precio=0.0;
    int codigoPlato, tam=TAMMAX/COLUMNAS;
    
    if(vehiculo =='B') pago = PAGOBICI;
    if(vehiculo =='M') pago = PAGOMOTO;
    while(true){
        inputPlatos>>codigoPlato;
        if(inputPlatos.eof()) break;
        if(codPlato == codigoPlato){
            inputPlatos>>ws;
            while(inputPlatos.get() != ' ');
            inputPlatos>>precio;
            //calculo del subtotal
            subtotal = precio*cantidad;
            pagorepartidor = subtotal *pago;
            //impresion del precio
            ouput<<setw(tam)<<left<<precio<<setw(tam)<<left<<subtotal<<endl;
            return;
        }
        else{
            while(inputPlatos.get() != '\n');
        }
    }
}

void imprimir_resumen_repartidor(double totalPagoPlatos, double totalPagoRepartidor, double totalRecaudado, ofstream &ouput){
    int tam=TAMMAX*((double)1/4) +3.5;
    
    ouput<<left<<setw(tam)<<"TOTAL A PAGAR: "<<right<<setw(tam)<<totalPagoPlatos<<endl;
    ouput<<left<<setw(tam)<<"TOTAL AL REPARTIDOR: "<<right<<setw(tam)<<totalPagoRepartidor<<endl;
    imprimir_linCaracter('-', ouput);
    ouput<<left<<setw(tam)<<"TOTAL RECAUDADO: "<<right<<setw(tam)<<totalRecaudado<<endl;
    imprimir_linCaracter('=', ouput);
} 


void busqueda_clientes_de_un_repartidor(char vehiculo, int codDistrito, ifstream &inputRepartos, ifstream &inputPlatos, ofstream &ouput, double &totalPagoPlatos, double &totalPagoRepartidor){
   //debo devolver suma de total a pagar por clientes y lo que le corresponde al repartidor
    //dependiendo del vehiculo
    inputRepartos.clear();
    inputRepartos.seekg(0, ios::beg);
    int n_clientes=1, tam=TAMMAX/COLUMNAS, codigoDistrito,  cantidad =0, codPlato;
    char Vehic,c;
    double subtotal=0.0, pagorepartidor=0.0, totalRecaudado=0.0;
    while(true){
        //busqueda de un cliente
        inputRepartos>>codigoDistrito;
        if(inputRepartos.eof()) break;
        inputRepartos>>Vehic;
        if(codDistrito == codigoDistrito  and vehiculo == Vehic){
            imprimir_linCaracter('-', ouput);
            ouput<<setw(2)<<""<<"CLIENTES A ATENDER: "<<endl<<setw(2)<<right<<setfill('0')<<n_clientes<<" "<<setfill(' ');
            imprimir_distrito(inputRepartos, ouput);
            ouput<<setw(2)<<"";
            ouput<<setw(2)<<""<<"PLATOS SOLICITADOS: "<<endl;
            ouput<<setw(tam)<<left<<"CODIGO"<<setw(tam)<<"CANTIDAD"<<setw(tam)<<"PRECIO"<<setw(tam)<<"SUBTOTAL"<<endl;
            int n_platos=1;
            while(true){
                //impresion de platos
                inputRepartos>>cantidad>>codPlato;
                c =inputRepartos.get();
                if( c== '\n') break;
                //impresion cada plato de un cliente
                ouput<<setw(2)<<setfill('0')<<right<<n_platos<<" "<<setfill(' ');
                ouput<<left<<setw(tam)<<codPlato<<setw(tam-3)<<cantidad;
                busqueda_impresion_precio(cantidad,n_platos,vehiculo,codPlato, inputPlatos, ouput, subtotal, pagorepartidor );//pagorepartidor, depende del tipo de vehiculo
                totalPagoPlatos += subtotal;
                totalPagoRepartidor += pagorepartidor; 
                n_platos++;
            }  
            imprimir_linCaracter('-', ouput);
            n_clientes++;
            totalRecaudado = totalPagoPlatos + totalPagoRepartidor;
            imprimir_resumen_repartidor(totalPagoPlatos, totalPagoRepartidor, totalRecaudado, ouput); 
        }
        else{
            while(inputRepartos.get() != '\n');
        }
    }
}


void procesar_repartidores(ifstream &inputPlatos, ifstream &inputRepartidores, ifstream &inputRepartos, ofstream &ouput, double &totalPedidos, double &totalRepartidores ){
    
    char vehiculo;
    int codDistrito, dniRepartidores, n_repartidor =1;
    double totalPagoPlatos=0.0, totalPagoRepartidor=0.0;
    
    while(true){//para cada repartidor
        inputRepartidores>>dniRepartidores;
        if(inputRepartidores.eof()) break;
        imprimir_cabecera_repartidor(n_repartidor,dniRepartidores,inputRepartidores, ouput, vehiculo, codDistrito);
        busqueda_clientes_de_un_repartidor(vehiculo, codDistrito, inputRepartos, inputPlatos, ouput, totalPagoPlatos, totalPagoRepartidor);
//        totalPedidos += totalPagoPlatos;
//        totalRepartidores+= totalPagoRepartidor;
        n_repartidor++;
        }
    }
    
   


void leer_y_procesar_repartidores(const char* name_arch_platos, const char* name_arch_repartos, const char* name_arch_repartidores, const char* name_arch_reporte){
    
    ifstream inputPlatos, inputRepartos, inputRepartidores;
    ofstream ouput;
    apertura_lectura(name_arch_platos, inputPlatos);
    apertura_lectura(name_arch_repartos, inputRepartos);
    apertura_lectura(name_arch_repartidores, inputRepartidores);
    apertura_escritura(name_arch_reporte, ouput);
    
    double  totalPedidos=0.0, totalRepartidores=0.0;
    
    imprimir_titulo( ouput);
    //me lo debe devolver ya actualizado y acumulado
    ouput<<fixed<<setprecision(2);
    procesar_repartidores(inputPlatos, inputRepartidores, inputRepartos, ouput, totalPedidos, totalRepartidores );
    
//    imprimir_reporte(totalPedidos,totalRepartidores);
    
}