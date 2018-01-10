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

#include "Player.h"

Player::Player() {
    
};

Player::~Player() {   
    glDeleteLists(idList, 1);
}

void Player::avancer(double distance) {   
    x -= distance * cos(alpha * M_PI / 180) * cos(phi * M_PI /180);
    y -= distance * sin(alpha * M_PI / 180) * cos(phi * M_PI /180);
    z += distance * sin(phi * M_PI / 180);
}

void Player::reculer(double distance) {  
    x += distance * cos(alpha * M_PI / 180);
    y += distance * sin(alpha * M_PI / 180);
    z -= distance * sin(phi * M_PI / 180);
}

void Player::render() {
    glPushMatrix();
    
    glRotated(alpha, 0, 0, 1);
    glRotated(phi, 0, 1, 0);
    
    glCallList(idList);
    glPopMatrix();
}


void Player::init() {  
    idList = glGenLists(1);
    glNewList(idList, GL_COMPILE);
    
    //Front
    glBegin(GL_QUADS);
    glColor3ub(0,255,0);
    glVertex3i(0,0,0);
    glVertex3i(0,0,3);
    glVertex3i(3,0,3);
    glVertex3i(3,0,0);
    glEnd();
    
    //Back
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
    glVertex3i(0,3,0);
    glVertex3i(0,3,3);
    glVertex3i(3,3,3);
    glVertex3i(3,3,0);
    glEnd();
    
    //Côtés pairs
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3i(0,0,0);
    glVertex3i(0,3,0);
    glVertex3i(0,3,3);
    glVertex3i(0,0,3);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3i(3,0,0);
    glVertex3i(3,3,0);
    glVertex3i(3,3,3);
    glVertex3i(3,0,3);
    glEnd();
    
    //Côtés impairs
    glBegin(GL_QUADS);
    glColor3ub(255,0,55);
    glVertex3i(0,0,0);
    glVertex3i(3,0,0);
    glVertex3i(3,3,0);
    glVertex3i(0,3,0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3ub(255,0,55);
    glVertex3i(0,0,3);
    glVertex3i(3,0,3);
    glVertex3i(3,3,3);
    glVertex3i(0,3,3);
    glEnd();
    
    glEndList();
}

