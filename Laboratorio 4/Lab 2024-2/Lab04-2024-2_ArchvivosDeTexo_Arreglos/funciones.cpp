/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 4 de mayo de 2025, 15:53
 */



#include "funciones.hpp"
void apertura_lectura(const char* name,ifstream &input){
    input.open(name, ios::in);
    if(not input.is_open()){
        cout<<"ERROR: El archivo "<<name<<" no se abrio";
    }
    else cout <<name<<" Se leyo correctamente "<<endl;
}

void apertura_escritura(const char* name,ofstream &ouput){
    ouput.open(name, ios::out);
    if(not ouput.is_open()){
        cout<<"ERROR: El archivo "<<name<<" no se abrio";
    }
    else cout <<"Al archivo se abrio";
}

void ignorar(ifstream &input, char delimitador){
    input>>ws;
    while(input.get() != delimitador);
}

void imprimir_linCaracter(ofstream &ouput, char car){
    ouput<<setw(TAMREPORTE)<<setfill(car)<<""<<setfill(' ')<<endl;
}

void cargarDatosDePlatos(const char* namePlatos,int *ArrcodigoPlatos, double *ArrprecioPlatos,int &cantPlatos){
    ifstream inputPlatos;
    apertura_lectura(namePlatos,inputPlatos);
    
    int codigoPlato;
    while(true){
        inputPlatos>>codigoPlato;
        if(inputPlatos.eof()) break;
        
        if (cantPlatos >= PLATOSMAX) {
            cout << "ERROR: Se excedió el número máximo de platos permitidos." << endl;
            break;
        }
        
        ArrcodigoPlatos[cantPlatos] = codigoPlato;
        ignorar(inputPlatos, ' '); //ws incluido
        inputPlatos>>ArrprecioPlatos[cantPlatos];
        ignorar(inputPlatos, '\n');
        cantPlatos++;
    }
}

void obtenerLetra(ifstream &inputRepartos, char &letra){
    inputRepartos>>ws;
    char c;
    inputRepartos.get(letra);
    while(true){
        c = inputRepartos.get();
        if(c==' ')  break;
    }
}


void cargarDatosVehiculosyDistritos(const char* nameRepartos,char *ArrtipoVehiculo,int *ArrcodigoDistritos,int &cantRepartos){
   
    ifstream inputRepartos;
    apertura_lectura(nameRepartos, inputRepartos);
//    fixed<<setprecision(2);
    int codigoDistrito;
    while(true){
        inputRepartos>>codigoDistrito;
        if(inputRepartos.eof()) break;
        
        if (cantRepartos >= REPARTOSMAX) {
            cout << "ERROR: Se excedió el número máximo de repartos permitidos." << endl;
            break;
        }

        
        ArrcodigoDistritos[cantRepartos] = codigoDistrito;
        inputRepartos>>ArrtipoVehiculo[cantRepartos];
        ignorar(inputRepartos, '\n');
        cantRepartos++; 
    }
}

void leerImprimirNombre(ofstream &ouput, ifstream &inputRepartidores){
    inputRepartidores>>ws;
    char c;
    int cant=0;
    while(true){
        inputRepartidores.get(c);
        if(c==' ') break;
        if(c=='/') c=' ';
        if(c>='a' and c<='z') c = c- ('a' -'A');
        ouput.put(c);
        cant++;
    }
    for(int i=0; i<(TAMREPORTE/COLUMNAS)-cant;i++) ouput.put(' ');
}

//void ImprimirVehiyObtenerLetra(ofstream &ouput, ifstream &inputRepartidores, char &letra){
//    inputRepartidores>>ws;
//    char c;
//    int cant=1;
//    
//    inputRepartidores.get(letra);
//    ouput<<letra;
//    while(true){
//        inputRepartidores.get(c);
//        if(c==' ') break;
//        if(c>='a' and c<='z') c = c- ('a' -'A');
//        ouput.put(c);
//        cant++;
//    }
//    for(int i=0; i<((TAMREPORTE/COLUMNAS)-cant);i++) ouput.put(' ');
//}

void imprimirDistrito(ofstream &ouput, ifstream &inputRepartidores){
    inputRepartidores>>ws;
    char c, letra;
    int cant=0;
    while(true){
        inputRepartidores.get(c);
        if(c=='\n') break;
        
        ouput.put(c);
        cant++;
    }
    for(int i=0; i<((TAMREPORTE/COLUMNAS)/2 -cant);i++) ouput.put(' ');
}

