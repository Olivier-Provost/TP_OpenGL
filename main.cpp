/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: androidlinux
 *
 * Created on 15 décembre 2017, 11:41
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string>
#include "sdlglutils.h"
#include <iostream>

using namespace std;

/*
 * 
 */
SDL_Window* win;
SDL_GLContext ctx;
GLuint idBrick;
bool isRunning = true;

class Coord {
public:
    int xMin, xMax, yMin, yMax;

    Coord(int xMin, int xMax, int yMin, int yMax) {
        this->xMin = xMin;
        this->xMax = xMax;
        this->yMin = yMin;
        this->yMax = yMax;
    }
};

class MonTableau {
public:
    GLuint idList;
    GLuint idBrick, idHerbe;

    int nbLignes, tailleCase;

    MonTableau(int nbLignes, int tailleCase) {

        this->nbLignes = nbLignes;
        this->tailleCase = tailleCase;

        idBrick = loadTexture("brick.jpg");
        idHerbe = loadTexture("herbe.jpg");

        idList = glGenLists(1);
        glNewList(idList, GL_COMPILE);

        stage(nbLignes, tailleCase);
        lignes(nbLignes, tailleCase);
        murs(nbLignes, tailleCase);

        glEndList();
    }

    ~MonTableau() {
        glDeleteLists(idList, 1);
        glDeleteTextures(1, &idHerbe);
        glDeleteTextures(1, &idBrick);
    }

    void render() {
        glCallList(idList);
    }

