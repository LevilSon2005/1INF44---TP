/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 11 de mayo de 2025, 10:23
 */

#include "funciones.hpp"

void apertura_lectura(const char* name,ifstream &input){
    input.open(name, ios::in);
    
    if(not input.is_open()){
        cout <<"ERROR: El archivo "<<name<<" no se abrio"<<endl;
    }
}

void apertura_escritura(const char* name,ofstream &ouput){
    ouput.open(name, ios::out);
    
    if(not ouput.is_open()){
        cout <<"ERROR: El archivo "<<name<<" no se abrio"<<endl;
    }
    else{
        cout<<"el reporte se abrio"<<endl;
    }
}

void imprimir_linCar(ofstream &ouput, char c){
    ouput<<setw(TAMREPORTE)<<setfill(c)<<""<<setfill(' ')<<endl;
}

void imprimir_pruebaStock(int *arrCodProducto_Stock,int *arrCodAlmacen_Stock,int *arrStockInicial_Stock,int cantProductos){
    ofstream ouput;
    apertura_escritura("prueba.txt", ouput);
    int tam = TAMREPORTE/3;
    ouput<<setw((TAMREPORTE+TITULOPRUEBA)/2)<<"REPORTE DE PRUEBA DEL ARCHIVO STOCKPRODUCTOS"<<endl;
    imprimir_linCar(ouput, '=');
    for(int i=0; i<cantProductos;i++){
       ouput<<setw(tam)<<left<<arrCodProducto_Stock[i]<<setw(tam)<<left<<arrCodAlmacen_Stock[i]
            <<setw(tam)<<left<<arrStockInicial_Stock[i]<<endl;
    }
    
}

bool validacionFecha(int fechaInicio, int fechaFinal){
   
    return (fechaInicio<fechaFinal);
}

void cargarArreglosStock(int *arrCodProducto_Stock,int *arrCodAlmacen_Stock,int *arrStockInicial_Stock,int &cantProductos){
    ifstream inputStock;
    int codProducto;
    
    apertura_lectura("StockProductos.txt",inputStock);
    
    while(true){
        inputStock>>codProducto;
        if(inputStock.eof()) break;
        arrCodProducto_Stock[cantProductos] = codProducto;
        inputStock>>arrCodAlmacen_Stock[cantProductos]>>arrStockInicial_Stock[cantProductos];
        cantProductos++;
    }
}

int leerFecha(ifstream &input){
    int d,m,a;
    char c;
    input>>d>>c>>m>>c>>a;
    return (a*10000 + m*100+d);
}

bool cumpleRangoFecha(int fecha, int fechaInicio, int fechaFinal){
    return (fecha>fechaInicio and fecha<fechaFinal);
}

void ignorar(ifstream &input, char delimitador){
    while(input.get() != delimitador);
}

int obtenerPosicion(int cantProductos,int codAlmacen_Trans,int codProducto_Trans,int *arrCodProducto_Stock,int *arrCodAlmacen_Stock){
    
    for(int i=0;i<cantProductos;i++){
        if(codAlmacen_Trans == arrCodAlmacen_Stock[i] and codProducto_Trans == arrCodProducto_Stock[i]){
            return i;
        }
    }
    return NO_ENCONTRADO;
}

void cargarArregloTransacciones(bool*arrProdcutoEncontrado,ifstream &inputTransacciones,int codAlmacen_Trans,char tipoTrans,int cantdProducto_Trans,int codAlmacenDestino_Trans,int codProducto_Trans,int *arrStockInicial_Stock,int cantProductos,
                                int *arrCodProducto_Stock,int *arrCodAlmacen_Stock,
                                int *arrIngresos_Trans,int *arrSalidas_Trans,int *arrEnvios_Trans,int *arrRecibidos_Trans,int *arrStockFinal_Trans){
    int pos=0, pos2=0;
    pos =obtenerPosicion(cantProductos,codAlmacen_Trans,codProducto_Trans,arrCodProducto_Stock,arrCodAlmacen_Stock);
    if(tipoTrans ==  'I') arrIngresos_Trans[pos] += cantdProducto_Trans;
    if(tipoTrans ==  'S') arrSalidas_Trans[pos] += cantdProducto_Trans;
    if(tipoTrans ==  'T') {
        pos2=obtenerPosicion(cantProductos,codAlmacenDestino_Trans,codProducto_Trans,arrCodProducto_Stock,arrCodAlmacen_Stock);
        arrEnvios_Trans[pos] += cantdProducto_Trans;
        arrRecibidos_Trans[pos2] -= cantdProducto_Trans;
    }
    if(pos<0 ){
        arrProdcutoEncontrado[pos] = false;
        return;
    }
    if(pos2<0 ){
        arrProdcutoEncontrado[pos2] = false;
        return;
    }
    arrProdcutoEncontrado[pos] = true;
    arrStockFinal_Trans[pos] = arrStockInicial_Stock[pos] + arrIngresos_Trans[pos] - arrSalidas_Trans[pos]  -arrEnvios_Trans[pos]  +arrRecibidos_Trans[pos] ;
}

