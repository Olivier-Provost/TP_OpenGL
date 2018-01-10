/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cube.h
 * Author: jeff
 *
 * Created on 5 janvier 2018, 15:28
 */

#ifndef CUBE_H
#define CUBE_H
#include "include.h"
#include "Player.h"

class Cube {
public:
    Cube();
    virtual ~Cube();
    void render();
    void init();
    bool isTouch, isAtEnd;
    bool isMove, isVisible;
    
    Uint32 rectTick;
    void decendre(Uint32 tick);
    bool isTouched(Player *cubeToTest);
    double x, y, z;
    double vZ;

private:
    GLuint idList;
};

#endif /* CUBE_H */

