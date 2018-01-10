/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cube.cpp
 * Author: jeff
 * 
 * Created on 5 janvier 2018, 15:28
 */

#include "Cube.h"

Cube::Cube() {
    z = 100;
    vZ = 5;
    rectTick = 0;
    isTouch = false;
    isAtEnd = false;
};

Cube::~Cube() {
    glDeleteLists(idList, 1);
}

void Cube::render() {
    glPushMatrix();
    glTranslated(0,0,z);
    glCallList(idList);
    glPopMatrix();
}

bool Cube::isTouched(Player* cubeToTest) {
    
    
    isTouch = true;
}

void Cube::decendre(Uint32 tick) {
    if (isTouch && isAtEnd && tick > rectTick + 60) {
        z -= vZ;
    }
}

void Cube::init() {
    idList = glGenLists(1);
    glNewList(idList, GL_COMPILE);
    
    glBegin(GL_QUADS);
    glColor3ub(0,255,0);
    glVertex3d(-1.5,0,0);
    glVertex3d(0,1.5,0);
    glVertex3d(1.5,0,0);
    glVertex3d(0,-1.5,0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex3d(-1.5,0,0);
    glVertex3d(-1.5,0,3);
    glVertex3d(0,-1.5,3);
    glVertex3d(0,-1.5,0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
    glVertex3d(0,-1.5,0);
    glVertex3d(0,-1.5,3);
    glVertex3d(1.5,0,3);
    glVertex3d(1.5,0,0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex3d(1.5,0,0);
    glVertex3d(1.5,0,3);
    glVertex3d(0,1.5,3);
    glVertex3d(0,1.5,0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
    glVertex3d(-1.5,0,0);
    glVertex3d(-1.5,0,3);
    glVertex3d(0,1.5,3);
    glVertex3d(0,1.5,0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3d(-1.5,0,3);
    glVertex3d(0,1.5,3);
    glVertex3d(1.5,0,3);
    glVertex3d(0,-1.5,3);
    glEnd();
    
    glEndList();
}

