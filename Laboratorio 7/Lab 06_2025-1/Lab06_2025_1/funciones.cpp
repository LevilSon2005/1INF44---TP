/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 9 de junio de 2025, 11:40
 */

#include "funciones.hpp"

void apertura_lectura(ifstream &input, const char* name){
    input.open(name, ios::in);
    if(not input.is_open()) {
        cout<<"El archivo "<< name<<" no se abrio"<<endl;
    }
}

void apertura_escritura(ofstream &ouput, const char* name){
    ouput.open(name, ios::out);
    if(not ouput.is_open()) {
        cout<<"El archivo "<< name<<" no se abrio"<<endl;
    }
    else
        cout<<"El reporte - "<< name<<" se abrio"<<endl;
}

imprimir_titulo(ofstream &ouput, const char* titulo){
    ouput<<setw((TAMREPORTE + strlen(titulo))/2)<<titulo<<endl;
}

imprmir_linC(ofstream &ouput, char c){
    ouput<<setw(TAMREPORTE)<<setfill(c)<<""<<setfill(' ')<<endl;
}

void ignorar(ifstream &input, char del){
    while(input.get() != del);
}

int calcularFecha(int d, int m, int a){
    return a*10000+m*100+d;
}

char* leer_cadena(ifstream &input, char del){
    char* cadena;
    char temporal[180];
    
    input.getline(temporal, 180, del);
    cadena = new char[strlen(temporal)+1];
    strcpy(cadena, temporal);
    
    return cadena;
}

int busquedaCadena(char*descripcion,char**arrDescripInf,int cantInf){
    
    for(int i=0;i<cantInf;i++){
        if(strcmp(arrDescripInf[i], descripcion)==0) return i;
    }
    
    return NO_ENCONTRADO;
}

void insertar_sinRepetir(int codigo,double precioMulta,char* descripcion,
               int*arrCodigoInfraccion,double*arrMultasInfracciones,char**arrDescripInf, int&cantInf){
    int pos;
    pos = busquedaCadena(descripcion,arrDescripInf,cantInf);
    
    if(pos == NO_ENCONTRADO){//primera vez
        arrCodigoInfraccion[cantInf] = codigo;
        arrMultasInfracciones[cantInf] = precioMulta;
        arrDescripInf[cantInf] = descripcion;
//         cout<<"codigo: "<< arrCodigoInfraccion[cantInf]<<endl;
//        cout<<"precio: "<<arrMultasInfracciones[cantInf]<<endl;
//        cout<<"descripcion: "<<arrDescripInf[cantInf]<<endl;
        cantInf++;
    }else{
        arrMultasInfracciones[cantInf] += precioMulta;
    }
    
        
}

void leer_TablaInfracciones(int*arrCodigoInfraccion,double*arrMultasInfracciones,char**arrDescripInf,
                            int&cantInf){
    
    ifstream input;
    apertura_lectura(input, "TablaDeInfracciones.txt");
    
    char* descripcion;
    int codigo;
    double precioMulta;
    
    while(true){
        input>>codigo;
        if(input.eof()) break;
        input>>precioMulta;
        input>>ws;
        descripcion = leer_cadena(input, '\n');
        insertar_sinRepetir(codigo,precioMulta,descripcion,
                    arrCodigoInfraccion,arrMultasInfracciones,arrDescripInf,cantInf);
                
    }
}

void  emitir_ReportePrueba(int*arrCodigoInfraccion,double*arrMultasInfracciones,char**arrDescripInf,int cantInf){
    ofstream ouput;
    apertura_escritura(ouput, "PruebaTablaInf.txt");
    
    imprimir_titulo(ouput, "REPORTE DE PRUEBA DE LA LISTA DE INFRACCIONES");
    imprmir_linC(ouput, '-');
    
    int tam=TAMREPORTE/6;
    ouput<<setw(tam)<<left<<"CODIGO INFRACCION"
            <<setw(tam)<<"PRECIO INFRACCION"
            <<setw(tam)<<"DESCRIPCION DE LA INFRACCION"<<endl;
    
    for(int i=0;i<cantInf;i++){
        ouput<<setw(4)<<"";
        ouput<<setw(tam)<<arrCodigoInfraccion[i]
            <<setw(tam)<<arrMultasInfracciones[i]
            <<setw(tam)<<arrDescripInf[i]<<endl;
    }
}

int busquedaIndice(int dni, int* arrDNI, int cantDni){
    for(int i=0;i<cantDni;i++){
        if(dni==arrDNI[i]) return i;
    }
    
    return NO_ENCONTRADO;
}

