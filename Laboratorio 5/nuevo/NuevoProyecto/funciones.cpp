/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 12 de mayo de 2025, 11:10
 */

#include "funciones.hpp"
void  apetura_lectura(const char * name,ifstream &input){
    input.open(name, ios::in);
    if(not input.is_open()){
        cout<<"ERROR: El archivo "<<name <<" no se abrio"<<endl;
    }
}

void  apetura_esccritura(const char * name,ofstream &ouput){
    ouput.open(name, ios::out);
    if(not ouput.is_open()){
        cout<<"ERROR: El archivo "<<name <<" no se abrio"<<endl;
    }
    else{
        cout<<"El reporte se abrio"<<endl;
    }
}

void imprimir_lin(ofstream &ouput, char c){
    ouput<<setw(TAMREPOTE1)<<setfill(c)<<""<<setfill(' ')<<endl;
}

void ignorar(ifstream &input,char delimitador){
    while(input.get() != delimitador);
}


void ignorarNombreCliente(ifstream &input){
    input>>ws;
    ignorar(input,']');
}

void  cargarArreglosRepartidores(int *arrDNIRepartidores,char *arrTipoVehiculo,int *arrCodDistrito, int &cantRepartidores){
    int dniRepatidor, codDistrito;
    char tipoVeh;
    ifstream inputRepartidores;
    apetura_lectura("Repartidores.txt", inputRepartidores);
    while(true){
        inputRepartidores>>dniRepatidor;
        if(inputRepartidores.eof()) break;
        arrDNIRepartidores[cantRepartidores] = dniRepatidor;
        inputRepartidores>>arrTipoVehiculo[cantRepartidores];
        ignorar(inputRepartidores, ' ');
        inputRepartidores>>arrCodDistrito[cantRepartidores];
        ignorar(inputRepartidores, '\n');
        cantRepartidores++;
    }
}

void cargarArreglosPlatos(int *arrCodPlatos,double *arrPrecioPlatos,double *arrDescuentosPlatos,int &cantPlatos){
    ifstream inputPlatos;
    apetura_lectura("PlatosOfrecidos.txt", inputPlatos);
    
    int codPlato;
    double precioPlato, descPlato;
    char c;
    while(true){
        inputPlatos>>codPlato;
        if(inputPlatos.eof()) break;
        arrCodPlatos[cantPlatos] = codPlato;
        inputPlatos>>arrPrecioPlatos[cantPlatos];
        c = inputPlatos.get();
        if(c != '\n') inputPlatos>>arrDescuentosPlatos[cantPlatos];
        c = inputPlatos.get();
        cantPlatos++;
    }
}

void imprimirPruebaArreglos(int *arrDNIRepartidores,char *arrTipoVehiculo,int *arrCodDistrito, int cantRepartidores,
                            int *arrCodPlatos,double *arrPrecioPlatos,double *arrDescuentosPlatos,int cantPlatos){
    ofstream ouput;
    apetura_esccritura("prueba.txt",ouput);
    int tam= TAMREPOTE1/3;
    
   ouput<<setw((TAMREPOTE1+TITULOPRUEBA1)/2)<<"ARCHIVO DE PRUEBAS DE REPORATIDORES"<<endl;
    imprimir_lin(ouput, '=');
    ouput<<setw(15)<<"";
    ouput<<setw(tam)<<left<<"DNI"<<setw(tam)<<left<<"TIPO DE VEHICULO"<<setw(tam)<<left<<"CODIGO DEL DISTRITO"<<endl;
    imprimir_lin(ouput, '-');
    for(int i=0;i<cantRepartidores;i++){
        ouput<<setw(15)<<"";
        ouput<<setw(tam)<<left<<arrDNIRepartidores[i]<<setw(tam)<<left<<arrTipoVehiculo[i]<<setw(tam)<<left<<arrCodDistrito[i]<<endl;
    }
    
    ouput<<""<<endl;
    imprimir_lin(ouput, '*');
    ouput<<setw((TAMREPOTE1+TITULOPRUEBA2)/2)<<"ARCHIVO DE PRUEBAS DE PLATOS"<<endl;
    imprimir_lin(ouput, '=');
    ouput<<setw(15)<<"";
    ouput<<setw(tam)<<left<<"CODIGO DE PLATO"<<setw(tam)<<left<<"PRECIO DEL PLATO"<<setw(tam)<<left<<"DESCUENTO DEL PLATO"<<endl;
    imprimir_lin(ouput, '-');
    for(int i=0;i<cantPlatos;i++){
        ouput<<setw(15)<<"";
        ouput<<setw(tam)<<left<<arrCodPlatos[i]<<setw(tam)<<left<<arrPrecioPlatos[i]<<setw(tam)<<left<<arrDescuentosPlatos[i]<<endl;
    }
}

