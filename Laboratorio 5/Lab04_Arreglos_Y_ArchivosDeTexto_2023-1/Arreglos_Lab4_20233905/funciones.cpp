/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 7 de mayo de 2025, 18:38
 */

#include "funciones.hpp"

void apertura_lectura(const char* name, ifstream &input){
    input.open(name, ios::in);
    if(not input.is_open()){
        cout<<"ERROR: El archivo "<<name<<" no abre"<<endl;
    }
}

void apertura_escritura(const char* name, ofstream &ouput){
    ouput.open(name, ios::out);
    if(not ouput.is_open()){
        cout<<"ERROR: El archivo "<<name<<" no abre"<<endl;
    }
    else{
        cout<<"el reporte  se abrio"<<endl;
    }
}

void ignorar(ifstream &input, char c){
    input>>ws;
    while(input.get() != c);
}

void imprimir_linCar(ofstream &ouput, char c){
    ouput<<setw(TAMREPORTE)<<setfill(c)<<""<<setfill(' ')<<endl;
}

void cargarArreglosLibros(int *arrCodLibros,double *arrPrecioLibros,int &cantLibros){
    ifstream inputLibros;
    apertura_lectura("Libros.txt", inputLibros);
    
    int codLibro;
    double precioLibro;
    while(true){
        inputLibros>>codLibro;
        if(inputLibros.eof()) break;
        ignorar(inputLibros, ' '); //ws incluido;
        inputLibros>>precioLibro;
        arrCodLibros[cantLibros]=codLibro;
        arrPrecioLibros[cantLibros]=precioLibro;
        cantLibros++;
    }
}

void cargarArreglosAutores(int *arrCodAutores,int *arregloCodigoLibrosPorAutores,double *arrRegaliasAutores,int &cantAutores){
    ifstream inputAutores;
    apertura_lectura("Autores.txt", inputAutores);
    
    int codAutor, codLibroPorAutor;
    double regalias;
    while(true){
        inputAutores>>codAutor;
        if(inputAutores.eof()) break;
        inputAutores>>codLibroPorAutor;
        inputAutores>>regalias;
        arrCodAutores[cantAutores]=codAutor;
        arregloCodigoLibrosPorAutores[cantAutores]=codLibroPorAutor;
        arrRegaliasAutores[cantAutores]=regalias;
        cantAutores++;
    }
}

int busquedaDeCantidadLibrosVendidos(int arrCodUnLibro,ifstream &inputVentas){
    int num, codigoLibro, cantidad=0;
    char c;
    
    inputVentas.clear();
    inputVentas.seekg(0, ios::beg);
    
    while(true){
        inputVentas>>num;
        if(inputVentas.eof()) break;
        inputVentas>>c>>num>>c>>num; //no importa la fecha
        
        inputVentas>>codigoLibro;
        if(codigoLibro == arrCodUnLibro){
            inputVentas>>cantidad;
            return cantidad;
        }
        else{
            ignorar(inputVentas, '\n');
        }
    }
}

void procesarImprimirAutoresDeUnLibro(int arrPrecioUnLibro,int arrCodUnLibro,int *arrCodAutores,int *arregloCodigoLibrosPorAutores,double *arrRegaliasAutores,int cantAutores, ofstream &ouput,
                                      double &mayorMontoPorAutor, double &menorMontoPorAutor, int& codiAutorMayorPagaPorLibro, int &codiAutorMenorPagaPorLibro,bool &encontrado ){
    int tam= TAMREPORTE/(COLUMNAS);
   encontrado = false;
    double montoPorAutor=0.0;
    mayorMontoPorAutor=0.0, menorMontoPorAutor=1e9;
    ouput<<""<<endl<<setw(4)<<""<<"REGALIAS DE LOS AUTORES"<<endl;
    ouput<<setw(4)<<"";
    ouput<<setw(tam)<<left<<"AUTOR"<<setw(tam)<<left<<"PORCENTAJE A RECIBIR"<<setw(tam)<<left<<"MONTO A RECIBIR"<<endl;
    for(int n_autores=0; n_autores<cantAutores;n_autores++){
        if(arrCodUnLibro == arregloCodigoLibrosPorAutores[n_autores]){
            encontrado = true;
            montoPorAutor = arrPrecioUnLibro * arrRegaliasAutores[n_autores];
            ouput<<setw(4)<<"";
            ouput<<setw(tam)<<left<<arrCodAutores[n_autores]<<setw(5)<<setfill('0')<<right<<arrRegaliasAutores[n_autores]<<setfill(' ')<<setw(tam-5)<<left<<"%"<<
                 setw(tam)<<left<<montoPorAutor <<endl;
            //determinar cual es mayor y menor
            if(montoPorAutor>mayorMontoPorAutor){
                codiAutorMayorPagaPorLibro = arrCodAutores[n_autores];
                mayorMontoPorAutor = montoPorAutor;
            }
            if(montoPorAutor<menorMontoPorAutor){
                codiAutorMenorPagaPorLibro = arrCodAutores[n_autores];
                menorMontoPorAutor = montoPorAutor;
            }
        }
    }
    if(not encontrado)ouput<<setw(4)<<""<<"NO SE ENCONTRO AUTORES PARA ESTE LIBRO"<<endl;
    imprimir_linCar(ouput, '_');
}