void LeerTransacciones(bool*arrProdcutoEncontrado,int* arrStockInicial_Stock,int* arrIngresos_Trans,int* arrSalidas_Trans,
                        int* arrEnvios_Trans,int* arrRecibidos_Trans,int* arrStockFinal_Trans,
                        int fechaInicio, int fechaFinal,int *arrCodProducto_Stock,int *arrCodAlmacen_Stock,int cantProductos){
    ifstream inputTransacciones;
    apertura_lectura("Transacciones.txt", inputTransacciones);
    
    int fecha,codAlmacen_Trans,codProducto_Trans, cantdProducto_Trans,codAlmacenDestino_Trans;
    char tipoTrans,c;
    while(true){
        inputTransacciones>>codAlmacen_Trans;
        if(inputTransacciones.eof()) break;
        fecha = leerFecha(inputTransacciones);
        if(cumpleRangoFecha(fecha,fechaInicio,fechaFinal)){
            while(true){
                inputTransacciones>>ws;
                ignorar(inputTransacciones, ' ');
                inputTransacciones>>codProducto_Trans>>cantdProducto_Trans>>tipoTrans;
                if(tipoTrans =='T') inputTransacciones>>codAlmacenDestino_Trans;
                c = inputTransacciones.get();
                if(c=='\n') break;
                cargarArregloTransacciones(arrProdcutoEncontrado,inputTransacciones,codAlmacen_Trans,tipoTrans,cantdProducto_Trans,codAlmacenDestino_Trans,codProducto_Trans,arrStockInicial_Stock,cantProductos,
                                            arrCodProducto_Stock,arrCodAlmacen_Stock,
                                            arrIngresos_Trans,arrSalidas_Trans,arrEnvios_Trans,arrRecibidos_Trans,arrStockFinal_Trans);
            }
        }
        else{
            ignorar(inputTransacciones, '\n');
        }
    }
}

void imprimir_titulo(ofstream &ouput,int dd_i, int mm_i,int aa_i,int dd_f, int mm_f,int aa_f){
    ouput<<setw((TAMREPORTE+TITULO1)/2)<<"CONSOLIDADO DE SOTCKS DE PRODUCTOS POR ALMACEN"<<endl;
    ouput<<setw((TAMREPORTE-TITULO2)/2)<<""<<"DEL "<<setfill('0')<<setw(2)<<right<<dd_i<<"/"<<setw(2)<<right<<mm_i<<"/"<<aa_i<<" AL "<<setw(2)<<right<<dd_f<<"/"<<setw(2)<<right<<mm_f<<"/"<<aa_f<<setfill(' ')<<endl;
    imprimir_linCar(ouput, '=');
}

void imprimir_nombreAlmacen(ifstream &inputAlmacen,ofstream &ouput){
    inputAlmacen>>ws;
    char c;
     inputAlmacen.ignore(7);
    
    while(true){
        c = inputAlmacen.get();
        if(c>='0' and c<='9') break;
        if((c>='a' and c<='z') or (c>='A' and c<='Z')){
            ouput.put(c);
        }
        else{
            c = ' ';
            ouput.put(c);
        }
       
    }
}

