/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 17 de mayo de 2025, 14:45
 */

#include "funciones.hpp"

apertura_lectura(const char* name, ifstream & input){
    input.open(name, ios::in);
    if(not input.is_open()){
        cout<<"ERROR: El archivo "<<name<<" no se abre"<<endl;
    }
}
apertura_escritura(const char* name, ofstream & ouput){
    ouput.open(name, ios::out);
    if(not ouput.is_open()){
        cout<<"ERROR: El archivo "<<name<<" no se abre"<<endl;
    }
    else
        cout<<"El archivo se abrio"<<endl;
}

void ignorar(ifstream &input, char delimitador){
    while(input.get() != delimitador);
}

void ignorar_nombre_articulo(ifstream &inputArticulos){
    inputArticulos>>ws;
    ignorar(inputArticulos, '}');
    
}

void cargarArregloArticulo(char *letras1,char *letras2,char *letras3,int *numsArt,double *precios,double *descs,int &cantArt){
    char c1,c;
    ifstream inputArticulos;
    apertura_lectura("articulos.txt", inputArticulos);
    
    while(true){
        inputArticulos>>c1;
        if(inputArticulos.eof()) break;
        letras1[cantArt]=c1;
        inputArticulos>>letras2[cantArt]>>letras3[cantArt]>>c>>numsArt[cantArt];
        ignorar_nombre_articulo(inputArticulos);
        inputArticulos>>precios[cantArt];
        c = inputArticulos.get();
        if(c != '\n') inputArticulos>>descs[cantArt]>>c;        
        cantArt++;
    }
    
}

void imprimir_lin(ofstream &ouput, char c){
    
    ouput<<setw(TAMREPORTE)<<setfill(c)<<""<<setfill(' ')<<endl;
}

void  imprimir_prueba_articulo(char *letras1,char *letras2,char *letras3,int *numsArt,double *precios,double *descs,int cantArt){
    
    ofstream ouput;
    apertura_escritura("prueba.txt", ouput);
    
    int tam = TAMREPORTE/COLUMNAS;
    ouput<<fixed<<setprecision(2);
    ouput<<setw((TAMREPORTE+30)/2-65)<<"REPORTE DE PRUEBA DE ARTICULOS"<<endl;
    imprimir_lin(ouput, '=');
    ouput<<setw(5)<<"";
            
    ouput<<setw(tam)<<left<<"CODIGOS"<<setw(tam)<<left<<"PRECIOS"<<setw(tam)<<left<<"DESCUENTOS"<<endl;
    for (int i=0; i<cantArt;i++){
        ouput<<setw(5)<<"";
        ouput<<letras1[i]<<letras2[i]<<letras3[i]<<"-"<<setw(3)<<right<<numsArt[i]<<setw(tam-7)<<""
                <<setw(tam)<<left<<precios[i]
                <<setw(tam)<<left<<descs[i]<<endl;
    }
    imprimir_lin(ouput, '=');
}

int transformarFecha(int dd,int mm,int aa){
    return aa*10000+mm*100+dd;
}

int buscarPosicion(int codVend,int *arrCodVend, int cantVendedores){
    
    for(int i=0;i<cantVendedores;i++){
        if(codVend == arrCodVend[i]) return i;
    }
    
    return NO_ENCONTRADO;
}

int buscarPosicionArt(char c1,char c2,char c3,int numArt, char *letras1,char *letras2,char *letras3,int *numsArt,int cantArt){
    
    for(int i=0;i<cantArt;i++){
        if(c1 == letras1[i] and c2 == letras2[i] and c3 == letras3[i]  and numArt == numsArt[i]) return i;
    }
    
    return NO_ENCONTRADO;
}

