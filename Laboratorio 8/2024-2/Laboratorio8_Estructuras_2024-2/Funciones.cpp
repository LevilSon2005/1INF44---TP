/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 13 de junio de 2025, 15:19
 */

#include <cinttypes>

#include "Funciones.hpp"
#include "Plato.hpp"
#include "Distrito.hpp"
#include "Cliente.hpp"


void apertura_lectura(ifstream &input, const char* name){
    input.open(name, ios::in);
    if(not input.is_open()){
        cout <<"El archivo "<<name<<" no se abrio"<<endl;
    }
}

void apertura_escritura(ofstream &ouput, const char* name){
    ouput.open(name, ios::out);
    if(not ouput.is_open()){
        cout <<"El archivo "<<name<<"no se abrio"<<endl;
    }
    else
        cout <<"El reporte - "<<name<<"se abrio"<<endl;
}

void imprimir_titulo(ofstream &ouput, const char*  titulo){
    ouput<<setw((TAMREPORTE+ strlen(titulo))/2)<<titulo<<endl;
}

void imprimir_linC(ofstream &ouput, char c){
    ouput<<setw(TAMREPORTE)<<setfill(c)<<""<<setfill(' ')<<endl;
    
}

char* leer_cadena(ifstream &input, char del){
    char* cadena;
    char temporal[100];
    
    input.getline(temporal, 100, del);
    cadena=new char[strlen(temporal)+1];
    strcpy(cadena, temporal);
    
    return cadena;
}

char* asignar_cadena(const char* buffer){
    char* cadena;
    
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    
    return cadena;
}

void leerPlatosOfrecidos(const char* name,struct Plato* arrPlatos,int &cantPlatos){
    ifstream input;
    apertura_lectura(input, name);
    
    char codigo[15];
    
    while(true){
        input.getline(codigo, 15, ',');
        if(input.eof()) break;
        arrPlatos[cantPlatos].codigo = asignar_cadena(codigo);//le paso la direccion de memoria con el espacio reservado
        arrPlatos[cantPlatos].descripcion = leer_cadena(input, ',');
        input>>arrPlatos[cantPlatos].precio;
        input.get();
        arrPlatos[cantPlatos].categoria = leer_cadena(input, '\n');
        cantPlatos++;
    }
}

void leerDistritosDeLima(const char* name,struct Distrito* arrDistritos,int &cantDistritos){
    ifstream input;
    apertura_lectura(input, name);
    
    char codigo[50];
    
    while(true){
        input.getline(codigo, 50, ',');
        if(input.eof()) break;
        arrDistritos[cantDistritos].codigo = asignar_cadena(codigo);
        arrDistritos[cantDistritos].nombre=leer_cadena(input, ',');
        arrDistritos[cantDistritos].ubicacion = leer_cadena(input, '\n');
        cantDistritos++;
    }
    
}

void leerClientes(const char* name,struct Cliente* arrClientes, int &cantClientes){
    ifstream input;
    apertura_lectura(input, name);
    int dni;
    while(true){
        input>>dni;
        if(input.eof()) break;
        input.get();
        arrClientes[cantClientes].dni = dni;
        arrClientes[cantClientes].nombre =leer_cadena(input, ',');
        arrClientes[cantClientes].distrito.codigo = leer_cadena(input, '\n');
        cantClientes++;
    }
}

void imprimir_prueba_distrito(const char* name,struct Distrito* arrDistritos,int cantDistritos){
    ofstream ouput;
    apertura_escritura(ouput, name);
     int tam=TAMREPORTE/3; 
   
    imprimir_titulo(ouput, "REPORTE DE DISTRITOS");
    imprimir_linC(ouput, '=');
    
    
    ouput<<setw(tam)<<left<<"CODIGO"
            <<setw(tam)<<"NOMBRE"
            <<setw(tam)<<"UBICACION"<<endl;
    imprimir_linC(ouput, '-');
    for(int i=0;i<cantDistritos;i++){
        ouput<<setw(tam)<<left<<arrDistritos[i].codigo
                <<setw(tam)<<left<<arrDistritos[i].nombre
                <<setw(tam)<<left<<arrDistritos[i].ubicacion<<endl;
    }
}

