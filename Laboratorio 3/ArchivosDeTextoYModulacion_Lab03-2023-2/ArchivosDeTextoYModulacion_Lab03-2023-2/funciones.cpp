/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: aml
 * 
 * Created on 25 de abril de 2025, 09:44 AM
 */

#include "funciones.hpp"

void apertura_lectura(ifstream &input,const char*  name_arch){
    input.open(name_arch,ios::in);
    if(not input.is_open()){
        cout <<"ERROR: El archivo "<<name_arch<<" no ae pudo abrir";
    }
}

void apertura_escritura(ofstream &ouput,const char*  name_arch){
    ouput.open(name_arch,ios::out);
    if(not ouput.is_open()){
        cout <<"ERROR: El archivo "<<name_arch<<" no ae pudo abrir";
    }
    else{
        cout <<"El archivo se abrio correctamente";
    }
}

void  imprimir_linCaracter(char c,ofstream &ouput){
    ouput<<setfill(c)<<setw(TAMMAX)<<""<<setfill(' ')<<endl;
}

void imprimir_titulo(ofstream &ouput){
    imprimir_linCaracter('=', ouput);
    ouput<<setw((TAMMAX + TITULO1)/2)<<"EMPRESA DE OPINION DE MERCADO TP S.A."<<endl;
    ouput<<setw((TAMMAX + TITULO2)/2)<<"AVENIDA UNIVERSITARIA 1234 San Miguel"<<endl;
    ouput<<setw((TAMMAX + TITULO3)/2)<<"LIMA - PERU"<<endl;
    imprimir_linCaracter('=', ouput);
    ouput<<setw((TAMMAX + TITULO4)/2)<<"REGISTRO DE PREFERENCIA DE LOS TELEVIDENTES POR CANAL DE PREFERENCIA"<<endl;
    
}
void imprimir_titulo_canal(int canal, ifstream &inputCanales, ofstream &ouput){
    char c;
    int cant=0, tam=TAMMAX/3, Tam = TAMMAX/COLUMNAS;
     imprimir_linCaracter('=', ouput);
    ouput<<"CANAL:";
    //lectura - impresion de los nombres 
    inputCanales>>ws;
    while(true){
        c=inputCanales.get();
        if(c=='\n') break;
        if(c=='/') c= ' ';
        if(c>='a' and c<='z') c = c -('a'-'A');
        ouput.put(c);
        cant++;
    }
    for(int i=0; i<tam-cant; i++) ouput.put(' ');
    ouput<<"NUMERO: "<<canal<<endl;
    ouput<<"LISTADO DE TELEVIDENTES QUE VEN EL CANAL: "<<endl;
    imprimir_linCaracter('-', ouput);
    ouput<<setw(Tam-5)<<left<<"DNI No.";
    ouput<<setw(Tam+12)<<left<<"NOMBRE";
    ouput<<setw(Tam-5)<<left<<"SEXO";
    ouput<<setw(Tam-4)<<left<<"CATEGORIA";
    ouput<<setw(Tam-2)<<left<<"COMPANIA";
    ouput<<setw(Tam-1)<<left<<"RANGO";
    ouput<<setw(Tam)<<left<<"DURACION"<<endl;
    imprimir_linCaracter('-', ouput);
}

int transformarHora(int h, int m, int s){
    return h*3600 + m*60 +s;
}

void imprimirHora(int hora, ofstream &ouput){
    int h, m,s;
    h= hora/3600;
    m = (hora/60)%60;
    s= hora%60;
    ouput<<setfill('0')<<setw(2)<<right<<h<<":"<<setw(2)<<right<<m<<":"<<setw(2)<<right<<s<<setfill(' ');
}

void leer_imprimir_nombre(ifstream &inputTelevidentes, ofstream &ouput){
    inputTelevidentes>>ws;
    char c;
    int i=1, tam=TAMMAX/COLUMNAS +12;
    
    while(true){
        inputTelevidentes.get(c);
        if(c==' ') break;
        if(c=='_') c=' ';
        else{
            if(i%2==0) c=c+('a'-'A');
        }
        ouput.put(c);
        i++;
    }
    for(int j=0; j<tam-(i-1);j++) ouput.put(' ');
}

void busqueda_impresion_nombre_sexo_categoria_compania(int dni, ifstream &inputTelevidentes, ofstream &ouput, int &cantMenor, int&cantJov, int &cantAdulto){
    inputTelevidentes.clear();
    inputTelevidentes.seekg(0, ios::beg);
    int dni_arch, tam = TAMMAX /COLUMNAS-5,d,m,a;
    char sexo, compania, car;
    
    while (true){
        inputTelevidentes>>dni_arch;
        if(inputTelevidentes.eof()) break;
        if(dni ==  dni_arch){
            leer_imprimir_nombre(inputTelevidentes, ouput); //incluido los espacios despues
            inputTelevidentes>>d>>car>>m>>car>>a>>sexo>>compania;
            //impresion 
            if(sexo == 'F') ouput<<setw(tam)<<"FEMENINO";
            else  ouput<<setw(tam)<<"MASCULINO";
            
            if(a>2009){
                 ouput<<setw(tam)<<"Menor";
                 cantMenor++;
            }
            else{
                if(a<1988){
                    ouput<<setw(tam)<<"Adulto";
                    cantAdulto++;
                }
                else{
                    ouput<<setw(tam)<<"Joven";
                    cantJov++;
                } 
            }
            if(compania== 'A') ouput<<setw(tam)<<"TVPUCP";
            if(compania== 'B') ouput<<setw(tam)<<"CableMas";
            if(compania== 'C') ouput<<setw(tam)<<"TPVision";
            
        }
        else{
            while(inputTelevidentes.get() != '\n');
        }
    }
}

