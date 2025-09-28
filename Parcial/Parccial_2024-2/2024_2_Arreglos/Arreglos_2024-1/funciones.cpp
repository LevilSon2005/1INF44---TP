/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 18 de mayo de 2025, 13:07
 */

#include <cinttypes>

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


void ignorar_texto(ifstream &input, char delimitador){
    input>>ws;
    ignorar(input, delimitador);
}

void imprimir_linCompleta(ofstream &ouput, char c){
    ouput<<setfill(c)<<setw(TAMREPORTE)<<""<<setfill(' ')<<endl;
}

void imprimir_linPrueba(ofstream &ouput, char c, int tam){
    ouput<<setfill(c)<<setw(tam)<<""<<setfill(' ')<<endl;
}

void leerPlatos(int *codigosPlat,int *cantidadesPrep,double *preciosPlat,double *descuentosPlat,int* cantidadesPrepAux,int &cantidadPlatos){
    int codPlato;
    char c;
    ifstream inputPlatos;
    apertura_lectura("PlatosOfrecidos.txt", inputPlatos);
    
    while(true){
        inputPlatos>>codPlato;
        if(inputPlatos.eof()) break;
        codigosPlat[cantidadPlatos] = codPlato;
        ignorar_texto(inputPlatos, '}');
        inputPlatos>>preciosPlat[cantidadPlatos]>>cantidadesPrep[cantidadPlatos];
        if(inputPlatos.get() != '\n') inputPlatos>>descuentosPlat[cantidadPlatos]>>c;
        cantidadesPrepAux[cantidadPlatos] = cantidadesPrep[cantidadPlatos];
        cantidadPlatos++;
    }
}

void leerClientes(int *dnisClien,double *descuentosClien,int &cantidadClientes){
    int dniCliente, codDistrito;
    char tipoVeh, hayDesc,c;
     ifstream inputClientes;
    apertura_lectura("Clientes.txt", inputClientes);
    
    while(true){
        inputClientes>>dniCliente;
        if(inputClientes.eof()) break;
        dnisClien[cantidadClientes] = dniCliente;
        ignorar_texto(inputClientes, ']');
        inputClientes>>codDistrito>>ws;
        ignorar(inputClientes, ' ');
        inputClientes>>tipoVeh>>hayDesc;
        if(hayDesc =='S') inputClientes>>descuentosClien[cantidadClientes]>>c;
        cantidadClientes++;
    }
    
}

void imprimir_pruebaArreglos(int *codigosPlat,int *cantidadesPrep,double *preciosPlat,double *descuentosPlat,int cantidadPlatos,
                            int *dnisClien,double *descuentosClien,int cantidadClientes){
    ofstream ouput;
    apertura_escritura("prueba.txt", ouput);
    int Tam=80, tam = Tam/5;
    
    ouput<<setw((Tam+TITULO1)/2)<<"REPORTE DE PRUEBA DE PLATOS"<<endl;
    imprimir_linPrueba(ouput,'=', Tam);
    ouput<<setw(tam+5)<<left<<"CODIGO DEL PLATO"<<setw(tam+8)<<left<<"CANTIDADES PREPARADAS"<<setw(tam-8)<<left<<"PRECIO"<<setw(tam-5)<<left<<"DESCUENTO"<<endl;
    imprimir_linPrueba(ouput,'-', Tam);
    for(int i=0;i< cantidadPlatos;i++){
        ouput<<setw(5)<<"";
        ouput<<setw(tam+10)<<left<<codigosPlat[i]
                <<setw(tam)<<left<<cantidadesPrep[i]
                <<setw(tam-7)<<left<<preciosPlat[i]
                <<setw(tam)<<left<<descuentosPlat[i]<<endl;
    }
    imprimir_linPrueba(ouput,'=', Tam);
    ouput<<setw((Tam+TITULO2)/2)<<"REPORTE DE PRUEBA DE CLIENTES"<<endl;
    imprimir_linPrueba(ouput,'=', Tam);
    ouput<<setw(5)<<"";
    ouput<<setw(tam-5)<<left<<"DNI"<<setw(tam+5)<<left<<"CODIGO DEL DISTRITO"<<setw(tam)<<left<<"DESCUENTO"<<endl;
    imprimir_linPrueba(ouput,'-', Tam);
    for(int i=0;i< cantidadClientes;i++){
        ouput<<setw(5)<<"";
        ouput<<setw(tam)<<left<<dnisClien[i]
                <<setw(tam)<<left<<descuentosClien[i]<<endl;
    }
}