void  procesar_ventas(char *letras1,char *letras2,char *letras3,int *numsArt,double *precios,double *descs,int cantArt,
                    int *arrCodVend,int *arrCantArt,int *arrFechaVentAntig,int *arrFechaVentRec,double *arrIngresosTotalVent,int &cantVendedores,
                    int &TotalCantVendido,double &TotalIngresosVentas){
    char c1,c2,c3,c;// c1 , c2 y c3 son las letras que forman parte del codigo del articulo
    int numArt, codVend, cantArtVendido,dd,mm,aa, fecha;
    int posVendedor=0,posArticulo=0;
    double ingresoVent=0.0, desc=0.0,ingresoVenta=0.0;
    ifstream inputVentas;
    apertura_lectura("ventas.txt", inputVentas);
    
    //JCW-489    13245501     5    2/09/2023       KSO-608     40112594    6  25/11/2023
    while(true){//para cada vendedor
        inputVentas>>c1;
        if(inputVentas.eof()) break;
        inputVentas>>c2>>c3>>c>>numArt>>codVend>>cantArtVendido>>dd>>c>>mm>>c>>aa;
        fecha = transformarFecha(dd,mm,aa);
        posVendedor= buscarPosicion(codVend,arrCodVend, cantVendedores);
        if(posVendedor == NO_ENCONTRADO){//No estaba en el arreglo , PRIMERA VEZ 
            arrCodVend[cantVendedores] = codVend;
            arrFechaVentAntig[cantVendedores] = fecha;
            arrFechaVentRec[cantVendedores] = fecha;
            cantVendedores++;
        }
        else{//ya estaba en el arreglo
            if(fecha<arrFechaVentAntig[posVendedor]) arrFechaVentAntig[posVendedor] =fecha;
            if(fecha>arrFechaVentRec[posVendedor]) arrFechaVentRec[posVendedor] =fecha; 
        }
        arrCantArt[posVendedor]+=cantArtVendido;
        posArticulo = buscarPosicionArt(c1,c2,c3,numArt, letras1,letras2,letras3,numsArt,cantArt);
        if(posArticulo != NO_ENCONTRADO){
            desc = descs[posArticulo]/100;
            ingresoVenta = precios[posArticulo] * cantArtVendido * (1-desc);
            arrIngresosTotalVent[posVendedor] += ingresoVenta;
        }
        TotalIngresosVentas +=ingresoVenta;
        TotalCantVendido += cantArtVendido;
    }
} 

void imprimir_fecha(int fecha, ofstream &ouput){
    int tam = TAMREPORTE/COLUMNAS;
    int d,m,a;
    a = fecha/10000;
    m = (fecha/100)%100;
    d = fecha%100;
    
    ouput<<setfill('0')<<setw(2)<<right<<d<<"/"<<setw(2)<<right<<m<<"/"<<a<<setfill(' ');
    
    for(int i=0;i<(tam-10);i++) ouput.put(' ');
            
}

void imprimir_reporte(int *arrCodVend,int *arrCantArt,int *arrFechaVentAntig,int *arrFechaVentRec,double *arrIngresosTotalVent,int &cantVendedores,
                        int &TotalCantVendido,double &TotalIngresosVentas){
    
    ofstream ouput;
    apertura_escritura("reporte.txt",ouput);
    int tam = TAMREPORTE/COLUMNAS;
    ouput<<"REPORTE DE VENTAS"<<endl;
    imprimir_lin(ouput, '=');
    ouput<<fixed<<setprecision(2);
    ouput<<setw(tam)<<left<<"CODIGO"<<setw(tam)<<left<<"CANT. ART. VENDIDOS"<<setw(tam)<<left<<"VENTA MAS ANTIGUA"<<setw(tam)<<left<<"VENTA MAS RECIENTE"<<setw(tam)<<left<<"TOTAL DE VENTAS"<<endl;
    
    for(int i=0;i<cantVendedores;i++){
        ouput<<setw(tam)<<left<<arrCodVend[i]<<setw(tam)<<left<<arrCantArt[i];
//        <<setw(tam)<<left<<arrFechaVentAntig[i]<<setw(tam)<<left<<arrFechaVentRec[i]
        imprimir_fecha(arrFechaVentAntig[i], ouput);
        imprimir_fecha(arrFechaVentRec[i], ouput);
        ouput<<setw(tam)<<left<<arrIngresosTotalVent[i]<<endl;
    }
    imprimir_lin(ouput, '=');
    ouput<<setw(tam)<<left<<"TOTALES"<<setw(tam)<<left<<TotalCantVendido<<setw(tam)<<left<<""<<setw(tam)<<left<<""<<setw(tam)<<left<<TotalIngresosVentas<<endl;
    imprimir_lin(ouput, '=');
}
