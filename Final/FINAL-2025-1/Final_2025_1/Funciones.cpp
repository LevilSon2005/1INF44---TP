/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 18 de julio de 2025, 19:15
 */

#include <string.h>

#include "Funciones.hpp"

void apertura_lectura(ifstream &input, const char* name){
    input.open(name,ios::in);
    if(not input.is_open())
       cout<<"El archivo "<< name <<"no se abrio"<<endl;
}

void apertura_escritura(ofstream &ouput, const char* name){
    ouput.open(name,ios::out);
    if(not ouput.is_open())
        cout<<"El archivo "<< name <<"no se abrio"<<endl;
    else
        cout<<"El reporte - "<<name<< " se abrio"<<endl;
}

void imprimir_titulo(ofstream& ouput, const char* titulo){
    ouput<<setw((TAMREPORTE + strlen(titulo))/2)<<titulo<<endl;
}

void imprimir_linC(ofstream &ouput, char c){
    ouput<<setfill(c)<<setw(TAMREPORTE)<<""<<setfill(' ')<<endl;
}

char* leer_cadena(ifstream &input, char del){
    char* cadena;
    char buffer[200];
    input.getline(buffer, 200, del);
    cadena =  new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

char* asignar_cadena(const char* buffer){
    char* cadena;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

int leer_int(ifstream &input){
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

char leer_char(ifstream &input){
    char dato;
    input>>dato;
    input.get();
    return dato;
}

void leerConductores(const char* name,struct Conductor* conductores, int &cantConductores){
    ifstream input;
    apertura_lectura(input, name);
    int dni;
    while(true){
        dni = leer_int(input);
        if(input.eof()) break;
        conductores[cantConductores].dni = dni;
        conductores[cantConductores].nombre = leer_cadena(input, ',');
        conductores[cantConductores].apellido = leer_cadena(input, ',');
        conductores[cantConductores].licencia = leer_cadena(input, '\n');
        conductores[cantConductores].cantidad_infracciones =0;
        conductores[cantConductores].infracciones = new Infraccion[10]{};
        conductores[cantConductores].vehiculo.dni_propietario =0;
        cantConductores++;        
    }
}

void imprimir_prueba_conductores(const char* name, struct Conductor* conductores, int cantConductores){
    ofstream ouput;
    apertura_escritura(ouput, name);
    int tam= TAMREPORTE/4;
    imprimir_titulo(ouput, "REPORTE DE PRUEBA DE CONDUCTORES");
    imprimir_linC(ouput, '=');
    
    for(int i=0;i<cantConductores;i++){
        ouput<<left<<setw(tam)<<conductores[i].dni
             <<setw(tam)<<conductores[i].nombre
             <<setw(tam)<<conductores[i].apellido
             <<setw(tam)<<conductores[i].licencia<<endl;
    }
}

void leerVehiculos(const char* name, struct Vehiculo* vehiculos, int &cantVehiculos){
    ifstream input;
    apertura_lectura(input, name);
    int dni;
    while(true){
        dni = leer_int(input);
        if(input.eof()) break;
        vehiculos[cantVehiculos].dni_propietario = dni;
        vehiculos[cantVehiculos].placa = leer_cadena(input, ',');
        vehiculos[cantVehiculos].marca_modelo  = leer_cadena(input, '\n');
        cantVehiculos++;
    }
}

void imprimir_prueba_vehiculos(const char* name, struct Vehiculo* vehiculos, int cantVehiculos){
    ofstream ouput;
    apertura_escritura(ouput, name);
    int tam=TAMREPORTE/3;
    
    imprimir_titulo(ouput, "REPORTE DE PRUEBA DE LOS CONDUCTORES");
    imprimir_linC(ouput, '=');
    ouput<<left<<setw(tam)<<"DNI"
            <<setw(tam)<<"PLACA"
            <<setw(tam)<<"MODELO"<<endl;
    imprimir_linC(ouput, '=');
    
    for(int i=0;i<cantVehiculos;i++){
        ouput<<left<<setw(tam)<<vehiculos[i].dni_propietario
            <<setw(tam)<<vehiculos[i].placa
            <<setw(tam)<<vehiculos[i].marca_modelo<<endl;
    }
}

struct Fecha leer_fecha(ifstream &input){
    struct Fecha fecha_retorno;
    int d,m,a;
    
    input>>d;
    input.get();
    input>>m;
    input.get();
    input>>a;
    input.get();
    
    fecha_retorno.aa = a;
    fecha_retorno.dd = d;
    fecha_retorno.mm = m;
    fecha_retorno.fecha = (a*10000+m*100+d);
    
    return fecha_retorno;
}

double modificarMonto(double &monto,char* codigo){
    if(codigo[0]=='C') monto = (monto*1.2);
    return monto;
}

//ORDENADO POR FECHAS
void leerInfracciones(const char* name, struct Infraccion* infracciones, int &cantInfracciones){
    ifstream input;
    apertura_lectura(input, name);
    int dni;
    double monto;
    while(true){
        dni=leer_int(input);
        if(input.eof()) break;
        infracciones[cantInfracciones].dni_conductor = dni;
        infracciones[cantInfracciones].fecha_infraccion = leer_fecha(input); //lee la coma
        infracciones[cantInfracciones].codigo = leer_cadena(input, ',');
        infracciones[cantInfracciones].descripcion = leer_cadena(input, ',');
        infracciones[cantInfracciones].gravedad = leer_cadena(input, ',');
        monto = leer_double(input);
        modificarMonto(monto,infracciones[cantInfracciones].codigo);
        infracciones[cantInfracciones].monto = monto;
        cantInfracciones++;
    }
}

void imprimir_fecha(ofstream& ouput, struct Fecha fecha, int tam){
    ouput<<setfill('0');
    ouput<<setw(2)<<right<<fecha.dd<<"/"
            <<setw(2)<<fecha.mm<<"/"
            <<setw(4)<<fecha.aa;
    ouput<<setfill(' ')<<setw(tam-10)<<"";
}

void imprimir_prueba_infracciones(const char* name, struct Infraccion* infracciones, int cantInfracciones){
    ofstream ouput;
    apertura_escritura(ouput, name);
    int tam=TAMREPORTE/6;
    imprimir_titulo(ouput, "REPORTE DE PRUBEA DE INFRACCIONES");
    imprimir_linC(ouput, '=');
    ouput<<left<<setw(tam)<<"DNI"
            <<setw(tam)<<"FECHA"
            <<setw(tam)<<"CODIGO"
            <<setw(tam)<<"DESCRIPCION"
            <<setw(tam)<<"GRAVEDAD"
            <<setw(tam)<<"MONTO"<<endl;
    
    for(int i=0;i<cantInfracciones;i++){
        ouput<<left<<setw(tam)<<infracciones[i].dni_conductor;
        imprimir_fecha(ouput, infracciones[i].fecha_infraccion, tam);
        ouput<<left<<setw(tam)<<infracciones[i].codigo
            <<setw(tam)<<infracciones[i].descripcion
            <<setw(tam)<<infracciones[i].gravedad
            <<setw(tam)<<infracciones[i].monto<<endl;
    }
}

int buscarDNI(int dni, struct Vehiculo* vehiculos, int cantVehiculos){
    for(int i=0;i<cantVehiculos;i++){
        if(dni == vehiculos[i].dni_propietario) return i;
    }
    return NO_ENCONTRADO;
}

void completar_datos_vehiculo(struct Vehiculo &vehiculo, struct Vehiculo vehiculo_dato){ //debe ir con &
    vehiculo.dni_propietario = vehiculo_dato.dni_propietario;
    vehiculo.marca_modelo = asignar_cadena(vehiculo_dato.marca_modelo);
    vehiculo.placa = asignar_cadena(vehiculo_dato.placa);
}

void completarInfracciones(struct Infraccion infraccion_conductor ,struct Infraccion infraccion_dato){
    infraccion_conductor.codigo = asignar_cadena(infraccion_dato.codigo);
    infraccion_conductor.descripcion = asignar_cadena(infraccion_dato.descripcion);
    infraccion_conductor.gravedad = asignar_cadena(infraccion_dato.gravedad);
    infraccion_conductor.fecha_infraccion = infraccion_dato.fecha_infraccion;
    infraccion_conductor.monto = infraccion_dato.monto;
    infraccion_conductor.dni_conductor = infraccion_dato.dni_conductor;
}

void busquedaInfracciones(struct Conductor &conductor, struct Infraccion* infracciones, int cantInfracciones){
    int n_infraccion=0;
    for(int i=0;i<cantInfracciones;i++){
        if(conductor.dni == infracciones[i].dni_conductor){
            n_infraccion = conductor.cantidad_infracciones;
            completarInfracciones(conductor.infracciones[n_infraccion], infracciones[i]);
            conductor.cantidad_infracciones++;
        }
    }
}

void actualizar_infracciones(struct Conductor* conductores, int cantConductores,
                            struct Vehiculo* vehiculos, int cantVehiculos,
                            struct Infraccion* infracciones, int cantInfracciones){
    int posVehiculo=0;
    for(int i=0;i<cantConductores;i++){
        posVehiculo = buscarDNI(conductores[i].dni, vehiculos, cantVehiculos);
        if(posVehiculo != NO_ENCONTRADO){
            completar_datos_vehiculo(conductores[i].vehiculo, vehiculos[posVehiculo]); //debe ir con &
            //aca falta completar las infracciones, SON MAS DE 1 INFRACCION
            busquedaInfracciones(conductores[i], infracciones, cantInfracciones);
        }
    }
}

void crearNombreArchivo(char* &name,struct Conductor conductor){ //FALTA MEMORIA
    char buffer[100];
    
    strcpy(buffer, "papeletas");
    strcat(buffer, "/");
    strcat(buffer, conductor.apellido);
    strcat(buffer, conductor.nombre);
    strcat(buffer, conductor.licencia);
    strcat(buffer, ".");
    strcat(buffer, "txt");
    
    name = new char[strlen(buffer)+1];
    strcpy(name, buffer);
}

void crear_reporte_infraccion(struct Conductor conductor, int n_infraccion){
    char* name;
    crearNombreArchivo(name, conductor); //FALTA MEMORIA
    
    ofstream ouput;
    ouput.open(name, ios::out);
    if(ouput.is_open()) cout<<"El archivo "<<name<<" se abrio"<<endl;
    
    
}

void imprimir_reportes(struct Conductor* conductores, int cantConductores){
    for(int i=0;i<cantConductores;i++){
        if(conductores[i].cantidad_infracciones != 0){
            for(int k=0;k<conductores[i].cantidad_infracciones;k++){
                crear_reporte_infraccion(conductores[i],k);
            }
        }
    }
}




