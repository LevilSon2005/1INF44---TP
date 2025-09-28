/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 7 de julio de 2025, 12:39
 */

#include <string.h>
#include <complex>

#include "Funciones.hpp"
#include "ListaAlumno.hpp"


void apertura_lectura(ifstream &input, const char* name){
    input.open(name,ios::in);
    if(not input.is_open())
        cout<<"El archivo "<<name<<" no se abre"<<endl;
}

void apertura_escritura(ofstream &ouput, const char* name){
    ouput.open(name,ios::out);
    if(not ouput.is_open())
        cout<<"El archivo "<<name<<" no se abre"<<endl;
    else
        cout<<"El reporte - "<<name<<" se abre"<<endl;
}

void imprimir_tiutlo(ofstream &ouput, const char* tiutlo){
    ouput<<setw((TAMREPORTE +strlen(tiutlo))/2)<<tiutlo<<endl;
}

void imprimir_linC(ofstream &ouput,  char c){
    ouput<<setfill(c)<<setw(TAMREPORTE)<<""<<setfill(' ')<<endl;
}

void imprimir_indice(ofstream &ouput, int indice){
    ouput<<setfill('0')<<setw(2)<<right<<indice<<") "<<setfill(' ');
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
    cadena =  new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

void ignorar(ifstream &input, char del){
    while(input.get() != del);
}


void inicializar_cursos(struct ListaCurso &lista_cursos){
    lista_cursos.inicio=nullptr;
    lista_cursos.final=nullptr;
    lista_cursos.cantCodPar = 0;
    lista_cursos.cantCodImpar = 0;
}

bool lista_curso_vacia(struct ListaCurso lista_cursos){
    return (lista_cursos.inicio == nullptr and lista_cursos.final ==  nullptr);
}

void insertarInicio(struct Curso aux, struct ListaCurso &lista_cursos){
    struct NodoCurso* new_nodo;
    
    new_nodo = new struct NodoCurso;
    new_nodo->datoCurso =  aux;
    new_nodo->siguiente =  nullptr;
    
    if(lista_curso_vacia(lista_cursos)){
        lista_cursos.inicio =  new_nodo;
        lista_cursos.final =  new_nodo;
    }else{
        new_nodo->siguiente = lista_cursos.inicio;
        lista_cursos.inicio =  new_nodo;
    }
    
}

void insertarFinal(struct Curso aux, struct ListaCurso &lista_cursos){
    struct NodoCurso* new_nodo;
    
    new_nodo = new struct NodoCurso;
    new_nodo->datoCurso =  aux;
    new_nodo->siguiente =  nullptr;
    
    if(lista_curso_vacia(lista_cursos)){
        lista_cursos.inicio =  new_nodo;
        lista_cursos.final =  new_nodo;
    }else{
        lista_cursos.final->siguiente = new_nodo;
        lista_cursos.final =  new_nodo;
    }
}

void leerCursos(const char* name, struct ListaCurso &lista_cursos){
    inicializar_cursos(lista_cursos);
    ifstream input;
    apertura_lectura(input, name);
    int codCurso;
    struct Curso aux;
    while(true){
        codCurso = leer_int(input);
        if(input.eof()) break;
        aux.codCurso = codCurso;
        aux.nombre = leer_cadena(input, ',');
        aux.creditos = leer_double(input);
        if(aux.codCurso%2==0){ //codigo par
            insertarInicio(aux, lista_cursos);
        }else{//codigo impar
            insertarFinal(aux, lista_cursos);
        }
    }     
}

void inicializar_escalas(struct ListaEscala &lista_escalas){
    lista_escalas.inicio = nullptr;
}

void insertar(struct Escala aux, struct ListaEscala &lista_escalas){
    struct NodoEscala* new_nodo;
    struct NodoEscala* recorrido = lista_escalas.inicio;
    
    new_nodo = new struct NodoEscala;
    new_nodo->datoEscala = aux;
    new_nodo->siguiente = nullptr;
    
    if(lista_escalas.inicio == nullptr) lista_escalas.inicio =  new_nodo;
    else{
        while(recorrido->siguiente != nullptr){
            recorrido = recorrido->siguiente;
        }
        recorrido->siguiente = new_nodo;
    }
}

void leerEscalas(const char* name, struct ListaEscala &lista_escalas){
    inicializar_escalas(lista_escalas);
    ifstream input;
    apertura_lectura(input, name);
    int anio, ciclo;
    struct Escala aux;
    while(true){
        anio = leer_int(input);
        if(input.eof()) break;
        ciclo = leer_int(input);
        aux.anho = anio;
        aux.ciclo = ciclo;
        aux.escala = leer_char(input);
        aux.valorCred = leer_double(input);
        insertar(aux, lista_escalas);   
    }
}


void inicializar_alumnos(struct ListaAlumno  &lista_alumnos){
    lista_alumnos.inicio =  nullptr;
}

void inicializar_campos(struct Alumno &aux){
    aux.escAlumno.anho =0;
    aux.escAlumno.ciclo =0;
    aux.escAlumno.valorCred =0.0;
    aux.cantidadCursos =0;
    aux.cursos = new struct Curso[8]{};
    aux.totalCreditos =0.0;
    aux.totalPago =0.0;
}

void insertarOrdenado(struct Alumno aux, struct ListaAlumno  &lista_alumnos){
    struct NodoAlumno* new_nodo;
    struct NodoAlumno* recorrido = lista_alumnos.inicio;
    struct NodoAlumno* anterior = nullptr;
    
    new_nodo = new struct NodoAlumno;
    new_nodo->datoAlumno = aux;
    new_nodo->siguiente = nullptr;
    
    if(lista_alumnos.inicio == nullptr) lista_alumnos.inicio = new_nodo; //lista vacia
    else if(anterior == nullptr) {//si se inserta al inicio
        new_nodo->siguiente = lista_alumnos.inicio;
        lista_alumnos.inicio =  new_nodo;
    }else{//posicion media o final
        anterior->siguiente = new_nodo;
        new_nodo->siguiente = recorrido;
    }
}

void leerAlumnos(const char* name, struct ListaAlumno  &lista_alumnos){
    inicializar_alumnos(lista_alumnos);
    ifstream input;
    apertura_lectura(input, name);
    struct Alumno aux{};
    int codAlumno;
    while(true){
        codAlumno = leer_int(input);
        if(input.eof()) break;
        aux.codAlumno = codAlumno;
        aux.nombre = leer_cadena(input, ',');
        aux.escAlumno.escala = leer_char(input);
        inicializar_campos(aux);
        insertarOrdenado(aux, lista_alumnos);
    }
}

int calcularCanCifras(int num){
    int cant=0;
    if(num==0) return 1;
    while(num>0){
        num = num/10;
        cant++;
    }
    
    return cant;
}

//si tiene memoria num_cad
void convertir_int_to_cadena(int num, char* num_cad){
    int cantCifras = calcularCanCifras(num);
    int cantAux, cifra;
    char cifra_cad[2]; //no olvidarse el '\0'
    cantAux = cantCifras;
    for(int i=0;i<cantCifras;i++){
        cifra = num/(int)pow(10,cantAux-1);
        cifra_cad[0] = '0' + cifra;
        cifra_cad[1] = '\0';
        (i==0)?(strcpy(num_cad, cifra_cad)):(strcat(num_cad, cifra_cad));
        num = num %(int)pow(10,cantAux-1);
        cantAux--;
    }
}

void formarNombreArch(char* name_arch, int ciclo, int anio){
    
    char anio_cad[6]{};
    char ciclo_cad[4]{};
    
    convertir_int_to_cadena(anio, anio_cad);
    convertir_int_to_cadena(ciclo, ciclo_cad);
    
    strcpy(name_arch, "ReporteFinalAlumnos");
    strcat(name_arch,"_");
    strcat(name_arch,anio_cad);
    strcat(name_arch,"_");
    strcat(name_arch,ciclo_cad);
    strcat(name_arch,".txt");
}

void imprimirCabecera(ofstream& ouput,struct Alumno alumno){
    int tam=TAMREPORTE/5;
    ouput<<"ALUMNO: "<<setw(tam-8)<<left<<alumno.codAlumno
            <<setw(2*tam)<<alumno.nombre
            <<"ESCALA: "<<setw(tam-8)<<alumno.escAlumno.escala
            <<"VALOR CREDITO: "<<setw(tam-15)<<alumno.escAlumno.valorCred<<endl;
    imprimir_linC(ouput, '-');
}

void imprimir_datos_alumnos(ofstream& ouput,struct ListaAlumno lista_alumnos){
    struct NodoAlumno* recorrido = lista_alumnos.inicio;
    while(recorrido){
        imprimirCabecera(ouput,recorrido->datoAlumno);
        recorrido = recorrido->siguiente;
    }
}

void emitir_reporte(int anio,int ciclo,struct ListaAlumno lista_alumnos){
    char* name_arch;
    name_arch = new char[100]{}; //YA TIENE MEMORIA
    char* titulo;
    ofstream ouput;
    
    if(ciclo==0 and anio==0){
        name_arch = asignar_cadena("ReporteInicialALumnos.txt");
        titulo = asignar_cadena("DETALLE DE PAGOS REALIZADO POR CICLO");
    }else{
        formarNombreArch(name_arch, ciclo, anio); //MEMORIAAA
        titulo = asignar_cadena("DETALLE PRELIMINAR DE ALUMNOS");
    }
    apertura_escritura(ouput, name_arch);
    imprimir_tiutlo(ouput, "INSTITUCION EDUCATIVA TP");
    imprimir_tiutlo(ouput, titulo);
//    if(ciclo !=0 and anio !=0) imprimirSemestre(ouput,anio, ciclo);
    imprimir_linC(ouput, '=');
    ouput<<fixed<<setprecision(2);
    imprimir_datos_alumnos(ouput, lista_alumnos);
}
