/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: androidlinux
 * 
 * Created on 10 janvier 2018, 08:48
 */

#include "Game.h"
#include <SDL2/SDL_image.h>

// méthodes publiques

Game::Game() {
    isRunning = true;
    tableau = new Tableau(10, 10);
    x = 100;
    y = 100;
}

Game::~Game() {
}

void Game::init() {
    initSDL();
    initOpengl();
    tableau->init(tableau->getNbLignes(), tableau->getTailleCase());
}

void Game::game() {
    gameLoop();
}

void Game::clean() {
    cleanOpenGl();
    cleanSDL();
}

// méthodes privées

void Game::initSDL() {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    win = SDL_CreateWindow("TP_OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
}

void Game::initOpengl() {
    context = SDL_GL_CreateContext(win);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, (double) 800 / 800, 1, 1000);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glClearColor(0.f, 0.f, 0.f, 1.f);
}

void Game::cleanOpenGl() {
    SDL_GL_DeleteContext(context);
}

void Game::cleanSDL() {
    SDL_DestroyWindow(win);
    IMG_Quit();
    SDL_Quit();
}

int Game::getX() {
    return x;
}

int Game::getY() {
    return y;
}

int Game::setX(int x) {
    this->x = x;
}

int Game::setY(int y) {
    this->y = y;
}

void Game::gameLoop() {
    SDL_Event event;
    const Uint8* states;
    Uint32 tick;
    while (isRunning) {
        tick = SDL_GetTicks();
        SDL_PollEvent(&event);
        states = SDL_GetKeyboardState(NULL);
        
        handleEvent(&event, states, tick);
        
        cleanScreen();
        renderGame();
        renderScreen();
    }
}

void Game::handleEvent(SDL_Event* event, const Uint8* states, Uint32 tick) {
    int tempX = getX();
    int tempY = getY();
    if (event->type == SDL_QUIT || states[SDL_SCANCODE_ESCAPE])
        isRunning = false;
    if (states[SDL_SCANCODE_UP]) {
        tempY++;
    }
    if (states[SDL_SCANCODE_DOWN]) {
        tempY--;
    }
    if (states[SDL_SCANCODE_LEFT]) {
        tempX--;
    }
    if (states[SDL_SCANCODE_RIGHT]) {
        tempX++;
    }
    
    setX(tempX);
    setY(tempY);
}

void Game::cleanScreen() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Game::renderGame() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(getX(),getY(),120,0,0,0,0,0,1);
    
    glPushMatrix();
    tableau->render();
    glPopMatrix();
}

void Game::renderScreen() {
    glFlush();
    SDL_GL_SwapWindow(win);
}