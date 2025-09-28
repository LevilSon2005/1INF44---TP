/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 20 de junio de 2025, 16:24
 */

#include "Funciones.hpp"

//reservo espacio para 135 estructuras de infracciones, osea aprox 135 infracciones que van a tener sus campos por cada estructura;
void reservar_memoria_arrInfracciones(struct TablaDeInfracciones* &arrTablaDeInfracciones){
    arrTablaDeInfracciones = new struct TablaDeInfracciones [135]{};
}

void reservar_memoria_arrEmpresas(struct EmpresasRegistradas* &arrEmpresasRegistradas){
    arrEmpresasRegistradas = new struct EmpresasRegistradas [45]{};
}

void imprimir_titulo(ofstream &ouput, const char* titulo){
    ouput<<setw((TAMREPORTE+strlen(titulo))/2)<<titulo<<endl;
}

void imprimir_linC(ofstream &ouput, char del){
    ouput<<setw(TAMREPORTE)<<setfill(del)<<""<<setfill(' ')<<endl;
}

void apertura_lectura(ifstream &input, const char* name){
    input.open(name, ios::in);
    if(not input.is_open())
        cout<<"El archivo "<<name<< " no se abre"<<endl;
}

void imprimir_indice(ofstream &ouput, int num){
    ouput<<setw(2)<<right<<num<<") ";
}

void apertura_escritura(ofstream &ouput, const char* name){
    ouput.open(name, ios::out);
    if(not ouput.is_open())
        cout<<"El archivo "<<name<< " no se abre"<<endl;
    else
        cout<<"El reporte - "<<name<<" se abre"<<endl;
}

int leer_entero(ifstream &input){
    int dato;
    input>>dato;
    input.get();
    
    return dato;
}

double leer_double(ifstream &input){
    double dato;
    input>>dato;
    input.get();
    
    return dato;
}

char* leer_cadena(ifstream &input, char del){
    char* cadena;
    char buffer[200];
    
    input.getline(buffer, 200, del);
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    
    
    return cadena;
}

char* asignar_cadena(const char* buffer){
    char* cadena;
    
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    
    return cadena;
}

void leerTablaInfracciones(const char* name,struct TablaDeInfracciones* arrTablaDeInfracciones,int &cantInfracciones){
    ifstream input;
    apertura_lectura(input,name);
    
    char codigo[15]{};
    
    while(true){
        input.getline(codigo,15,',');
        if(input.eof()) break;
        arrTablaDeInfracciones[cantInfracciones].codigo = asignar_cadena(codigo);
        arrTablaDeInfracciones[cantInfracciones].multa = leer_double(input);
        arrTablaDeInfracciones[cantInfracciones].descripcion = leer_cadena(input, '\n');
        
        cantInfracciones++;
    }
}

void reservar_memoria_placas(char** &placas){
    placas = new char* [10]; //todas las placas que tiene una empresa
}

void toMayus(char* cadena){
    for(int i=0;cadena[i]; i++){
        if(cadena[i]!= ' ' and  cadena[i]>='a' and cadena[i]<='z') cadena[i] -= ('a'-'A');
    }
}

void leerEmpresasregistradas(const char* name,struct EmpresasRegistradas* arrEmpresasRegistradas,int &cantEmpresas){
    ifstream input;
    apertura_lectura(input, name);
    int dni;
    char* nombre;
    char* distrito;
    while(true){
        input>>dni;
        if(input.eof())break;
        input.get();
        nombre = leer_cadena(input, ',');
        distrito = leer_cadena(input, '\n');
        toMayus(nombre);
        toMayus(distrito);
        
        //ASIGNACION E INICIALIZACION
        arrEmpresasRegistradas[cantEmpresas].dni = dni;
        arrEmpresasRegistradas[cantEmpresas].nombre = asignar_cadena(nombre);
        arrEmpresasRegistradas[cantEmpresas].distrito= asignar_cadena(distrito);
        reservar_memoria_placas(arrEmpresasRegistradas[cantEmpresas].placas); //reserva de memoria para las placas
        arrEmpresasRegistradas[cantEmpresas].fechaDeInfraccion.fecha = 99999999;
        arrEmpresasRegistradas[cantEmpresas].fechaDePago.fecha = 0;
        cantEmpresas++;       
    }
}



