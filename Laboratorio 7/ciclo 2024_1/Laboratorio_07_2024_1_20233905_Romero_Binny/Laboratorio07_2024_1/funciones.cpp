/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 4 de junio de 2025, 14:36
 */

#include "funciones.hpp"


void apertura_lectura(ifstream &input, const char* name){
    input.open(name, ios::in);
    if(not input.is_open()){
        cout<<"El archivo "<<name<< " no se abrio"<<endl;
    }
}

void apertura_escritura(ofstream &ouput, const char* name){
    ouput.open(name, ios::out);
    if(not ouput.is_open()){
        cout<<"El archivo "<<name<< " no se abrio"<<endl;
    }
    else
        cout<<"El reporte se abrio"<<endl;
}

void imprimir_linC(ofstream &ouput, char c){
    ouput<<setw(TAMREPORTE)<<setfill(c)<<""<<setfill(' ')<<endl;
}

void SolicitarCodigosFacultades(char* codFacuPedida_1,char* codFacuPedida_2){
//    cout<<"Ingrese las dos facultades que desea que el programa analice: "<<endl;
//    cout<<"Ingrese el codigo de la primera facultad: ";
//    cin>>codFacuPedida_1;
//    cout<<"Ingrese el codigo de la segunda facultad: ";
//    cin>>codFacuPedida_2;
    strcpy(codFacuPedida_1,"FARQUITURB") ;
    strcpy(codFacuPedida_2,"EEGGCC") ;
}

int busquedaIndice(int codAlumno,int* arrCodigoAlumno, int cantAlumnos){
    
    for(int i=0;i<cantAlumnos;i++){
        if(arrCodigoAlumno[i] == codAlumno)return i;
    }
    
    return NO_ENCONTRADO;
}

void insertarAlumnoSinRepeticion(int codAlumno,double credCurso,int notaAlumno,
       int*arrCodigoAlumno,int*arrNumCursos,double*arrSumaPondearada,double*arrNumCreditos,int&cantAlumnos){
    int posAlumno;
    posAlumno=busquedaIndice(codAlumno, arrCodigoAlumno, cantAlumnos);
    if(posAlumno == NO_ENCONTRADO){
        arrCodigoAlumno[cantAlumnos] = codAlumno;
        arrNumCursos[cantAlumnos] = 1;
        arrSumaPondearada[cantAlumnos] = notaAlumno*credCurso;
        arrNumCreditos[cantAlumnos] = credCurso;
        cantAlumnos++;
    }
    else{
        arrNumCursos[posAlumno]++;
        arrSumaPondearada[posAlumno] += notaAlumno*credCurso;
        arrNumCreditos[posAlumno] += credCurso;
    }
}

//Insertar sin repeticion
void LeerCalificaciones(int*arrCodigoAlumno,int*arrNumCursos,double*arrSumaPondearada,double*arrNumCreditos,int&cantAlumnos){
    ifstream inputCalificaciones;
    apertura_lectura(inputCalificaciones, "Calificaciones.txt");
    char codCurso[NOMBRECURSO]{};
    int codAlumno, notaAlumno;
    double credCurso;
    
    while(true){
        inputCalificaciones>>codCurso;
        if(inputCalificaciones.eof()) break;
        inputCalificaciones>>credCurso;
        while(true){
            if(inputCalificaciones.get() == '\n') break;
            inputCalificaciones>>codAlumno>>notaAlumno;
            insertarAlumnoSinRepeticion(codAlumno,credCurso,notaAlumno,
                   arrCodigoAlumno, arrNumCursos,arrSumaPondearada,arrNumCreditos,cantAlumnos);
        }
    }
}

bool verificarSiEsFacultadPedida(char* facultad){
    if(strcmp(facultad, "EEGGCC")==0 or strcmp(facultad, "FARQUITURB")==0){
        return true;
    }
    else
        return false;
}

char* leer_cadena(ifstream &input, char del){
    char* cadena;
    char temporal[100];
    
    input.getline(temporal, 100, del);
    cadena = new char[strlen(temporal)+1];
    strcpy(cadena, temporal);
    
    return cadena;
}


void reservar_memoriaFija(char** arrAlumnos,int cantAlumnos){
    //reservo memoria para luego poder concatenar
    for(int i=0;i<cantAlumnos;i++){
        arrAlumnos[i] = new char[120];
    }
}



void llenar_arreglos(char**arrAlumnos,char**arrFacultad,int cantAlumnos,
                     char*nombre,char*facultad,int codigo,int* arrCodigoAlumno){
    int pos = busquedaIndice(codigo, arrCodigoAlumno, cantAlumnos);
    
    if(pos != NO_ENCONTRADO){
        arrAlumnos[pos] = nombre;
        arrFacultad[pos] = facultad;
//        cout<<"nombre: "<<arrAlumnos[pos]<<endl;
//        cout<<"facultad: "<<arrFacultad[pos]<<endl;
//        cout<<"pos: "<<pos<<endl;
    }
    else{
        arrAlumnos[pos] = new char[10];
        arrFacultad[pos] = new char[10];
        
    }
}

void LeerAlumnos(char**arrAlumnos,char**arrFacultad,int*arrCodigoAlumno,int cantAlumnos){
    ifstream input;
    apertura_lectura(input, "Alumnos.csv");
    int codigo;
    char* nombre;
    char* facultad;
    bool facultadPedida;
//    reservar_memoriaFija(arrAlumnos,cantAlumnos);
    while(true){
        input>>codigo;
        if(input.eof()) break;
        input.get();
        nombre = leer_cadena(input, ',');
        facultad = leer_cadena(input, '\n');
        facultadPedida = verificarSiEsFacultadPedida(facultad);
        if(facultadPedida){
            llenar_arreglos(arrAlumnos,arrFacultad,cantAlumnos,
                            nombre,facultad,codigo,arrCodigoAlumno);
        }
    }
}

void emitir_reporte(int*arrCodigoAlumno,char**arrAlumnos,int*arrNumCursos,
                    double*arrSumaPondearada,double*arrNumCreditos,char**arrFacultad,int cantAlumnos){
    ofstream ouput;
    apertura_escritura(ouput, "reporte.txt");
    int tam=TAMREPORTE/7;
    double promPonderado;
    bool facultadPedida; 
    for(int i=0;i<cantAlumnos;i++){
        facultadPedida = verificarSiEsFacultadPedida(arrFacultad[i]);
        cout<<"nombre: "<<arrAlumnos[i]<<endl;
        cout<<"facultad: "<<arrFacultad[i]<<endl;
        if(facultadPedida){
            promPonderado = arrSumaPondearada[i]/arrNumCursos[i];
            ouput<<arrCodigoAlumno[i]<<" - "<<setw(2*tam-11)<<left<<arrAlumnos[i]
             <<setw(tam)<<arrNumCursos[i]
             <<setw(tam)<<arrSumaPondearada[i]
             <<setw(tam)<<arrNumCreditos[i]
             <<setw(tam)<<promPonderado
             <<setw(tam)<<arrFacultad[i]<<endl;
        }
    }
}