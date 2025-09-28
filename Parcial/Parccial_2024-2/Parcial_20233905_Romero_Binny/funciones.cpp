/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 13 de mayo de 2025, 22:01
 */

#include "funciones.hpp"

void  apertura_lectura(const char* name,ifstream &input){
    input.open(name, ios::in);
    if(not input.is_open()){
        cout<<"ERROR: El archivo "<<name<<" no se abrio"<<endl;
    }
}

void  apertura_escritura(const char* name,ofstream &ouput){
    ouput.open(name, ios::out);
    if(not ouput.is_open()){
        cout<<"ERROR: El archivo "<<name<<" no se abrio"<<endl;
    }
    else{
        cout<<"el reporte se abrio"<<endl;
    }
}

void ignorar(ifstream &input, char delimitador){
    while(input.get() != delimitador);
}

void leer_imprimir_nombreCliente(ofstream &ouput, ifstream &inputClientes){
//    int cant;
    char c;
    
    while(true){
        c=inputClientes.get();
        if(c == ']') break;
        ouput.put(c);
//        cant++;
    }
    
    
}

void leer_imprimir_Distrito(ifstream &inputClientes,ofstream &ouput){
    char c;
    
    while(true){
        c=inputClientes.get();
        if(c == ' ') break;
        if(c == '_') c=' ';
        ouput.put(c);
//        cant++;
    }
}

void procesa_imprime_cabecera(int dniCliente,ifstream &inputClientes,ofstream &ouput,
                                int &codDistrito,char &tipoVeh,char &hayDesc,double &descuento, double &comision){
    char c;
    
    inputClientes>>ws;
    ouput<<"CLIENTE: "<<dniCliente<<" - ";
    leer_imprimir_nombreCliente(ouput, inputClientes);
    ouput<<"  DISTRITO:  ";
    inputClientes>>codDistrito>>ws;
    leer_imprimir_Distrito(inputClientes,ouput);
    inputClientes>>tipoVeh>>hayDesc;
    if (hayDesc == 'S') {
        inputClientes >> descuento>>c;
    } else {
        descuento = 0.0;
    }
    ouput<<"  TIPO DE VEHICULO: ";
    (tipoVeh == 'M')? ouput<<" Motocicleta  " : ouput<<" Bicicleta  ";
    (tipoVeh == 'M')? comision=0.1 : comision=0.05;
    ouput<<" DESCUENTO: "<<descuento<<"%"<<endl;
//    ignorar(inputClientes, '\n');
}

void imprimir_lin(ofstream &ouput, char c){
    ouput<<setw(TAMREPORTE)<<setfill(c)<<""<<setfill(' ')<<endl;
}



void buscar_imprimir_nombre_plato(ifstream &inputPlatos, ofstream &ouput){
    inputPlatos>>ws;
    int tam= TAMREPORTE/COLUMNAS+10, cant=0;
    char c;
    while(true){
        c=inputPlatos.get();
        if(c=='}') break;
        ouput.put(c);
        cant++;
    }
    for(int i=0; i<(tam+2-cant);i++) ouput.put(' ');
}

void  procesar_imprimir_plato(int n_plato,int numeroPedido,int cantPlato,int codPlato,ifstream &inputPlatos, ofstream &ouput,
                        double &precio, double &descuentoporPlato, double &subtotal){
    inputPlatos.clear();
    inputPlatos.seekg(0, ios::beg);
    subtotal=0.0;
    char c;
    double descuento;
    int codigoPlato, StockPlato, tam= TAMREPORTE/COLUMNAS;
    while(true){//para los datos de un plato
        inputPlatos>>codigoPlato;
        if(inputPlatos.eof()) break;
        if(codigoPlato == codPlato){
            ouput<<setw(4)<<""<<n_plato<<")"<<setw(2)<<""<<codPlato<<"-";
            buscar_imprimir_nombre_plato(inputPlatos, ouput);//ws dendtro
            inputPlatos>>precio>>StockPlato;
            c=inputPlatos.get();
            if(c != '\n') inputPlatos>>descuento>>c;
            subtotal = precio*cantPlato;
            descuentoporPlato = subtotal * ((double)descuento/100);
            ouput<<setw(tam-3)<<left<<cantPlato<<setw(tam)<<left<<precio<<setw(tam)<<left<<subtotal<<descuento<<"%"<<" - "<<descuentoporPlato<<endl;
        }
        else{
            ignorar(inputPlatos, '\n');
        }
        
    }
}

