/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: lidou
 * 
 * Created on 5 janvier 2018, 15:28
 */

#include <SDL2/SDL_image.h>
#include "Game.h"

// public methodes

Game::Game() {
    isRunning = true;
    skyBox = new SkyBox();
    plateauBas = new Plateau();
    plateauHaut = new Plateau();
    player = new Player();
}

Game::~Game() {
}

void Game::init() {
    initSDL();
    initOpengl();
    skyBox->init();
    plateauBas->init();
    plateauHaut->init();
    player->init();

}

void Game::game() {
    gameLoop();
}

void Game::clean() {
    cleanOpenGl();
    cleanSDL();
}

//private methodes

void Game::initSDL() {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_JPG);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    win = SDL_CreateWindow("OpenGl Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    // La souris est invisible
    SDL_ShowCursor(false);
    SDL_SetRelativeMouseMode(SDL_TRUE);
}

void Game::initOpengl() {
    SDL_GLContext context = SDL_GL_CreateContext(win);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, (double) 1024 / 768, 1, 1000);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glClearColor(0.f, 0.f, 0.f, 1.f);
}

void Game::gameLoop() {
    SDL_Event event;
    const Uint8* states;
    Uint32 statesMouse;
    Uint32 tick;
    while(isRunning) {
        tick = SDL_GetTicks();
        SDL_PollEvent(&event);
        states = SDL_GetKeyboardState(NULL);
        statesMouse = SDL_GetRelativeMouseState(&xM, &yM);
        
        handleEvent(states, &statesMouse, tick);
        
        std::cout << player->x << "    " << player->y << "    " << tick << std::endl;
        
        cleenScreen();
        renderGame();
        renderScreen();
    }
}

void Game::handleEvent(const Uint8* states, Uint32* statesMouse, Uint32 tick) {
    if (states[SDL_SCANCODE_ESCAPE]) {
        isRunning = false;
    }
}

void Game::renderGame() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(40,40,50,player->x,player->y,50,0,0,1);
    
    glPushMatrix();
    skyBox->render();
    glPopMatrix();
    glPushMatrix();
    plateauBas->render();
    glPopMatrix();
//    glPushMatrix();
//    glTranslated(0,0,95);
//    plateauHaut->render();
//    glPopMatrix();
//    glPushMatrix();
//    glTranslated(0,0,50);
//    player->render();
//    glPopMatrix();
}

void Game::addCube(Uint32 tick) {
    
}

void Game::cleenScreen() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Game::renderScreen() {
    glFlush();
    SDL_GL_SwapWindow(win);
}

void Game::cleanOpenGl() {
    SDL_GL_DeleteContext(context);
}

void Game::cleanSDL() {
    SDL_DestroyWindow(win);
    IMG_Quit();
    SDL_Quit();
}