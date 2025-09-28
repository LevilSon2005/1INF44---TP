/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   funciones.cpp
 * Author: binny
 * 
 * Created on 29 de mayo de 2025, 11:56
 */

#include "funciones.hpp"

void ignorar(ifstream input, char delimitador){
    while(input.get() != delimitador);
}

void apertura_lectura(ifstream &input, const char* name){
    input.open(name, ios::in);
    if(not input.is_open()){
        cout << "El archivo "<<name<< " no se abrio"<<endl;
    }
}

void apertura_escritura(ofstream &ouput, const char* name){
    ouput.open(name, ios::out);
    if(not ouput.is_open()){
        cout << "El archivo "<<name<< " no se abrio"<<endl;
    }
    else{
        cout<<"El reporte se abrio"<<endl;
    }
}


int Solicitud_Usuario_PedidoDeFacultad(){
    int codPedidoFacu;
    //    cout<<"Ingrese el codigo de la Facultad que desea buscar"<<endl;
//    cin>>codPedidoFacu;
    codPedidoFacu = 500017;
    return codPedidoFacu;
}

int busquedaBinaria(int codAlumno,int *arrCodigoAlumnos,int cantAlumnos){
    int indInf, indSup, indMedio;
    
    indInf=0;
    indSup = cantAlumnos-1;
    while(true){
        indMedio = (indInf +indSup)/2;
        if(indInf>indSup) return NO_ENCONTRADO;
        
        if(arrCodigoAlumnos[indMedio] == codAlumno) return indMedio;
        else if(codAlumno>arrCodigoAlumnos[indMedio]) indInf = indMedio+1;
        else indSup = indMedio -1;
    }
}


void insertarOrdenadoAlumnos(int codAlumno,int*arrCodigoAlumnos,int&cantAlumnos,
                             int *arrNumCursos,double *arrNumCreditos,double *arrSumaPonderada,
                            double credCurso,int notaAlumno){
    int posAlumno,posInserccion;
    posAlumno = busquedaBinaria(codAlumno, arrCodigoAlumnos, cantAlumnos);
    //NOTA: Aqui se toma el +1 porque se quiere insertar a la siguiente posicion
    if(posAlumno == NO_ENCONTRADO){ //CODALUMNO NO SE REPITE - CODIGO DEL ALUMNO NO ESTÁ EN EL ARREGLO
        posInserccion = cantAlumnos -1;
        //este while es para ubicar donde insertar, al final el posInsertar quedo uno antes del que quieres insertar
        while(posInserccion>=0 and codAlumno<arrCodigoAlumnos[posInserccion]){
            arrCodigoAlumnos[posInserccion +1] = arrCodigoAlumnos[posInserccion];
            arrNumCursos[posInserccion +1] = arrNumCursos[posInserccion];
            arrNumCreditos[posInserccion +1] = arrNumCreditos[posInserccion];
            arrSumaPonderada[posInserccion +1] = arrSumaPonderada[posInserccion];
            posInserccion--;
        }
        //Para la primera vez pasa de frente y también luego de que tengamos el Indice de Inserccion ya calculado
        arrCodigoAlumnos[posInserccion +1] = codAlumno;
        arrNumCursos[posInserccion +1] ++;
        arrNumCreditos[posInserccion+1] += credCurso;
        arrSumaPonderada[posInserccion+1] += notaAlumno ;
        cantAlumnos++;
    }

    //No se toma el +1 porque solo se actualiza
    else{//CUANDO EL COD ALUMNO SÍ ESTA EN EL ARREGLO
        arrNumCursos[posAlumno] ++;
        arrNumCreditos[posAlumno] += credCurso;
        arrSumaPonderada[posAlumno] += notaAlumno ;
    }
}


//COMO VAMOS A HACER INSERTAR ORDENADO EL ARREGLO de codAlumnos está vacio.
//Ordenado ascendententemente
void leerCalificaciones(int *arrCodigoAlumnos,int *arrNumCursos,double *arrNumCreditos,double *arrSumaPonderada,int &cantAlumnos){
    ifstream inputCalificaciones, inputAlumnos;
    apertura_lectura(inputCalificaciones, "Calificaciones.txt");
    apertura_lectura(inputAlumnos, "Alumnos.txt");
    int codNumCurso, codAlumno, notaAlumno;
    double credCurso;
    char Letra1Curso,Letra2Curso,Letra3Curso;
    
    while(true){
        inputCalificaciones>>Letra1Curso;
        if(inputCalificaciones.eof()) break;
        inputCalificaciones>>Letra2Curso>>Letra3Curso>>codNumCurso>>credCurso;
        while(true){
            if(inputCalificaciones.get() == '\n') break;
            inputCalificaciones>>codAlumno>>notaAlumno;
            insertarOrdenadoAlumnos(codAlumno,arrCodigoAlumnos,cantAlumnos,
                                    arrNumCursos,arrNumCreditos,arrSumaPonderada,
                                   credCurso, notaAlumno);
        }
    }
}

