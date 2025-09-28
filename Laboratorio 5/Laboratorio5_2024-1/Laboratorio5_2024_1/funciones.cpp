/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 16 de mayo de 2025, 12:03
 */

#include <cinttypes>

#include "funciones.hpp"

void apertura_lectura(const char* name, ifstream &input){
    input.open(name, ios::in);
    if(not input.is_open()) {
        cout<<"ERROR: El archivo "<<name << " no se abre"<<endl;
        
    }
}

void apertura_escritura(const char* name, ofstream &ouput){
    ouput.open(name, ios::out);
    if(not ouput.is_open()) {
        cout<<"ERROR: El archivo "<<name << " no se abre"<<endl;
    }
    else{
        cout<<"el reporte se abrio"<<endl;
    }
}

void ignorar(ifstream &input, char delimitador){
    while(input.get() != delimitador);
}

void ignorar_nombre_especialidad(ifstream &inputMedicos){
    inputMedicos>>ws;
    char c;
    c = inputMedicos.get();
    ignorar(inputMedicos, '/');
    inputMedicos>>ws;
    ignorar(inputMedicos, ' ');
    
}

void  imprimir_lin(ofstream &ouput,char c){
    ouput<<setw(TAMREPORTE)<<setfill(c)<<""<<setfill(' ')<<endl;
}

void cargarArregloMedicos(int *codMedicos,double *tarifasCita,int &cantMedicos){
    ifstream inputMedicos;
    apertura_lectura("Medicos.txt", inputMedicos);
    int codMedico;
    ofstream ouput;
    apertura_escritura("prueba.txt",ouput);
    
    while(true){
        inputMedicos>>codMedico;
        if(inputMedicos.eof()) break;
        codMedicos[cantMedicos] = codMedico;
        ignorar_nombre_especialidad(inputMedicos);
        inputMedicos>>tarifasCita[cantMedicos];
        cantMedicos++;        
    }
    ouput<<"MEDICOS: "<<endl;
    imprimir_lin(ouput,'-');
    for(int i=0;i<cantMedicos;i++){
        ouput<<codMedicos[i]<<"-"<<tarifasCita[i]<<endl;
    }
    imprimir_lin(ouput, '=');
}

void ignorar_nombre_medicina(ifstream &input){
    input>>ws;
    ignorar(input, ' ');
}

void cargarArregloMedicinas(int *codMedicinas,double *preciosMedicinas,int &cantMedicinas){
    ifstream inputMedicinas;
    apertura_lectura("Medicinas.txt", inputMedicinas);
    ofstream ouput;
    apertura_escritura("prueba.txt",ouput);
            
    int codMedicina;
    double precioMedicina;
    
    while(true){
        inputMedicinas>>codMedicina;
        if(inputMedicinas.eof()) break;
        codMedicinas[cantMedicinas] = codMedicina;
        ignorar_nombre_medicina(inputMedicinas);
        inputMedicinas>>precioMedicina;
        preciosMedicinas[cantMedicinas] = precioMedicina;
        ouput<<codMedicinas[cantMedicinas]<<" - "<<preciosMedicinas[cantMedicinas]<<endl;
        cantMedicinas++;        
    }
    
    ouput<<"MEDICINAS"<<endl;
    imprimir_lin(ouput,'-');
    for(int i=0;i<cantMedicinas;i++){
        ouput<<codMedicinas[i]<<"-"<<preciosMedicinas[i]<<endl;
    }
}

void leer_retonarHora(ifstream &inputCitas, int &hora){
    int h,m,s;
    char c;
    inputCitas>>h>>c>>m>>c>>s;
    
    hora = h*3600 + m*60 + s;
}

int buscarPosicion(int codigoMedico,int *codMedicos,int &cantMedicos){
    for(int i=0;i<cantMedicos;i++){
        if(codigoMedico ==codMedicos[i]) return i;
    }
    return NO_ENCONTRADO;
}

