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

#ifndef PLAYER_H
#define PLAYER_H
#include "include.h"

class Player {
public:
    Player();
    virtual ~Player();
    void render();
    void init();
    double phi, alpha;
    void avancer(double distance);
    void reculer(double distance);
    double x, y, z;

private:
    GLuint idList;
};

#endif /* PLAYER_H */