    void stage(int nbLignes, int tailleCase) {
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

    void lignes(int nbLignes, int tailleCase) {
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

    void murs(int nbLignes, int tailleCase) {
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
};

/*class MesObstacles {
public:
    MonTableau tableau;
    bool isObstacle;
    GLuint idList;
    Coord table[tableau.nbLignes][tableau.nbLignes];

    MesObstacles(MonTableau tableau) {
        idList = glGenLists(1);
        glNewList(idList, GL_COMPILE);

        for (int i = 0; i < (tableau.nbLignes); i++) {
            for (int j = 0; j < tableau.nbLignes; j++) {
                table[i][j] = Coord((tableau.tailleCase * i) - (tableau.nbLignes * tableau.tailleCase / 2), (tableau.tailleCase * i) - (tableau.nbLignes * tableau.tailleCase / 2), (tableau.tailleCase * j) - (tableau.nbLignes * tableau.tailleCase / 2), (tableau.tailleCase * j) - (tableau.nbLignes * tableau.tailleCase / 2));
            }
        }

        glEndList();
    }

    ~MesObstacles() {
        glDeleteLists(idList, 1);
    }

    void render() {
        glCallList(idList);
    }
    
    void creerObst(Coord coord) {
        glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0, 0);
        glVertex3i(coord.xMin, coord.yMin, 10);
        glTexCoord2d(0, 1);
        glVertex3i(coord.xMin, coord.yMin, 25);
        glTexCoord2d(5, 1);
        glVertex3i(coord.xMin, coord.yMax, 25);
        glTexCoord2d(5, 0);
        glVertex3i(coord.xMin, coord.yMax, 10);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0, 0);
        glVertex3i(coord.xMin, coord.yMin, 10);
        glTexCoord2d(0, 1);
        glVertex3i(coord.xMin, coord.yMin, 25);
        glTexCoord2d(5, 1);
        glVertex3i(coord.xMax, coord.yMin, 25);
        glTexCoord2d(5, 0);
        glVertex3i(coord.xMax, coord.yMin, 10);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0, 0);
        glVertex3i(coord.xMin, coord.yMax, 10);
        glTexCoord2d(0, 1);
        glVertex3i(coord.xMin, coord.yMax, 25);
        glTexCoord2d(5, 1);
        glVertex3i(coord.xMax, coord.yMax, 25);
        glTexCoord2d(5, 0);
        glVertex3i(coord.xMax, coord.yMax, 10);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, idBrick);
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glTexCoord2d(0, 0);
        glVertex3i(coord.xMax, coord.yMin, 10);
        glTexCoord2d(0, 1);
        glVertex3i(coord.xMax, coord.yMin, 25);
        glTexCoord2d(5, 1);
        glVertex3i(coord.xMax, coord.yMax, 25);
        glTexCoord2d(5, 0);
        glVertex3i(coord.xMax, coord.yMax, 10);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(200, 200, 200);
        glVertex3i(coord.xMin, coord.yMin, 25);
        glVertex3i(coord.xMin, coord.yMax, 25);
        glVertex3i(coord.xMax, coord.yMax, 25);
        glVertex3i(coord.xMax, coord.yMin, 25);
        glEnd();
    }
};*/

class MonCube {
public:
    GLuint idList;

    int x = -45, y = 45;
    
    int tailleHalf;

    MonCube(int tailleHalf) {
        idList = glGenLists(1);
        glNewList(idList, GL_COMPILE);

        glPushMatrix();
        creerCube(tailleHalf);
        glPopMatrix();

        glEndList();
    }

    ~MonCube() {
        glDeleteLists(idList, 1);
    }

    void render() {
        glTranslated(x, y, 10.01);
        glCallList(idList);
    }

    void creerCube(int tailleHalf) {
        glBegin(GL_QUADS);
        glColor3ub(255, 0, 0);
        glVertex3i(-tailleHalf, tailleHalf, 0);
        glVertex3i(tailleHalf, tailleHalf, 0);
        glVertex3i(tailleHalf, -tailleHalf, 0);
        glVertex3i(-tailleHalf, -tailleHalf, 0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 0, 0);
        glVertex3i(-tailleHalf, tailleHalf, tailleHalf * 2);
        glVertex3i(tailleHalf, tailleHalf, tailleHalf * 2);
        glVertex3i(tailleHalf, -tailleHalf, tailleHalf * 2);
        glVertex3i(-tailleHalf, -tailleHalf, tailleHalf * 2);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(0, 255, 0);
        glVertex3i(-tailleHalf, tailleHalf, 0);
        glVertex3i(-tailleHalf, tailleHalf, tailleHalf * 2);
        glVertex3i(tailleHalf, tailleHalf, tailleHalf * 2);
        glVertex3i(tailleHalf, tailleHalf, 0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(0, 255, 0);
        glVertex3i(-tailleHalf, -tailleHalf, 0);
        glVertex3i(-tailleHalf, -tailleHalf, tailleHalf * 2);
        glVertex3i(tailleHalf, -tailleHalf, tailleHalf * 2);
        glVertex3i(tailleHalf, -tailleHalf, 0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(0, 0, 255);
        glVertex3i(tailleHalf, tailleHalf, 0);
        glVertex3i(tailleHalf, tailleHalf, tailleHalf * 2);
        glVertex3i(tailleHalf, -tailleHalf, tailleHalf * 2);
        glVertex3i(tailleHalf, -tailleHalf, 0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(0, 0, 255);
        glVertex3i(-tailleHalf, tailleHalf, 0);
        glVertex3i(-tailleHalf, tailleHalf, tailleHalf * 2);
        glVertex3i(-tailleHalf, -tailleHalf, tailleHalf * 2);
        glVertex3i(-tailleHalf, -tailleHalf, 0);
        glEnd();
    }
};

int main(int argc, char** argv) {

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG);
    win = SDL_CreateWindow("Test d'un Labyrinthe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    ctx = SDL_GL_CreateContext(win);

    MonTableau tableau = MonTableau(10, 10);
    MonCube cube = MonCube(3);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, (double) 800 / 800, 1, 10000);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glClearColor(0, 0, 0, 1);
    int x = 100;
    int y = 100;
    SDL_Event event;
    const Uint8* stateK;

    while (isRunning) {
        stateK = SDL_GetKeyboardState(NULL);
        SDL_PollEvent(&event);

        if (event.type == SDL_QUIT)
            isRunning = false;
        if (stateK[SDL_SCANCODE_ESCAPE])
            isRunning = false;
        if (stateK[SDL_SCANCODE_UP])
            x++;
        if (stateK[SDL_SCANCODE_DOWN])
            x--;
        if (stateK[SDL_SCANCODE_LEFT])
            y++;
        if (stateK[SDL_SCANCODE_RIGHT])
            y--;
        if (stateK[SDL_SCANCODE_W])
            cube.x++;
        if (stateK[SDL_SCANCODE_S])
            cube.x--;
        if (stateK[SDL_SCANCODE_D])
            cube.y--;
        if (stateK[SDL_SCANCODE_A])
            cube.y++;

        cout << cube.x << "  " << cube.y << endl;

        //effacer écran
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //dessin
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(x, y, 120, 0, 0, 0, 0, 0, 1);

        glPushMatrix();
        tableau.render();
        cube.render();
        glPopMatrix();

        //Mettre à jour l'écran
        SDL_GL_SwapWindow(win);

    }

    SDL_GL_DeleteContext(ctx);
    SDL_DestroyWindow(win);
    IMG_Quit();
    SDL_Quit();

    return 0;
}