/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plateau.h
 * Author: jeff
 *
 * Created on 5 janvier 2018, 15:28
 */

#ifndef PLATEAU_H
#define PLATEAU_H
#include "include.h"

class Plateau {
public:
    Plateau();
    virtual ~Plateau(); 
    void render();
    void init();
private:
    GLuint idList, idTextureSol, idTextureMur;
};

#endif /* PLATEAU_H */

