/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 27 de abril de 2025, 21:40
 */

#include "funciones.hpp"

void apertura_lectura(const char* name,ifstream &input){
    input.open(name,ios::in);
    if(not input.is_open()){
        cout<<"ERROR: El archivo "<<name<<" no se abrio correctamente";
    }
}

void apertura_escritura(const char* name,ofstream &ouput){
    ouput.open(name,ios::out);
    if(not ouput.is_open()){
        cout<<"ERROR: El archivo "<<name<<" no se abrio correctamente";
    }
    else{
        cout<<"Se abrio correctamente";
    }
}

void imprimir_linCar(char c, ofstream &ouput){
    ouput<<setw(TAMMAX)<<setfill(c)<<""<<setfill(' ')<<endl;
}

void imprimir_nombre_medicos(ifstream &input, ofstream &ouput){
    input>>ws;
    char c;
    int i=0;
    while(true){
        input.get(c);
        if(c=='/') {
            c=' ';
            i++;
        }
        if(i==2) break;
        ouput.put(c);
    }
}

void imprimir_especialidad_medicinas(ifstream &input, ofstream &ouput){
    int cant=0;
    input>>ws;
    char c;
    while(true){
        input.get(c);
        if(c==' ') break;
        if(c=='_') c= ' ';
        ouput.put(c);
        cant++;
    }
    
    for(int j=0; j<tam2+5-cant;j++) ouput.put(' ');
}

int transformarHora(int h, int m, int s){
    return h*3600 + m*60 +s;
}

void  imprimir_cabecera_medico(int codMedico, ifstream &inputMedicos, ofstream &ouput, double &tarifa){
     
    //CABECERA: el input>>ws esta dentro
    
    ouput<<"Codigo del medico: "<<codMedico<<endl;
    ouput<<"Nombre del medico: ";
    imprimir_nombre_medicos(inputMedicos, ouput );
    ouput<<endl;
    ouput<<"Especialidad del medico: ";
    imprimir_especialidad_medicinas(inputMedicos, ouput);
    ouput<<endl;
    inputMedicos>>tarifa;
    ouput<<"Tarifa: ";
    ouput<<tarifa<<endl;
    ouput<<"PACIENTES ATENDIDOS"<<endl;
    imprimir_linCar('-', ouput);
}

void imprimir_hora(int hora, ofstream &ouput){
    
    int h, m, s;
    
    h=hora/3600;
    m = (hora/60)%60;
    s = hora%60;
    
    ouput<<setfill('0')<<setw(2)<<right<<h<<":"<<setw(2)<<right<<m<<":"<<setw(2)<<right<<s<<setfill(' ')<<setw(tam-8)<<"";
}

