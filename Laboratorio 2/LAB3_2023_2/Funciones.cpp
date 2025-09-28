
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 20 de abril de 2025, 22:20
 */

#include "Funciones.hpp"

void apertura_lectura(ifstream &input, const char* name_arch){
    input.open(name_arch, ios::in);
    if(not input.is_open()){
        cout<<"ERROR: El archivo "<<name_arch<<"no se pudo abrir";
    }
}

void apertura_escritura(ofstream &ouput, const char* name_arch){
    ouput.open(name_arch, ios::out);
    if(not ouput.is_open()){
        cout<<"ERROR: El archivo "<<name_arch<<"no se pudo abrir";
    }
    else{
        cout<<"El archivo se abrio correctamente";
    }
}

void imprimir_lin_caracter(char c, ofstream &ouput){
    ouput<<setw(TAM_MAX)<<setfill(c)<<""<<setfill(' ')<<endl;
}

void imprimir_titulo(ofstream &ouput_reporte){
    imprimir_lin_caracter('=', ouput_reporte);
    ouput_reporte<<setw((TAM_MAX + TITULO1) /2)<<"EMPRESA DE OPINION DE MERCADO"<<endl;
    ouput_reporte<<setw((TAM_MAX + TITULO2) /2)<<"AVENIDA UNIVERSITARIA 1234 San Miguel"<<endl;
    ouput_reporte<<setw((TAM_MAX + TITULO3) /2)<<"LIMA - PERU"<<endl;
    imprimir_lin_caracter('=', ouput_reporte);
    ouput_reporte<<setw((TAM_MAX + TITULO4) /2)<<"REGSITRO DE PREFERENCIA DE LOS TELEVIDENTE POR CANAL DE PREFERENCIA"<<endl;
    imprimir_lin_caracter('=', ouput_reporte);
}

void imprimir_header_columnas(ofstream &ouput_reporte){
    imprimir_lin_caracter('-', ouput_reporte);
    ouput_reporte<<left<<setw((TAM_MAX /COLUMNAS))<<"DNI No.";
    ouput_reporte<<left<<setw((TAM_MAX /COLUMNAS)+16)<<"NOMBRE";
    ouput_reporte<<left<<setw((TAM_MAX /COLUMNAS)-5)<<"SEXO";
    ouput_reporte<<left<<setw((TAM_MAX /COLUMNAS)-6)<<"CATEGORIA";
    ouput_reporte<<left<<setw((TAM_MAX /COLUMNAS)-3)<<"COMPANIA";
    ouput_reporte<<left<<setw((TAM_MAX /COLUMNAS))<<"RANGO.";
    ouput_reporte<<left<<setw((TAM_MAX /COLUMNAS))<<"DURACION"<<endl;
    imprimir_lin_caracter('-', ouput_reporte);
}

void  imprimir_cabecera(ifstream &input_canales, ofstream &ouput_reporte, int canal){
    int  tam= TAM_MAX/3, cant;
    char c;
    imprimir_lin_caracter('=', ouput_reporte);
    ouput_reporte<<"CANAL: ";
    cant=0;
    while(input_canales.get() != '/');//no lee hasta que aparezca /
    while(true){
        c = input_canales.get();
        if(c == '\n') break;
        if(c=='/') c=' ';
        if(c>= 'a' and c<='z') c = c - ('a'- 'A'); //to mayus
        ouput_reporte.put(c);
        cant++;
    }
    ouput_reporte<<setw(tam-cant-7)<<""<<"NUMERO: "<<canal<<endl;
    ouput_reporte<<"LISTAS DE TELEVIDENTES QUE VEN EL CANAL"<<endl;
   
    
    imprimir_header_columnas(ouput_reporte);
}

int transformar_hora(int h,int m, int s){
    return h*3600+m*60+s;
}
void imprimir_hora(int hora, ofstream &ouput){
    int h, m,s;
    h=hora/3600;
    m = (hora/60)%60;
    s = hora%60;
    
    ouput<<right<<setfill('0')<<setw(2)<<h<<":"<<setw(2)<<m<<":"<<setw(2)<<s<<setfill(' ')<<endl;
    
}


void leer_imprimir_nombre(ifstream &input_televidente, ofstream &ouput_reporte){
    char c;
    
    int i=1;
    while(true){
        c = input_televidente.get();
        if(c == ' ') break;
        if(c== '_') c= ' ';
        else{
            if(i%2==0) c= c + ('a'-'A');
        }
        ouput_reporte.put(c); 
        i++;
    }
    ouput_reporte<<setw((TAM_MAX /COLUMNAS+16) - (i-1))<<"";
}

void imprimir_categoria(ofstream &ouput_reporte,int d, int m,int a ){
    if(a>2009) ouput_reporte<<left<<setw((TAM_MAX /COLUMNAS)-6)<<"MENOR";
    else if(a>1988) ouput_reporte<<left<<setw((TAM_MAX /COLUMNAS)-6)<<"JOVEN";
    else ouput_reporte<<left<<setw((TAM_MAX /COLUMNAS)-6)<<"ADULTO";
}