int obtenerPosicion(int codigoDistrito,char tipoVeh,char *arrTipoVehiculo,int *arrCodDistrito,int cantRepartidores){
    
    for(int i=0;i<cantRepartidores;i++){
        if(codigoDistrito == arrCodDistrito[i] and tipoVeh ==  arrTipoVehiculo[i]){
            return i;
        }
    }
    return NO_ENCONTRADO;
}

int obtenerPosicionPlatos(int codigoPlato,int *arrCodPlatos,int cantPlatos){
    for(int i=0;i<cantPlatos;i++){
        if(codigoPlato == arrCodPlatos[i]){
            return i;
        }
    }
    return NO_ENCONTRADO;
}

void intercambiarI(int &a,int &b){
    int aux;
    aux=a;
    a=b;
    b=aux;
}

void intercambiarC(char &a,char &b){
    char aux;
    aux=a;
    a=b;
    b=aux;
}

void intercambiarD(double &a,double &b){
    double aux;
    aux=a;
    a=b;
    b=aux;
}

void LeerPlatosEntregadosPorUnRepartidor(ifstream &inputRepartos, 
            int &cantTPlatosPorRepartidor,double &montoTPlatosPorRepartidor,double &descuentoTPlatosPorRepartidor,
            int *arrCodPlatos,double *arrPrecioPlatos,double *arrDescuentosPlatos,int cantPlatos){    
    int cantidadPlato, codigoPlato, posPlato;
    char c;
    while(true){
        inputRepartos>>cantidadPlato>>codigoPlato;
        c = inputRepartos.get();
        
        posPlato = obtenerPosicionPlatos(codigoPlato,arrCodPlatos,cantPlatos);
        
        if(posPlato != NO_ENCONTRADO){
            cantTPlatosPorRepartidor += cantidadPlato;
            montoTPlatosPorRepartidor += arrPrecioPlatos[posPlato] * cantidadPlato;
            descuentoTPlatosPorRepartidor += arrDescuentosPlatos[posPlato];
            
        }
        else{
            cout<<"No se encontro el plato"<<endl;
        }
        
        if(c == '\n') break;
    }
}

void cargarArrIntermediosRepartidores(int pos,double comision,int cantTPlatosPorRepartidor,double montoTPlatosPorRepartidor,double descuentoTPlatosPorRepartidor,double descCliente,
                                            int *arrCantPlatosPorRepartidor,double *arrMontoPlatosPorRepartidor,double *arrDescPlatosPorRepartidor,double *arrDescClientesPorRepartidor,double *arrPagoRepartidor,double *arrMontoTotalPorRepartidor){
    arrCantPlatosPorRepartidor[pos] += cantTPlatosPorRepartidor;
    arrMontoPlatosPorRepartidor[pos] += montoTPlatosPorRepartidor;
    arrDescPlatosPorRepartidor[pos] += descuentoTPlatosPorRepartidor;
    arrDescClientesPorRepartidor[pos] += descCliente;
    arrPagoRepartidor[pos] += montoTPlatosPorRepartidor *comision;
    arrMontoTotalPorRepartidor[pos] += (montoTPlatosPorRepartidor - descuentoTPlatosPorRepartidor -descCliente - (montoTPlatosPorRepartidor *comision));
}

