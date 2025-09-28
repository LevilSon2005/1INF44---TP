/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 1 de junio de 2025, 17:21
 */

#include "funciones.hpp"
void apertura_lectura(const char* name,ifstream &input){
    input.open(name,ios::in);
    if(not input.is_open()){
        cout<<"ERROR: El archivo "<<name<<" no se abrio correctamente"<<endl;
    }
}

void apertura_escritura(const char* name,ofstream &ouput){
    ouput.open(name,ios::out);
    if(not ouput.is_open()){
        cout<<"ERROR: El archivo "<<name<<" no se abrio correctamente"<<endl;
    }
    else{
        cout<<"Se abrio correctamente"<<endl;
    }
}

void imprimir_linCar( ofstream &ouput,char c){
    ouput<<setw(TAMREPORTE)<<setfill(c)<<""<<setfill(' ')<<endl;
}

int busquedaBinaria(int codPlato,int*arrCodPlatos,int &cantidadPlatos){
    int indInf, indSup, indMedio;  
    indInf = 0;
    indSup = cantidadPlatos-1;
    
    while(true){
        if(indInf>indSup)return NO_ENCONTRADO;
        indMedio = (indInf + indSup) /2;
        if(codPlato == arrCodPlatos[indMedio]) return indMedio;
        if(codPlato < arrCodPlatos[indMedio]) indInf = indMedio +1;
        if(codPlato > arrCodPlatos[indMedio]) indSup = indMedio -1;
//        cout<<"indMedio: "<<indMedio<<endl;
//        cout<<"indInf: "<<indInf<<endl;
//        cout<<"indSup: "<<indSup<<endl;
    }
}

int my_strleng(const char* cadena){
    int i=0;
    for( ;cadena[i];i++);
    return i;
}

void my_strcpy(char* cadena, const char* source){
    int i=0;
    for(;source[i];i++){
        cadena[i] = source[i];
    }
    cadena[i] = '\0';
}

void my_strcat(char* cadena1, const char*cadena2){
    int pos= my_strleng(cadena1);
    my_strcpy(&cadena1[pos],cadena2);
}

void my_strprepend(char* cadena1, const char* cadena2){
    char aux[MAXNOMBRE]{};
    my_strcpy(aux, cadena2);
    my_strcat(aux,cadena1);
    my_strcpy(cadena1, aux);
}

int my_strcmp(const char* cadena1, const char* cadena2){
    int i=0;
    while(true){
        if(cadena1[i] != cadena2[i]) {
            if(cadena1[i] > cadena2[i]) return 1;
            if(cadena1[i] < cadena2[i]) return -1;
        }
        if(cadena1[i] == '\0') return 0;
        i++;
    }
}

void InsertarOrdenadoPlatos(int* arrCodPlatos,int*arrNumPlatosVendidos,int& cantidadPlatos,
                            int codPlato, int cantPlato){
    int posPlato, posInserccion;
    
    posPlato = busquedaBinaria(codPlato,arrCodPlatos,cantidadPlatos);
//    cout<<"PosPlato: "<<posPlato<<endl;
    if(posPlato == NO_ENCONTRADO){//Primera vez del plato - Arreglo vacio en esa pos - necesita inserccion
        posInserccion = cantidadPlatos-1; //para la primera posicion
        //te deja el indice anterior
        while(posInserccion>=0 and codPlato > arrCodPlatos[posInserccion]){
            arrCodPlatos[posInserccion+1] = arrCodPlatos[posInserccion];
            arrNumPlatosVendidos[posInserccion+1] = arrNumPlatosVendidos[posInserccion];
            posInserccion--;
        }
        arrCodPlatos[posInserccion+1] = codPlato;
        arrNumPlatosVendidos[posInserccion+1] = cantPlato;
        cantidadPlatos++;
    }
    else{//Arreglo no vacio- ya estaba un dato antes en esa pos- solo necesita acumulacion
        arrNumPlatosVendidos[posPlato] += cantPlato;
    }
}

void leerRepartosARealizar(int* arrCodPlatos,int*arrNumPlatosVendidos,int& cantidadPlatos){
    ifstream inputRepartos;
    apertura_lectura("RepartosARealizar.txt", inputRepartos);
 
    int numeroPedido, dni, cantPlato, codPlato;
    
    while(true){
        inputRepartos>>numeroPedido;
        if(inputRepartos.eof()) break;
        inputRepartos>>dni;
        while(true){
            if(inputRepartos.get() == '\n') break;
            inputRepartos>>cantPlato>>codPlato;
            InsertarOrdenadoPlatos(arrCodPlatos,arrNumPlatosVendidos,cantidadPlatos,
                                   codPlato, cantPlato);
        }
    }
    
}

