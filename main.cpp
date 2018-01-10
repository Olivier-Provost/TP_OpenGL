/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jeff
 *
 * Created on 5 janvier 2018, 15:23
 */


#include "include.h"
#include <stdlib.h>    
#include <time.h>
#include "Game.h"

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(NULL));
    Game game;
    game.init();
    game.game();
    game.clean();

    return 0;
}

