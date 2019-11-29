/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Objetos.hpp
 * Author: Luiz Antunes
 *
 * Created on 6 de Outubro de 2018, 16:06
 */

#ifndef OBJETOS_HPP
#define OBJETOS_HPP

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include <cmath>

#include "Map.hpp"
#include "Som.hpp"

class Personagem{
private:
    SDL_Rect src, dest;
    SDL_Texture *Textura;
    
    int DirecaoColisao, DirecaoMovimento;
    int Vel;
    Som *som;

    void ColisaoHorizontalPositiva(SDL_Rect destM);
    void ColisaoHorizontalNegativa(SDL_Rect destM);
    void ColisaoVerticalPositiva(SDL_Rect destM);
    void ColisaoVerticalNegativa(SDL_Rect destM);
public:
    Personagem(int PosX, int PosY, int w, int h, const char* TextureName);
    ~Personagem();

    void Movimento(int Direcao, int Velocidade);
    void Mover();

    void Colisao(int Direcao);
    void ColisaoMapa(Map *mapa);

    int GetDirecaoMovimento();

    void Render();
};

#endif /* OBJETOS_HPP */