void busqueda_impresion_una_medicina(int dni,int i, int cantidad, int  codMedicina,double descuento, ifstream &inputMedicinas, ofstream &ouput, double &pagoUnaMedicina){
    inputMedicinas.clear();
    inputMedicinas.seekg(0, ios::beg);
    char c;
    double precio;
    int codigoMedicina;
    while(true){
        inputMedicinas.get(c);
        if(c=='\n') break;
        else{
            inputMedicinas>>codigoMedicina;
            if(inputMedicinas.eof()) break;
        
            if(codigoMedicina == codMedicina){
                ouput<<setfill('0')<<setw(2)<<right<<i<<setfill(' ')<<setw(4)<<""<<setw(tam2-7)<<setw(tam2-8)<<left<<codMedicina;
                imprimir_especialidad_medicinas(inputMedicinas, ouput);
                inputMedicinas>>precio;

                pagoUnaMedicina = cantidad*precio*(descuento/2);
                ouput<<setw(tam2)<<cantidad<<setw(tam2)<<precio<<setw(tam2)<<pagoUnaMedicina<<endl;
                return;
            }
            else{
                while(inputMedicinas.get() != '\n');
            }
        }
        
    }
}
void busqueda_imprime_un_paciente(int d,double tarifa, int codMedico,ofstream &ouput,ifstream &inputCitas,  ifstream &inputMedicinas, double &pagoCita, double &pagoMedicinas){
    int cantidad,hora_i, hora_f,m,a,dni,h_i,m_i, s_i,h_f,m_f, s_f, codigoMedico, hora_dur, codMedicina;
    double descuento, pagoUnaMedicina;
    char car,c;
    pagoMedicinas=0.0;
    //imprimir cabecera del paciente
    inputCitas>>car>>m>>car>>a>>dni>>descuento>>h_i>>car>>m_i>>car>>s_i>>h_f>>car>>m_f>>car>>s_f>>codigoMedico;
    hora_i = transformarHora(h_i, m_i, s_i);
    hora_f = transformarHora(h_f, m_f, s_f); 
    hora_dur = hora_f- hora_i;
    if(codigoMedico == codMedico and hora_dur < (2*3600 + 31*60 + 25)){
        ouput<<setw(2)<<setfill('0')<<right<<d<<"/"<<setw(2)<<right<<m<<"/"<<a<<setfill(' ')<<setw(tam-10)<<"";
        ouput<<setw(tam)<<left<<dni;
        imprimir_hora(hora_i, ouput);
        imprimir_hora(hora_f, ouput);
        ouput<<setw(tam)<<left<<descuento;
        pagoCita = tarifa*descuento*((double)hora_dur/3600);
        ouput<<setw(tam)<<left<<pagoCita<<endl;
        imprimir_linCar('-', ouput);
        int i=1;
        ouput<<"Medicinas recetadas: "<<endl;
        ouput<<setw(ESPACIO)<<"";
        ouput<<setw(tam2-24)<<left<<"No"<<setw(tam2-8)<<left<<"Codigo"<<setw(tam2+5)<<left<<"Descripcion"<<setw(tam2)<<left<<"Cantidad"<<setw(tam2)<<left<<"Precio"<<setw(tam2)<<left<<"Pago"<<endl;
        
        while(true){
            //imprimir cada medicina
            inputCitas>>codMedicina>>cantidad;
            inputCitas.get(c);
            if(c =='\n') break;
            ouput<<setw(ESPACIO)<<"";
            busqueda_impresion_una_medicina(dni,i,cantidad, codMedicina,descuento, inputMedicinas, ouput, pagoUnaMedicina);
            pagoMedicinas += pagoUnaMedicina;
            i++;
        }
        imprimir_linCar('-', ouput);
    }
    else{
        while(inputCitas.get() != '\n');
    }
}

void procesar_un_medico(int codMedico, ifstream &inputCitas, ifstream &inputMedicinas, ifstream &inputMedicos, ofstream &ouput, int &codMayor){
    //DEBO DEVOLVER EL CODIGO MAYOR
    double tarifa,pagoCitas, pagoMedicinas,pagoMayor =0.0, pagoTotal=0.0;
    imprimir_cabecera_medico(codMedico, inputMedicos, ouput, tarifa);
    int d;
    
    
    
    inputCitas.clear();
    inputCitas.seekg(0, ios::beg);
    while(true){
        
        //para cada paciente
        inputCitas>>d;
        if(inputCitas.eof()) break;
        busqueda_imprime_un_paciente(d,tarifa,codMedico,ouput,inputCitas, inputMedicinas, pagoCitas, pagoMedicinas );
        pagoTotal =  pagoCitas + pagoMedicinas;
        if(pagoTotal>pagoMayor){
            pagoMayor = pagoTotal;
            codMayor = codMedico;
        }
        
    }
    
    
}

void leer_procesar_registrosMedicos(const char* name_citas, const char* name_medicinas, const char* name_medicos, const char* name_reporte){
    
    ifstream inputCitas, inputMedicos, inputMedicinas;
    ofstream ouput;
    
    apertura_lectura(name_citas, inputCitas);
    apertura_lectura(name_medicinas, inputMedicinas);
    apertura_lectura(name_medicos, inputMedicos);
    apertura_escritura(name_reporte, ouput);
    
    int codMedico, codMayor;
    double PagoTotalMedicinas=0.0, PagoTotal=0.0;
    
    ouput<<fixed<<setprecision(2);
    while(true){
        inputMedicos>>codMedico;
        if(inputMedicos.eof()) break;
        procesar_un_medico(codMedico, inputCitas, inputMedicinas, inputMedicos, ouput, codMayor);
        imprimir_linCar('=', ouput);
    }
}