void impresionResumenPorLibro(ofstream &ouput, double mayorMontoAutorPorLibro, double menorMontoAutorPorLibro, int codiAutorMayorPagaPorLibro,int codiAutorMenorPagaPorLibro){
   int tam=TAMREPORTE/(COLUMNAS+2);
    ouput<<setw(4)<<""<<setw(tam)<<left<<"AUTOR CON MAYOR PAGO :"<<endl;
    ouput<<setw(4)<<""<<setw(tam)<<left<<"CODIGO:"<<setw(tam)<<left<<codiAutorMayorPagaPorLibro<<endl;
    ouput<<setw(4)<<""<<setw(tam)<<left<<"SUELDO:"<<setw(tam)<<left<<mayorMontoAutorPorLibro<<endl;
    ouput<<""<<endl;
    ouput<<setw(4)<<""<<setw(tam)<<left<<"AUTOR CON MENOR PAGO :"<<endl;
    ouput<<setw(4)<<""<<setw(tam)<<left<<"CODIGO:"<<setw(tam)<<left<<codiAutorMenorPagaPorLibro<<endl;
    ouput<<setw(4)<<""<<setw(tam)<<left<<"SUELDO:"<<setw(tam)<<left<<menorMontoAutorPorLibro<<endl;
    ouput<<""<<endl;
}

void actualizarDatosParaResumenTotal(int arrCodLibros,double mayorMontoAutorPorLibro, double menorMontoAutorPorLibro, int codiAutorMayorPagaPorLibro, int codiAutorMenorPagaPorLibro,double montoPorLibro,
                                        double &pagoMejorAuto,int &codAutorMejorPagado,double &pagoPeorAuto,int &codAutorPeorPagado,int &codLibroMasRecuado,double &pagoMejorLibro,int &codlibroPeorPagado,double &pagoPeorLibro){
        if(mayorMontoAutorPorLibro>pagoMejorAuto){ 
            pagoMejorAuto = mayorMontoAutorPorLibro;
            codAutorMejorPagado = codiAutorMayorPagaPorLibro;
        }
        if(menorMontoAutorPorLibro<pagoPeorAuto){
            pagoPeorAuto = menorMontoAutorPorLibro;
            codAutorPeorPagado = codiAutorMenorPagaPorLibro;
        }
        if(montoPorLibro>pagoMejorLibro){ 
            codLibroMasRecuado = arrCodLibros;
            pagoMejorLibro = montoPorLibro;
        }
        if(montoPorLibro<pagoPeorLibro){
            codlibroPeorPagado = arrCodLibros;
            pagoPeorLibro = montoPorLibro;
        }
}

void imprimir_resumen_total(ofstream &ouput,double pagoMejorAuto,int codAutorMejorPagado,double pagoPeorAuto,int codAutorPeorPagado,int codLibroMasRecuado,double pagoMejorLibro,int codlibroPeorPagado,double pagoPeorLibro){
    int tam=TAMREPORTE/(COLUMNAS+2);
    ouput<<setw(tam)<<left<<"LIBRO QUE MAS VENDIO"<<endl;
    ouput<<setw(tam)<<left<<"CODIGO:"<<setw(tam)<<left<<codLibroMasRecuado<<endl;
    ouput<<setw(tam)<<left<<"PAGO RECAUDADO:"<<setw(tam)<<left<<pagoMejorLibro<<endl;
    ouput<<""<<endl;
    ouput<<setw(tam)<<left<<"LIBRO QUE MENOS VENDIO"<<endl;
    ouput<<setw(tam)<<left<<"CODIGO:"<<setw(tam)<<left<<codlibroPeorPagado<<endl;
    ouput<<setw(tam)<<left<<"PAGO RECAUDADO:"<<setw(tam)<<left<<pagoPeorLibro<<endl;
    ouput<<""<<endl;
    ouput<<setw(tam)<<left<<"AUTOR CON MAYOR SUELDO"<<endl;
    ouput<<setw(tam)<<left<<"CODIGO:"<<setw(tam)<<left<<codAutorMejorPagado<<endl;
    ouput<<setw(tam)<<left<<"SUELDO:"<<setw(tam)<<left<<pagoMejorAuto<<endl;
    ouput<<""<<endl;
    ouput<<setw(tam)<<left<<"AUTOR CON MENOR SUELDO"<<endl;
    ouput<<setw(tam)<<left<<"CODIGO:"<<setw(tam)<<left<<codAutorPeorPagado<<endl;
    ouput<<setw(tam)<<left<<"SUELDO:"<<setw(tam)<<left<<pagoPeorAuto<<endl;
    
}

