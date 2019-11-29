/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Som.hpp
 * Author: Luiz Antunes
 *
 * Created on 6 de Outubro de 2018, 16:19
 */

#ifndef SOM_HPP
#define SOM_HPP

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

#include <iostream>
#include <cstring>

class Som {
private:
    Mix_Chunk *MovimentacaoPersonagem;
    Mix_Chunk *fase1;
    Mix_Chunk *fase2;
    Mix_Chunk *fase3;
    Mix_Chunk *fase4;
public:
    Som();
    ~Som();

    void TocarSom(int Canal, char NomeSom[20], int NumeroRepeticoes);
};

#endif /* SOM_HPP */