void imprimir_reporteDNI(int dni,char tipo, int placa1,int placa2, ofstream &ouput){
    
    int tam=TAMREPORTE/2;
    ouput<<setw(tam)<<left<<dni
            <<tipo<<placa1<<"-"<<placa2<<endl;
}

void imprimir_titulo_reporte(int tam, ofstream &ouput){
    imprimir_titulo(ouput, "REPORTE DE DNIS");
    imprmir_linC(ouput, '-');
    ouput<<setw(tam)<<left<<"DNI"
            <<setw(tam)<<"PLACA"<<endl;
    imprmir_linC(ouput, '-');
}

void insertarSinRepetirDni(int dni,int fecha,int fecha_p,int codInf,bool pagoInf,
                     int*arrCodigoInfraccion,double*arrMultasInfracciones,int cantInf,
                    int *arrDNI,int* arrMasMultaAntigua,int*arrUltimaPendiente,
                          double* arrTotalMultas,double* arrTotalPagadas,double* arrTotalPendientes,int &cantDni){
    int posDni, posInf;
    posDni = busquedaIndice(dni, arrDNI, cantDni);
    posInf = busquedaIndice(codInf, arrCodigoInfraccion, cantInf);
    
    if(posInf != NO_ENCONTRADO){
        if(posDni ==NO_ENCONTRADO){
            arrDNI[cantDni] = dni;
            arrMasMultaAntigua[cantDni] = fecha;
            if(pagoInf){//si pago la infraccion
                arrUltimaPendiente[cantDni] = fecha_p;
                arrTotalPagadas[cantDni] = arrMultasInfracciones[posInf];
            }
            else{//si no pago la infraccion
                arrTotalPagadas[cantDni] =0;
                arrTotalPendientes[cantDni] = arrMultasInfracciones[posInf];
            }
            arrTotalMultas[cantDni] = arrMultasInfracciones[posInf];
            cantDni++;
        }
        else{
           if(fecha<arrMasMultaAntigua[posDni]) arrMasMultaAntigua[posDni] = fecha;
           if(pagoInf){
               if(fecha_p>arrUltimaPendiente[posDni]) arrUltimaPendiente[posDni] =fecha_p;
               arrTotalPagadas[posDni] += arrMultasInfracciones[posInf];
           }
           else{
               arrTotalPendientes[posDni] += arrMultasInfracciones[posInf];
           }
           arrTotalMultas[posDni] +=  arrMultasInfracciones[posInf];
        }
    }
    
}

void leer_InfraccionesCometidas(int*arrCodigoInfraccion,double*arrMultasInfracciones,char**arrDescripInf,int cantInf,
                            int *arrDNI,int* arrMasMultaAntigua,int*arrUltimaPendiente,
                          double* arrTotalMultas,double* arrTotalPagadas,double* arrTotalPendientes,int &cantDni){
    ifstream input;
    apertura_lectura(input, "InfraccionesCometidas.txt");
    int d,m,a,placa1,placa2,dni,codInf, fecha;
    int d_p,m_p,a_p, fecha_p=0;
    char tipo,c;
    bool pagoInf;
    int tam=TAMREPORTE/2;
    ofstream ouput;
    apertura_escritura(ouput, "PlacasRegistradas.txt");
    imprimir_titulo_reporte(tam, ouput);
    
    while(true){
        pagoInf=false;
        input>>d;
        if(input.eof()) break;
        input>>c>>m>>c>>a>>tipo>>placa1>>c>>placa2;
        input>>dni>>codInf;
        fecha = calcularFecha(d,m,a);
        if(input.get() != '\n'){
            pagoInf = true;
            input>>c>>d_p>>c>>m_p>>c>>a_p;    
            fecha_p = calcularFecha(d_p,m_p,a_p);
        }
        imprimir_reporteDNI(dni, tipo,placa1,placa2, ouput);
        
        insertarSinRepetirDni(dni,fecha,fecha_p,codInf,pagoInf,
                        arrCodigoInfraccion,arrMultasInfracciones,cantInf,
                        arrDNI,arrMasMultaAntigua,arrUltimaPendiente,
                              arrTotalMultas,arrTotalPagadas,arrTotalPendientes,cantDni);
    }
}

void obtenerPlaca(const char* listaDePlacas, int n, char* placa){
    if(n<1)return;
    int cantPlacas=1;
    int j=0, current=1;
    //para contar el numero de placas
    for(int i=0; listaDePlacas[i]; i++ ){
        if(listaDePlacas[i]=='/') cantPlacas++;
    }
    
    //si es que me piden una placas que no existe
    if(n>cantPlacas) return;
    
    //copia la placa que piden
    for(int i=0;listaDePlacas[i];i++){
        if(listaDePlacas[i] =='/') current++;
        if(current == n){
            
        }
    }
    
    
}
