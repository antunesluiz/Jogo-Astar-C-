/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menus.hpp
 * Author: Luiz Antunes
 *
 * Created on 2 de Novembro de 2018, 10:44
 */

#ifndef MENU_HPP
#define MENU_HPP

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

class Menu {
protected:
    SDL_Rect src, dest;
    SDL_Texture *textura;
    bool motion;
public:
    Menu(int x, int y, int w, int h, const char* nome);
    ~Menu();
    
    void Render();
    
    SDL_Rect GetRect();
    void SetMotion(bool x);
    bool GetMotion();
};

#endif /* MENU_HPP */