void actualizarResumenPorPlato(double comision,double precio,double descuento,double subtotal,int cantPlato,
                               double &totalPorUnPlatoSinDecuento,double &descuentoPorUnPlato,double &totalPagadoPorPlato,double &pagoRepartidorPorPlato){
    int pagoPlato ;
    totalPorUnPlatoSinDecuento += subtotal;
    descuentoPorUnPlato += descuento;
    pagoPlato = (subtotal - descuento);
    totalPagadoPorPlato += pagoPlato;
    pagoRepartidorPorPlato += (pagoPlato*comision);
}

void imprimir_resumen_por_plato(ofstream &ouput,double totalPorUnPlatoSinDecuento,double descuentoPorUnPlato,double descuentoCliente,double totalPagadoPorPlato,double pagoRepartidorPorPlato){
    int tam= TAMREPORTE/COLUMNAS+15;
    ouput<<setw(4)<<""<<setw(tam)<<left<<"TOTAL PEDIDO SIN DESCUENTO: "<<setw(6)<<right<<totalPorUnPlatoSinDecuento<<endl;
    ouput<<setw(4)<<""<<setw(tam)<<left<<"DECUENTO TOTAL POR PLATOS: "<<setw(6)<<right<<descuentoPorUnPlato<<endl;
    ouput<<setw(4)<<""<<setw(tam)<<left<<"DESCUENTO DEL CLIENTE: "<<setw(6)<<right<<descuentoCliente<<endl;
    ouput<<setw(4)<<""<<setw(tam)<<left<<"TOTAL PAGADO POR EL CLIENTE: "<<setw(6)<<right<<totalPagadoPorPlato<<endl;
    ouput<<setw(4)<<""<<setw(tam)<<left<<"PAGO AL REPARTIDOR: "<<setw(6)<<right<<pagoRepartidorPorPlato<<endl;
}

void actualizar_resumen_cliente(double &TotalRecaudadoClientes,double &TotalPagarRepartidores,double totalPagadoPorPlato,double pagoRepartidorPorPlato){
    TotalRecaudadoClientes += totalPagadoPorPlato;
    TotalPagarRepartidores += pagoRepartidorPorPlato;
}

void procesar_pedidos_de_Un_Cliente(double comision,int descuentoCliente,int dniCliente,ifstream &inputPlatos, ifstream &inputRepartidores, ifstream &inputRepartos,ofstream &ouput,
                                        double &TotalRecaudadoClientes,double &TotalPagarRepartidores){
    inputRepartos.clear();
    inputRepartos.seekg(0,ios::beg);
    int numeroPedido, dniRepartos, cantPlato, codPlato,n_plato, n_pedido=1,tam= TAMREPORTE/COLUMNAS;
    char c;
    double subtotal=0.0,precio,descuento,totalPorUnPlatoSinDecuento=0.0,descuentoPorUnPlato=0.0, totalPagadoPorPlato=0.0, pagoRepartidorPorPlato=0.0;
    while(true){//para cada pedido de un cliente
        inputRepartos>>numeroPedido;
        if(inputRepartos.eof()) break;
        inputRepartos>>dniRepartos;
        if(dniRepartos == dniCliente){
            n_plato=1;
            ouput<<setw(2)<<setfill('0')<<right<<n_pedido<<setfill(' ')<<")"<< setw(2)<<""<<"PEDIDO: "<<numeroPedido<<endl;
            ouput<<setw(4)<<""<<setw(8)<<""<<setw(tam+10)<<left<<"PLATO"<<setw(tam)<<left<<"CANTIDAD"<<setw(tam)<<left<<"PRECIO"<<setw(tam)<<left<<"SUBTOTAL"<<setw(tam)<<left<<"DESCUENTO"<<endl;
            while(true){//para un plato
                inputRepartos>>cantPlato>>codPlato;
                c= inputRepartos.get();
                if(c=='\n') break;
                procesar_imprimir_plato(n_plato,numeroPedido,cantPlato,codPlato,inputPlatos, ouput,precio, descuento,subtotal);
                actualizarResumenPorPlato(comision,precio,descuento,subtotal,cantPlato,
                                           totalPorUnPlatoSinDecuento,descuentoPorUnPlato,totalPagadoPorPlato,pagoRepartidorPorPlato);
                n_plato++;   
            }
            n_pedido++;
            imprimir_lin(ouput, '-');
            imprimir_resumen_por_plato(ouput,totalPorUnPlatoSinDecuento,descuentoPorUnPlato,descuentoCliente,totalPagadoPorPlato,pagoRepartidorPorPlato);
            imprimir_lin(ouput, '-');
        }
        else{
            ignorar(inputRepartos, '\n');
        }
        actualizar_resumen_cliente(TotalRecaudadoClientes,TotalPagarRepartidores,totalPagadoPorPlato,pagoRepartidorPorPlato);
    }
}