void procesarArreglosIntermedios( ifstream &inputCitas,int posMedico, int horaDur,double descuentoPac,
                                int* arrEnterosMedicos,double *arrDoublesMedicos,
                                int*arrCantMedicina,double *arrDoublesMedicina,
                                int *codMedicos,double *tarifasCita,int cantMedicos,
                                int *codMedicinas,double *preciosMedicinas,int cantMedicinas,
                                double &ingresoPromedio){
    char c;
    bool tuvoMedicina= false;
    int codigoMedicina,cantidadMedicina, posMedicina,i=0;
    c = inputCitas.get();
    double ingresoPorDoctor=0.0;
    double ingresoCita = ((double)horaDur/3600) * (1-((double)descuentoPac/100)) * tarifasCita[posMedico];
    arrDoublesMedicos[3*posMedico] += ingresoCita;//arrIngresoPorCitas
    arrEnterosMedicos[3*posMedico+2]++;//arrTotalPacientes - con o sin medicina

    double totalIngresoPorMedicinas = 0.0; // CORREGIDO: acumulador local por paciente

    if(c !='\n'){
        while(true){//para cada medicamento
            inputCitas>>codigoMedicina>>cantidadMedicina;
            posMedicina = buscarPosicion(codigoMedicina,codMedicinas, cantMedicinas);
            if(posMedicina !=  NO_ENCONTRADO){//paciente que tiene medicina
                if(i==0) arrEnterosMedicos[3*posMedico] ++;  //arrPacienteconMedicina
                double ingresoSinDes = cantidadMedicina * preciosMedicinas[posMedicina];
                double ingresoConDes = ingresoSinDes * (1-((double)descuentoPac/200)); // CORREGIDO: aplicar descuento correctamente
                tuvoMedicina = true;
                totalIngresoPorMedicinas += ingresoConDes; // CORREGIDO

                arrCantMedicina[posMedicina] += cantidadMedicina;
                arrDoublesMedicina[3*posMedicina] += ingresoSinDes;
                arrDoublesMedicina[3*posMedicina+1] += ingresoSinDes - ingresoConDes; // CORREGIDO: solo el descuento
                arrDoublesMedicina[3*posMedicina+2] += ingresoConDes; // CORREGIDO: total con descuento
            }         
            i++;
            c= inputCitas.get();
            if(c == '\n') break;
        } 
        arrDoublesMedicos[3*posMedico+1] += totalIngresoPorMedicinas; // CORREGIDO
        arrDoublesMedicos[3*posMedico+2] += ingresoCita + totalIngresoPorMedicinas; // CORREGIDO
    } else {
        // Si no hay medicinas, el total solo es el ingreso por cita
        arrDoublesMedicos[3*posMedico+2] += ingresoCita;
        arrEnterosMedicos[3*posMedico+1] ++; //arrPacienteSinMedicina
    }
    if(not tuvoMedicina) arrEnterosMedicos[3*posMedico+1] ++; //arrPacienteSinMedicina
    ingresoPorDoctor = arrDoublesMedicos[3*posMedico+2];
    ingresoPromedio += ingresoPorDoctor;
}

void leerCitas(int* arrEnterosMedicos,double *arrDoublesMedicos,
                int*arrCantMedicina,double *arrDoublesMedicina,
                int *codMedicos,double *tarifasCita,int cantMedicos,
                int *codMedicinas,double *preciosMedicinas,int cantMedicinas,
                double &ingresoPromedio){
    ifstream inputCitas;
    apertura_lectura("CitasMedicas.txt", inputCitas);
    int d,m,a,dniPac, codigoMedico,horaI,horaF,posMedico, codigoMedicina, cantidadMedicina;
    double descuentoPac,horaDur;
    char c;
    while(true){//para cada paciente
        inputCitas>>d;
        if(inputCitas.eof()) break;
        inputCitas>>c>>m>>c>>a>>dniPac>>descuentoPac;
        leer_retonarHora(inputCitas, horaI);
        leer_retonarHora(inputCitas, horaF);
        horaDur = horaF - horaI;
        inputCitas>>codigoMedico;
        posMedico = buscarPosicion(codigoMedico,codMedicos,cantMedicos);
        if(posMedico !=  NO_ENCONTRADO){//pacientes atendidos por un medico
              
            procesarArreglosIntermedios(inputCitas, posMedico,horaDur,descuentoPac,
                                        arrEnterosMedicos,arrDoublesMedicos,
                                        arrCantMedicina,arrDoublesMedicina,
                                        codMedicos,tarifasCita,cantMedicos,
                                        codMedicinas,preciosMedicinas,cantMedicinas,
                                        ingresoPromedio);
        } 
        else{
            ignorar(inputCitas, '\n');
            
        }
    }
}

