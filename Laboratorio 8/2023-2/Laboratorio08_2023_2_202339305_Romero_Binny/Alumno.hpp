/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Alumno.hpp
 * Author: Binny
 *
 * Created on 16 de junio de 2025, 11:37
 */

#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#define MAXNOMBRE 45

struct Alumno{
    int codigo;
    char nombre[MAXNOMBRE]{};
    char escala;
};

#endif /* ALUMNO_HPP */

