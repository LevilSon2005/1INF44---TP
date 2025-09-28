/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 17 de abril de 2025, 16:26
 */

#include "Funciones.hpp"

void apertura_lectura(ifstream &input, const char* name_arch){
    input.open(name_arch, ios::in);
    if(not input.is_open()){
        cout<<"ERROR: El archivo "<<name_arch<<" no se puede abrir. "<<endl;
        exit(1);
    }
}

void apertura_escritura(ofstream &ouput, const char* name_arch){
    ouput.open(name_arch, ios::out);
    if(not ouput.is_open()){
        cout<<"ERROR: El archivo "<<name_arch<<" no se puede abrir. "<<endl;
        exit(1);
    }
    else{
        cout<<"El archivo se ha creado correctamente";
    }
}

void imprimpir_titulo(int d_i,int m_i, int a_i,int d_f, int m_f, int a_f, ofstream &ouput_reporte){
    ouput_reporte<<setw((TAM_MAX + TITULO1)/2)<<"MINISTERIO DE TRASNPORTE"<<endl;
    ouput_reporte<<setw((TAM_MAX + TITULO2)/2)<<"MULTAS IMPUESTAS A LAS COMPANIAS"<<endl;
    ouput_reporte<<setw((TAM_MAX - TITULO3) /2)<<""<<"RANGO DE FECHAS A CONSULTAR: DEL "<<d_i<<"/"<<setw(2)<<setfill('0')<<m_i<<"/"<<a_i<<" AL "<<d_f<<"/"<<setw(2)<<setfill('0')<<m_f<<"/"<<a_f<<endl;
    
}

void imprimir_lin_caracter(char c, ofstream &ouput_reporte){
    ouput_reporte<<setw(TAM_MAX)<<setfill(c)<<""<<endl;
    ouput_reporte<<setfill(' ');
}

void Leer_imprimir_nombre(ifstream &input_infracciones, int &cant, ofstream &ouput_reporte){
    cant = 0;
    input_infracciones>>ws;
    char c;
    while (true){
        c = input_infracciones.get();
      if(c == ' ' or c=='\n') return;  
      if(c == '/' or c=='-' or c=='_') c = ' '; 
      if(c >= 'a' and c <= 'z'){
          c = c - ('a' - 'A');
      }
      ouput_reporte<<c;
      cant++;
    }
    
}

void imprimir_header(ifstream &input_infracciones, ofstream &ouput_reporte){
    //incluidos titulos de columnas
    int tam= TAM_MAX/2;
//    while(input_infracciones.get() != '\n');//decartar hasta el salto de linea
    ouput_reporte<<"Vehículos Infractores"<<endl;
    ouput_reporte<<setw(tam)<<""<<setw((tam + INCREMENTOS) /2)<<"INCREMENTOS"<<endl;
    ouput_reporte<<setw(TAM_MAX/COLUMNAS)<<left<<"TIPO";
    ouput_reporte<<setw(TAM_MAX/COLUMNAS)<<left<<"PLACA";
    ouput_reporte<<setw(TAM_MAX/COLUMNAS)<<left<<"MARCA";
    ouput_reporte<<setw(TAM_MAX/COLUMNAS)<<left<<"MODELO";
    ouput_reporte<<setw(TAM_MAX/COLUMNAS)<<left<<"COLOR";
    ouput_reporte<<setw(TAM_MAX/COLUMNAS)<<left<<"FECHA";
    ouput_reporte<<setw(TAM_MAX/COLUMNAS)<<left<<"HORA";
    ouput_reporte<<setw(TAM_MAX/COLUMNAS)<<left<<"GRAVEDAD";
    ouput_reporte<<setw(TAM_MAX/COLUMNAS)<<left<<"MULTA";
    ouput_reporte<<setw(TAM_MAX/COLUMNAS)<<left<<"POR TIPO";
    ouput_reporte<<setw(TAM_MAX/COLUMNAS)<<left<<"POR FECHA";
    ouput_reporte<<setw(TAM_MAX/COLUMNAS)<<left<<"POR HORA";
    ouput_reporte<<setw(TAM_MAX/COLUMNAS)<<left<<"TOTAL A PAGAR"<<endl;
    
}