void imprimir_nombre_cliente(ofstream &ouput, ifstream &inputRepartos){
    inputRepartos>>ws;
    char c;
    while(true){
        inputRepartos.get(c);
        if(c==']') break;
        ouput.put(c);
    }
}

double buscarPrecioPlato(int codigoPlato,int *ArrcodigoPlatos,double *ArrprecioPlatos, int cantPlatos){
//    double precio = -1;
    for(int i=0; i<cantPlatos;i++){
        if(codigoPlato == ArrcodigoPlatos[i]) return ArrprecioPlatos[i];
    }
    
//    return precio;
}

void procesarImprmirUnCliente(char vehiculo,int n_clientes,ifstream &inputRepartos, ofstream &ouput, double &pago_platos_por_cliente, double &pago_al_repartidor_por_cliente,
                                     int *ArrcodigoPlatos,double *ArrprecioPlatos,int cantPlatos){
    int Tam = (TAMREPORTE/3)*2, tam = Tam/COLUMNAS, n_platos=1;
    ouput<<setw(2)<<right<<setfill('0')<<n_clientes<<setfill(' ');
    imprimir_nombre_cliente(ouput, inputRepartos);
    ouput<<endl<<"PLATOS SOLICITADOS: "<<endl;
    ouput<<setw(3)<<""<<setw(tam)<<left<<"CODIGO"<<setw(tam)<<left<<"CANTIDAD"<<setw(tam)<<left<<"PRECIO"<<setw(tam)<<left<<"SUBTOTAL"<<endl;
    
    int cantidad_de_un_plato, codigoPlato;
    double precioPlato, subtotal, pago_repartidor_por_vehiculo, comision_por_vehiculo;
    char c;
    while(true){//de un solo plato
        inputRepartos>>cantidad_de_un_plato>> codigoPlato;
        c=inputRepartos.get();
        if(c == '\n') break;
        //aca empieza la comparacion de arreglos con datos leidos
        ouput<<right<<setw(2)<<setfill('0')<<n_platos<<" "<<setfill(' ');
        ouput<<setw(tam)<<left<<codigoPlato<<setw(tam)<<left<<cantidad_de_un_plato;
        precioPlato = buscarPrecioPlato(codigoPlato,ArrcodigoPlatos,ArrprecioPlatos, cantPlatos);
        subtotal = precioPlato * cantidad_de_un_plato;
        ouput<<setw(tam)<<left<<precioPlato<<setw(tam)<<left<<subtotal<<endl;
        pago_platos_por_cliente += subtotal;
        (vehiculo =='M')?(comision_por_vehiculo= 0.1):(comision_por_vehiculo=0.05);
        pago_repartidor_por_vehiculo = subtotal *comision_por_vehiculo;
        pago_al_repartidor_por_cliente += pago_repartidor_por_vehiculo;
        n_platos++;
    }
    
    
    
}

void procesar_clientes_por_repartidor(int codigoDistrito,char vehiculo,ifstream &inputRepartos,ofstream &ouput,
                                          int *ArrcodigoPlatos,double *ArrprecioPlatos, int cantPlatos, int cantRepartos,
                                          double &pago_platos_por_cliente, double &pago_al_repartidor_por_cliente){
    inputRepartos.clear();
    inputRepartos.seekg(0, ios::beg);
    int  n_clientes=1;
    int codDistrito;
    char letraVehiculo;
    bool repartidorTineneClientes=false;
    while(true){
        inputRepartos>>codDistrito;
        if(inputRepartos.eof())  break;
        
        inputRepartos>>letraVehiculo;
        if(codDistrito == codigoDistrito and letraVehiculo ==  vehiculo){
            procesarImprmirUnCliente(vehiculo,n_clientes,inputRepartos, ouput, pago_platos_por_cliente, pago_al_repartidor_por_cliente,
                                     ArrcodigoPlatos,/*ArrcodigoDistritos,*/ArrprecioPlatos,/*ArrtipoVehiculo,*/ cantPlatos);
            repartidorTineneClientes = true;
            n_clientes++;
            
            imprimir_linCaracter(ouput, '-');
//            imprimir_resumen_por_cliente(pago_platos_por_cliente, pago_al_repartidor_por_cliente, ouput);
                                     
        }else{
            ignorar(inputRepartos, '\n');
        }
    }
    
    if(not repartidorTineneClientes) ouput <<"EL REPARTIDOS NO TIENE PEDIDOS"<<endl;
}