void imprimir_nombre(ifstream &inputRepartidores, ofstream &ouput){
    inputRepartidores>>ws;
    char c;
    while(true){
        c= inputRepartidores.get();
        if(c=='\n') break;
        if(c=='_') c=' ';
        ouput.put(c);
    }
}

void BusquedaImpresionRepartidor(int codDistrito,char tipoVeh,ifstream &inputRepartidores,ofstream &ouput,double TotalRecaudadoClientes,double TotalPagarRepartidores){
    inputRepartidores.clear();
    inputRepartidores.seekg(0,ios::beg);
    int dniRepartidor, codigoDistrito;
    char Vehiculo;
    while(true){
        inputRepartidores>>dniRepartidor;
        if(inputRepartidores.eof()) break;
        inputRepartidores>>ws;
        Vehiculo = inputRepartidores.get();
        ignorar(inputRepartidores, ' ');
        inputRepartidores>>codigoDistrito;
        if(tipoVeh == Vehiculo and codigoDistrito==codDistrito ){
            ouput<<"MONTO TOAL PAGADO POR EL CLIENTE:      "<<TotalRecaudadoClientes<<endl;
            ouput<<"REPARTIDOR:  "<<dniRepartidor<<" - ";
            imprimir_nombre(inputRepartidores, ouput);
            ouput<<setw(2)<<""<<"PAGO TOTAL: "<<TotalPagarRepartidores<<endl;
            imprimir_lin(ouput, '=');
        }
        else{
            ignorar(inputRepartidores, '\n');
        }        
    }
}

void  procesar_clientes(ifstream &inputClientes, ifstream &inputPlatos, ifstream &inputRepartidores, ifstream &inputRepartos,ofstream &ouput,
                        double &TotalRecaudadoClientes,double &TotalPagarRepartidores){
    //90367684   CORONEL CHUMPITAZ HELI]   8594   Villa_Maria_del_Triunfo   M   S   13.04%
    int dniCliente, codDistrito, n_cliente=1;
    char tipoVeh, hayDesc;
    double descuentoCliente;
    //para cliente
    double montoTotalPorCliente=0.0, pagoRepartidorPorCleinte=0.0, comision;
    int codRepartidor;
    while(true){//para cada cliente
        inputClientes>>dniCliente;
        if(inputClientes.eof()) break;
        procesa_imprime_cabecera(dniCliente,inputClientes,ouput,
                                codDistrito,tipoVeh,hayDesc,descuentoCliente,comision);
        imprimir_lin(ouput, '-');
        ouput<<"REPARTOS: "<<endl;
        imprimir_lin(ouput, '-');
        procesar_pedidos_de_Un_Cliente(comision,descuentoCliente,dniCliente,inputPlatos, inputRepartidores, inputRepartos,ouput,
                                        TotalRecaudadoClientes,TotalPagarRepartidores);
        n_cliente++;
        BusquedaImpresionRepartidor(codDistrito,tipoVeh,inputRepartidores,ouput,TotalRecaudadoClientes,TotalPagarRepartidores);
        
         //    actualizar_reporteGeneral(TotalRecaudadoClientes,TotalPagarRepartidores,montoTotalPorCliente,pagoRepartidorPorCleinte);
    } 
}

void  Leer_procesar_clientes(const char* nameClientes, const char* namePlatos, const char* nameRepartidores, const char* nameRepartos, const char* nameReporte){
    ifstream inputClientes, inputPlatos, inputRepartidores, inputRepartos;
    ofstream ouput;
    
    double TotalRecaudadoClientes=0.0, TotalPagarRepartidores=0.0;
    
    apertura_lectura(nameClientes,inputClientes);
    apertura_lectura(namePlatos,inputPlatos);
    apertura_lectura(nameRepartidores,inputRepartidores);
    apertura_lectura(nameRepartos,inputRepartos);
    apertura_escritura(nameReporte,ouput);
    
    ouput<<fixed<<setprecision(2);
    procesar_clientes(inputClientes, inputPlatos, inputRepartidores, inputRepartos,ouput,
                        TotalRecaudadoClientes,TotalPagarRepartidores);
//    imprimir_reporte(TotalRecaudadoClientes,TotalPagarRepartidore)
}
