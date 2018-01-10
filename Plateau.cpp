/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plateau.cpp
 * Author: jeff
 * 
 * Created on 5 janvier 2018, 15:28
 */

#include "Plateau.h"

Plateau::Plateau() {
}

Plateau::~Plateau() {
    glDeleteLists(idList, 1);
    glDeleteTextures(1, &idTextureMur);
    glDeleteTextures(1, &idTextureSol);
}

void Plateau::render() {
    glPushMatrix();
    glCallList(idList);
    glPopMatrix();
}

void Plateau::init() {   
    idTextureMur = loadTexture("img/bambou.jpg");
    idTextureSol = loadTexture("img/sol.jpg");
    
    idList = glGenLists(1);
    glNewList(idList, GL_COMPILE);
    
    glBindTexture(GL_TEXTURE_2D, idTextureSol);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,0);
    glVertex3i(-25, -25, 5);
    glTexCoord2d(0,10);
    glVertex3i(-25, 25, 5);
    glTexCoord2d(10,10);
    glVertex3i(25, 25, 5);
    glTexCoord2d(10,0);
    glVertex3i(25, -25, 5);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, idTextureMur);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,0);
    glVertex3i(-25, -25, 0);
    glTexCoord2d(0,1);
    glVertex3i(-25, -25, 5);
    glTexCoord2d(10,1);
    glVertex3i(25, -25, 5);
    glTexCoord2d(10,0);
    glVertex3i(25, -25, 0);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, idTextureMur);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,0);
    glVertex3i(-25, -25, 0);
    glTexCoord2d(0,1);
    glVertex3i(-25, -25, 5);
    glTexCoord2d(10,1);
    glVertex3i(-25, 25, 5);
    glTexCoord2d(10,0);
    glVertex3i(-25, 25, 0);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, idTextureMur);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,0);
    glVertex3i(25, 25, 0);
    glTexCoord2d(0,1);
    glVertex3i(25, 25, 5);
    glTexCoord2d(10,1);
    glVertex3i(-25, 25, 5);
    glTexCoord2d(10,0);
    glVertex3i(-25, 25, 0);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, idTextureMur);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,0);
    glVertex3i(25, 25, 0);
    glTexCoord2d(0,1);
    glVertex3i(25, 25, 5);
    glTexCoord2d(10,1);
    glVertex3i(25, -25, 5);
    glTexCoord2d(10,0);
    glVertex3i(25, -25, 0);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, idTextureSol);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,0);
    glVertex3i(-25, -25, 0);
    glTexCoord2d(0,10);
    glVertex3i(-25, 25, 0);
    glTexCoord2d(10,10);
    glVertex3i(25, 25, 0);
    glTexCoord2d(10,0);
    glVertex3i(25, -25, 0);
    glEnd();
    
    glEndList();
}
