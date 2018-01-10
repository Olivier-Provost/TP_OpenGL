/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tableau.cpp
 * Author: androidlinux
 * 
 * Created on 10 janvier 2018, 08:13
 */

#include "Tableau.h"

Tableau::Tableau() {
    nbLignes = 0;
    tailleCase = 0;
}

Tableau::Tableau(int nbLignes, int tailleCase) {
    this->nbLignes = nbLignes;
    this->tailleCase = tailleCase;
}

Tableau::~Tableau() {
    glDeleteLists(idList, 1);
    glDeleteTextures(1, &idHerbe);
    glDeleteTextures(1, &idBrick);
}

int Tableau::getNbLignes() {
    return nbLignes;
}

int Tableau::getTailleCase() {
    return tailleCase;
}

void Tableau::render() {
    glCallList(idList);
}

void Tableau::init(int nbLignes, int tailleCase) {
    idBrick = loadTexture("brick.jpg");
    idHerbe = loadTexture("herbe.jpg");
    
    idList = glGenLists(1);
    glNewList(idList, GL_COMPILE);
    
    plateau(nbLignes, tailleCase);
    mursExterieur(nbLignes, tailleCase);
    lignes(nbLignes, tailleCase);
    
    glEndList();
}

void Tableau::plateau(int nbLignes, int tailleCase) {
    //dessous
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 0);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 0);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 0);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 0);
        glEnd();

        //Exterieur
        glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0, 0);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 0);
        glTexCoord2d(0, 1);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 10);
        glTexCoord2d(5, 1);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 10);
        glTexCoord2d(5, 0);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 0);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0, 0);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 0);
        glTexCoord2d(0, 1);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 10);
        glTexCoord2d(5, 1);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 10);
        glTexCoord2d(5, 0);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 0);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0, 0);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 0);
        glTexCoord2d(0, 1);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 10);
        glTexCoord2d(5, 1);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 10);
        glTexCoord2d(5, 0);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 0);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0, 0);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 0);
        glTexCoord2d(0, 1);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 10);
        glTexCoord2d(5, 1);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 10);
        glTexCoord2d(5, 0);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 0);
        glEnd();

        //plancher
        //glBindTexture(GL_TEXTURE_2D, idHerbe);
        glBegin(GL_QUADS);
        glColor3ub(222, 222, 222);
        //glTexCoord2d(0, 0);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 10);
        //glTexCoord2d(0, 1);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 10);
        //glTexCoord2d(1, 1);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 10);
        //glTexCoord2d(1, 0);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 10);
        glEnd();
    }

