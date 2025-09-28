/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 15 de mayo de 2025, 21:16
 */

#include "funciones.hpp"

void apertura_lectura(const char*  name,ifstream &input){
    input.open(name, ios::in);
    if(not input.is_open()){
        cout<<"El archvio se abrio"<<endl;
    }
}

void apertura_escritura(const char*  name,ofstream &ouput){
    ouput.open(name, ios::out);
    if(not ouput.is_open()){
         cout<<"El archvio se abrio"<<endl;
    }
    else{
        cout<<"se abrio el reporte"<<endl;
    }
}

void leer_imprimir_nombre(ifstream &inputPacientes, ofstream &ouput){
    inputPacientes>>ws;
    char c;
    int cant=0;
    int tam= TAMREPORTE/6-10;
    c = inputPacientes.get();
    while(true){
        c = inputPacientes.get();
        if(c==']' or c=='/' ) break;
        ouput.put(c);
        cant++;
    }
    for(int i=0;i<(2*tam-cant);i++) ouput.put(' ');
}

void imprimir_lin(ofstream &ouput, char c){
    ouput<<setw(TAMREPORTE)<<setfill(c)<<""<<setfill(' ')<<endl;
}

void ignorar(ifstream &input, char delimitador){
    while(input.get() != delimitador);
}

int transformarHora(int h,int m,int s){
    return (h*3600 + m*60+s);
}

void imprimir_hora(ofstream &ouput,int hora){
    int h,m,s;
    int tam= TAMREPORTE/6;
    h = hora/3600;
    m= (hora/60)%60;
    s=hora%60;
    
    ouput<<setw(tam)<<left<<setfill('0')<<setw(2)<<right<<h<<":"<<setw(2)<<right<<m<<":"<<setw(2)<<right<<s<<setfill(' ')<<setw(tam-8)<<"";
}

//void leer_imprimir_nombre_medico(ifstream &inputMedicos, ofstream &ouput){
//    char c;
//    
//    while(true){
//        
//    }
//}

void imprimir_especialidad(ifstream &inputPacientes, ofstream &ouput){
    inputPacientes>>ws;
    int tam= TAMREPORTE/6;
    int cant=0;
    char c;
    while(true){
        c = inputPacientes.get();
        if(c==' ' ) break;
        ouput.put(c);
        cant++;
    }
    
    for(int i=0;i<(tam-cant);i++) ouput.put(' ');
}

void imprimir_busqueda_datos_medico(double descuento,int dd,int mm,int aa,int hhi,int ssi,int mmi,int hhf,int mmf,int ssf,
                                    int codMedico,ifstream &inputMedicos,ofstream &ouput){
    int tam= TAMREPORTE/6,horaI,horaF, horaDur,codigoMedico;
    double tarifaMedico, pagoCita;
    inputMedicos.clear();
    inputMedicos.seekg(0,ios::beg);
    
    ouput<<setw(tam)<<left<<"Fecha"<<setw(tam)<<left<<"Duracion"<<setw(2*tam-20)<<left<<"Medico"<<setw(tam)<<left<<"Especialidad"<<setw(tam)<<left<<"Pago por cita"<<endl;
    ouput<<setw(tam)<<left<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<aa<<setfill(' ')<<setw(tam-10)<<"";
    horaI = transformarHora(hhi,mmi,ssi);
    horaF = transformarHora(hhf,mmf,ssf);
    horaDur = horaF - horaI;
    imprimir_hora(ouput, horaDur);
    while(true){
        inputMedicos>>codigoMedico;
        if(inputMedicos.eof()) break;
        if(codMedico == codigoMedico){
            
            leer_imprimir_nombre(inputMedicos, ouput);
            imprimir_especialidad(inputMedicos,ouput);
            inputMedicos>>tarifaMedico;
            pagoCita = tarifaMedico * descuento;
            ouput<<setw(tam)<<left<<pagoCita<<endl;
            return;
        }
        else{
            ignorar(inputMedicos, '\n');
        }
    }       
//    ignorar(inputMedicos, '\n');
            
}

void procesar_citas(double descuento,int dniPac,ifstream &inputMedicos, ifstream &inputMedicinas, ifstream &inputCitas, ofstream &ouput){
    int dd,mm,aa,dniPaciente,hhi,ssi,mmi,hhf,mmf,ssf,codMedico,codMedicina,cantMedicina,tam= TAMREPORTE/6,
            horaI,horaF, horaDur,codigoMedico;
    char c;
    inputCitas.clear();
    inputCitas.seekg(0, ios::beg);
    
    while(true){//por 
        inputCitas>>dd;
        if(inputCitas.eof()) break;
        inputCitas >> c>> mm >> c >> aa >> dniPaciente;
        if(dniPac == dniPaciente){
           inputCitas>>hhi>>c>>mmi>>c>>ssi>>hhf>>c>>mmf>>c>>ssf;
           inputCitas>>codMedico;
           
           imprimir_busqueda_datos_medico(descuento,dd,mm,aa,hhi,ssi,mmi,hhf,mmf,ssf,
                                    codMedico,inputMedicos,ouput);
           ignorar(inputCitas,  '\n');
//           procesar_medicinas()
        }
        else{
            ignorar(inputCitas, '\n');
        }
        
    }
}

void  procesar_reporte(ifstream &inputMedicos, ifstream &inputMedicinas, ifstream &inputCitas, ifstream &inputPacientes,ofstream &ouput){
    int dniPac, anioNac, codDistrito;
    double descuento;
    char c;
    while(true){
        inputPacientes>>dniPac;
        if(inputPacientes.eof()) break;
        ouput<<" PACIENTE : "<< dniPac<<" - ";
        leer_imprimir_nombre(inputPacientes, ouput);
        inputPacientes>>codDistrito>>anioNac>>descuento;
        ouput<<" Ano de nacimiento :"<<anioNac<<setw(3)<<""<<"%Descuento: "<<descuento<<endl;
        imprimir_lin(ouput, '-');
        procesar_citas(descuento,dniPac,inputMedicos, inputMedicinas, inputCitas,ouput);
    }
}

void procesar_pacientes(const char* nCitas, const char* nPacientes, const char* nMedicos, const char* nMedicinas,const char* nReporte){
    
    ifstream inputMedicos, inputMedicinas, inputCitas, inputPacientes;
    ofstream ouput;
    
    apertura_lectura(nMedicos,inputMedicos);
    apertura_lectura(nMedicinas,inputMedicinas);
    apertura_lectura(nCitas,inputCitas);
    apertura_lectura(nPacientes,inputPacientes);
    apertura_escritura(nReporte, ouput);
    
    procesar_reporte(inputMedicos, inputMedicinas, inputCitas, inputPacientes,ouput);
}