void imprimir_linea(ofstream &ouput, char c){
    ouput<<setw(TAMREPORTE)<<setfill(c)<<""<<setfill(' ')<<endl;
}

int my_strlen(const char* cadena){
    int i;
    for(i=0; cadena[i];i++);
    return i;
}

void my_strcpy(char* cadenaDestino, const char* source){
    int i;
    for(i=0; source[i];i++){
        cadenaDestino[i] = source[i];
    }
    cadenaDestino[i] = '\0';
}

void my_strcat(char* cadena1, const char* cadena2){
    int pos=my_strlen(cadena1); //para que comienza al final de la cadena y apartir de ahí copie el texto de la cadena2
    my_strcpy(&cadena1[pos], cadena2);
}

// 0: cadena1 = cadena2
// 1: cadena1 > cadena2
// -1: cadena1 < cadena2
int my_strcmp(const char* cadena1, const char*cadena2){
    int i;
    while(true){
        if (cadena1[i] != cadena2[i]){
            return (cadena1[i]>cadena2[i])?1:-1;
        }
        if(cadena1[i]=='\0') return 0;
    }
}

void my_prepend(char*cadena1, const char* cadena2){
    char aux[100]{};
    my_strcpy(aux,cadena2);
    my_strcat(aux,cadena1);
    my_strcpy(cadena1,aux);
}

void imprimir_titulo(ofstream &ouput, const char* titulo){
    ouput<<setw((TAMREPORTE + my_strlen(titulo))/2)<<titulo<<endl;
}

void FormatearNombreFacultad(char *nombreFacultad, char* nombreFacultadFormateado){
    int i;
    char aux[MAXNOMBRE]{};
    for( i=0;nombreFacultad[i];i++){
        if(nombreFacultad[i] == '_') nombreFacultad[i]=' ';
//        cout<<"Iteracion "<<i<<endl;
//        cout<<"nombreFacultad: '"<<nombreFacultad[i]<<"'"<<endl;
        aux[i] = nombreFacultad[i];
//        cout<<"aux: '"<<aux[i]<<" '"<<endl;
    }
    aux[i] ='\0';
    
    my_strcpy(nombreFacultadFormateado, aux);
//    cout<<"aux: "<<aux<<endl;
//    cout<<nombreFacultadFormateado<<endl;
}

void imprimir_cabecera(ofstream &ouput,char *nombreFacultad){
    int tam=TAMREPORTE/COLUMNAS;
    char nombreFacultadFormateado[MAXNOMBRE]{};
    imprimir_titulo(ouput, "INSTITUCION EDUCATIVA_TP");
    imprimir_titulo(ouput, "PROMEDIO PONDERADO DE LOS ALUMNOS MATRICULADOS");
    imprimir_titulo(ouput, "CICLO: 2024-1");
    FormatearNombreFacultad(nombreFacultad,nombreFacultadFormateado);
    imprimir_titulo(ouput, nombreFacultadFormateado);
    imprimir_linea(ouput, '=');
    ouput<<setw(4)<<"";
    ouput<<setw(2*tam-4)<<left<<"ALUMNO"
            <<setw(tam)<<"No. de Cursos"
            <<setw(tam)<<"Suma Ponderada"
            <<setw(tam)<<"No. de Creditos"
            <<setw(tam)<<"Prom Ponderado"<<endl;
    imprimir_linea(ouput, '=');
}

void LeerFacultadesEImprimirTitulo(ofstream &ouput,ifstream &inputFacultades,int codPedidoFacu){
    char nombreFacultad[MAXNOMBRE]{};
    int codFacultad;
    while(true){
        inputFacultades>>nombreFacultad;
        if(inputFacultades.eof()) break;
        inputFacultades>>codFacultad;
        if(codFacultad ==codPedidoFacu) {
//            cout<<nombreFacultad;
            imprimir_cabecera(ouput,nombreFacultad);
            break;
        }
    }
}