void cargarArreglos(double *arrPrecio,double *arrIngresoBruto,double *arrDescuento,bool *arrTieneDescuento,double *arrTotal,
                    int *arrNumPlatosVendidos,int *arrCodPlatos,int cantPlatos,
                    int codPlato,double precio,bool hayDescuento,double descuento){
    double ingresoBruto=0.0;
    int posPlato = busquedaBinaria(codPlato,arrCodPlatos,cantPlatos);
    if(posPlato != NO_ENCONTRADO){
        arrPrecio[posPlato] += precio;
        ingresoBruto=precio*arrNumPlatosVendidos[posPlato];
        arrIngresoBruto[posPlato] += ingresoBruto;
        arrTieneDescuento[posPlato] += hayDescuento;
        arrDescuento[posPlato] += descuento;
        arrTotal[posPlato] += ingresoBruto - (descuento/100);
    }
}


void leerPlatosOfrecidos(double *arrPrecio,double *arrIngresoBruto,double *arrDescuento,bool *arrTieneDescuento,double *arrTotal,
                         int *arrNumPlatosVendidos,int *arrCodPlatos, int cantPlatos){
    ifstream inputPlatos;
    apertura_lectura("PlatosOfrecidos.txt", inputPlatos);
    char nombrePlato[MAXNOMBRE]{}, categoriaPlato[MAXNOMBRE]{},c;
    int codPlato;
    double precio, descuento=0;
    bool hayDescuento;
    
    while(true){
        hayDescuento=false;
        inputPlatos>>codPlato;
        if(inputPlatos.eof()) break;
        inputPlatos>>nombrePlato>>precio>>categoriaPlato;
        if(inputPlatos.get() != '\n'){
            hayDescuento = true;
            inputPlatos>>descuento>>c;
        }
        cargarArreglos(arrPrecio,arrIngresoBruto,arrDescuento,arrTieneDescuento,arrTotal,
                       arrNumPlatosVendidos,arrCodPlatos, cantPlatos,
                       codPlato,precio,hayDescuento,descuento);
    }
}

void imprimir_encabezado(ofstream &ouput){
    int tam = TAMREPORTE/7;
    //imprimir titulo
    ouput<<setw(tam)<<left<<"CODIGO"
            <<setw(tam)<<left<<"CANTIDAD"
            <<setw(tam)<<left<<"PRECIO"
            <<setw(tam)<<left<<"INGRESO BRUTO"
            <<setw(tam)<<left<<"TIENE DESCUENTO"
            <<setw(tam)<<left<<"DESCUENTO"
            <<setw(tam)<<left<<"INGRESO TOTAL"<<endl;
    
    imprimir_linCar(ouput, '=');
}

void imprimir_reportePrueba(double *arrPrecio,double *arrIngresoBruto,double *arrDescuento,bool *arrTieneDescuento,double *arrTotal,
                         int *arrNumPlatosVendidos,int *arrCodPlatos, int cantPlatos){
    ofstream ouput;
    apertura_escritura("ReporteDePruebaDeCargaDeDatos.txt", ouput);
    ouput<<fixed<<setprecision(2);
    int tam = TAMREPORTE/7;
    imprimir_encabezado(ouput);
    
    for (int i=0;i<cantPlatos;i++){
        ouput<<setw(tam)<<left<<arrCodPlatos[i]
            <<setw(tam)<<left<<arrNumPlatosVendidos[i]
            <<setw(tam)<<left<<arrPrecio[i]
            <<setw(tam)<<left<<arrIngresoBruto[i]
            <<setw(tam)<<left<<arrTieneDescuento[i]
            <<setw(tam)<<left<<arrDescuento[i]
            <<setw(tam)<<left<<arrTotal[i]<<endl;
    }
    imprimir_linCar(ouput, '=');
}

void reemplazarGuion(char *nombrePlato){
    for(int i=0;nombrePlato[i];i++){
        if(nombrePlato[i] =='_') nombrePlato[i]=' ';
    }
}

void camelizarPlato(char* nombrePlato){
    for(int i=0;nombrePlato[i];i++){
        if(i>0 and nombrePlato[i-1]!=' ' and nombrePlato[i]>='A' and nombrePlato[i]<='Z') {
            nombrePlato[i] += 'a'-'A';
        }
    }
}

void FormatearNombre(char* nombrePlato,char* categoriaPlato,bool hayDescuento){
    char aux[MAXNOMBRE]{};
    my_strcpy(aux, nombrePlato);
    if(hayDescuento){
        my_strcat(aux,"-");
        my_strcat(aux,"PROMOCIONADO");
    }
    my_strcat(aux,"-");
    my_strcat(aux,categoriaPlato);
    my_strcpy(nombrePlato, aux);
}

