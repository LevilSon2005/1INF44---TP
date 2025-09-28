/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 5 de julio de 2025, 18:28
 */

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

void leerLexicon(const char* name,struct Palabras* lexicon, int &cantLexicon){
    ifstream input;
    apertura_lectura(input, name);
    
    char* palabra;
    int polaridad;
    while(true){
        palabra = leer_cadena(input, ',');
        if(input.eof()) break;
        polaridad = leer_int(input);
        lexicon[cantLexicon].texto = asignar_cadena(palabra);
//        cout<<"lexicon: "<<lexicon[cantLexicon].texto<<endl;
        lexicon[cantLexicon].polaridad = polaridad;
        cantLexicon++;
    }
}

void leerPlatos(const char* name,struct Plato* platos, int &cantPlatos){
    ifstream input;
    apertura_lectura(input, name);
    
    char* codigo;
    
    while(true){
        codigo = leer_cadena(input, ',');
        if(input.eof()) break;
        platos[cantPlatos].codigo = asignar_cadena(codigo);
        platos[cantPlatos].nombre = leer_cadena(input, ',');
        platos[cantPlatos].precio = leer_double(input);
        platos[cantPlatos].cantidad =0;
//        cout<< platos[cantPlatos].nombre<<endl;
        cantPlatos++;
    }
}

int leer_hora(ifstream &input){
    int h,m;
    input>>h;
    input.get();
    input>>m;
    
    return (h*100+m);
}

double buscarPrecio(char* codPlato, struct Plato* platos, int cantPlatos){
    
    for(int i=0; i<cantPlatos;i++){
        if(strcmp(codPlato, platos[i].codigo)==0) return platos[i].precio;
    }    
    return 0;
}

int buscarcodPlato (char* codPlato, struct Plato* platos, int cantPlatos){
    for(int i=0; i<cantPlatos;i++){
        if(strcmp(codPlato, platos[i].codigo)==0) return i;
    }    
    return NO_ENCONTRADO;
}

void leerAtenciones(const char* name,struct Atencion* atenciones,int &cantAtenciones,
                   struct Plato* platos, int cantPlatos){
    ifstream input;
    apertura_lectura(input, name);
    char codigo[20];
    int numPedido, fecha, n_plato, cantidad_plato,posPlato;
    double precioPlato;
    while(true){
        input>>numPedido;
        if(input.eof()) break;
        atenciones[cantAtenciones].codigo = numPedido;
        atenciones[cantAtenciones].hora = leer_hora(input); //21:36 -> 2136
        //reservamos memoria para arreglo de platos y comentarios
        atenciones[cantAtenciones].platos_atendidos = new struct Plato[20]{};
        atenciones[cantAtenciones].comentarios =  new struct Comentario[20]{};
        while(true){
            if(input.get() == '\n') break;
            n_plato = atenciones[cantAtenciones].cantidad_platos;
            input>>codigo;
            input>>cantidad_plato;
            atenciones[cantAtenciones].platos_atendidos[n_plato].codigo = asignar_cadena(codigo);
            atenciones[cantAtenciones].platos_atendidos[n_plato].cantidad += cantidad_plato;
            posPlato = buscarcodPlato(atenciones[cantAtenciones].platos_atendidos[n_plato].codigo, platos, cantPlatos);
//            cout<<"posicion: "<<posPlato<<endl;
            
            if(posPlato != NO_ENCONTRADO){
                precioPlato = platos[posPlato].precio;
//                cout<<platos[posPlato].precio<<endl;
//                cout<<"-----"<<endl;
                atenciones[cantAtenciones].platos_atendidos[n_plato].precio = precioPlato;
                atenciones[cantAtenciones].platos_atendidos[n_plato].nombre = asignar_cadena(platos[posPlato].nombre);
                atenciones[cantAtenciones].total_ventas += atenciones[cantAtenciones].platos_atendidos[n_plato].cantidad * precioPlato;
                atenciones[cantAtenciones].cantidad_platos++; 
            }
            
        }
        cantAtenciones++;    
    }
}

int buscarCodAtencion(int codAtencion, struct Atencion* atenciones,int cantAtenciones){
    for(int i=0;i<cantAtenciones;i++){
        if(codAtencion == atenciones[i].codigo) return i;
    }
    return NO_ENCONTRADO;
}

void preprocesar(char* &comentario){
    int i,k=0;
    char* aux;
    aux = asignar_cadena(comentario);
    char nueva_cadena[200];
    //"Los platos estuvieron muy ricos y sabrosos, el pedido fue rapido. ¡Volveria seguramente!"
    for(i=0; aux[i];i++){
        if((aux[i]>='a' and aux[i]<='z') or (aux[i]>='A' and aux[i]<='Z') or (aux[i] == ' ')){
            if(aux[i]>='A' and aux[i]<='Z') aux[i] += 'a'-'A';
            nueva_cadena[k] = aux[i];
            k++;
        }
    }
    nueva_cadena[k] = '\0';
    
    strcpy(comentario, nueva_cadena);
}

int contarPalabras(char* comentario){
    int cant =0;
    for(int i=0;comentario[i];i++){
        if(comentario[i] ==' ') cant++;
    }
    return cant+1;
}

int  buscarInicio(char* comentario, int numPalabra){
    int current = 1;
    for( int i=0;comentario[i];i++){
        if(current == numPalabra) return i;
        if(comentario[i] == ' ') current++;
    }
}