void leerArchivoRepartos(int *arrDNIRepartidores,char *arrTipoVehiculo,int *arrCodDistrito, int cantRepartidores,
         int *arrCantPlatosPorRepartidor,double *arrMontoPlatosPorRepartidor,double *arrDescPlatosPorRepartidor,double *arrDescClientesPorRepartidor,double *arrPagoRepartidor,double *arrMontoTotalPorRepartidor,
         int *arrCodPlatos,double *arrPrecioPlatos,double *arrDescuentosPlatos,int cantPlatos,
         int *arrCantVendidoPorPlato, double *arrDescTotalPorPlato){
    ifstream inputRepartos;
    
    apetura_lectura("RepartosARealizar.txt", inputRepartos);
    int codigoDistrito, pos;
    char tipoVeh, hayDescuento,c;
    double descCliente, comision;
    
    
    while(true){//por cada repartidor
        int cantTPlatosPorRepartidor=0;
         double montoTPlatosPorRepartidor=0.0,descuentoTPlatosPorRepartidor=0.0;
         
        inputRepartos>>codigoDistrito;
        if(inputRepartos.eof()) break;
        inputRepartos>>tipoVeh;
        (tipoVeh == 'B') ? comision = 0.05 : comision = 0.1; 
        ignorarNombreCliente(inputRepartos);
        inputRepartos>>hayDescuento;
        pos = obtenerPosicion(codigoDistrito,tipoVeh,arrTipoVehiculo,arrCodDistrito,cantRepartidores);
        
        if(pos != NO_ENCONTRADO){
           if (hayDescuento=='S') { 
               inputRepartos>>descCliente>>c;
           }else{
               descCliente=0;
           }
           
             LeerPlatosEntregadosPorUnRepartidor(inputRepartos, cantTPlatosPorRepartidor,montoTPlatosPorRepartidor,descuentoTPlatosPorRepartidor,
                                                arrCodPlatos,arrPrecioPlatos,arrDescuentosPlatos,cantPlatos);
             
             cargarArrIntermediosRepartidores(pos,comision,cantTPlatosPorRepartidor,montoTPlatosPorRepartidor,descuentoTPlatosPorRepartidor,descCliente,
                                            arrCantPlatosPorRepartidor,arrMontoPlatosPorRepartidor,arrDescPlatosPorRepartidor,arrDescClientesPorRepartidor,arrPagoRepartidor,arrMontoTotalPorRepartidor);
        }
        else{
            ignorar(inputRepartos, '\n');
        }
    }
}

void ordenarArreglo(int *arrDNIRepartidores,char *arrTipoVehiculo,int *arrCodDistrito, int cantRepartidores,
            int *arrCantPlatosPorRepartidor,double *arrMontoPlatosPorRepartidor,double *arrDescPlatosPorRepartidor,double *arrDescClientesPorRepartidor,double *arrPagoRepartidor,double *arrMontoTotalPorRepartidor){
    
    for(int i=0;i<cantRepartidores-1;i++){
        for(int k=i+1;k<cantRepartidores;k++){
            if(arrDNIRepartidores[i]>arrDNIRepartidores[k]){
                intercambiarI(arrDNIRepartidores[i],arrDNIRepartidores[k]);
                intercambiarC(arrTipoVehiculo[i],arrTipoVehiculo[k]);
                intercambiarI(arrCodDistrito[i],arrCodDistrito[k]);
                intercambiarI(arrCantPlatosPorRepartidor[i],arrCantPlatosPorRepartidor[k]);
                intercambiarD(arrMontoPlatosPorRepartidor[i],arrMontoPlatosPorRepartidor[k]);
                intercambiarD(arrDescPlatosPorRepartidor[i],arrDescPlatosPorRepartidor[k]);
                intercambiarD(arrDescClientesPorRepartidor[i],arrDescClientesPorRepartidor[k]);
                intercambiarD(arrPagoRepartidor[i],arrPagoRepartidor[k]);
                intercambiarD(arrMontoTotalPorRepartidor[i],arrMontoTotalPorRepartidor[k]);
            }
        }
    }
}

void imrpimirReporte1(int *arrDNIRepartidores,char *arrTipoVehiculo,int *arrCodDistrito, int cantRepartidores,
            int *arrCantPlatosPorRepartidor,double *arrMontoPlatosPorRepartidor,double *arrDescPlatosPorRepartidor,double *arrDescClientesPorRepartidor,double *arrPagoRepartidor,double *arrMontoTotalPorRepartidor){
    int tam=TAMREPOTE1/COLUMNAS1;
    ifstream inputNombreRepartidores;
    ofstream ouput;
    apetura_lectura("NombresRepartidores.txt", inputNombreRepartidores);
     apetura_esccritura("reporte.txt",ouput);
     
     ouput<<setw((TAMREPOTE1+TITULO1)/2)<<"EMPRESA DE REPARTOS A DOMICILIOS TP S.A."<<endl;
     ouput<<setw((TAMREPOTE1+TITULO2)/2)<<"ENTREGA POR REPARTIDORES"<<endl;
     imprimir_lin(ouput, '=');
    for(int i=0;i<cantRepartidores;i++){
        ouput<<setw(tam)<<left<<arrDNIRepartidores[i]
                <<setw(tam)<<left<<arrTipoVehiculo[i]
                <<setw(tam)<<left<<arrCodDistrito[i]
                <<setw(tam)<<left<<arrCantPlatosPorRepartidor[i]
                <<setw(tam)<<left<<arrMontoPlatosPorRepartidor[i]
                <<setw(tam)<<left<<arrDescPlatosPorRepartidor[i]
                <<setw(tam)<<left<<arrDescClientesPorRepartidor[i]
                <<setw(tam)<<left<<arrPagoRepartidor[i]
                <<setw(tam)<<left<<arrMontoTotalPorRepartidor[i]<<endl;
    }
}
