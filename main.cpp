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

#include "include.h"
#include <stdlib.h>
#include "Game.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Game game;
    game.init();
    game.game();
    game.clean();

    return 0;
}