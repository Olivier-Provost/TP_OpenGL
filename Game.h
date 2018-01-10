/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: lidou
 *
 * Created on 5 janvier 2018, 15:28
 */

#ifndef GAME_H
#define GAME_H
#include "include.h"
#include "SkyBox.h"
#include "Plateau.h"
#include "Player.h"
#include "Cube.h"
#include <vector>

class Game {
public:
    Game();
    virtual ~Game();
    
    void init();
    void game();
    void clean();
    
private:
    SDL_Window* win;
    SDL_GLContext context;
    
    SkyBox* skyBox;
    Plateau *plateauBas, *plateauHaut;
    Player *player;
    std::vector<Cube*> cubes;
    
    int nbTouche;
    int fps = 60;
    
    bool isRunning;
    void initSDL();
    void initOpengl();
    int xM, yM;
    Uint32 tickCube,timeNextCube;
    void gameLoop();
    void cleenScreen();
    void renderGame();
    void renderScreen();
    void handleEvent(const Uint8* states, Uint32* statesMouse,Uint32 tick);
    void cleanOpenGl();
    void cleanSDL();
    void addCube(Uint32 tick);

};

#endif /* GAME_H */

