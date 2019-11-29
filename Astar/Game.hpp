/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.hpp
 * Author: Luiz Antunes
 *
 * Created on 4 de Outubro de 2018, 21:05
 */

#ifndef GAME_HPP
#define GAME_HPP

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include <iostream>
#include <cstdlib>

#include "Map.hpp"
#include "Objetos.hpp"
#include "Menu.hpp"
#include "Som.hpp"

using namespace std;

class Game {
private:
    SDL_Window* window;
    bool isRunning;

    Map *mapa;
    
    Personagem *personagem;
    
    Menu *menuprincipal;
    Menu *botaoprincipal;
    Menu *instrucoes;
    Menu *botaoinstrucoes;
    
    Som *som;
    
    int Maplvl;
    bool menu;
    bool instrucao;
public:
    Game();
    ~Game();

    void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void HandleEvents();
    void Update();
    void Render();
    void Clean();

    bool Running();

    static SDL_Renderer* renderer;
};

#endif /* GAME_HPP */