//void imprimir_lin(ofstream &ouput, char c){
//    ouput<<setw(TAMREPORTE)<<setfill(c)<<""<<setfill(' ')<<endl;
//}

void imprimir_cabecera_1(ofstream &ouput){
    imprimir_lin(ouput, '=');
    ouput<<setw((TAMREPORTE+TITULO1)/2)<<"EMPRESA DE SALUD S.A."<<endl;
    ouput<<setw((TAMREPORTE+TITULO2)/2)<<"REGISTRO DE INGRESOS POR MEDICO"<<endl;
    imprimir_lin(ouput, '=');
}

void imprimir_cabecera_2(ofstream &ouput){
    imprimir_lin(ouput, '=');
    ouput<<setw((TAMREPORTE+TITULO1)/2)<<"EMPRESA DE SALUD S.A."<<endl;
    ouput<<setw((TAMREPORTE+TITULO3)/2)<<"REGISTRO DE INGRESOS POR MEDICAMENTO"<<endl;
    imprimir_lin(ouput, '=');
}

void imprimir_header_1(ofstream &ouput){
    int tam = TAMREPORTE/COLUMNAS;
    ouput<<setw(tam)<<left<<"No."<<setw(tam)<<left<<"Codigo del"<<setw(tam)<<left<<"Tarifa"<<setw(tam)<<left<<"Ingreso por"<<setw(tam)<<left<<"Ingreso por"<<setw(tam)<<left<<"Total"<<setw(tam)<<left<<"Pacientes atendidos"<<setw(tam)<<left<<"Pacientes atendidos"<<setw(tam)<<left<<"Total de"<<endl;
    ouput<<setw(tam)<<left<<""<<setw(tam)<<left<<"medico"<<setw(tam)<<left<<""<<setw(tam)<<left<<"las citas"<<setw(tam)<<left<<"medicamentos"<<setw(tam)<<left<<"ingresado"<<setw(tam)<<left<<"con medicinas"<<setw(tam)<<left<<"sin medicinas"<<setw(tam)<<left<<"pacientes"<<endl;
    imprimir_lin(ouput, '-');
}

void imprimir_header_2(ofstream &ouput){
    int tam = TAMREPORTE/COLUMNAS;
    ouput<<setw(tam)<<left<<"No."<<setw(tam)<<left<<"Codigo del"<<setw(tam)<<left<<"Precio"<<setw(tam)<<left<<"Cantidad de unidades"<<setw(tam)<<left<<"Ingresos sin"<<setw(tam)<<left<<"Descuentos por"<<setw(tam)<<left<<"Total"<<endl;
    ouput<<setw(tam)<<left<<""<<setw(tam)<<left<<"medicamento"<<setw(tam)<<left<<""<<setw(tam)<<left<<"vendidas"<<setw(tam)<<left<<"descuentos"<<setw(tam)<<left<<"los seguros"<<setw(tam)<<left<<"con ingresado"<<endl;
    imprimir_lin(ouput, '-');
}

void  imprimir_ReporteIngresos(int *codMedicos,double *tarifasCita,int *arrEnterosMedicos,double *arrDoublesMedicos,int cantMedicos,
                            int *codMedicinas,double *preciosMedicinas,int *arrCantMedicina,double *arrDoublesMedicina,int cantMedicinas){
    ofstream ouput;
    apertura_escritura("reporte.txt", ouput);
    int tam = TAMREPORTE/COLUMNAS;        
    imprimir_cabecera_1(ouput);
    imprimir_header_1(ouput);
//    ouput<<fixed<<setprecision(2);
    for(int i=0;i<cantMedicos;i++){
        ouput<<setw(3)<<right<<setfill('0')<<i<<setfill(' ')<<setw(tam-3)<<""<<
            setw(tam)<<left<<codMedicos[i]<<
            setw(tam)<<left<<tarifasCita[i]<<
            setw(tam)<<left<<arrDoublesMedicos[3*i]<<
            setw(tam)<<left<<arrDoublesMedicos[3*i+1]<<
            setw(tam)<<left<<arrDoublesMedicos[3*i+2]<<
            setw(tam)<<left<<arrEnterosMedicos[3*i]<<
            setw(tam)<<left<<arrEnterosMedicos[3*i+1]<<
            setw(tam)<<left<<arrEnterosMedicos[3*i+2]<<endl;
    }
    imprimir_lin(ouput, '=');
    ouput<<""<<endl;
    ouput<<""<<endl;
    imprimir_lin(ouput, '=');
    imprimir_cabecera_2(ouput);
    imprimir_header_2(ouput);
    
    for(int i=0;i<cantMedicinas;i++){
        ouput<<setw(3)<<right<<setfill('0')<<i<<setfill(' ')<<setw(tam-3)<<""<<
            setw(tam)<<left<<codMedicinas[i]<<
            setw(tam)<<left<<preciosMedicinas[i]<<
            setw(tam)<<left<<arrCantMedicina[i]<<
            setw(tam)<<left<<arrDoublesMedicina[3*i]<<
            setw(tam)<<left<<arrDoublesMedicina[3*i+1]<<
            setw(tam)<<left<<arrDoublesMedicina[3*i+2]<<endl;
    }
}