void imprimir_prueba_Platos(const char* name,struct Plato* arrPlatos,int cantPlatos){
    ofstream ouput;
    apertura_escritura(ouput, name);
     int tam=TAMREPORTE/4; 
   
    imprimir_titulo(ouput, "REPORTE DE PLATOS OFRECIDOS");
    imprimir_linC(ouput, '=');
    
    ouput<<fixed<<setprecision(2);
    ouput<<setw(tam)<<left<<"CODIGO"
            <<setw(tam)<<"DESCRIPCION"
            <<setw(tam)<<"PRECIO"
            <<setw(tam)<<"CATEGORIA"<<endl;
    imprimir_linC(ouput, '-');
    for(int i=0;i<cantPlatos;i++){
        ouput<<setw(tam)<<left<<arrPlatos[i].codigo
                <<setw(tam)<<left<<arrPlatos[i].descripcion
                <<setw(tam)<<left<<arrPlatos[i].precio
                <<setw(tam)<<left<<arrPlatos[i].categoria<<endl;
    }
}

void imprimir_prueba_Clientes(const char* name,struct Cliente* arrClientes,int cantClientes){
    ofstream ouput;
    apertura_escritura(ouput, name);
    int tam=TAMREPORTE/3; 
   
    imprimir_titulo(ouput, "REPORTE DE CLIENTES");
    imprimir_linC(ouput, '=');
    
    ouput<<setw(tam)<<left<<"DNI"
            <<setw(tam)<<"NOMBRE"
            <<setw(tam)<<"CODIGO DEL DISTRITO"<<endl;
    imprimir_linC(ouput, '-');
    for(int i=0;i<cantClientes;i++){
        ouput<<setw(tam)<<left<<arrClientes[i].dni
                <<setw(tam)<<left<<arrClientes[i].nombre
                <<setw(tam)<<left<<arrClientes[i].distrito.codigo<<endl;
    }
}


int buscar_distrito(char* codDistrito,struct Distrito*arrDistritos,int cantDistritos){
    
    for(int i=0;i<cantDistritos;i++){
        if(strcmp(codDistrito,arrDistritos[i].codigo)==0) return i;
    }
    
    return NO_ENCONTRADO;
}

int buscar_dni(int dni,struct Cliente*arrClientes,int cantClientes){
    
    for(int i=0;i<cantClientes;i++){
        if(dni == arrClientes[i].dni) return i;
    }
    
    return NO_ENCONTRADO;
}

int buscar_plato(char* codPlato,struct Plato* arrPlatos,int cantPlatos){
    for(int i=0;i<cantPlatos;i++){
        if(strcmp(codPlato,arrPlatos[i].codigo)==0) return i;
    }
    
    return NO_ENCONTRADO;
}

void completarArreglosClientes(int codPedido,int dni,char* codPlato,int cantidadPedDeUnPlato,
                                struct Distrito* arrDistritos,int cantDistritos,
                                struct Plato* arrPlatos,int cantPlatos,
                                struct Cliente* arrClientes,int cantClientes){
    int cantPedidos;
    int posCliente=buscar_dni(dni,arrClientes,cantClientes);
    if(posCliente != NO_ENCONTRADO){
        int posDistrito = buscar_distrito(arrClientes[posCliente].distrito.codigo,arrDistritos,cantDistritos);
        int posPlato = buscar_plato(codPlato,arrPlatos,cantPlatos);
        if(posDistrito != NO_ENCONTRADO and posPlato != NO_ENCONTRADO){
            arrClientes[posCliente].distrito.nombre = arrDistritos[posDistrito].nombre;
            //llenar el arreglo de platos pedidos
            cantPedidos = arrClientes[posCliente].cantidadDePedidos;

            arrClientes[posCliente].pedidos[cantPedidos].codigoPedido = codPedido;
            arrClientes[posCliente].pedidos[cantPedidos].codigoPlato = asignar_cadena(codPlato);
            
//            cout<<arrClientes[posCliente].pedidos[cantPedidos].codigoPlato<<endl;
            
            arrClientes[posCliente].pedidos[cantPedidos].descripcion = asignar_cadena(arrPlatos[posPlato].descripcion);
            arrClientes[posCliente].pedidos[cantPedidos].cantidad = cantidadPedDeUnPlato;
            arrClientes[posCliente].pedidos[cantPedidos].precio = arrPlatos[posPlato].precio;
            double subtotal = arrPlatos[posPlato].precio * cantidadPedDeUnPlato;
            arrClientes[posCliente].pedidos[cantPedidos].subtotal = subtotal;
            //
            arrClientes[posCliente].montoTotal += subtotal; 
            arrClientes[posCliente].cantidadDePedidos ++;
        }
    }
}

void leerPedidosRealizados(const char* name,struct Distrito* arrDistritos,int cantDistritos,
                          struct Plato* arrPlatos,int cantPlatos,
                          struct Cliente* arrClientes,int cantClientes){
    ifstream input;
    apertura_lectura(input, name);
    
    int codPedido, dni, cantidadPedDeUnPlato;
    char codPlato[10];
    while(true){
        input>>codPedido;
        if(input.eof())  break;
        input>>dni;
        input>>codPlato;
        input>>cantidadPedDeUnPlato;
        cout<<codPlato<<endl;
        completarArreglosClientes(codPedido,dni,codPlato,cantidadPedDeUnPlato,
                                arrDistritos,cantDistritos,
                                arrPlatos,cantPlatos,
                                arrClientes,cantClientes);
    }
}