void Tableau::mursExterieur(int nbLignes, int tailleCase) {
    //murs extérieurs
        glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0, 0);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 10);
        glTexCoord2d(0, 1);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 30);
        glTexCoord2d(5, 1);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 30);
        glTexCoord2d(5, 0);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 10);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0, 0);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 10);
        glTexCoord2d(0, 1);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 30);
        glTexCoord2d(5, 1);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 30);
        glTexCoord2d(5, 0);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 10);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0, 0);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 10);
        glTexCoord2d(0, 1);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 30);
        glTexCoord2d(5, 1);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 30);
        glTexCoord2d(5, 0);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 10);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0, 0);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 10);
        glTexCoord2d(0, 1);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 30);
        glTexCoord2d(5, 1);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 30);
        glTexCoord2d(5, 0);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 10);
        glEnd();

        //murs intérieurs
        glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0, 0);
        glVertex3i(-(nbLignes / 2 * tailleCase), (nbLignes / 2 * tailleCase), 10);
        glTexCoord2d(0, 1);
        glVertex3i(-(nbLignes / 2 * tailleCase), (nbLignes / 2 * tailleCase), 30);
        glTexCoord2d(5, 1);
        glVertex3i((nbLignes / 2 * tailleCase), (nbLignes / 2 * tailleCase), 30);
        glTexCoord2d(5, 0);
        glVertex3i((nbLignes / 2 * tailleCase), (nbLignes / 2 * tailleCase), 10);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0, 0);
        glVertex3i((nbLignes / 2 * tailleCase), (nbLignes / 2 * tailleCase), 10);
        glTexCoord2d(0, 1);
        glVertex3i((nbLignes / 2 * tailleCase), (nbLignes / 2 * tailleCase), 30);
        glTexCoord2d(5, 1);
        glVertex3i((nbLignes / 2 * tailleCase), -(nbLignes / 2 * tailleCase), 30);
        glTexCoord2d(5, 0);
        glVertex3i((nbLignes / 2 * tailleCase), -(nbLignes / 2 * tailleCase), 10);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0, 0);
        glVertex3i((nbLignes / 2 * tailleCase), -(nbLignes / 2 * tailleCase), 10);
        glTexCoord2d(0, 1);
        glVertex3i((nbLignes / 2 * tailleCase), -(nbLignes / 2 * tailleCase), 30);
        glTexCoord2d(5, 1);
        glVertex3i(-(nbLignes / 2 * tailleCase), -(nbLignes / 2 * tailleCase), 30);
        glTexCoord2d(5, 0);
        glVertex3i(-(nbLignes / 2 * tailleCase), -(nbLignes / 2 * tailleCase), 10);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0, 0);
        glVertex3i(-(nbLignes / 2 * tailleCase), -(nbLignes / 2 * tailleCase), 10);
        glTexCoord2d(0, 1);
        glVertex3i(-(nbLignes / 2 * tailleCase), -(nbLignes / 2 * tailleCase), 30);
        glTexCoord2d(5, 1);
        glVertex3i(-(nbLignes / 2 * tailleCase), (nbLignes / 2 * tailleCase), 30);
        glTexCoord2d(5, 0);
        glVertex3i(-(nbLignes / 2 * tailleCase), (nbLignes / 2 * tailleCase), 10);
        glEnd();

        //Top
        //glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(200, 200, 200);
        //glTexCoord2d(0, 0);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 30);
        //glTexCoord2d(0, 1);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 30);
        //glTexCoord2d(1, 1);
        glVertex3i((nbLignes / 2 * tailleCase), (nbLignes / 2 * tailleCase), 30);
        //glTexCoord2d(1, 0);
        glVertex3i(-(nbLignes / 2 * tailleCase), (nbLignes / 2 * tailleCase), 30);
        glEnd();

        // glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(200, 200, 200);
        // glTexCoord2d(0, 0);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 30);
        // glTexCoord2d(0, 1);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 30);
        // glTexCoord2d(1, 1);
        glVertex3i((nbLignes / 2 * tailleCase), -(nbLignes / 2 * tailleCase), 30);
        //glTexCoord2d(1, 0);
        glVertex3i((nbLignes / 2 * tailleCase), (nbLignes / 2 * tailleCase), 30);
        glEnd();

        //glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(200, 200, 200);
        //glTexCoord2d(0, 0);
        glVertex3i(((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 30);
        //glTexCoord2d(0, 1);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 30);
        //glTexCoord2d(1, 1);
        glVertex3i(-(nbLignes / 2 * tailleCase), -(nbLignes / 2 * tailleCase), 30);
        //glTexCoord2d(1, 0);
        glVertex3i((nbLignes / 2 * tailleCase), -(nbLignes / 2 * tailleCase), 30);
        glEnd();

        //glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(200, 200, 200);
        //glTexCoord2d(0, 0);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), -((nbLignes + 2) / 2 * tailleCase), 30);
        //glTexCoord2d(0, 1);
        glVertex3i(-((nbLignes + 2) / 2 * tailleCase), ((nbLignes + 2) / 2 * tailleCase), 30);
        //glTexCoord2d(1, 1);
        glVertex3i(-(nbLignes / 2 * tailleCase), (nbLignes / 2 * tailleCase), 30);
        //glTexCoord2d(1, 0);
        glVertex3i(-(nbLignes / 2 * tailleCase), -(nbLignes / 2 * tailleCase), 30);
        glEnd();
    }

void Tableau::lignes(int nbLignes, int tailleCase) {
    for (int i = 0; i < nbLignes; i++) {
            glBegin(GL_LINES);
            glColor3ub(255, 0, 0);
            glVertex3d((tailleCase * i) - (nbLignes * tailleCase / 2), -((tailleCase * nbLignes) / 2), 10.01);
            glVertex3d((tailleCase * i) - (nbLignes * tailleCase / 2), ((tailleCase * nbLignes) / 2), 10.01);
            glEnd();
        }
        for (int i = 0; i < nbLignes; i++) {
            glBegin(GL_LINES);
            glColor3ub(255, 0, 0);
            glVertex3d(-((tailleCase * nbLignes) / 2), (tailleCase * i) - (nbLignes * tailleCase / 2), 10.01);
            glVertex3d(((tailleCase * nbLignes) / 2), (tailleCase * i) - (nbLignes * tailleCase / 2), 10.01);
            glEnd();
        }

        glBegin(GL_LINES);
        glColor3ub(0, 255, 0);
        glVertex3d(0, ((tailleCase * nbLignes) / 2), 10.02);
        glVertex3d(0, -((tailleCase * nbLignes) / 2), 10.02);
        glEnd();

        glBegin(GL_LINES);
        glColor3ub(0, 255, 0);
        glVertex3d(((tailleCase * nbLignes) / 2), 0, 10.02);
        glVertex3d(-((tailleCase * nbLignes) / 2), 0, 10.02);
        glEnd();
}