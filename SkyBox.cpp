/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SkyBox.cpp
 * Author: jeff
 * 
 * Created on 5 janvier 2018, 15:29
 */

#include "SkyBox.h"

SkyBox::SkyBox() {
}

SkyBox::~SkyBox() {
    glDeleteLists(idList, 1);
    glDeleteTextures(1, &idLeft);
    glDeleteTextures(1, &idFront);
    glDeleteTextures(1, &idRight);
    glDeleteTextures(1, &idBack);
    glDeleteTextures(1, &idTop);
    glDeleteTextures(1, &idBot);
}

void SkyBox::render() {   
    glPushMatrix();
    glCallList(idList);
    glPopMatrix();
}

void SkyBox::init() {   
    idLeft = loadTexture("img/left.jpg");
    idFront = loadTexture("img/front.jpg");
    idRight = loadTexture("img/right.jpg");
    idBack = loadTexture("img/back.jpg");
    idTop = loadTexture("img/top.jpg");
    idBot = loadTexture("img/bottom.jpg");
    
    idList = glGenLists(1);
    glNewList(idList, GL_COMPILE);
    
    //Front
    glBindTexture(GL_TEXTURE_2D, idFront);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,0);
    glVertex3i(-50, 50, 0);
    glTexCoord2d(0,1);
    glVertex3i(-50, 50, 100);
    glTexCoord2d(1,1);
    glVertex3i(50, 50, 100);
    glTexCoord2d(1,0);
    glVertex3i(50, 50, 0);
    glEnd();
    
    //Right
    glBindTexture(GL_TEXTURE_2D, idRight);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,0);
    glVertex3i(50, 50, 0);
    glTexCoord2d(0,1);
    glVertex3i(50, 50, 100);
    glTexCoord2d(1,1);
    glVertex3i(50, -50, 100);
    glTexCoord2d(1,0);
    glVertex3i(50, -50, 0);
    glEnd();
    
    //Back
    glBindTexture(GL_TEXTURE_2D, idBack);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,0);
    glVertex3i(50, -50, 0);
    glTexCoord2d(0,1);
    glVertex3i(50, -50, 100);
    glTexCoord2d(1,1);
    glVertex3i(-50, -50, 100);
    glTexCoord2d(1,0);
    glVertex3i(-50, -50, 0);
    glEnd();
    
    //Left
    glBindTexture(GL_TEXTURE_2D, idLeft);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,0);
    glVertex3i(-50, -50, 0);
    glTexCoord2d(0,1);
    glVertex3i(-50, -50, 100);
    glTexCoord2d(1,1);
    glVertex3i(-50, 50, 100);
    glTexCoord2d(1,0);
    glVertex3i(-50, 50, 0);
    glEnd();
    
    //Top
    glBindTexture(GL_TEXTURE_2D, idTop);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,0);
    glVertex3i(-50, -50, 100);
    glTexCoord2d(0,1);
    glVertex3i(-50, 50, 100);
    glTexCoord2d(1,1);
    glVertex3i(50, 50, 100);
    glTexCoord2d(1,0);
    glVertex3i(50, -50, 100);
    
    //Bottom
    glBindTexture(GL_TEXTURE_2D, idBot);
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2d(0,0);
    glVertex3i(-50, -50, 100);
    glTexCoord2d(0,1);
    glVertex3i(-50, 50, 100);
    glTexCoord2d(1,1);
    glVertex3i(50, 50, 100);
    glTexCoord2d(1,0);
    glVertex3i(50, -50, 100);
    
    glEndList();
}