void imprimir_headers(ofstream &ouput){
    int tam= TAMREPORTE/COLUMNAS;
    
    imprimir_linCar(ouput, '-');
    ouput<<setw(tam)<<left<<"PRODUCTO"
            <<setw(tam)<<left<<"STOCK INICIAL"
            <<setw(tam)<<left<<"INGRESOS"
            <<setw(tam)<<left<<"SALIDAS"
            <<setw(tam)<<left<<"ENVIADO A ALM."
            <<setw(tam)<<left<<"RECIBIDO DE ALM."
            <<setw(tam)<<left<<"STOCK FINAL"
            <<setw(tam)<<left<<"OBSERVACIONES"<<endl;
    imprimir_linCar(ouput, '-');
}

void intercambiarI(int &a, int &b){
    int aux;
    aux = a;
    a=b;
    b=aux;
}

void ordenarArreglos(int cantProductos,int* arrCodProducto_Stock,int* arrCodAlmacen_Stock,int* arrStockInicial_Stock,
                    int* arrIngresos_Trans,int* arrSalidas_Trans,int* arrEnvios_Trans,int* arrRecibidos_Trans,int* arrStockFinal_Trans){
    
    for(int i=0;i<cantProductos-1;i++){
        for(int k=i+1;k<cantProductos;k++){
            if((arrCodAlmacen_Stock[k]>arrCodAlmacen_Stock[i] or arrCodAlmacen_Stock[k]==arrCodAlmacen_Stock[i] ) and (arrCodProducto_Stock[i]>arrCodProducto_Stock[k])){
                intercambiarI(arrCodAlmacen_Stock[k], arrCodAlmacen_Stock[i]);
                intercambiarI(arrCodProducto_Stock[k], arrCodProducto_Stock[i]);
                intercambiarI(arrStockInicial_Stock[k], arrStockInicial_Stock[i]);
                intercambiarI(arrIngresos_Trans[k], arrIngresos_Trans[i]);
                intercambiarI(arrSalidas_Trans[k], arrSalidas_Trans[i]);
                intercambiarI(arrEnvios_Trans[k], arrEnvios_Trans[i]);
                intercambiarI(arrRecibidos_Trans[k], arrRecibidos_Trans[i]);
                intercambiarI(arrStockFinal_Trans[k], arrStockFinal_Trans[i]);
            }
        }
    }
}

void imprimirReporte(bool*arrProdcutoEncontrado,int dd_i, int mm_i,int aa_i,int dd_f, int mm_f,int aa_f,int cantProductos,
                    int* arrCodProducto_Stock,int* arrCodAlmacen_Stock,int* arrStockInicial_Stock,
                    int* arrIngresos_Trans,int* arrSalidas_Trans,int* arrEnvios_Trans,int* arrRecibidos_Trans,int* arrStockFinal_Trans){
    ofstream ouput;
    ifstream inputAlmacen;
    apertura_escritura("reporte.txt", ouput);
    apertura_lectura("Almacen.txt",inputAlmacen);
    imprimir_titulo(ouput,dd_i, mm_i,aa_i,dd_f, mm_f,aa_f);
    int codAlmacen, tam=TAMREPORTE/COLUMNAS;
    
    while(true){ // para cada almacen
        inputAlmacen>>codAlmacen;
        if(inputAlmacen.eof()) break;
        ouput<<"ALMACEN: "<<codAlmacen<<" - ";
        imprimir_nombreAlmacen(inputAlmacen, ouput);
        ignorar(inputAlmacen, '\n'); // para el código postal
        ouput<<endl;
        imprimir_headers(ouput);

        for(int i=0; i<cantProductos;i++){
            if(codAlmacen == arrCodAlmacen_Stock[i] and arrProdcutoEncontrado[i]){
                ouput<<setw(tam)<<left<<arrCodProducto_Stock[i]
                        <<setw(tam)<<left<<arrStockInicial_Stock[i]
                        <<setw(tam)<<left<<arrIngresos_Trans[i]
                        <<setw(tam)<<left<<arrSalidas_Trans[i]
                        <<setw(tam)<<left<<arrEnvios_Trans[i]
                        <<setw(tam)<<left<<arrRecibidos_Trans[i]
                        <<setw(tam)<<left<<arrStockFinal_Trans[i];
                if(arrStockFinal_Trans[i]<0) ouput<<setw(tam)<<left<<"Trans. Incorrecta";
                ouput<<endl;
            }
            
        }
//      
        imprimir_linCar(ouput, '=');
    }   
}

