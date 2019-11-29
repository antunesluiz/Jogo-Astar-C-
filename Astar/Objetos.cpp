/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Objetos.hpp"
#include "TextureManager.hpp"

Personagem::Personagem(int PosX, int PosY, int w, int h, const char* TextureName) {
    Textura = TextureManager::LoadTexture(TextureName);

    src.h = dest.h = h;
    src.w = dest.w = w;
    src.x = dest.x = PosX;
    src.y = dest.y = PosY;

    DirecaoMovimento = 0;

    som = new Som();
}

void Personagem::Movimento(int Direcao, int Velocidade) {
    DirecaoMovimento = Direcao;
    Vel = Velocidade;
}

void Personagem::Mover() {
    if (DirecaoMovimento == 1) {
        dest.y = dest.y + Vel;
    } else {
        if (DirecaoMovimento == 2) {
            dest.y = dest.y - Vel;
        } else {
            if (DirecaoMovimento == 3) {
                dest.x = dest.x + Vel;
            } else {
                if (DirecaoMovimento == 4) {
                    dest.x = dest.x - Vel;
                }
            }
        }
    }
}

void Personagem::Colisao(int Direcao) {
    DirecaoColisao = Direcao;
}

void Personagem::ColisaoMapa(Map* mapa) {
    int type, map[TamanhoMatriz][TamanhoMatriz];
    SDL_Rect destM;
    destM.h = 32;
    destM.w = 32;

    mapa->GetMap(map);

    for (int row = 0; row < TamanhoMatriz; row++) {
        for (int column = 0; column < TamanhoMatriz; column++) {
            type = map[row][column];

            destM.x = column * 32;
            destM.y = row * 32;

            switch (type) {
                case 0:
                    break;
                case 4:
                    if (DirecaoColisao == 1) {
                        if (dest.x == destM.x && (dest.y + dest.h >= destM.y && dest.y <= destM.y + destM.h)) {
                            map[row][column] = 0;
                        }
                    } else {
                        if (DirecaoColisao == 2) {
                            if (dest.x == destM.x && (dest.y <= destM.y + destM.h && dest.y + dest.h >= destM.y)) {
                                map[row][column] = 0;
                            }
                        } else {
                            if (DirecaoColisao == 3) {
                                if (dest.y == destM.y && (dest.x + dest.w >= destM.x && dest.x <= destM.x + destM.w)) {
                                    map[row][column] = 0;
                                }
                            } else {
                                if (DirecaoColisao == 4) {
                                    if (dest.y == destM.y && (dest.x <= destM.x + destM.w && dest.x + dest.w >= destM.x)) {
                                        map[row][column] = 0;
                                    }
                                }
                            }
                        }
                    }
                    break;
                default:
                    if (DirecaoColisao == 1) {
                        Personagem::ColisaoVerticalPositiva(destM);
                    } else {
                        if (DirecaoColisao == 2) {
                            Personagem::ColisaoVerticalNegativa(destM);
                        } else {
                            if (DirecaoColisao == 3) {
                                Personagem::ColisaoHorizontalPositiva(destM);
                            } else {
                                if (DirecaoColisao == 4) {
                                    Personagem::ColisaoHorizontalNegativa(destM);
                                }
                            }
                        }
                    }
                    break;
            }

            mapa->SetMap(map);
        }
    }

    mapa->ContaDiscos();
}

void Personagem::ColisaoHorizontalNegativa(SDL_Rect destM) {
    if (dest.y == destM.y && dest.x == destM.x + destM.w) {
        DirecaoMovimento = 0;
    }
}

void Personagem::ColisaoHorizontalPositiva(SDL_Rect destM) {
    if (dest.y == destM.y && dest.x + dest.w == destM.x) {
        DirecaoMovimento = 0;
    }
}

void Personagem::ColisaoVerticalNegativa(SDL_Rect destM) {
    if (dest.x == destM.x && dest.y == destM.y + destM.h) {
        DirecaoMovimento = 0;
    }
}

void Personagem::ColisaoVerticalPositiva(SDL_Rect destM) {
    if (dest.x == destM.x && dest.y + dest.h == destM.y) {
        DirecaoMovimento = 0;
    }
}

int Personagem::GetDirecaoMovimento() {
    return DirecaoMovimento;
}

void Personagem::Render() {
    TextureManager::Draw(Textura, src, dest);
}

Personagem::~Personagem() {

}