int buscarFin(char* comentario, int start){
    int i;
    for(i=start;comentario[i];i++){
        //para la ultima la ultima palabra no cumple porque no entra por no encontrar el ' ', solo encuentra el fin 
        //de linea, asi que no entra al for
        if(comentario[i]==' ')return i;
    }
    //i queda con el indice del fin de linea, por eso se pone -1
    return i-1;
}

void sacarPalabra(char* comentario, int numPalabra, char* palabra){
    int k=0;
    char aux[50];
    int start = buscarInicio(comentario, numPalabra);
    int end = buscarFin(comentario, start);
    
    for(int i=start;i<end;i++){
        aux[k] = comentario[i];
        k++;
    }
    aux[k] = '\0';
    strcpy(palabra, aux);
}

int buscarPolaridad(char* palabra,struct Palabras* lexicon, int cantLexicon){
    for(int i=0;i<cantLexicon;i++){
        if(strcmp(lexicon[i].texto,palabra)==0){
//            cout<<"repeticion: "<<lexicon[i].texto<<"-"<<palabra<<endl;
            return lexicon[i].polaridad;
        }
    }
    return 0;
}

void completarCamposComentario(char* comentario, struct Comentario &struct_comentario,
                               struct Palabras* lexicon, int cantLexicon){
    char palabra[100];
    int cantidad_palabras, polaridad=0;
    
    cantidad_palabras = contarPalabras(comentario);
    
    for(int i=0;i<cantidad_palabras;i++){
        int n_palabra = struct_comentario.cantidad_palabras;
        sacarPalabra(comentario, i+1, palabra);
        struct_comentario.palabras[n_palabra].texto = asignar_cadena(palabra);
        polaridad = buscarPolaridad(palabra,lexicon, cantLexicon); //si la palabra no se encuentra se retorna cero
        struct_comentario.polaridad_total += polaridad;
        struct_comentario.cantidad_palabras++;
    }
    
    
}

void leerComentarios(const char* name,struct Atencion* atenciones,int cantAtenciones,
                    struct Palabras* lexicon, int cantLexicon){
    ifstream input;
    apertura_lectura(input, name);
    int codAtencion,posAtencion, n_comentario=0, n_palabra=0;
    char* comentario;
    while(true){
        codAtencion  = leer_int(input);
        if(input.eof()) break;
        comentario = leer_cadena(input,'\n');
        posAtencion = buscarCodAtencion(codAtencion, atenciones, cantAtenciones);
        if(posAtencion != NO_ENCONTRADO){
            n_comentario = atenciones[posAtencion].cantidad_comentarios;
            atenciones[posAtencion].comentarios[n_comentario].texto = asignar_cadena(comentario); //tal cual leido
            preprocesar(comentario); 
            atenciones[posAtencion].comentarios[n_comentario].pre_procesado = asignar_cadena(comentario);//pre-procesado
            completarCamposComentario(comentario, atenciones[posAtencion].comentarios[n_comentario],
                                      lexicon,cantLexicon);
//            cout<<comentario<<endl;
            atenciones[posAtencion].cantidad_comentarios++;
        }
    }
}

void imprimir_cabecera(ofstream &ouput, int codAtencion, int hora){
    int tam=TAMREPORTE/2;
    int h = hora/100;
    int m= hora%100;
    ouput<<"No.  ATENCION "<<setw(tam-strlen("No.  ATENCION "))<<left<<codAtencion
    <<"Atendido a las: ";
    ouput<<setfill('0')<<right<<setw(2)<<h<<":"<<setw(2)<<m<<setfill(' ');
    (hora<12)?(ouput<<" AM"):(ouput<<" PM");
    ouput<<endl;
    imprimir_linC(ouput, '-');
}

int calcularPolaridad(struct Atencion atencion){
    int polaridad=0;
    for(int i=0;i<atencion.cantidad_comentarios;i++){
        polaridad += atencion.comentarios[i].polaridad_total;
    }
    
    return polaridad;
}

void emitirReporte(const char* name,struct Palabras* lexicon, int cantLexicon,
                  struct Atencion* atenciones,int cantAtenciones){
    ofstream ouput;
    apertura_escritura(ouput, name);
    struct Plato* platos;
    int polaridad=0;
    imprimirTitulo(ouput, "EMPRESA DE REPARTOS A DOMICILIO TP S.A");
    imprimirTitulo(ouput, "RELACION DE ATENCIONES");
    imprimir_linC(ouput, '=');
    ouput<<fixed<<setprecision(2);
    for(int i=0;i<cantAtenciones;i++){
        imprimir_cabecera(ouput, atenciones[i].codigo, atenciones[i].hora);
        platos= atenciones[i].platos_atendidos;
        for(int k=0;k<atenciones[i].cantidad_platos;k++){
            ouput<<platos[k].codigo<<") "<<setw(50)<<left<<platos[k].nombre;
            ouput<<setw(10)<<platos[k].precio<<setw(10)<<platos[k].cantidad
                  <<setw(10)<<platos[k].cantidad*platos[k].precio<<endl;
        }
        polaridad = calcularPolaridad(atenciones[i]);
        ouput<<"Polaridad total de los comentarios:     "<<polaridad<<endl;
        imprimir_linC(ouput, '=');
    }
}