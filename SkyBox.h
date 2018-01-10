/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SkyBox.h
 * Author: jeff
 *
 * Created on 5 janvier 2018, 15:29
 */

#ifndef SKYBOX_H
#define SKYBOX_H


#include "include.h"

class SkyBox {
public:
    SkyBox();
    virtual ~SkyBox();
    void render();
    void init();
private:
    GLuint idList, idLeft, idFront, idRight, idBack, idTop, idBot;
};

#endif /* SKYBOX_H */

