/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Pokemon.hpp
 * Author: Binny
 *
 * Created on 20 de junio de 2025, 15:47
 */

#ifndef POKEMON_HPP
#define POKEMON_HPP

#include "Stats.hpp"

struct Pokemon{
    int number;
    char* name;
    char* type1;
    char* type2;
    struct Stats st_Attacks;
    bool isLegendary;
};

#endif /* POKEMON_HPP */