void cambiarCaracteresExtras(char *nombreAlumno, char* aux){
    for(int i=0;nombreAlumno[i];i++){
        if(nombreAlumno[i] == '/' or nombreAlumno[i] == '-') nombreAlumno[i] = ' ';
    }
    my_strcpy(aux, nombreAlumno);
//    cout<<aux<<endl;
}

void camelizarNombreAlumno(char* cadena){
    for(int i=0;cadena[i];i++){
        if(i>0 and cadena[i-1]!=' ' and cadena[i]>='A' and cadena[i]<='Z') cadena[i] = cadena[i] +32;
    }
}

void FormatearNombreAlumno(char*apellidos,char* nombreAlumno, char* nombreAlumnoFormateado){
    char aux[MAXNOMBRE]{};
    cambiarCaracteresExtras(nombreAlumno, aux);
    my_strcat(aux, " ");
    my_strcat(aux, apellidos);
    camelizarNombreAlumno(aux);
    my_strcpy(nombreAlumnoFormateado, aux);
//    cout<<"Nombre Formateado: "<<nombreAlumnoFormateado<<endl;
//    cout<<"aux1: "<<aux<<endl;
}

void juntarApellidos(char* apellido1, char* apellido2, char* apellidos){
    char aux[MAXNOMBRE]{};
    my_strcpy(aux, apellido1);
    my_strcat(aux, " ");
    my_strcat(aux, apellido2);
    my_strcpy(apellidos,aux);
}

void imprimir_lineaReporte(ofstream &ouput,int codAlumno, int PosAlumno,char* nombreAlumnoFormateado, 
                           int* arrNumCursos, double* arrNumCreditos,double* arrSumaPonderada,double PromPonderado){
    int tam=TAMREPORTE/COLUMNAS;
    ouput<<left<<setw(8)<<codAlumno<<" - "<<setw(2*tam-8)<<nombreAlumnoFormateado
            <<setw(tam)<<arrNumCursos[PosAlumno]
            <<setw(tam)<<arrNumCreditos[PosAlumno]
            <<setw(tam)<<arrSumaPonderada[PosAlumno]
            <<setw(tam)<<PromPonderado<<endl; 
}

void LeerAlumnosEImpresionDeReporte(int *arrCodigoAlumnos,int *arrNumCursos,double *arrNumCreditos,double *arrSumaPonderada,int cantAlumnos,
                                   int codPedidoFacu){
    ifstream inputAlumnos, inputFacultades;
    ofstream ouput;
    apertura_escritura(ouput, "reporte.txt");
    apertura_lectura(inputAlumnos, "Alumnos.txt");
    apertura_lectura(inputFacultades, "Facultades.txt");
    char nombreAlumno[MAXNOMBRE]{},nombreAlumnoFormateado[MAXNOMBRE]{},apellido1[MAXNOMBRE]{}, apellido2[MAXNOMBRE]{},apellidos[MAXNOMBRE]{};
    double PromPonderado =0.0;
    int codAlumno, codFacultad,PosAlumno;
    LeerFacultadesEImprimirTitulo(ouput,inputFacultades,codPedidoFacu);
    while(true){
        inputAlumnos>>codAlumno;
        if(inputAlumnos.eof()) break;
        inputAlumnos>>ws;
        inputAlumnos.getline(apellido1,15,'/');
        inputAlumnos.getline(apellido2,15,'/');
        inputAlumnos>>nombreAlumno>>codFacultad;
        if(codFacultad == codPedidoFacu){
            PosAlumno= busquedaBinaria(codAlumno, arrCodigoAlumnos, cantAlumnos);
            juntarApellidos(apellido1, apellido2, apellidos);
            if(PosAlumno != NO_ENCONTRADO){
                PromPonderado = (arrSumaPonderada[PosAlumno]/arrNumCursos[PosAlumno]);
                cout<<PromPonderado<<endl;
                FormatearNombreAlumno(apellidos,nombreAlumno, nombreAlumnoFormateado);
                imprimir_lineaReporte(ouput,codAlumno, PosAlumno,nombreAlumnoFormateado,
                                        arrNumCursos, arrNumCreditos,arrSumaPonderada,PromPonderado);
            }
        }
    } imprimir_linea(ouput, '=');
}