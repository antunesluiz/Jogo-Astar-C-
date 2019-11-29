/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Menu.hpp"
#include "TextureManager.hpp"

Menu::Menu(int x, int y, int w, int h, const char* nome) {
    textura = TextureManager::LoadTexture(nome);
    
    src.h = dest.h = h;
    src.w = dest.w = w;
    src.x = dest.x = x;
    src.y = dest.y = y;
}

void Menu::Render() {
    TextureManager::Draw(textura, src, dest);
}

SDL_Rect Menu::GetRect() {
    return dest;
}

bool Menu::GetMotion() {
    return motion;
}

void Menu::SetMotion(bool x) {
    motion = x;
}

Menu::~Menu() {
    
}