int buscarPosicion(int codigoPlatoSolicitado,int *codigosPlat,int cantidadPlatos){
    for(int i=0;i<cantidadPlatos;i++){
        if(codigoPlatoSolicitado == codigosPlat[i]) return i;
    }
    return NO_ENCONTRADO;
}


void leerRepartos(int *PlatosAtendidos,int *PlatosNoAtendidos,
                double *descuentosTotales,double *montoEsperado,double *montoBruto,double *montoRecibido,
                int *codigosPlat,int *cantidadesPrep,double *preciosPlat,double *descuentosPlat,int cantidadPlatos,
                int *dnisClien,double *descuentosClien,int cantidadClientes){
    ifstream inputRepartos;
    apertura_lectura("RepartosARealizar.txt", inputRepartos);
    int numPedido, dniCliente, cantPlatoSolicitado=0, codigoPlatoSolicitado=0, platosNoDisponibles=0, platosRestantes=0;
    int posCliente=0,posPlato=0;
    double montoBrutoPlato=0.0,descuentoTotal=0.0;
    while(true){
        inputRepartos>>numPedido;
        if(inputRepartos.eof()) break;
        inputRepartos>>dniCliente;
        while(true){
            if(inputRepartos.get() == '\n') break;
            inputRepartos>>cantPlatoSolicitado>>codigoPlatoSolicitado;
            posCliente = buscarPosicion(dniCliente,dnisClien,cantidadClientes);
            if(posCliente != NO_ENCONTRADO){
                posPlato = buscarPosicion(codigoPlatoSolicitado,codigosPlat,cantidadPlatos);
                 if(posPlato != NO_ENCONTRADO){
                     descuentoTotal = (descuentosClien[posCliente] + descuentosPlat[posPlato]);
                     descuentosTotales[posPlato] +=  descuentoTotal;
                     montoEsperado[posPlato] += cantPlatoSolicitado* preciosPlat[posPlato];
                     if(cantidadesPrep[posPlato]>=cantPlatoSolicitado){
                         PlatosAtendidos[posPlato] +=cantPlatoSolicitado;
                         cantidadesPrep[posPlato] -= cantPlatoSolicitado;
                         montoBrutoPlato= cantPlatoSolicitado* preciosPlat[posPlato];
                     }else{
                         platosRestantes = cantidadesPrep[posPlato];
                         platosNoDisponibles = cantPlatoSolicitado - platosRestantes;
                         cantidadesPrep[posPlato] -= platosRestantes;
                         PlatosAtendidos[posPlato] += platosRestantes;
                         PlatosNoAtendidos[posPlato] += platosNoDisponibles;
                         montoBrutoPlato = platosRestantes * preciosPlat[posPlato];
                     }
                     montoBruto[posPlato] += montoBrutoPlato;
                     montoRecibido[posPlato] += (montoBrutoPlato *(1- (descuentoTotal/100)));
                 }
            }
        }
    }
}