void  eliminar_dato(int numDato,int *codMedicos,double*tarifasCita, int *arrEnterosMedicos,double *arrDoublesMedicos,int &cantMedicos){
    int pos;
    pos = numDato--; //posicion del dato que quieres eliminar
    
    //utilizo for porque se que cuantas veces itero, desde pos hasta el penultimo ano
    for(int i=pos ; i<cantMedicos-1;i++){
        codMedicos[i] = codMedicos[i+1];
        tarifasCita[i] = tarifasCita[i+1];
        arrEnterosMedicos[3*i] = arrEnterosMedicos[3*(i+1)];
        arrEnterosMedicos[3*i+1] = arrEnterosMedicos[3*(i+1)+1];
        arrEnterosMedicos[3*i+2] = arrEnterosMedicos[3*(i+1)+2];
        arrDoublesMedicos[3*i] = arrDoublesMedicos[3*(i+1)];
        arrDoublesMedicos[3*i+1] = arrDoublesMedicos[3*(i+1)+1];
        arrDoublesMedicos[3*i+2] = arrDoublesMedicos[3*(i+1)+2];
    }
    //el for movio todos los elementos para arriba
    //Aunque quede un dato repetido al final, lo limitas con la cantida de datos
    cantMedicos--;
            
}

void eliminar_doctores(int *codMedicos,double*tarifasCita,int *arrEnterosMedicos,double *arrDoublesMedicos,int &cantMedicos,double ingresoPromedio){
    
    
    for(int i=0;i<cantMedicos;i++){
        if(arrDoublesMedicos[3*i+2]-ingresoPromedio<0){
            eliminar_dato(i,codMedicos,tarifasCita,arrEnterosMedicos,arrDoublesMedicos,cantMedicos);
        }
    }
}

//INserrtar_ordenado(datos que voy a poner en arrgelos, arreglos donde se pone esos datos)

void imprimir_MejoresMedicos(int *codMedicos,double*tarifasCita,int *arrEnterosMedicos,double *arrDoublesMedicos,int cantMedicos){
    int tam = TAMREPORTE/COLUMNAS; 
    ofstream ouput;
    apertura_escritura("reporte_2.txt", ouput);
    
    imprimir_lin(ouput, '=');
    ouput<<""<<endl;
    ouput<<""<<endl;
    imprimir_lin(ouput, '=');
    
    for(int i=0;i<cantMedicos;i++){
        ouput<<setw(3)<<right<<setfill('0')<<i+1<<setfill(' ')<<setw(tam-3)<<""
                <<setw(tam)<<left<<codMedicos[i]
                <<setw(tam)<<left<<tarifasCita[i]
                <<setw(tam)<<left<<arrDoublesMedicos[3*i]
                <<setw(tam)<<left<<arrDoublesMedicos[3*i+1]
                <<setw(tam)<<left<<arrDoublesMedicos[3*i+2]
                <<setw(tam)<<left<<arrEnterosMedicos[3*i]
                <<setw(tam)<<left<<arrEnterosMedicos[3*i+1]
                <<setw(tam)<<left<<arrEnterosMedicos[3*i+2]<<endl;
    }
}

