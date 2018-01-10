/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: androidlinux
 *
 * Created on 10 janvier 2018, 08:48
 */

#ifndef GAME_H
#define GAME_H
#include "include.h"
#include "Tableau.h"

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
    
    Tableau* tableau;
    
    int fps = 60;
    
    int x, y;
    
    bool isRunning;
    void initSDL();
    void initOpengl();
    void cleanOpenGl();
    void cleanSDL();
    
    int getX();
    int getY();
    int setX(int x);
    int setY(int y);
    
    void gameLoop();
    void handleEvent(SDL_Event* event, const Uint8* states, Uint32 tick);
    
    void cleanScreen();
    void renderGame();
    void renderScreen();

};

#endif /* GAME_H */