void intercambiarI(int &a,int &b){
    int aux;
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
void intercambiarC(char &a,char &b){
    char aux;
    aux=a;
    a=b;
    b=aux;
}

void odenarArreglos(int *codigosPlat,double*preciosPlat,int*cantidadesPrepAux,int*PlatosAtendidos,int*PlatosNoAtendidos,int cantidadPlatos,
                   double *descuentosTotales,double *montoEsperado,double *montoBruto,double *montoRecibido){
    
    for(int i=0;i<cantidadPlatos-1;i++){
        for(int k=i+1;k<cantidadPlatos;k++){
            if(cantidadesPrepAux[i]<cantidadesPrepAux[k]){
                intercambiarI(codigosPlat[i],codigosPlat[k]);
                intercambiarD(preciosPlat[i],preciosPlat[k]);
                intercambiarI(cantidadesPrepAux[i],cantidadesPrepAux[k]);
                intercambiarI(PlatosAtendidos[i],PlatosAtendidos[k]);
                intercambiarI(PlatosNoAtendidos[i],PlatosNoAtendidos[k]);
                intercambiarD(descuentosTotales[i],descuentosTotales[k]);
                intercambiarD(montoEsperado[i],montoEsperado[k]);
                intercambiarD(montoBruto[i],montoBruto[k]);
                intercambiarD(montoRecibido[i],montoRecibido[k]);
            }
        }
    }
}

void imprimir_reporte(int *codigosPlat,double*preciosPlat,int*cantidadesPrepAux,int*PlatosAtendidos,int*PlatosNoAtendidos,int cantidadPlatos,
                   double *descuentosTotales,double *montoEsperado,double *montoBruto,double *montoRecibido, const char* name){
    ofstream ouput;
    apertura_escritura(name, ouput);
    int tam = TAMREPORTE/COLUMNAS;
    double montoTotalEsperado=0.0, montoTotalBruto=0.0, montoTotalRecibido=0.0;
    ouput<<setw((TAMREPORTE+TITULO3)/2)<<"EMPRESA DE RELACIONES A DOMICILIO TP S.A."<<endl;
    ouput<<setw((TAMREPORTE+TITULO4)/2)<<"RELACION DE PLATOS VENDIDOS"<<endl;
    imprimir_linCompleta(ouput, '=');
    ouput<<setw(3*tam)<<left<<""<<setw(2*tam)<<left<<"CANTIDAD DE PLATOS"<<setw(tam)<<left<<""<<setw(3*tam)<<left<<"MONTOS RECAUDADOS"<<endl;
    ouput<<setw(tam)<<left<<"CODIGO"<<setw(tam)<<left<<"PRECIO"<<setw(tam)<<left<<"PREPARADOS"<<setw(tam)<<left<<"ATENDIDOS"<<setw(tam)<<left<<"NO ATENDIDOS"<<setw(tam)<<left<<"DESCUENTO"<<setw(tam)<<left<<"ESPERADO"<<setw(tam)<<left<<"BRUTO"<<setw(tam)<<left<<"RECIBIDO"<<endl;
    imprimir_linCompleta(ouput, '-');
    
    for(int i=0;i<cantidadPlatos;i++){
        ouput<<setw(tam)<<left<<codigosPlat[i]
                <<setw(tam)<<left<<preciosPlat[i]
                <<setw(tam)<<left<<cantidadesPrepAux[i]
                <<setw(tam)<<left<<PlatosAtendidos[i]
                <<setw(tam)<<left<<PlatosNoAtendidos[i]
                <<setw(tam)<<left<<descuentosTotales[i]
                <<setw(tam)<<left<<montoEsperado[i]
                <<setw(tam)<<left<<montoBruto[i]
                <<setw(tam)<<left<<montoRecibido[i]<<endl;
        montoTotalEsperado += montoEsperado[i];
        montoTotalBruto += montoBruto[i];
        montoTotalRecibido += montoRecibido[i];
    }
    imprimir_linCompleta(ouput,'=');
    ouput<<setw(5*tam)<<left<<""<<setw(tam)<<left<<"TOTALES: "<<setw(tam)<<left<<montoTotalEsperado<<setw(tam)<<left<<montoTotalBruto<<setw(tam)<<left<<montoTotalRecibido<<endl;
    imprimir_linCompleta(ouput,'=');
    
}

void eliminarDato(int numDato,int *codigosPlat,double*preciosPlat,int*cantidadesPrepAux,int*PlatosAtendidos,int*PlatosNoAtendidos,int &cantidadPlatos,
                   double *descuentosTotales,double *montoEsperado,double *montoBruto,double *montoRecibido){
    int pos;
    pos= numDato-1;
    for(int i=pos;i<cantidadPlatos-1;i++){
        codigosPlat[i] =  codigosPlat[i+1];
        preciosPlat[i] =  preciosPlat[i+1];
        PlatosAtendidos[i] =  PlatosAtendidos[i+1];
        PlatosNoAtendidos[i] =  PlatosNoAtendidos[i+1];
        descuentosTotales[i] =  descuentosTotales[i+1];
        montoEsperado[i] =  montoEsperado[i+1];
        montoBruto[i] =  montoBruto[i+1];
        montoRecibido[i] =  montoRecibido[i+1];
    }
    cantidadPlatos--;
}

void eliminarNoAtendidos(int *codigosPlat,double*preciosPlat,int*cantidadesPrepAux,int*PlatosAtendidos,int*PlatosNoAtendidos,int &cantidadPlatos,
                   double *descuentosTotales,double *montoEsperado,double *montoBruto,double *montoRecibido){
//    int contador=0;
    for(int i=0;i<cantidadPlatos;i++){
        if(PlatosNoAtendidos[i] == 0){
//            contador++;
            eliminarDato(i+1,codigosPlat,preciosPlat,cantidadesPrepAux,PlatosAtendidos,PlatosNoAtendidos,cantidadPlatos,
                   descuentosTotales,montoEsperado,montoBruto,montoRecibido);
            i--;
        }
    }    
}