int buscar(int dni,struct EmpresasRegistradas* arrEmpresasRegistradas, int cantEmpresas){
    for(int i=0;i<cantEmpresas;i++){
        if(dni == arrEmpresasRegistradas[i].dni) return i;
    }
    
    return NO_ENCONTRADO;
}


//placa tiene memoria reservada
//void completarDatosEmpresa( struct EmpresasRegistradas &empresa, char* placa){
//    //lenar arreglo de char**
//    
//    
//    empresa.numPlaca++;
//    //
//    
//}

void leerPlacasRegistradas(const char* name,struct EmpresasRegistradas* arrEmpresasRegistradas,int cantEmpresas){
    ifstream input;
    apertura_lectura(input, name);
    int dni, posEmpresa, cantPlacas=0;
    char* placa;
    placa = new char[10];
    while(true){
        input>>dni;
        if(input.eof()) break;
        input>>placa;
        posEmpresa = buscar(dni,arrEmpresasRegistradas, cantEmpresas);
        if(posEmpresa != NO_ENCONTRADO){//Llenar datos para UNA empresa
            
            cantPlacas=arrEmpresasRegistradas[posEmpresa].numPlaca;
            arrEmpresasRegistradas[posEmpresa].placas[cantPlacas] = asignar_cadena(placa);
            arrEmpresasRegistradas[posEmpresa].numPlaca++;
        }
    }
}

int leerFecha(ifstream &input){
    char c;
    int d,m,a;
    input>>d>>c>>m>>c>>a;
    return a*10000+m*100+d;
}

int  buscarEmpresa(char* placa, struct EmpresasRegistradas* arrEmpresasRegistradas, int cantEmpresas){
    for(int i=0;i<cantEmpresas;i++){
        for(int k=0;k<arrEmpresasRegistradas[i].numPlaca;k++){
            if (strcmp(arrEmpresasRegistradas[i].placas[k],placa)==0) return i;
        }
    }
    
    return NO_ENCONTRADO;
}

int buscarInfraccion(char* codInfraccion,struct TablaDeInfracciones* arrTablaDeInfracciones, int cantInfracciones){
    for(int i=0;i<cantInfracciones;i++){
        if(strcmp(arrTablaDeInfracciones[i].codigo, codInfraccion)==0)return i;
    }
    
    return NO_ENCONTRADO;
}

//COMPLETAR dd, mm, aa;
void completarFecha(struct Fecha &FechaPorCompletar, int fecha){
    int d, m,a;
    FechaPorCompletar.aa = fecha/10000;
    FechaPorCompletar.mm = (fecha/100)%100;
    FechaPorCompletar.dd = fecha%100;
}

void leerInfraccionesCometidas(const char* name,struct TablaDeInfracciones* arrTablaDeInfracciones,int cantInfracciones,
                             struct EmpresasRegistradas* arrEmpresasRegistradas,int cantEmpresas){
    ifstream input;
    apertura_lectura(input, name);
    int fecha=0, fecha_p=0,posEmpresa,posInf, precioInf;
    char* placa;
    char* codInfraccion;
    char hapagado;
    while(true){
        fecha = leerFecha(input);
        if(input.eof()) break;
        input.get();
        placa = leer_cadena(input, ',');
        codInfraccion = leer_cadena(input, ',');
        input.get(hapagado);
        if(input.get() != '\n'){ //para P
            fecha_p = leerFecha(input);
        }
        posEmpresa = buscarEmpresa(placa, arrEmpresasRegistradas, cantEmpresas);
        posInf = buscarInfraccion(codInfraccion, arrTablaDeInfracciones, cantInfracciones);
        
        if(posEmpresa != NO_ENCONTRADO and posInf != NO_ENCONTRADO){
            if(arrEmpresasRegistradas[posEmpresa].fechaDeInfraccion.fecha>fecha) arrEmpresasRegistradas[posEmpresa].fechaDeInfraccion.fecha = fecha;
            if(arrEmpresasRegistradas[posEmpresa].fechaDePago.fecha<fecha_p) arrEmpresasRegistradas[posEmpresa].fechaDePago.fecha=fecha_p;
            //para completar dd ,mm,aa;
            completarFecha(arrEmpresasRegistradas[posEmpresa].fechaDeInfraccion, arrEmpresasRegistradas[posEmpresa].fechaDeInfraccion.fecha);
            completarFecha(arrEmpresasRegistradas[posEmpresa].fechaDePago, arrEmpresasRegistradas[posEmpresa].fechaDePago.fecha);
            //
            precioInf = arrTablaDeInfracciones[posInf].multa;
            (hapagado=='P')?(arrEmpresasRegistradas[posEmpresa].totalPagado+=precioInf):(arrEmpresasRegistradas[posEmpresa].totalAdeudado+=precioInf);
            arrEmpresasRegistradas[posEmpresa].cantidadDeFaltas++;
        } 
    }
}

