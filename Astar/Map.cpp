/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Map.hpp"
#include "TextureManager.hpp"

Map::Map(int mapa) {
    Bloco = TextureManager::LoadTexture("Imagens/TexturaMapa/Bloco.png");
    Disco = TextureManager::LoadTexture("Imagens/TexturaMapa/Disco.png");

    if (mapa == 1) {
        LoadMatrizFromFile(lvl1, "Mapas/lvl1.txt");
        LoadMap(lvl1);
        QuantDiscos = 6;
    } else {
        if (mapa == 2) {
            LoadMatrizFromFile(lvl2, "Mapas/lvl2.txt");
            LoadMap(lvl2);
        } else {
            if (mapa == 3) {
                LoadMatrizFromFile(lvl3, "Mapas/lvl3.txt");
                LoadMap(lvl3);
            } else {
                if (mapa == 4) {
                    LoadMatrizFromFile(lvl4, "Mapas/lvl4.txt");
                    LoadMap(lvl4);
                } else {
                    if (mapa == 0) {
                        LoadMatrizFromFile(lvl0, "Mapas/lvl0.txt");
                        LoadMap(lvl0);
                    }
                }
            }
        }
    }

    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;

    dest.x = dest.y = 0;
}

Map::~Map() {

}

void Map::LoadMatrizFromFile(int arr[TamanhoMatriz][TamanhoMatriz], const char* NomeArquivo) {
    FILE *arq;
    int i = 0, j = 0;

    arq = fopen(NomeArquivo, "r");

    if (arq == NULL) {
        cout << "Nao foi possivel abrir o arquivpo!" << endl;
    } else {
        for (i = 0; i < TamanhoMatriz; i++) {
            for (j = 0; j < TamanhoMatriz; j++) {
                fscanf(arq, "%1d", &arr[i][j]);
            }
        }
    }

    fclose(arq);
}

void Map::LoadMap(int arr[TamanhoMatriz][TamanhoMatriz]) {
    for (int row = 0; row < TamanhoMatriz; row++) {
        for (int column = 0; column < TamanhoMatriz; column++) {
            map[row][column] = arr[row][column];
        }
    }
}

int Map::GetMap(int x[TamanhoMatriz][TamanhoMatriz]) {
    for (int i = 0; i < TamanhoMatriz; i++) {
        for (int j = 0; j < TamanhoMatriz; j++) {
            x[i][j] = map[i][j];
        }
    }
}

void Map::DrawMap() {
    int type;

    for (int row = 0; row < TamanhoMatriz; row++) {
        for (int column = 0; column < TamanhoMatriz; column++) {
            type = map[row][column];

            dest.x = column * 32;
            dest.y = row * 32;

            switch (type) {
                case 1:
                    TextureManager::Draw(Bloco, src, dest);
                    break;
                case 4:
                    TextureManager::Draw(Disco, src, dest);
                    break;
            }
        }
    }
}

void Map::SetMap(int x[TamanhoMatriz][TamanhoMatriz]) {
    for (int i = 0; i < TamanhoMatriz; i++) {
        for (int j = 0; j < TamanhoMatriz; j++) {
            map[i][j] = x[i][j];
        }
    }
}

void Map::ContaDiscos() {
    int quant = 0;

    for (int i = 0; i < TamanhoMatriz; i++) {
        for (int j = 0; j < TamanhoMatriz; j++) {
            if (map[i][j] == 4) {
                quant++;
            }
        }
    }

    QuantDiscos = quant;
}

int Map::GetQuantDiscos() {
    return QuantDiscos;
}

void Map::SetDiscos(int x) {
    QuantDiscos = x;
}