void procesar_repartidores(ifstream &inputRepartos,ifstream &inputRepartidores,ofstream &ouput,double &totalPlatos,double &totalRepartidores, 
                           int *ArrcodigoPlatos,/* int* ArrcodigoDistritos,*/double *ArrprecioPlatos,/* char *ArrtipoVehiculo,*/
                            int cantPlatos, int cantRepartos){
    int n_repartidores=1;
    double pago_platos_por_cliente=0.0, pago_al_repartidor_por_cliente=0.0;
    char vehiculo;
    int dni, tam = TAMREPORTE/COLUMNAS, codigoDistrito;
    while(true){//para cada repartidor
        inputRepartidores>>dni;
        if(inputRepartidores.eof()) break;
        ouput<<right<<setw(2)<<setfill('0')<<n_repartidores<<setfill(' ')<<"  REPARRTIDOR:"<<endl;
        ouput<<setw(tam)<<left<<"NOMBRE"<<setw(tam)<<left<<"DNI"<<setw(tam)<<left<<"VEHICULO"<<setw(tam)<<left<<"DISTRITO A ATENDER"<<endl;
        leerImprimirNombre(ouput, inputRepartidores);
        obtenerLetra(inputRepartidores, vehiculo); 
        ouput<<setw(tam)<<left<<dni;
        (vehiculo=='B')?(ouput<<left<<setw(tam)<<"BICICLETA"):(ouput<<left<<setw(tam)<<"MOTOCICLETA");
        inputRepartidores>>codigoDistrito;
        ouput<<left<<setw(tam/4)<<codigoDistrito;
        imprimirDistrito(ouput, inputRepartidores);
        ouput<<endl;
        imprimir_linCaracter(ouput, '-');
        ouput<<"CLIENTES A ATENDER"<<endl;
        procesar_clientes_por_repartidor(codigoDistrito,vehiculo,inputRepartos,ouput,
                                          ArrcodigoPlatos,/*ArrcodigoDistritos,*/ArrprecioPlatos,/*ArrtipoVehiculo,*/ cantPlatos, cantRepartos,
                                          pago_platos_por_cliente, pago_al_repartidor_por_cliente);
        imprimir_linCaracter(ouput, '=');
        totalPlatos += pago_platos_por_cliente;
        totalRepartidores += pago_al_repartidor_por_cliente;
        n_repartidores++;
    }
}

void imprimir_prueba(int *ArrcodigoPlatos, double *ArrprecioPlatos, int cantPlatos,ofstream &prueba){
    for(int i=0; i<cantPlatos;i++){
        prueba<<setw(8)<<left<<ArrcodigoPlatos[i]<<setw(8)<<left<<ArrprecioPlatos[i]<<endl;
    }
}

void procesarImprimirRepartos(int *ArrcodigoPlatos, int* ArrcodigoDistritos,double *ArrprecioPlatos, char *ArrtipoVehiculo, int cantPlatos, int cantRepartos){
    //subtotal cant*precio
    ifstream inputRepartos, inputRepartidores;
    ofstream ouput, prueba;
    apertura_lectura("RepartosARealizar.txt", inputRepartos);
    apertura_lectura("Repartidores.txt", inputRepartidores);
    apertura_escritura("reporte.txt",ouput);
    apertura_escritura("prueba.txt",prueba);
    
    double totalPlatos=0.0, totalRepartidores=0.0;
    ouput<<fixed<<setprecision(2);
    imprimir_prueba(ArrcodigoPlatos, ArrprecioPlatos,cantPlatos, prueba);
//    imprimir_tiutlo(ouput);
    imprimir_linCaracter(ouput, '=');
    procesar_repartidores(inputRepartos,inputRepartidores,ouput,totalPlatos,totalRepartidores,ArrcodigoPlatos,ArrprecioPlatos, cantPlatos, cantRepartos);
//    imprimir_reporte(ouput, totalPlatos,totalReoartidores);
}
