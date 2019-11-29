/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Som.hpp"

Som::Som() {
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    MovimentacaoPersonagem = Mix_LoadWAV("Sounds/Personagem/Mover.wav");
    fase1 = Mix_LoadWAV("Sounds/Mapa/1980.wav");
    fase2 = Mix_LoadWAV("Sounds/Mapa/1990.wav");
    fase3 = Mix_LoadWAV("Sounds/Mapa/2000.wav");
    fase4 = Mix_LoadWAV("Sounds/Mapa/2010.wav");
}

Som::~Som() {
    Mix_FreeChunk(MovimentacaoPersonagem);
    Mix_FreeChunk(fase1);
    Mix_FreeChunk(fase2);
    Mix_FreeChunk(fase3);
    Mix_FreeChunk(fase4);
    Mix_Quit();
}

void Som::TocarSom(int Canal, char NomeSom[], int NumeroRepeticoes) {
    if (strcmp(NomeSom, "Mover") == 0) {
        Mix_PlayChannel(Canal, MovimentacaoPersonagem, NumeroRepeticoes);
    }
    
    if (strcmp(NomeSom, "fase1") == 0) {
        Mix_PlayChannel(Canal, fase1, NumeroRepeticoes);
    }
    
    if (strcmp(NomeSom, "fase2") == 0) {
        Mix_PlayChannel(Canal, fase2, NumeroRepeticoes);
    }
    
    if (strcmp(NomeSom, "fase3") == 0) {
        Mix_PlayChannel(Canal, fase3, NumeroRepeticoes);
    }
    
    if (strcmp(NomeSom, "fase4") == 0) {
        Mix_PlayChannel(Canal, fase4, NumeroRepeticoes);
    }
}
