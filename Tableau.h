/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tableau.h
 * Author: androidlinux
 *
 * Created on 10 janvier 2018, 08:13
 */

#ifndef TABLEAU_H
#define TABLEAU_H

#include "include.h"

class Tableau {
public:
    Tableau();
    Tableau(int nbLignes, int tailleCase);
    virtual ~Tableau();
    int getNbLignes();
    int getTailleCase();
    void render();
    void init(int nbLignes, int tailleCase);
    void plateau(int nbLignes, int tailleCase);
    void mursExterieur(int nbLignes, int tailleCase);
    void lignes(int nbLignes, int tailleCase);
private:
    GLuint idList, idBrick, idHerbe;
    int nbLignes, tailleCase;

};

#endif /* TABLEAU_H */

