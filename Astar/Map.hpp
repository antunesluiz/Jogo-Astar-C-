/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Map.hpp
 * Author: Luiz Antunes
 *
 * Created on 5 de Outubro de 2018, 22:04
 */

#ifndef MAP_HPP
#define MAP_HPP

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include <iostream>
#include <fstream>
#include <cstring>

#define TamanhoMatriz 20

using namespace std;

class Map {
private:
    SDL_Texture *Bloco;
    SDL_Texture *Disco;

    SDL_Rect src, dest;

    int map[TamanhoMatriz][TamanhoMatriz];
    int lvl0[TamanhoMatriz][TamanhoMatriz];
    int lvl1[TamanhoMatriz][TamanhoMatriz];
    int lvl2[TamanhoMatriz][TamanhoMatriz];
    int lvl3[TamanhoMatriz][TamanhoMatriz];
    int lvl4[TamanhoMatriz][TamanhoMatriz];

    int QuantDiscos;

    void LoadMatrizFromFile(int arr[TamanhoMatriz][TamanhoMatriz], const char* NomeArquivo);
    void LoadMap(int arr[TamanhoMatriz][TamanhoMatriz]);
public:
    Map(int mapa);
    ~Map();

    void DrawMap();

    void ContaDiscos();
    int GetQuantDiscos();

    int GetMap(int x[TamanhoMatriz][TamanhoMatriz]);
    void SetMap(int x[TamanhoMatriz][TamanhoMatriz]);
    
    void SetDiscos(int x);
};

#endif /* MAP_HPP */