void busqueda_impresion_empresa(ifstream &input_empresas,ofstream &ouput_reporte, int tam, int dni){
    int dni_empresa, cant2;
    input_empresas.clear();
    input_empresas.seekg(0, ios::beg);
    
       while(true){
        input_empresas>>dni_empresa;
        
        if(input_empresas.eof()) {
            ouput_reporte<<"NO HAY EMPRESA"<<endl;
            return;
        }
        if(dni == dni_empresa){
            input_empresas>>ws;
            while(input_empresas.get() != ' '); //SALTA HASTA QUE ENCUENTRES UN ESPACIO
            ouput_reporte<<"EMPRESA: ";
            Leer_imprimir_nombre(input_empresas, cant2,ouput_reporte);
            ouput_reporte<<setw(tam -9 -cant2)<<""<<endl;
            return;
        }
        else{
            input_empresas.ignore(180, '\n');;
            continue;
        }
    } 
}

void leer_imprimir_caractVehic(ifstream &input_vehiculos,ofstream &ouput_reporte, int&n){
    char c;
    
    //posiblemente falte el ws
    n=0;
    while(true){
        c=input_vehiculos.get();
        if(c=='\n' or c==' ') break;
        ouput_reporte.put(c);
        n++;
    }
}

void busqueda_impresion_caractVehic(char tipo,int placa_1, int placa_2,ifstream &input_vehiculos,ofstream &ouput_reporte){
    char tipo_arch, guion;
    int placa1_arch,placa2_arch, n, tam=TAM_MAX/COLUMNAS;
    input_vehiculos.clear();
    input_vehiculos.seekg(0, ios::beg);
    while(true){
        input_vehiculos>>tipo_arch;
        if(input_vehiculos.eof()) break;
        input_vehiculos>>placa1_arch>>guion>>placa2_arch;
        if(tipo_arch == tipo and placa1_arch == placa_1 and placa2_arch==placa_2){
            input_vehiculos>>ws;
            for(int i=1; i<=3; i++){
                leer_imprimir_caractVehic(input_vehiculos, ouput_reporte, n); 
//                if(i==3){
//                   ouput_reporte<<setw(tam-n)<<""<<endl; 
//                }
//                else{
                  ouput_reporte<<setw(tam-n)<<"";  
//                }
            }
        }
        else{
            input_vehiculos.ignore(180, '\n');
            continue;
        }
    }
}

int transformar_fecha(int d, int m, int a){
    return a*10000 + m*100 +d;
}

void imprimir_incrementos(ofstream &ouput_reporte, int tipo,int hora,int fecha_i, int fecha_f, double multa, int fecha, double &pago_total_vehiculo){
    double multa_fecha, multa_hora, multa_tipo;
    if(tipo=='P') multa_tipo = multa * D_PEQUENO;
    if(tipo=='M') multa_tipo = multa * D_MEDIANO;
    if(tipo=='C') multa_tipo = multa * D_GRANDE;
    ouput_reporte<<left<<setw(TAM_MAX/COLUMNAS)<<multa_tipo;
    //
    if(fecha<fecha_i) multa_fecha = multa*D_FECHA1;
    else if(fecha>fecha_f) multa_fecha = multa;
    else multa_fecha = multa*D_FECHA2;
    ouput_reporte<<left<<setw(TAM_MAX/COLUMNAS)<<multa_fecha;
    //  
    if(hora> (4*3600+30*60) and hora<(11*3600+25*60)) multa_hora = multa*D_MANANA;
    else if(hora>=(11*3600+25*60) and hora<=(20*3600+40*60)) multa_hora = multa*D_TARDE;
    else multa_hora = multa*D_NOCHE;
    ouput_reporte<<left<<setw(TAM_MAX/COLUMNAS)<<multa_hora;
    pago_total_vehiculo = multa + multa_fecha + multa_hora + multa_tipo;
    ouput_reporte<<left<<setw(TAM_MAX/COLUMNAS)<<pago_total_vehiculo<<endl;
    
}

