/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Game.hpp"

SDL_Renderer* Game::renderer = nullptr;

Game::Game() {
    Maplvl = 0;
    menu = true;
    instrucao = false;
}

Game::~Game() {

}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;

    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        cout << "Subsistemas da sdl inicializada!..." << endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            cout << "Janela criada!" << endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            cout << "Renderizacao criada" << endl;
        }

        isRunning = true;
    } else {
        isRunning = false;
    }

    mapa = new Map(Maplvl);
    personagem = new Personagem(64, 64, 32, 32, "Imagens/TexturaPersonagem/TestePersonagem.png");

    menuprincipal = new Menu(0, 0, 640, 640, "Imagens/TexturaMenu/MenuPrincipal.png");
    botaoprincipal = new Menu(190, 30, 291, 170, "Imagens/TexturaMenu/BotaoPrincipal.png");
    instrucoes = new Menu(0, 0, 640, 640, "Imagens/TexturaMenu/Instrucoes.png");

    som = new Som;
    som->TocarSom(1, "fase4", 5);
}

void Game::HandleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:
                    if (personagem->GetDirecaoMovimento() == 0) {
                        personagem->Movimento(4, 4);
                        personagem->Colisao(4);
                    }
                    break;
                case SDLK_RIGHT:
                    if (personagem->GetDirecaoMovimento() == 0) {
                        personagem->Movimento(3, 4);
                        personagem->Colisao(3);
                    }
                    break;
                case SDLK_UP:
                    if (personagem->GetDirecaoMovimento() == 0) {
                        personagem->Movimento(2, 4);
                        personagem->Colisao(2);
                    }
                    break;
                case SDLK_DOWN:
                    if (personagem->GetDirecaoMovimento() == 0) {
                        personagem->Movimento(1, 4);
                        personagem->Colisao(1);
                    }
                    break;
                case SDLK_b:
                    instrucao = false;
                    break;
                case SDLK_m:
                    delete(mapa);
                    Maplvl = 0;
                    mapa = new Map(0);
                    menu = true;
                    instrucao = false;

                    break;
                case SDLK_i:
                    instrucao = true;
            }
        case SDL_MOUSEMOTION:
            int a, b;
            SDL_GetMouseState(&a, &b);

            if (a >= botaoprincipal->GetRect().x && a <= botaoprincipal->GetRect().x + botaoprincipal->GetRect().w) {
                if (b >= botaoprincipal->GetRect().y && b <= botaoprincipal->GetRect().y + botaoprincipal->GetRect().h) {
                    botaoprincipal->SetMotion(true);
                } else {
                    botaoprincipal->SetMotion(false);
                }
            } else {
                botaoprincipal->SetMotion(false);
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x, y;
            SDL_GetMouseState(&x, &y);

            if (x >= botaoprincipal->GetRect().x && x <= botaoprincipal->GetRect().x + botaoprincipal->GetRect().w) {
                if (y >= botaoprincipal->GetRect().y && y <= botaoprincipal->GetRect().y + botaoprincipal->GetRect().h) {
                    delete(mapa);
                    Maplvl += 1;
                    mapa = new Map(Maplvl);
                    menu = false;

                    delete(personagem);
                    personagem = new Personagem(64, 64, 32, 32, "Imagens/TexturaPersonagem/TestePersonagem.png");
                }
            }
    }
}

void Game::Update() {
    personagem->Mover();
    personagem->ColisaoMapa(mapa);

    if (Maplvl == 0) {
        mapa->SetDiscos(1);
    }

    if (mapa->GetQuantDiscos() == 0) {
        if (menu == false) {
            delete(mapa);
            delete(personagem);

            if (Maplvl < 5) {
                if (menu == false) {
                    cout << Maplvl << endl;

                    Maplvl += 1;
                } else {
                    Maplvl = 0;
                }
            } else {
                Maplvl = 0;
            }

            mapa = new Map(Maplvl);
            personagem = new Personagem(64, 64, 32, 32, "Imagens/TexturaPersonagem/TestePersonagem.png");
        }
    }
}

void Game::Render() {
    SDL_RenderClear(renderer);

    if (Maplvl == 0) {
        menuprincipal->Render();

        if (botaoprincipal->GetMotion() == true) {
            botaoprincipal->Render();
        }
    }

    if (Maplvl != 0) {
        personagem->Render();
    }

    if (instrucao == true && Maplvl == 0) {
        SDL_RenderClear(renderer);
        instrucoes->Render();
    }

    mapa->DrawMap();
    SDL_RenderPresent(renderer);
}

void Game::Clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    delete(mapa);
    delete(personagem);
    delete(menuprincipal);
    delete(botaoprincipal);
    delete(som);
    delete(instrucoes);

    cout << "Jogo finalizado!" << endl;
}

bool Game::Running() {
    return isRunning;
}