void intercambiarStruct(struct EmpresasRegistradas &a,struct EmpresasRegistradas &b){
    struct EmpresasRegistradas aux;
    aux=a;
    a=b;
    b=aux;
}  

void intercambiarStruct(struct TablaDeInfracciones &a,struct TablaDeInfracciones &b){
    struct TablaDeInfracciones aux;
    aux=a;
    a=b;
    b=aux;
}

void ordenarEmpresas(struct EmpresasRegistradas* arrEmpresasRegistradas,int cantEmpresas){
    for(int i=0;i<cantEmpresas-1;i++){
        for(int k=i+1;k<cantEmpresas;k++){
            if(strcmp(arrEmpresasRegistradas[i].distrito,arrEmpresasRegistradas[k].distrito)>0 or 
              strcmp(arrEmpresasRegistradas[i].distrito,arrEmpresasRegistradas[k].distrito)==0 and
              arrEmpresasRegistradas[i].fechaDeInfraccion.fecha<arrEmpresasRegistradas[k].fechaDeInfraccion.fecha){
                 intercambiarStruct(arrEmpresasRegistradas[i], arrEmpresasRegistradas[k]);   
            }
        }
    }
}

void ordenarInfracciones(struct TablaDeInfracciones* arrTablaDeInfracciones,int cantInfracciones){
    for(int i=0;i<cantInfracciones-1;i++){
        for(int k=i+1;k<cantInfracciones;k++){
            if(strcmp(arrTablaDeInfracciones[i].codigo, arrTablaDeInfracciones[k].codigo)<0){
                intercambiarStruct(arrTablaDeInfracciones[i], arrTablaDeInfracciones[k]);
            }
        }
    }
}

void imprimir_placas(ofstream &ouput, struct EmpresasRegistradas empresa, int cantPlacas){
    int cant=0;
    for(int i=0;i<cantPlacas;i++){
        if(i>0){
            ouput<<"/";
            cant++;
        }
        ouput<<empresa.placas[i];
    }
    ouput<<setw(60-(cant*9+8))<<"";
}

void imprimir_fecha(ofstream &ouput, struct Fecha fecha){
    ouput<<setfill('0')<<setw(2)<<right<<fecha.dd<<"/"<<setw(2)<<fecha.mm<<"/"<<fecha.aa<<setfill(' ')<<setw(4)<<"";
            
}

void  emitir_reporte(const char* name,struct TablaDeInfracciones* arrTablaDeInfracciones,int cantInfracciones,
                       struct EmpresasRegistradas* arrEmpresasRegistradas,int cantEmpresas){
    ofstream ouput;
    apertura_escritura(ouput, name);
    
    ouput<<fixed<<setprecision(2);
    for(int i=0;i<cantEmpresas;i++){
        imprimir_indice(ouput, i+1);
        ouput<<setw(15)<<left<<arrEmpresasRegistradas[i].dni
                <<setw(40)<<arrEmpresasRegistradas[i].nombre
                <<setw(30)<<arrEmpresasRegistradas[i].distrito;
        imprimir_placas(ouput, arrEmpresasRegistradas[i], arrEmpresasRegistradas[i].numPlaca);
        imprimir_fecha(ouput, arrEmpresasRegistradas[i].fechaDeInfraccion);
        imprimir_fecha(ouput, arrEmpresasRegistradas[i].fechaDePago);
        ouput<<setw(15)<<left<<arrEmpresasRegistradas[i].totalPagado
               <<setw(15)<<arrEmpresasRegistradas[i].totalAdeudado
                <<setw(5)<<arrEmpresasRegistradas[i].cantidadDeFaltas<<endl;
    }
    
   
}