void imprimir_linea(int placa_1,int placa_2,int dd,int mm,int aa,int hr,int min,int sg, char tipo, char gravedad, ifstream &input_vehiculos, ofstream &ouput_reporte, int fecha_i, int fecha_f, double &pago_total_vehiculo){
    double multa;
    if(tipo=='P') ouput_reporte<<left<<setw(TAM_MAX/COLUMNAS)<<"PEQUENO";
    if(tipo=='M') ouput_reporte<<left<<setw(TAM_MAX/COLUMNAS)<<"MEDIANO";
    if(tipo=='C') ouput_reporte<<left<<setw(TAM_MAX/COLUMNAS)<<"GRANDE";
    ouput_reporte<<tipo<<placa_1<<placa_2<<setw((TAM_MAX/COLUMNAS)-7)<<"";
    busqueda_impresion_caractVehic(tipo,placa_1, placa_2,input_vehiculos,ouput_reporte);
    ouput_reporte<<setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setfill(' ')<<aa<<left<<setw((TAM_MAX/COLUMNAS)-10)<<"";
    ouput_reporte<<setfill('0')<<setw(2)<<hr<<":"<<setw(2)<<min<<":"<<setw(2)<<sg<<left<<setfill(' ')<<setw((TAM_MAX/COLUMNAS)-8)<<"";
    if(gravedad=='L') {
        multa = LEVE;
        ouput_reporte<<left<<setw(TAM_MAX/COLUMNAS)<<"LEVE"<<setw(TAM_MAX/COLUMNAS)<<multa;
    }  
    if(gravedad=='G') {
        multa = GRAVE;
        ouput_reporte<<left<<setw(TAM_MAX/COLUMNAS)<<"GRAVE"<<setw(TAM_MAX/COLUMNAS)<<multa;
    }  
    if(gravedad=='M') {
        multa=MUY_GRAVE;
        ouput_reporte<<left<<setw(TAM_MAX/COLUMNAS)<<"MUY GRAVE"<<setw(TAM_MAX/COLUMNAS)<<multa;
    }  
    int hora = hr*3600 + min*60 + sg;
    int fecha = transformar_fecha(dd, mm, aa);
    imprimir_incrementos(ouput_reporte, tipo,hora,fecha_i, fecha_f, multa, fecha, pago_total_vehiculo);
    //falta clacular los pagos totales
}

void determinar_mayor_menor(int dni, double pago, int &dni_mayor, int &dni_menor, double &pago_mayor, double &pago_menor){
    
    if(pago < pago_menor) {
        pago_menor = pago; 
        dni_menor = dni;
    }
        
    if(pago > pago_mayor){
        pago_mayor = pago; 
        dni_mayor = dni;
    }
        
}

void Leer_multa_cada_vehiculo(ifstream &input_infracciones, ifstream &input_vehiculos,ofstream &ouput_reporte, int fecha_i,int fecha_f, double &pago_por_persona, int dni, int &dni_mayor, int &dni_menor, double &pago_mayor, double &pago_menor){
    //c es el ultimo caracter despues de la gravedad de la infracccion
    double pago_total_vehiculo;
    int placa_1,placa_2,dd,mm,aa,hr,min,sg;
    char tipo, guion, slash, D_Puntos, gravedad, c;
    
    while(true){//para cada multa por vehiculo
        input_infracciones>>tipo>>placa_1>>guion>>placa_2>>dd>>slash>>mm>>slash>>aa>>hr>>D_Puntos>>min>>D_Puntos>>sg;
        input_infracciones>>ws>>gravedad;
        c=input_infracciones.get();
        imprimir_linea(placa_1,placa_2,dd,mm,aa,hr,min,sg, tipo, gravedad, input_vehiculos, ouput_reporte, fecha_i, fecha_f, pago_total_vehiculo);
        pago_por_persona = pago_por_persona + pago_total_vehiculo;
        determinar_mayor_menor(dni, pago_por_persona, dni_mayor, dni_menor, pago_mayor, pago_menor);
        
        if(c=='\n') break;
        else{
            input_infracciones>>ws;
        }
    }
}