void imprimir_titulo_centrado(ofstream &ouput, const char* titulo){
    int len = my_strleng(titulo);
    ouput<<setw((TAMREPORTE + len)/2)<<titulo<<endl;
}

void imprimir_titulos(ofstream &ouput){
    int tam=TAMREPORTE/9;
    imprimir_titulo_centrado(ouput,"EMPRESA DE REPARTOS A DOMICILIOS TP S.A.");
    imprimir_titulo_centrado(ouput,"RELACION DE PLATOS VENDIDOS");
    imprimir_linCar(ouput,'=');
    ouput<<setw(4*tam-3)<<left<<"No.  PLATO OFRECIDO"
         <<setw(tam+3)<<left<<"CANTIDAD VENDIDA"
         <<setw(tam)<<left<<"PRECIO"
         <<setw(tam)<<left<<"INGRESO BRUTO"
         <<setw(tam)<<left<<"DESCUENTO"
         <<setw(tam)<<left<<"TOTAL"<<endl;
    imprimir_linCar(ouput, '-');
}

void modificarCadena(char* nombrePlato,char* categoriaPlato,bool  hayDescuento){
    reemplazarGuion(nombrePlato);
    camelizarPlato(nombrePlato);
    FormatearNombre(nombrePlato,categoriaPlato,hayDescuento);
}

void imprimir_lineaReporte(double *arrPrecio,double *arrIngresoBruto,double *arrDescuento, double *arrTotal,int n,
                         int *arrNumPlatosVendidos,int *arrCodPlatos, char* nombrePlato,int cantPlatos,
                         ofstream &ouput, int posPlato){
    int tam=TAMREPORTE/9;
    ouput<<setw(3)<<setfill('0')<<right<<n<<setfill(' ')<<") "
            <<setw(6)<<left<<arrCodPlatos[posPlato];
    ouput<<setw(4*tam-11)<<left<<nombrePlato;
    ouput<<setw(tam)<<left<<arrNumPlatosVendidos[posPlato]
         <<setw(tam)<<left<<arrPrecio[posPlato]
         <<setw(tam)<<left<<arrIngresoBruto[posPlato]
         <<setw(tam)<<left<<arrDescuento[posPlato]
         <<setw(tam)<<left<<arrTotal[posPlato]<<endl;
} 

void imprimir_resumen(ofstream &ouput,double totalIngresoBruto,double montoTotalIngresos){
    int tam=TAMREPORTE/9;
    imprimir_linCar(ouput, '=');
    ouput<<setw(6*tam)<<left<<"TOTAL:";
    ouput<<setw(tam)<<totalIngresoBruto
    <<setw(tam)<<""<<setw(tam)<<left<<montoTotalIngresos<<endl;
}

void emitirReporte(double *arrPrecio,double *arrIngresoBruto,double *arrDescuento,bool *arrTieneDescuento,double *arrTotal,
                         int *arrNumPlatosVendidos,int *arrCodPlatos, int cantPlatos){
    ifstream inputPlatos;
    ofstream ouput;
    apertura_lectura("PlatosOfrecidos.txt", inputPlatos);
    apertura_escritura("reporte.txt", ouput);
    char nombrePlato[MAXNOMBRE]{}, categoriaPlato[MAXNOMBRE]{},c;
    int codPlato, n=1;
    double precio, descuento=0,totalIngresoBruto=0.0, montoTotalIngresos=0.0;
    bool hayDescuento;
    ouput<<fixed<<setprecision(2);
    imprimir_titulos(ouput);
    while(true){
        hayDescuento=false;
        inputPlatos>>codPlato;
        if(inputPlatos.eof()) break;
        inputPlatos>>nombrePlato>>precio>>categoriaPlato;
        if(inputPlatos.get() != '\n'){
            hayDescuento = true;
            inputPlatos>>descuento>>c;
        }
        int posPlato = busquedaBinaria(codPlato, arrCodPlatos, cantPlatos);
        if(posPlato != NO_ENCONTRADO){
           totalIngresoBruto += arrIngresoBruto[posPlato];
           montoTotalIngresos += arrTotal[posPlato];
            modificarCadena(nombrePlato,categoriaPlato,hayDescuento);
            imprimir_lineaReporte(arrPrecio,arrIngresoBruto,arrDescuento,arrTotal,n,
                        arrNumPlatosVendidos,arrCodPlatos,nombrePlato,cantPlatos,ouput,posPlato); 
        }
        n++;
    }
    imprimir_resumen(ouput,totalIngresoBruto,montoTotalIngresos);
}