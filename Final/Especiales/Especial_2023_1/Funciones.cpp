/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 7 de julio de 2025, 0:14
 */

#include <random>

#include "Funciones.hpp"

void apertura_lectura(ifstream &input, const char* name){
    input.open(name, ios::in);
    if(not input.is_open()){
        cout<<"El archivo "<<name<<" no se abrio"<<endl;
    }
}

void apertura_escritura(ofstream &ouput, const char* name){
    ouput.open(name, ios::out);
    if(not ouput.is_open()){
        cout<<"El archivo "<<name<<" no se abrio"<<endl;
    }else
        cout<<"El reporte - "<<name<<" se abrio"<<endl;
}

void imprimirTitulo(ofstream &ouput, const char* titulo){
    ouput<<setw((TAMREPORTE + strlen(titulo))/2)<<titulo<<endl;
}

void imprimir_linC(ofstream &ouput, char c){
    ouput<<setfill(c)<<setw(TAMREPORTE)<<""<<setfill(' ')<<endl;
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

void inicializar_usuarios(struct ListaUsuario &lista_usuarios){
    lista_usuarios.inicio = nullptr;
}


struct Fecha leer_fecha(ifstream& input){
    struct Fecha fecha_retorno;
    int d,m,a;
    char c;
    
    input>>a>>c>>m>>c>>d;
    
    fecha_retorno.aa = a;
    fecha_retorno.mm = m;
    fecha_retorno.dd = d;
    fecha_retorno.fecha = a*10000+m*100+d;
    
    return fecha_retorno;
}

void insertarOrdenado(struct Usuario aux, struct ListaUsuario &lista_usuarios){
    struct NodoUsuario* new_nodo;
    struct NodoUsuario* recorrido = lista_usuarios.inicio;
    struct NodoUsuario* anterior = nullptr;
    
    new_nodo = new struct NodoUsuario;
    new_nodo->datoUsuario  = aux;
    new_nodo->siguiente = nullptr;
    
    while(recorrido){
        if(strcmp(recorrido->datoUsuario.nombre, aux.nombre)>0) break;
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    //lista vacia
    if(lista_usuarios.inicio == nullptr)lista_usuarios.inicio = new_nodo;
    else if(anterior ==  nullptr){ //si comienza al inicio
        new_nodo->siguiente = lista_usuarios.inicio;
        lista_usuarios.inicio = new_nodo;
    }else{//si pos generica o final
        anterior->siguiente = new_nodo;
        new_nodo->siguiente = recorrido;
    }
}

//54393647,Reyes Tang Edward ,V,13.00,XW06135,3/07/2023,VA35843,2/07/2023,QO90975,6/07/2023
void leerUsuarios(const char* name,struct ListaUsuario &lista_usuarios){
    inicializar_usuarios(lista_usuarios);
    ifstream input;
    apertura_lectura(input, name);
    struct Usuario aux;
    int dni,n_libro=0;
    while(true){
        dni= leer_int(input);
        if(input.eof()) break;
        aux.dni = dni;
        aux.nombre = leer_cadena(input, ',');
        aux.categoria = leer_char(input);
        aux.calificacion = leer_double(input);
        aux.libros = new struct LibrosEnSuPoder[6]{};
        aux.cantidad_libros=0;
        while(true){
            n_libro = aux.cantidad_libros;
            aux.libros[n_libro].codigoLibro = leer_cadena(input, ',');
            aux.libros[n_libro].fecha = leer_fecha(input);
            if(input.get()=='\n') break;
            aux.cantidad_libros++;
        }
        insertarOrdenado(aux, lista_usuarios);
    }
}

void imprimir_reporte_inicial(const char* name,struct ListaUsuario lista_usuarios){
    struct NodoUsuario* recorrido = lista_usuarios.inicio;
    ofstream ouput;
    apertura_escritura(ouput, name);
    int tam=TAMREPORTE/5;
    imprimirTitulo(ouput, "PRUEBA INCIAL DE LOS DATOS DEL ARCHIVO USUARIOS");
    imprimir_linC(ouput, '=');
    
    ouput<<fixed<<setprecision(2);
    while(recorrido){
        struct Usuario usuario = recorrido->datoUsuario;
        ouput<<"USUARIO: "<<usuario.dni<<" - "<<setw(50)<<left<<usuario.nombre
            <<"CATEGORIA: "<<setw(10)<<usuario.categoria
            <<"CALIFICACION: "<<setw(10)<<usuario.calificacion<<endl;
        
        imprimir_linC(ouput, '-');
        ouput<<"LIBROS PRESTADOS: "<<endl;
        for(int i=0;i < usuario.cantidad_libros;i++){
            struct LibrosEnSuPoder libro = usuario.libros[i];
            ouput<<i+1<<") "
                 <<setw(tam)<<left<<libro.codigoLibro
                 <<setw(tam)<<libro.fecha.fecha<<endl;
        }
        imprimir_linC(ouput, '=');
        recorrido = recorrido->siguiente;
    }
}

struct NodoUsuario* buscarDni(int dni,struct ListaUsuario lista_usuarios){
    struct NodoUsuario* recorrido = lista_usuarios.inicio;
    
    while(recorrido){
        if(dni == recorrido->datoUsuario.dni) return recorrido;
        recorrido = recorrido->siguiente;
    }
    
    return nullptr;
}


bool verificarSuMaximo(struct NodoUsuario* posUsuario){
    
    if(posUsuario->datoUsuario.categoria == 'D' 
            and posUsuario->datoUsuario.cantidad_libros>=6) return false;
    
    if(posUsuario->datoUsuario.categoria == 'A' 
            and posUsuario->datoUsuario.cantidad_libros>=4) return false;
    
    if(posUsuario->datoUsuario.categoria == 'V' 
            and posUsuario->datoUsuario.cantidad_libros>=2) return false;
}

bool verificarSiTieneLibro(char* codLibro,struct LibrosEnSuPoder* libros,
                    int cantidad_libros){
    for(int i=0;i<cantidad_libros;i++){
        if(strcmp(codLibro, libros[i].codigoLibro)==0) return true;
    }
    
    return false;
}

void descuentoCalificacion(struct NodoUsuario* posUsuario){
    double descuento;
    switch (posUsuario->datoUsuario.categoria){
        case 'D': descuento = 0.8;
        break;
        case 'A': descuento = 0.9;
        break;
        case 'V': descuento = 0.85;
        break;
    }
    
    posUsuario->datoUsuario.calificacion *= descuento;
}

void agregarLibro(char* codLibro,struct NodoUsuario* posUsuario){
    int n_libro = posUsuario->datoUsuario.cantidad_libros;
    posUsuario->datoUsuario.libros[n_libro].codigoLibro = asignar_cadena(codLibro);
    posUsuario->datoUsuario.libros[n_libro].fecha.fecha = 20233905;
    posUsuario->datoUsuario.cantidad_libros++;
}

void eliminarLibro(char* codLibro, struct NodoUsuario* posUsuario){
    int cantLibros = posUsuario->datoUsuario.cantidad_libros;
    for(int i=0;i<cantLibros;i++){
        if(strcmp(codLibro, posUsuario->datoUsuario.libros[i].codigoLibro)==0){
            posUsuario->datoUsuario.libros[i] = posUsuario->datoUsuario.libros[cantLibros-1];
        }
    }
    
    posUsuario->datoUsuario.cantidad_libros--;
}

void completarOperacion(char* codLibro,char tipoOperacion,struct NodoUsuario* posUsuario, 
                        struct ListaUsuario lista_usuarios){
    bool puedePedirPrestamo=true;
    bool yaTieneLibro;
    if(tipoOperacion == 'P'){//prestamo
        puedePedirPrestamo = verificarSuMaximo(posUsuario);
        if(puedePedirPrestamo){
            yaTieneLibro = verificarSiTieneLibro(codLibro,posUsuario->datoUsuario.libros,
                            posUsuario->datoUsuario.cantidad_libros);
            (yaTieneLibro)?(descuentoCalificacion(posUsuario)):(agregarLibro(codLibro,posUsuario));
        }else descuentoCalificacion(posUsuario); 
    }
    else{//devoucion
        //no tomare en cuenta el descuento por fecha porque no te dan la fecha de devolucion en el txt de prestamos
        eliminarLibro(codLibro, posUsuario);
    }
}

void leerPrestamos(const char* name,struct ListaUsuario lista_usuarios){
    ifstream input;
    apertura_lectura(input, name);
    struct NodoUsuario* posUsuario;
    char tipoOperacion , *codLibro;
    int dni;
    
    while(true){
        input>>tipoOperacion;
        if(input.eof()) break;
        input>>dni>>ws;
        codLibro = leer_cadena(input, '\n');
        posUsuario =  buscarDni(dni, lista_usuarios);
        if(posUsuario != nullptr){
            completarOperacion(codLibro,tipoOperacion,posUsuario, lista_usuarios);
        }
    }
}