void cambiar_int(int&a, int&b){
    int aux;
    aux=a;
    a=b;
    b=aux;
}

void cambiar_double(double&a, double&b){
    double aux;
    aux=a;
    a=b;
    b=aux;
}

void cambiar_cadena(char*&a, char*&b){
    char* aux;
    aux=a;
    a=b;
    b=aux;
}

void cambiar_struct(struct Cliente&a, struct Cliente&b){
    struct Cliente aux;
    aux=a;
    a=b;
    b=aux;
}


void cambiar_structPlatPed(struct PlatoPedido&a, struct PlatoPedido&b){
    struct PlatoPedido aux;
    aux=a;
    a=b;
    b=aux;
}


void ordenar(struct Cliente* arrClientes,int cantClientes){
    for(int i=0;i<cantClientes-1;i++){
        for(int k=i+1;k<cantClientes;k++){
            if(strcmp(arrClientes[i].nombre, arrClientes[k].nombre)>0){
                cambiar_struct(arrClientes[i], arrClientes[k]);
            }
        }
    }
}

void ordenar_PlatosPedidos(struct PlatoPedido* pedidos, int cantPedidos){
    for(int i=0;i<cantPedidos-1;i++){
        for(int k=i+1;k<cantPedidos;k++){
            if(strcmp(pedidos[i].codigoPlato, pedidos[k].codigoPlato)<0){
                cambiar_structPlatPed(pedidos[i], pedidos[k]);
            }
        }
    }
}

void ordenar_Platos(struct Cliente* arrClientes,int cantClientes){
    for(int i=0;i<cantClientes;i++){
       ordenar_PlatosPedidos(arrClientes[i].pedidos, arrClientes[i].cantidadDePedidos);
    }
}

void  imprimir_platoPedido(const struct PlatoPedido &Pedido, ofstream &ouput, int n_pedido){
    ouput<<fixed<<setprecision(2);
    ouput<<setw(12)<<""<<setw(3)<<setfill('0')<<n_pedido<<setfill(' ')
                    <<setw(10)<<Pedido.codigoPedido
                    <<setw(10)<<Pedido.codigoPlato
                    <<setw(50)<<Pedido.descripcion
                    <<setw(10)<<Pedido.precio
                    <<setw(12)<<Pedido.cantidad
                    <<setw(8)<<Pedido.subtotal<<endl;
}

void imprimir_reporte(const char* name,struct Cliente*arrClientes,int cantClientes){
    ofstream ouput;
    apertura_escritura(ouput, name);
    imprimir_titulo(ouput, "EMPRESA DE REPARTOS A DOMICILIO TP S. A.");
    imprimir_titulo(ouput, "RELACION DE PEDIDOS DEL CLIENTE");
    imprimir_linC(ouput, '=');
    for(int i=0;i<cantClientes;i++){
        if(arrClientes[i].distrito.nombre != nullptr){
           ouput<<"CLIENTE No. "<<setw(3)<<right<<setfill('0')<<i+1<<setfill(' ')<<endl;
            ouput<<setw(12)<<left<<"DNI"
                    <<setw(30)<<"NOMBRE"
                    <<setw(30)<<"DISTRITO"
                    <<setw(10)<<"PAGO TOTAL"<<endl;
            ouput<<setw(12)<<arrClientes[i].dni
                    <<setw(30)<<arrClientes[i].nombre
                    <<setw(10)<<arrClientes[i].distrito.codigo
                    <<setw(20)<<arrClientes[i].distrito.nombre
                    <<setw(10)<<arrClientes[i].montoTotal<<endl;
            imprimir_linC(ouput, '-');
            ouput<<setw(12)<<""<<"PEDIDOS REALIZADOS"<<endl;
                ouput<<setw(12)<<""<<setw(4)<<"No. "
                        <<setw(10)<<"PEDIDOS"
                        <<setw(10)<<"CODIGO"
                        <<setw(49)<<"DESCRIPCION"
                        <<setw(8)<<"PRECIO"
                        <<setw(12)<<"CANTIDAD"
                        <<setw(8)<<"SUBTOTAL"<<endl;
            for(int k=0;k<arrClientes[i].cantidadDePedidos;k++){
                imprimir_platoPedido(arrClientes[i].pedidos[k], ouput,k+1);
            }
            imprimir_linC(ouput, '='); 
        }
        
    }
}