void imprimir_multa_por_persona(ifstream &input_infracciones,ifstream &input_vehiculos, ifstream &input_empresas,ofstream &ouput_reporte, int fecha_i, int fecha_f, double &pago_total,
                                int &dni_mayor, int &dni_menor, double &pago_mayor, double &pago_menor){
    int n=1, tam=TAM_MAX/3, cant, dni;
    
    while(true){
        double pago_por_persona=0.0;
        input_infracciones>>dni;
        if(input_infracciones.eof()) break;
        imprimir_lin_caracter('=', ouput_reporte);
        ouput_reporte<<"COMPANIA N° "<<n<<endl;
        ouput_reporte<<"REPRESENTANTE LEGAL:";
        Leer_imprimir_nombre(input_infracciones, cant, ouput_reporte);
        ouput_reporte<<setw(tam -20 -cant)<<"";
        ouput_reporte<<"DNI: "<<dni<<setw(tam-12)<<"";
        busqueda_impresion_empresa(input_empresas,ouput_reporte, tam, dni);
        imprimir_lin_caracter('-', ouput_reporte);  
        n++;
        imprimir_header(input_infracciones, ouput_reporte);
        input_infracciones>>ws;
        ouput_reporte<<fixed<<setprecision(2);
        Leer_multa_cada_vehiculo(input_infracciones,input_vehiculos, ouput_reporte, fecha_i, fecha_f,pago_por_persona, dni, dni_mayor, dni_menor, pago_mayor, pago_menor);
        pago_total += pago_por_persona;
        imprimir_lin_caracter('-', ouput_reporte);
        ouput_reporte<<"PAGO TOTAL: "<<pago_por_persona<<endl;
    }
}


void imprimir_reporte(int dni_mayor, int dni_menor, double pago_mayor, double pago_menor, ofstream &ouput_reporte){
    ouput_reporte<<setw(BORDE)<<setfill('/')<<""<<setfill(' ')<<endl;
    ouput_reporte<<'/'<<setw(BORDE -2)<<"COMPANIA CON MAYOR PAGO DE INFRACCIONES: "<<'/'<<endl;
    ouput_reporte<<'/'<<"DNI: "<<dni_mayor<<setw(BORDE - 15)<<""<<'/'<<endl;
    ouput_reporte<<'/'<<"TOTAL PAGADO: "<<pago_mayor<<setw(BORDE-24)<<""<<'/'<<endl;
    ouput_reporte<<setw(BORDE)<<setfill('/')<<""<<setfill(' ')<<endl;
    ouput_reporte<<'/'<<setw(BORDE -2)<<"COMPANIA CON MENOR PAGO DE INFRACCIONES: "<<'/'<<endl;
    ouput_reporte<<'/'<<"DNI: "<<dni_menor<<setw(BORDE - 15)<<""<<'/'<<endl;
    ouput_reporte<<'/'<<"TOTAL PAGADO: "<<pago_menor<<setw(BORDE-22)<<""<<'/'<<endl;
    ouput_reporte<<setw(BORDE)<<setfill('/')<<""<<setfill(' ')<<endl;
}

void leer_procesar_infracciones(const char* name_arch_empresas,const char* name_arch_vehiculos,const char* name_arch_infracciones,const char* name_arch_reporte){
    ifstream input_empresas,input_vehiculos,input_infracciones;
    ofstream ouput_reporte;
    
    apertura_lectura(input_empresas, name_arch_empresas);
    apertura_lectura(input_vehiculos, name_arch_vehiculos);
    apertura_lectura(input_infracciones, name_arch_infracciones);
    apertura_escritura(ouput_reporte, name_arch_reporte);
    double pago_total;
    int d_i, m_i, a_i, d_f, m_f, a_f, dni, dni_mayor, dni_menor;
    double pago_mayor, pago_menor;
    char slash;
    input_infracciones>>d_i >>slash>> m_i >>slash>>a_i >>d_f >>slash>> m_f >>slash>> a_f;
    int fecha_i = transformar_fecha(d_i, m_i, a_i);
    int fecha_f = transformar_fecha(d_f, m_f, a_f);
    pago_menor = 15963000000;
    pago_mayor = 0;
    imprimpir_titulo(d_i, m_i, a_i, d_f, m_f, a_f, ouput_reporte);
    imprimir_multa_por_persona(input_infracciones, input_vehiculos,input_empresas,ouput_reporte, fecha_i, fecha_f, pago_total, dni_mayor, dni_menor, pago_mayor, pago_menor);
    imprimir_lin_caracter('=', ouput_reporte);
    ouput_reporte<<"PAGO RECAUDADO POR INFRACCIONES: "<<pago_total<<endl;
    imprimir_lin_caracter('=', ouput_reporte);
    ouput_reporte<<endl;
    imprimir_reporte(dni_mayor, dni_menor, pago_mayor, pago_menor, ouput_reporte);
}


