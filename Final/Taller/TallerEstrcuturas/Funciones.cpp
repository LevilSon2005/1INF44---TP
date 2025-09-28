/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: binny
 * 
 * Created on 1 de julio de 2025, 19:29
 */

#include <string.h>
#include <inttypes.h>

#include "Funciones.hpp"

void apertura_lectura(ifstream &input, const char* name){
    input.open(name,ios::in);
    if(not input.is_open())
        cout<<"El archivo "<<name<<" no se abre"<<endl;
}

void apertura_escritura(ofstream &ouput, const char* name){
    ouput.open(name,ios::out);
    if(not ouput.is_open())
        cout<<"El archivo "<<name<<" no se abre"<<endl;
    else
        cout<<"El reporte - "<<name<<" se abre"<<endl;
}

void imprimir_tiutlo(ofstream &ouput, const char* tiutlo){
    ouput<<setw((TAMREPORTE +strlen(tiutlo))/2)<<tiutlo<<endl;
}

void imprimir_linC(ofstream &ouput,  char c){
    ouput<<setfill(c)<<setw(TAMREPORTE)<<""<<setfill(' ')<<endl;
}

void imprimir_indice(ofstream &ouput, int indice){
    ouput<<setfill('0')<<setw(2)<<right<<indice<<") "<<setfill(' ');
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

char* leer_cadena(ifstream &input, char del){
    char* cadena;
    char buffer[200];
    
    input.getline(buffer, 200, del);
    cadena =  new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    
    return cadena;
}

char* asignar_cadena(const char* buffer){
    char* cadena;
    cadena =  new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

void ignorar(ifstream &input, char del){
    while(input.get() != del);
}

void reserva_memoria(struct Curso* &arrCurso){
    arrCurso = new struct Curso[50]{};
}

void leerCursos(const char* name, struct Curso* arrCurso, int &cantCursos){
    ifstream input;
    apertura_lectura(input, name);
    int codigo;
    
    while(true){
        codigo = leer_int(input);
        if(input.eof()) break;
        arrCurso[cantCursos].codCurso = codigo;
        arrCurso[cantCursos].nombre = leer_cadena(input, ',');
        arrCurso[cantCursos].creditos = leer_double(input);
        cantCursos++;      
    }
}

void imprimir_reporte_cursos(const char* name, struct Curso* arrCurso, int cantCursos){
    ofstream ouput;
    apertura_escritura(ouput, name);
    int tam=TAMREPORTE/4;
    imprimir_tiutlo(ouput, "REPORTE DE PRUEBA DE CURSOS");
    imprimir_linC(ouput, '=');
    
    ouput<<setw(15)<<"";
    ouput<<left<<setw(tam-25)<<"CODIGO"
            <<setw(tam+25)<<"NOMBRE"
            <<setw(tam)<<"CREDITOS"<<endl;
    
    imprimir_linC(ouput, '-');
    ouput<<fixed<<setprecision(2);
    for(int i=0;i<cantCursos;i++){
        ouput<<setw(15)<<"";
        ouput<<left<<setw(tam-25)<<arrCurso[i].codCurso
            <<setw(tam+25)<<arrCurso[i].nombre
            <<setw(tam)<<arrCurso[i].creditos<<endl;
    }
}


void reserva_memoria_escalas(struct Escala* &arrEscalas){
    arrEscalas =  new struct Escala[45]{};
}

void leerEscalas(const char* name, struct Escala* arrEscalas, int &cantEscalas){
    ifstream input;
    apertura_lectura(input, name);
    int anio, ciclo;
    
    while(true){
        anio = leer_int(input);
        if(input.eof()) break;
        ciclo = leer_int(input);
        arrEscalas[cantEscalas].anho = anio;
        arrEscalas[cantEscalas].ciclo =ciclo;
        arrEscalas[cantEscalas].escala = leer_char(input);
        arrEscalas[cantEscalas].valorCred = leer_double(input);
        cantEscalas++;
    }
}

void imprimir_reporte_cursos(const char* name, struct Escala* arrEscalas, int cantEscalas){
    ofstream ouput;
    apertura_escritura(ouput, name);
    int tam=TAMREPORTE/4;
    
    imprimir_tiutlo(ouput, "REPORTE DE PRUEBA DE LAS ESCALAS");
    imprimir_linC(ouput, '=');
    ouput<<setw(35)<<"";
    ouput<<left<<setw(tam)<<"SEMESTRE"
            <<setw(tam)<<"ESCALA"
            <<setw(tam)<<"PRECIO DEL CREDITO"<<endl;
    imprimir_linC(ouput, '-');
    ouput<<fixed<<setprecision(2);
    for(int i=0;i<cantEscalas;i++){
        ouput<<setw(35)<<"";
        ouput<<left<<arrEscalas[i].anho<<"-"<<arrEscalas[i].ciclo<<setw(tam-6)<<""
                <<setw(tam)<<arrEscalas[i].escala
                <<setw(tam)<<arrEscalas[i].valorCred<<endl;
    }
}

void reserva_memoria_alumnos( struct Alumno* &arrAlumnos){
    arrAlumnos = new struct Alumno[100]{};
}

void leerAlumnos(const char* name, struct Alumno* arrAlumnos, int &cantAlumnos){
    ifstream input;
    apertura_lectura(input, name);
    
    int codigo;
    while(true){
        codigo = leer_int(input);
        if(input.eof()) break;
        arrAlumnos[cantAlumnos].codAlumn = codigo;
        arrAlumnos[cantAlumnos].nombre = leer_cadena(input, ',');
        arrAlumnos[cantAlumnos].escAlumno.escala = leer_char(input);
        arrAlumnos[cantAlumnos].escAlumno.ciclo = 0;
        arrAlumnos[cantAlumnos].escAlumno.anho = 0;
        arrAlumnos[cantAlumnos].escAlumno.valorCred = 0.0;
        arrAlumnos[cantAlumnos].cursos = new struct Curso[8]{};
        arrAlumnos[cantAlumnos].cantidadCursos =0;
        arrAlumnos[cantAlumnos].totalCreditos =0.0;
        arrAlumnos[cantAlumnos].totalPago =0.0;
        cantAlumnos++;
    }
}

int contarCifras(int numero){
    int cant=0;
    if(numero == 0) return 1; 
    while(numero>0){
        numero = numero/10;
        cant++;
    }
    return cant;
}

char* convertir_int_to_cadena(int numero){
    char* cadena;
    cadena = new char[6]{};
    char cifra_char[2];
    int cantCifras=0, aux, cifra;
    cantCifras = contarCifras(numero);
    aux =  cantCifras;
    for(int i=0;i<cantCifras;i++){
        cifra = (numero/int(pow(10,aux-1)))%10;
        cifra_char[0] = ('0'+cifra);
        cifra_char[1] = '\0';
        if(i==0) strcpy(cadena, cifra_char);
        else strcat(cadena, cifra_char);
        aux--;
    }
    return cadena;
}

void convertirNuevoTitulo(int anioPedido, int cicloPedido , char* &nombre_arch){
    char* anio_cad, *ciclo_cad;
    nombre_arch = new char[40]{};
    strcpy(nombre_arch,"ReporteAlumnos_");
    anio_cad = convertir_int_to_cadena(anioPedido);
    ciclo_cad = convertir_int_to_cadena(cicloPedido);
    strcat(nombre_arch, anio_cad);
    strcat(nombre_arch, "_");
    strcat(nombre_arch, ciclo_cad);
    strcat(nombre_arch, ".txt");
}

void imprimir_semestre(ofstream &ouput, int anioPedido, int cicloPedido){
    ouput<<setw(89)<<right<<"CICLO : "<<anioPedido<<"-"<<cicloPedido<<endl;
}

void imprimir_datosAlumno(ofstream &ouput, const struct Alumno &alumno){
    int tam = (TAMREPORTE -80)/2;
    ouput<<"ALUMNO:  "<<alumno.codAlumn<<" - "<<setw(60)<<left<<alumno.nombre
          <<"ESCALA: "<<setw(tam-10)<<alumno.escAlumno.escala
          <<"Valor Credito: "<<setw(tam-16)<<alumno.escAlumno.valorCred<<endl;
    imprimir_linC(ouput, '-');
}

void imprimir_cabeceraAlumno(ofstream &ouput){
    ouput<<setw(4)<<""<<setw(76)<<left<<"CURSO MATRICULADO"
            <<setw(20)<<"CREDITOS"
            <<setw(20)<<"MONTO PAGADO"<<endl;
}

void imprimir_cursos(ofstream &ouput,const struct Alumno &alumno,double precioCred){
    for(int i=0;i<alumno.cantidadCursos;i++){
        imprimir_indice(ouput, i+1);
        ouput<<alumno.cursos[i].codCurso<<" - "<<setw(67)<<left<<alumno.cursos[i].nombre
             <<setw(20)<<alumno.cursos[i].creditos
             <<setw(20)<<(alumno.cursos[i].creditos*precioCred)<<endl;
    }
    imprimir_linC(ouput, '-');
    
    ouput<<"TOTAL CREDITOS: "<<alumno.totalCreditos<<"       "
            <<"TOTAL MONTO PAGADO: "<<alumno.totalPago<<endl;
    imprimir_linC(ouput, '=');
}

void imprimir_resumen(ofstream &ouput, int cantAlumnos, double montoTotalAlumnos){
    ouput<<"RESUMEN: "<<endl;
    ouput<<"CANTIDAD TOTAL DE ALUMNOS:   "<<cantAlumnos<<"       ";
    ouput<<"MONTO TOTAL PAGADO:    "<<montoTotalAlumnos<<endl;
}

void emitir_reporte(int anioPedido, int cicloPedido, struct Curso* arrCurso, int cantCursos,
                    struct Escala* arrEscalas, int cantEscalas,
                    struct Alumno* arrAlumnos, int cantAlumnos){
    ofstream ouput;
    int cantAlumnosSemestrePedido =0;
    double montoTotalAlumnos=0.0;
    char* nombre_arch, *titulo1;
    if(anioPedido == 0 and cicloPedido ==0){
        nombre_arch = asignar_cadena("ReporteInicialAlumnos.txt");
        titulo1 = asignar_cadena("DETALLE PRELIMINAR DE ALUMNOS");
    }else{
        convertirNuevoTitulo(anioPedido, cicloPedido , nombre_arch);
        titulo1 = asignar_cadena("DETALLES DE PAGO REALIZADO POR CICLO");
    }
    apertura_escritura(ouput, nombre_arch);
    imprimir_tiutlo(ouput, "INSTITUCION EDUCATIVA TP");
    imprimir_tiutlo(ouput, titulo1);
    if(anioPedido !=0 and cicloPedido !=0)imprimir_semestre(ouput, anioPedido, cicloPedido);
    imprimir_linC(ouput, '=');
    ouput<<fixed<<setprecision(2);
    for(int i=0;i<cantAlumnos;i++){
        if(arrAlumnos[i].escAlumno.anho == anioPedido and arrAlumnos[i].escAlumno.ciclo == cicloPedido){
            imprimir_datosAlumno(ouput, arrAlumnos[i]);
            imprimir_cabeceraAlumno(ouput);
            imprimir_cursos(ouput,arrAlumnos[i],arrAlumnos[i].escAlumno.valorCred);
            montoTotalAlumnos += arrAlumnos[i].totalPago; //actualizando estadisticas
            cantAlumnosSemestrePedido++;
        }
    }
    imprimir_resumen(ouput, cantAlumnosSemestrePedido, montoTotalAlumnos);
}

void solicitarSemestre(int &anioPedido,int &cicloPedido){
    cout<<"Ingrese el anio: ";
    cin >>  anioPedido;
    cout<<"Ingrese el ciclo: ";
    cin >>  cicloPedido;
}

int busquedaCodAlumno(int codAlumno, struct Alumno *arrAlumnos, int cantAlumnos){
    for(int i=0;i<cantAlumnos;i++){
        if(codAlumno == arrAlumnos[i].codAlumn) return i;
    }
    return NO_ENCONTRADO;
}

int buscarEscala(int anio,int ciclo,char escala, struct Escala* arrEscalas, int cantEscalas){
    for(int i=0;i<cantEscalas;i++){
        if(anio == arrEscalas[i].anho and ciclo == arrEscalas[i].ciclo and escala == arrEscalas[i].escala) return i;
    }
    return NO_ENCONTRADO;    
}

int busquedaCodCurso(int codCurso,struct Curso* arrCurso, int cantCursos){
    for(int i=0;i<cantCursos;i++){
        if(codCurso == arrCurso[i].codCurso) return i;
    }
    
    return NO_ENCONTRADO;
}

struct Escala llenarEscala(int anio, int ciclo,int posEscala, struct Escala* arrEscalas){
    struct Escala escalaRetorno;
    escalaRetorno.anho = anio;
    escalaRetorno.ciclo = ciclo;
    escalaRetorno.escala = arrEscalas[posEscala].escala;
    escalaRetorno.valorCred = arrEscalas[posEscala].valorCred;
    return escalaRetorno;
}

struct Curso llenarCurso(int posCurso,struct Curso* arrCurso){
    struct Curso cursoRetorno;
    
    cursoRetorno.codCurso = arrCurso[posCurso].codCurso;
    cursoRetorno.creditos = arrCurso[posCurso].creditos;
    cursoRetorno.nombre = asignar_cadena(arrCurso[posCurso].nombre);
    
    return cursoRetorno;
}

void  leerMatricula(const char* name, int anioPedido, int cicloPedido,
                struct Curso* arrCurso, int cantCursos,
                struct Escala* arrEscalas, int cantEscalas,
                struct Alumno* arrAlumnos, int cantAlumnos){
    ifstream input;
    apertura_lectura(input, name);
    int anio, ciclo, codAlumno, codCurso, posAlumno,posCurso,posEscala;
    while(true){
        input>>anio;
        if(input.eof()) break;
        input.get();
        input>>ciclo;
        if(anio == anioPedido and ciclo == cicloPedido){
            input>>codAlumno;
            posAlumno = busquedaCodAlumno(codAlumno, arrAlumnos, cantAlumnos);
            if(posAlumno != NO_ENCONTRADO){
                posEscala = buscarEscala(anio, ciclo,arrAlumnos[posAlumno].escAlumno.escala, arrEscalas, cantEscalas);
                if(posEscala != NO_ENCONTRADO){
                    arrAlumnos[posAlumno].escAlumno = llenarEscala(anio, ciclo,posEscala, arrEscalas);
                    while(true){
                        if(input.get() == '\n') break;
                        input>>codCurso;
                        posCurso = busquedaCodCurso(codCurso, arrCurso, cantCursos);
                        arrAlumnos[posAlumno].cursos[arrAlumnos[posAlumno].cantidadCursos] = llenarCurso(posCurso,arrCurso);
                        arrAlumnos[posAlumno].cantidadCursos++;
                        arrAlumnos[posAlumno].totalCreditos += arrCurso[posCurso].creditos;
                        arrAlumnos[posAlumno].totalPago += (arrCurso[posCurso].creditos)*(arrEscalas[posEscala].valorCred);
                    }
                }
            }else ignorar(input, '\n');
        }else ignorar(input, '\n');
    }
}