void impresion_un_televidente(int dni, int h_i, int m_i, int s_i, int h_f, int m_f, int s_f, ifstream &inputTelevidentes, ofstream &ouput, int &duracion_s, int &cantMenor, int&cantJov, int &cantAdulto){
    int tam = TAMMAX/COLUMNAS-5, hora_i, hora_f;
    
    ouput<<setw(tam)<<left<<dni;
    busqueda_impresion_nombre_sexo_categoria_compania(dni, inputTelevidentes, ouput, cantMenor,cantJov, cantAdulto);
    ouput<<setfill('0')<<setw(2)<<right<<h_i<<":"<<setw(2)<<right<<m_i<<":"<<setw(2)<<right<<s_i<<"-"<<setw(2)<<right<<h_f<<":"<<setw(2)<<right<<m_f<<":"<<setw(2)<<right<<s_f<<setfill(' ')<<setw(tam-9)<<"";
    hora_i = transformarHora(h_i, m_i, s_i);
    hora_f = transformarHora(h_f, m_f, s_f);
    duracion_s= hora_f - hora_i;
    imprimirHora(duracion_s, ouput);
    ouput<<setw(tam-8)<<endl;
}

void impimir_reporte(int cantTelevidentes, int duracion_por_canal, int cantMenores, int cantJov, int cantAdultos, ofstream &ouput){
    int promedioHora;
    double porMenores, porJov, porAdultos;
    promedioHora = duracion_por_canal/cantTelevidentes; 
    porMenores = ((double)cantMenores/cantTelevidentes) *100;
    porJov = ((double)cantJov/cantTelevidentes) *100;
    porAdultos = ((double)cantAdultos/cantTelevidentes) *100;
    imprimir_linCaracter('-', ouput);
    ouput<<"PROMEDIO DE TIEMPO QUE VEN LOS TELEVIDENTES EL CANAL: ";
    imprimirHora( promedioHora, ouput);
    ouput<<endl;
    ouput<<"PORCENTAJES SEGUN SU EDAD: "<<endl<<fixed<<setprecision(2);
    ouput<<setw(20)<<""<<"MENORES: "<< porMenores<<"%"<<endl;
    ouput<<setw(20)<<""<<"JOVENES: "<< porJov<<"%"<<endl;
    ouput<<setw(20)<<""<<"ADULTOS: "<< porAdultos<<"%"<<endl;
    ouput<<"TOTAL DE PERSONAS QUE VEN EL CANAL: "<< cantTelevidentes<<endl;
    imprimir_linCaracter('=', ouput);
}

void busqueda_impresion_televidentes(int canal, ifstream &inputRegristo, ifstream &inputTelevidentes,ofstream &ouput, int &promDuracSeg, int &cantMenores, int &cantJov, int &cantAdultos){
    inputRegristo.clear();
    inputRegristo. seekg(0, ios::beg);
    
    int dni, cantTelevidentes=0; //de regsitro
    int canal_arch, h_i, m_i, s_i, h_f, m_f, s_f, duracion_cada_televidente, duracion_por_canal=0;
    char car, c;
    cantJov =0, cantMenores=0, cantAdultos=0;
    while(true){//impresion de cada canal

        inputRegristo>>dni;
        if(inputRegristo.eof()) break;
        
        while(true){//busqueda  de un dni que vea ese canal. Se repite;
            inputRegristo>>canal_arch;
            inputRegristo>>h_i>>car>>m_i>>car>>s_i>>h_f>>car>>m_f>>car>>s_f;
            if(canal == canal_arch) {
                impresion_un_televidente(dni, h_i, m_i, s_i, h_f, m_f, s_f, inputTelevidentes, ouput, duracion_cada_televidente, cantMenores, cantJov, cantAdultos);
                duracion_por_canal += duracion_cada_televidente;
                while(inputRegristo.get() != '\n');
                cantTelevidentes++;
                break; 
            }else{
                c= inputRegristo.get();
                if (c== '\n') break;
                //si no es el utltimo que continue buscando con los otros canales
                //para ver si coinciden
            }
            
        }
        
    }
    
    impimir_reporte(cantTelevidentes, duracion_por_canal, cantMenores, cantJov, cantAdultos, ouput);
}

void procesar_cada_canal(int canal, ifstream &inputCanales, ifstream &inputRegristo, ifstream &inputTelevidentes, ofstream &ouput){
    int promDurac/*en segundos*/, cantMenores, cantAdultos, cantJov;
    imprimir_titulo_canal(canal, inputCanales, ouput);
    busqueda_impresion_televidentes(canal, inputRegristo, inputTelevidentes,ouput, promDurac, cantMenores, cantAdultos, cantJov);
    
}

void leer_procesar_canales(const char* name_arch_canales, const char* name_arch_registro, const char* name_arch_televidentes, const char* name_arch_reporte){
    
    ifstream  inputTelevidentes ,inputCanales, inputRegristo;
    ofstream ouput;
    
    apertura_lectura(inputTelevidentes, name_arch_televidentes);
    apertura_lectura(inputCanales, name_arch_canales);
    apertura_lectura(inputRegristo, name_arch_registro);
    apertura_escritura(ouput, name_arch_reporte);
    
    imprimir_titulo(ouput);
    int canal;
    while(true){
        inputCanales>>canal;
        if(inputCanales.eof()) break;
        procesar_cada_canal(canal, inputCanales, inputRegristo, inputTelevidentes, ouput);
    }
}