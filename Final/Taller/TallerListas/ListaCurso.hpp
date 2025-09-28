/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListaCurso.hpp
 * Author: Binny
 *
 * Created on 7 de julio de 2025, 12:45
 */

#ifndef LISTACURSO_HPP
#define LISTACURSO_HPP

#include "NodoCurso.hpp"

struct ListaCurso{
    struct NodoCurso* inicio;
    struct NodoCurso* final;
    int cantCodPar;
    int cantCodImpar;
};

#endif /* LISTACURSO_HPP */

