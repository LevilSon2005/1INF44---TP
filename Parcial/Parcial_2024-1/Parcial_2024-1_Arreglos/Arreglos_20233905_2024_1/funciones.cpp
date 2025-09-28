/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 17 de mayo de 2025, 20:26
 */

#include "funciones.hpp"


void apertura_lectura(const char* name, ifstream &input){
    input.open(name, ios::in);
    if(not input.is_open()){
        cout<<"ERROR: El archcivo"<<name<<" no se abre"<<endl;
    }
}

void apertura_escritura(const char* name, ofstream &ouput){
    ouput.open(name, ios::out);
    if(not ouput.is_open()){
        cout<<"ERROR: El archcivo"<<name<<" no se abre"<<endl;
    }
    else{
        cout<<"El reporte se abrio"<<endl;
    }
}

void  ignorar(ifstream &input, char delimitador){
    while(input.get() != delimitador);
}

void ignorarNombre(ifstream &inputPacientes){
    inputPacientes>>ws;
    ignorar(inputPacientes, ']');
}

char conseguirClasificacion(int anioNac){
    if(anioNac>=2019) return 'A';
    if(anioNac>=2013 and anioNac<=2018) return'B';
    if(anioNac>=2006 and anioNac<=2012) return'C';
    if(anioNac>=1998 and anioNac<=2005) return'D';
    if(anioNac>=1965 and anioNac<=1997) return'E';
    if( anioNac<=1965) return'F';
}

void cargarArregloPacientes(int *dnisPac,int *codigosDist,char *clasificacionesPac,double *descuentosPac,int &cantidadPac){
    int codPaciente, anioNac;
    ifstream inputPacientes;
    apertura_lectura("Pacientes.txt",inputPacientes);
    while(true){
        inputPacientes>>codPaciente;
        if(inputPacientes.eof()) break;
        dnisPac[cantidadPac] =codPaciente;
        ignorarNombre(inputPacientes);
        inputPacientes>>codigosDist[cantidadPac]>>anioNac;
        inputPacientes>>descuentosPac[cantidadPac];
        clasificacionesPac[cantidadPac] = conseguirClasificacion(anioNac);
        
        cantidadPac++;
    }
}

void cargarArregoMedicinas(int *codigosMedic,double *preciosMedic, int&cantMedicina){
    int codMedicina;
    ifstream inputMedicinas;
    apertura_lectura("Medicinas.txt",inputMedicinas);
    
    while(true){
        inputMedicinas>>codMedicina;
        if(inputMedicinas.eof()) break;
        codigosMedic[cantMedicina] = codMedicina;
        inputMedicinas>>ws;
        ignorar(inputMedicinas, ' ');
        inputMedicinas>>preciosMedic[cantMedicina];
        cantMedicina++;
    }
}

//void imprimir_arregloPacietes(int *dnisPac,int *codigosDist,char *clasificacionesPac,double *descuentosPac,int cantidadPac,
//                                int *codigosMedic,double *preciosMedic, int&cantMedicina){
//    
//}

int buscarPaciente(int dniPac, int *dnisPac, int cantidadPac){
    for(int i=0;i<cantidadPac;i++){
        if(dniPac == dnisPac[i]) return i;
    }
    
    return NO_ENCONTRADO;
}

int buscarMedicina(int codMedicina, int *codigosMedic, int cantMedicina){
    for(int i=0;i<cantMedicina;i++){
        if(codMedicina == codigosMedic[i]) return i;
    }
    return NO_ENCONTRADO;
}


void leerCitas(int *cantCitas,int *cantMedicinas,double *pagosPacientes,
              int *dnisPac,int *codigosDist,char *clasificacionesPac,double *descuentosPac,int cantidadPac,
              int *codigosMedic,double *preciosMedic, int cantMedicina){
    
    ifstream inputMedicinas;
    apertura_lectura("CitasMedicas.txt",inputMedicinas);
    int d,m,a,hh,mm,ss, dniPac, num, codMedicina, cantidadMedicina, posPaciente=0,posMedicina=0;
    char c, car;
    while(true){
        inputMedicinas>>d;
        if(inputMedicinas.eof()) break;
        inputMedicinas>>c>>m>>c>>a>>dniPac>>hh>>c>>mm>>c>>ss>>hh>>c>>mm>>c>>ss>>num;
        posPaciente = buscarPaciente(dniPac, dnisPac, cantidadPac);
        while(true){
          if(inputMedicinas.get() == '\n')  break; 
          inputMedicinas>>codMedicina>>cantidadMedicina;
          if(posPaciente != NO_ENCONTRADO){
            posMedicina = buscarMedicina(codMedicina,codigosMedic,cantMedicina);
            if(posMedicina != NO_ENCONTRADO){
               cantMedicinas[posPaciente]++;
               pagosPacientes[posPaciente] = cantidadMedicina * preciosMedic[posMedicina] *(1- descuentosPac[posMedicina]/200);
            }
          }  
        }
        
         if(posPaciente != NO_ENCONTRADO) cantCitas[posPaciente]++;    
    }
}

//LEES Y DECIDAS SI ACTUALIZAS O NO CON BUSQUEDAS DE POSICION 

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

void intercambiarI(int &a,int &b){
    int aux;
    aux=a;
    a=b;
    b=aux;
}


void ordenar_datos(int *dnisPac,int *codigosDist,char *clasificacionesPac,double *descuentosPac,int *cantCitas,int *cantMedicinas,double *pagosPacientes,int cantPac){
    
    for(int i=0;i<cantPac-1;i++){
        for(int k=i+1;k<cantPac;k++){
            if(clasificacionesPac[i]>clasificacionesPac[k] or (clasificacionesPac[i]==clasificacionesPac[k] and codigosDist[i]<codigosDist[k])){
                intercambiarC(clasificacionesPac[i],clasificacionesPac[k]);
                intercambiarI(codigosDist[i],codigosDist[k]);
                intercambiarI(dnisPac[i],dnisPac[k]);
                intercambiarD(descuentosPac[i],descuentosPac[k]);
                intercambiarI(cantCitas[i],cantCitas[k]);
                intercambiarI(cantMedicinas[i],cantMedicinas[k]);
                intercambiarD(pagosPacientes[i],pagosPacientes[k]);
            }
        }
    }
}

void imprimir_reporte(int *dnisPac,int *codigosDist,char *clasificacionesPac,double *descuentosPac,int *cantCitas,int *cantMedicinas,double *pagosPacientes,int cantPac){
    ofstream ouput;
    apertura_escritura("reporte.txt", ouput);
    int tam=TAMREPORTE/COLUMNAS;
    
    for(int i=0;i<cantPac;i++){
        ouput<<setw(tam)<<left<<clasificacionesPac[i]
                <<setw(tam)<<left<<codigosDist[i]
                <<setw(tam)<<left<<dnisPac[i]
                <<setw(tam)<<left<<descuentosPac[i]
                <<setw(tam)<<left<<cantCitas[i]
                <<setw(tam)<<left<<cantMedicinas[i]
                <<setw(tam)<<left<<pagosPacientes[i]<<endl;
    }
}