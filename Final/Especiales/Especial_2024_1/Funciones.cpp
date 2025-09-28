/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 5 de julio de 2025, 12:14
 */

#include "Funciones.hpp"
#include "ListaLibro.hpp"

void apertura_lectura(ifstream &input, const char* name){
    input.open(name, ios::in);
    if( not input.is_open())
        cout<<"El archivo"<<name<<"no se abre"<<endl;
}

void apertura_ecritura(ofstream &ouput, const char* name){
    ouput.open(name, ios::out);
    if( not ouput.is_open())
        cout<<"El reporte - "<<name<<"se abre"<<endl;
}

void ignorar(ifstream &input, char del){
    while(input.get() != del);
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

void imprimir_titulo(ofstream &ouput, const char* titulo){
    ouput<<setw((TAMREPORTE + strlen(titulo))/2)<<titulo<<endl;
}

void imprimir_linC(ofstream &ouput, char c){
    ouput<<setfill(c)<<setw(TAMREPORTE)<<""<<setfill(' ')<<endl;
}

void inicializar_listaCliente(struct ListaCliente &lista_cliente){
    lista_cliente.inicio =  nullptr;
}

bool listaClienteVacia(struct ListaCliente l){
    return (l.inicio == nullptr);
}

void insertar(struct Cliente c,struct ListaCliente &lista_cliente){
    struct NodoCliente* new_nodo;
    
    new_nodo  = new struct NodoCliente;
    new_nodo->datoCliente =  c;
    new_nodo->siguiente = nullptr;
    
    if(listaClienteVacia(lista_cliente)) lista_cliente.inicio = new_nodo;
    else{
        new_nodo->siguiente = lista_cliente.inicio;
        lista_cliente.inicio = new_nodo;
    }
}

void leerClientes(const char* name, struct ListaCliente &lista_cliente){
    inicializar_listaCliente(lista_cliente);
    ifstream input;
    apertura_lectura(input, name);
    struct Cliente c;
    int dni;
    while(true){
        dni = leer_int(input);
        if(input.eof()) break;
        c.nombre = leer_cadena(input, '\n');
        c.dni = dni;
        c.montoComprado =0,0;
        c.descuentoFuturo =0.0;
        insertar(c,lista_cliente);
    }
}

void imprimir_prueba_cliente(const char* name, struct ListaCliente lista_cliente){
    struct NodoCliente* recorrido = lista_cliente.inicio;
    ofstream ouput;
    apertura_ecritura(ouput, name);
    int tam= TAMREPORTE/7;
    
    imprimir_titulo(ouput, "REPORTE DE PRUEBA INICIAL DE LOS DATOS DE LOS CLIENTES");
    imprimir_linC(ouput, '=');
    
    ouput<<setw(tam)<<"";
    ouput<<left<<setw(tam)<<"DNI"
            <<setw(3*tam-5)<<"NOMBRE"
            <<setw(tam)<<"MONTO COMPRADO"
            <<setw(tam)<<"DESCUENTO FUTURO"<<endl;
    
    imprimir_linC(ouput, '=');
    ouput<<fixed<<setprecision(2);
    while(recorrido){
        ouput<<setw(tam)<<"";
        ouput<<left<<setw(tam)<<recorrido->datoCliente.dni
            <<setw(3*tam)<<recorrido->datoCliente.nombre
            <<setw(tam)<<recorrido->datoCliente.montoComprado
            <<setw(tam)<<recorrido->datoCliente.descuentoFuturo<<endl;
        recorrido =  recorrido->siguiente;
    }
}

void inicializar_listaLibro(struct ListaLibro &lista_libros){
    lista_libros.inicio =  nullptr;
    lista_libros.final = nullptr;
    lista_libros.cantLibroBarato =0;
    lista_libros.cantLibroCaro =0;
}

void inicializamos(struct Libro &l){
    l.librerias = new struct Libreria [5]{};
    //tambien inicializamos el arreglo de ventas;
    for(int i=0;i<5;i++){
        l.librerias[i].ventas = new struct Venta[10]{};
        l.librerias[i].cantidadVentas = 0;
    }
    l.cantidadLibrerias =0;
    l.totalVentas =0.0;
    l.unidadesVendidas =0;
    l.cantidadBuenasCalificaciones =0;
    l.sumaBuenasCalificaciones =0.0;
    l.cantidadMalasCalificaciones =0;
    l.sumaMalasCalificaciones =0.0;
}

void leerLibros(const char* name, struct ListaLibro &lista_libros){
    inicializar_listaLibro(lista_libros);
    ifstream input;
    apertura_lectura(input, name);
    
    struct Libro l;
    char* codLibro;
    
    while(true){
        codLibro = leer_cadena(input, ',');
        if(input.eof()) break;
        l.codigo = asignar_cadena(codLibro);
        l.titulo = leer_cadena(input, ',');
        l.autor = leer_cadena(input, ',');
        l.precio = leer_double(input);
        inicializamos(l);
        if(l.precio <100){ //LIBRO BARATO
            insertarInicio(l, lista_libros);
        }else{//LIBRO CARO
            insertarFinal(l, lista_libros);
        }
    }
    
}

bool listaLibroVacia(struct ListaLibro l){
    return (l.inicio == nullptr and l.final == nullptr);
}

void insertarInicio(struct Libro libro, struct ListaLibro &lista_libros){
    struct NodoLibro* new_nodo;
    
    new_nodo = new struct NodoLibro;
    new_nodo->datoLibro = libro;
    new_nodo->siguiente = nullptr;
    
    if(listaLibroVacia(lista_libros)){
        lista_libros.inicio = new_nodo;
        lista_libros.final =  new_nodo;
    }else{
        new_nodo->siguiente =  lista_libros.inicio;
        lista_libros.inicio = new_nodo;
    }
    lista_libros.cantLibroBarato++;
}

void insertarFinal(struct Libro libro, struct ListaLibro &lista_libros){
    struct NodoLibro* new_nodo;
    
    new_nodo = new struct NodoLibro;
    new_nodo->datoLibro = libro;
    new_nodo->siguiente = nullptr;
    
    if(listaLibroVacia(lista_libros)){
        lista_libros.inicio = new_nodo;
        lista_libros.final =  new_nodo;
    }else{
        lista_libros.final->siguiente =  new_nodo;
        lista_libros.final = new_nodo;
    }
    lista_libros.cantLibroCaro++;
}

void imprimir_prueba_libro(const char* name, struct ListaLibro lista_libros){
    struct NodoLibro* recorrido =  lista_libros.inicio;
    ofstream ouput;
    apertura_ecritura(ouput, name);
    int tam= (TAMREPORTE+100)/13;
    imprimir_titulo(ouput, "REPORTE DE PRUEBA INICIAL DE LOS DATOS DE LOS LIBROS");
    imprimir_linC(ouput, '=');
    ouput<<left<<setw(tam)<<"CODIGO"
            <<setw(3*tam)<<"TITULO"
            <<setw(2*tam)<<"AUTOR"
            <<setw(tam)<<"PRECIO"
            <<setw(tam)<<"TOTAL VENTAS"
            <<setw(tam)<<"UNIDADES VENDIDAS"
            <<setw(tam)<<"CANT BUENAS CALIF"
            <<setw(tam)<<"SUMA MALAS CALIF"
            <<setw(tam)<<"CANT MALAS CALIF"
            <<setw(tam)<<"SUMAS MALAS CALIF"<<endl;
    imprimir_linC(ouput, '=');
    ouput<<fixed<<setprecision(2);
    while(recorrido){
        ouput<<left<<setw(tam)<<recorrido->datoLibro.codigo
            <<setw(3*tam)<<recorrido->datoLibro.titulo
            <<setw(2*tam)<<recorrido->datoLibro.autor
            <<setw(tam)<<recorrido->datoLibro.precio
            <<setw(tam)<<recorrido->datoLibro.totalVentas
            <<setw(tam)<<recorrido->datoLibro.unidadesVendidas
            <<setw(tam)<<recorrido->datoLibro.cantidadBuenasCalificaciones
            <<setw(tam)<<recorrido->datoLibro.sumaBuenasCalificaciones
            <<setw(tam)<<recorrido->datoLibro.cantidadMalasCalificaciones
            <<setw(tam)<<recorrido->datoLibro.sumaMalasCalificaciones<<endl;
        recorrido =  recorrido->siguiente;
    }
}

int leer_fecha(ifstream &input){
    int d,m,a;
    
    input>>d;
    input.get();
    input>>m;
    input.get();
    input>>a;
    
    return a*10000+m*100+d;
}

struct NodoCliente* buscarDni(int dni, const struct ListaCliente &lista_cliente){
    struct NodoCliente* recorrido = lista_cliente.inicio;
    
    while(recorrido){
        if(dni == recorrido->datoCliente.dni) return recorrido;
        recorrido = recorrido->siguiente;
    }
    return nullptr;
}

struct NodoLibro* buscarCodLibro(char* codLibro,const struct ListaLibro &lista_libros){
    struct NodoCliente* recorrido = lista_libros.inicio;
    
    while(recorrido){
        if(strcmp(codLibro, recorrido->datoCliente.nombre)==0) return recorrido;
        recorrido = recorrido->siguiente;
    }
    return nullptr;
}

int buscarCodLibreria(int codLibreria, struct Libreria* librerias, int cantLibrerias){
    for(int i=0;i<cantLibrerias;i++){
        if(codLibreria == librerias[i].codigo)return i;
    }
    return NO_ENCONTRADO;
}

void leerVenta(const char* name, struct ListaCliente &lista_cliente, struct ListaLibro &lista_libros){
    ifstream input;
    apertura_lectura(input, name);
    struct Libro posLibro;
    struct Cliente posCliente;
    bool buenaCalificacion = false;
    int codLibreria, fecha, dni, calificacion, n_libreria =0, posLibreria=0;
    double precioLibro=0.0;
    char codLibro[15];
    
    while(true){
        input>>codLibreria;
        if(input.eof()) break;
        fecha = leer_fecha(input);
        while(true){
            if(input.get() == '\n') break;
            input>>codLibro;
            input>>dni>>calificacion;
            if(calificacion >50) buenaCalificacion = true;
            posCliente =  buscarDni(dni, lista_cliente)->datoCliente;
            posLibro = buscarCodLibro(codLibro, lista_libros)->datoLibro;
            if(posLibro != nullptr and posCliente != nullptr){
                precioLibro = posLibro.precio;
                posLibreria = buscarCodLibreria(codLibreria, posLibro.librerias,posLibro.cantidadLibrerias);
                if(posLibreria != NO_ENCONTRADO){//primera vez de la libreria
                    n_libreria = posLibro.cantidadLibrerias;
//                    inicializar_datos_libreria(posLibro.librerias[n_libreria], n_libreria,
//                                              precioLibro,codLibreria,dni,fecha,calificacion);
                    posLibro.totalVentas = precioLibro;
                    posLibro.unidadesVendidas =1;
                    posLibro.cantidadLibrerias++;
                }else{//solo se actualizan los datos de la libreria
                    posLibro.cantidadLibrerias++;
//                    actualizar_datos_libreria(posLibro.librerias[n_libreria],
//                                            precioLibro,dni,fecha,calificacion);
                    posLibro.totalVentas += precioLibro;
                    posLibro.unidadesVendidas++;
                }
                if(buenaCalificacion){
                    posLibro.cantidadBuenasCalificaciones++;
                    posLibro.sumaBuenasCalificaciones += calificacion;
                }else{
                    posLibro.cantidadMalasCalificaciones ++;
                    posLibro.sumaMalasCalificaciones += calificacion;
                }
            }
        }
    }
}