void imprimir_linea2(int d, int m,int a, char sexo, char compania, ofstream &ouput_reporte){
    if(sexo== 'F') ouput_reporte<<left<<setw((TAM_MAX /COLUMNAS)-5)<<"FEMENINO";
    else ouput_reporte<<left<<setw((TAM_MAX /COLUMNAS)-5)<<"MASCULINO";
    imprimir_categoria(ouput_reporte,d, m,a );
    if(compania=='A') ouput_reporte<<left<<setw((TAM_MAX /COLUMNAS)-3)<<"TVPUCP";
    else if(compania=='B') ouput_reporte<<left<<setw((TAM_MAX /COLUMNAS)-3)<<"CableMas";
    else ouput_reporte<<left<<setw((TAM_MAX /COLUMNAS)-3)<<"TPVision";
    
}

void busqueda_nombre_sexo_categoria_compania(int dni_registro, ifstream &input_televidente, ofstream &ouput_reporte){
    int dni_televidente, d, m,a;
    char car, sexo, compania;  
    input_televidente.clear();
    input_televidente.seekg(0, ios::beg);
    
    while(true){
        input_televidente>>dni_televidente;
        if(input_televidente.eof()) break;
        if(dni_registro == dni_televidente){
            input_televidente>>ws;
            leer_imprimir_nombre(input_televidente, ouput_reporte);
            input_televidente>>d>>car>>m>>car>>a>>sexo>>compania;
            imprimir_linea2(d, m,a, sexo, compania, ouput_reporte); //imprime categoria, sexo y compania
        }
        else{
            while(input_televidente.get() != '\n');
        }
        
    }
    
    
//    while(true){
//       input_televidente>>dni_televidente;
//       if(input_televidente.eof()) break;
//       input_televidente>>ws;
//       leer_imprimir_nombre(input_televidente, ouput_reporte);
//       input_televidente>>d>>car>>m>>car>>a>>sexo>>compania;
//       busqueda_impresion(ouput_reporte, input_televidente,dni_registro);
//       
//    }
    
    
    
}

void leer_imprimir_canal_por_persona(int dni_registro,int canal, ifstream &input_registro, ofstream &ouput_reporte, ifstream &input_televidente){
    //69323674     556   13:54:27  16:12:37
    int canal_registro,h_i,m_i,s_i,h_f,m_f,s_f, hora_i, hora_f, hora_dur;
    char car;
    while(true){//para cada canal
       input_registro>>canal_registro>>h_i>>car>>m_i>>car>>s_i>>h_f>>car>>m_f>>car>>s_f;
       if(canal == canal_registro){
           ouput_reporte<<left<<setw(TAM_MAX/COLUMNAS)<<dni_registro;
           busqueda_nombre_sexo_categoria_compania(dni_registro,input_televidente, ouput_reporte); //para cada Dni imprimes nombre_Sexo_categ_compania
           ouput_reporte<<right<<setfill('0');
           ouput_reporte<<setw(2)<<h_i<<car<<setw(2)<<m_i<<car<<setw(2)<<s_i<<"-"<<setw(2)<<h_f<<car<<setw(2)<<m_f<<car<<setw(2)<<s_f<<setfill(' ')<<setw((TAM_MAX/COLUMNAS)-17)<<"";
           hora_i = transformar_hora(h_i,m_i,s_i);
           hora_f = transformar_hora(h_f,m_f,s_f);
           hora_dur = hora_f - hora_i;
           imprimir_hora(hora_dur, ouput_reporte);
       }
       if(input_registro.get() == '\n') break;
    }
}


void busqueda_impresion_dato_cada_televidente(int canal, ifstream &input_registro, ofstream &ouput_reporte,  ifstream &input_televidente){
    int dni_registro;
    input_registro.clear();
    input_registro.seekg(0, ios::beg);
    while(true){//cada iteracion cada dni
        input_registro>>dni_registro;
        if(input_registro.eof()) break;
        leer_imprimir_canal_por_persona(dni_registro, canal, input_registro, ouput_reporte, input_televidente);
//        busqueda_nombre_sexo_categoria_compania(dni_registro,input_televidente, ouput_reporte); //para cada Dni imprimes nombre_Sexo_categ_compania
    }
    
}

void imprimir_canales(ifstream &input_canales, ifstream &input_televidentes, ifstream &input_registro, ofstream &ouput_reporte ){
    int canal;
    while(true){
        input_canales>>canal;
        if(input_canales.eof()) break;
        imprimir_cabecera(input_canales, ouput_reporte, canal);//FALTA COLUMNAS
        busqueda_impresion_dato_cada_televidente(canal, input_registro, ouput_reporte, input_televidentes);//DNI - RANGO - DURACION
    }
    
    
    //falta
}

void leer_procesar_canales(const char* name_arch_canales, const char* name_arch_televidentes, const char* name_arch_registro, const char* name_arch_reporte){
    
    ifstream input_canales, input_televidentes, input_registro;
    ofstream ouput_reporte;
    apertura_lectura(input_canales, name_arch_canales);
    apertura_lectura(input_televidentes, name_arch_televidentes);
    apertura_lectura(input_registro, name_arch_registro);
    apertura_escritura(ouput_reporte, name_arch_reporte);
    imprimir_titulo(ouput_reporte);
    imprimir_canales(input_canales, input_televidentes, input_registro, ouput_reporte );
}