void procesar_Libros(ifstream &inputVentas,ofstream &ouput,int *arrCodLibros,double *arrPrecioLibros,int cantLibros,
                    int *arrCodAutores,int *arregloCodigoLibrosPorAutores,double *arrRegaliasAutores,int cantAutores,
                    int &codAutorMejorPagado,int &codAutorPeorPagado,int &codLibroMasRecuado,int &codlibroPeorPagado,
                    double &pagoMejorAuto,double &pagoPeorAuto,double &pagoMejorLibro,double &pagoPeorLibro){
    bool encontrado ;
    int n_libro=1, tam = TAMREPORTE /COLUMNAS, cantidad,codiAutorMayorPagaPorLibro, codiAutorMenorPagaPorLibro;
    double montoPorLibro=0.0, mayorMontoAutorPorLibro=0.0, menorMontoAutorPorLibro=1e9;
    
    for(int n_libro=0; n_libro<cantLibros; n_libro++){
        
        cantidad = busquedaDeCantidadLibrosVendidos(arrCodLibros[n_libro],inputVentas);
        montoPorLibro = cantidad * arrPrecioLibros[n_libro];
        
        ouput<<setw(2)<<setfill('0')<<right<<n_libro+1<<") "<<setfill(' ');
        ouput<<setw(tam)<<left<<"LIBRO"<<setw(tam)<<left<<"CANTIDAD"<<setw(tam)<<left<<"PRECIO"<<setw(tam)<<left<<"MONTO RECAUDADO"<<endl;
        ouput<<setw(4)<<"";
        ouput<<setw(tam)<<left<<arrCodLibros[n_libro]<<setw(tam)<<left<<cantidad<<
              setw(tam)<<left<<arrPrecioLibros[n_libro]<<setw(tam)<<left<<montoPorLibro<<endl;
        //busqueda de autores y sus pagos
        procesarImprimirAutoresDeUnLibro(arrPrecioLibros[n_libro],arrCodLibros[n_libro],arrCodAutores,arregloCodigoLibrosPorAutores,arrRegaliasAutores,cantAutores, ouput, 
                                        mayorMontoAutorPorLibro, menorMontoAutorPorLibro, codiAutorMayorPagaPorLibro, codiAutorMenorPagaPorLibro,encontrado);
        if(encontrado){
            impresionResumenPorLibro(ouput, mayorMontoAutorPorLibro, menorMontoAutorPorLibro, codiAutorMayorPagaPorLibro, codiAutorMenorPagaPorLibro);
            imprimir_linCar(ouput, '=');  
            
        }   
        actualizarDatosParaResumenTotal(arrCodLibros[n_libro],mayorMontoAutorPorLibro, menorMontoAutorPorLibro, codiAutorMayorPagaPorLibro, codiAutorMenorPagaPorLibro,montoPorLibro,
                                            pagoMejorAuto,codAutorMejorPagado,pagoPeorAuto,codAutorPeorPagado,codLibroMasRecuado,pagoMejorLibro,codlibroPeorPagado,pagoPeorLibro);
    }
    imprimir_linCar(ouput, '=');
    imprimir_resumen_total(ouput,pagoMejorAuto,codAutorMejorPagado,pagoPeorAuto,codAutorPeorPagado,codLibroMasRecuado,pagoMejorLibro,codlibroPeorPagado,pagoPeorLibro);
}


void procesar_imprimir_reporte(int *arrCodLibros,double *arrPrecioLibros,int cantLibros,int *arrCodAutores,int *arregloCodigoLibrosPorAutores,double *arrRegaliasAutores,int cantAutores){
    ifstream inputVentas;
    ofstream ouput;
    apertura_lectura("Ventas.txt", inputVentas);
    apertura_escritura("reporte.txt", ouput);
    
    int codAutorMejorPagado =0, codAutorPeorPagado =0, codLibroMasRecuado =0, codlibroPeorPagado=0;
    double pagoMejorAuto=0.0,pagoPeorAuto=1e9,pagoMejorLibro=0.0, pagoPeorLibro=1e9;
    ouput<<fixed<<setprecision(2);
//    imprimir_titulo(ouput);
    imprimir_linCar(ouput, '=');
    procesar_Libros(inputVentas,ouput,arrCodLibros,arrPrecioLibros,cantLibros,
                    arrCodAutores,arregloCodigoLibrosPorAutores,arrRegaliasAutores,cantAutores,
                    codAutorMejorPagado,codAutorPeorPagado,codLibroMasRecuado,codlibroPeorPagado,
                    pagoMejorAuto,pagoPeorAuto,pagoMejorLibro,pagoPeorLibro);
//    imprimir_resumen(codAutorMejorPagado,codAutorPeorPagado,codLibroMasRecuado,codlibroPeorPagado,
//                    pagoMejorAuto,pagoPeorAuto,pagoMejorLibro,pagoPeorLibro);
}

