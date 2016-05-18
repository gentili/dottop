/*
 * util.cpp
 *
 *  Created on: Dec 3, 2015
 *      Author: gentili
 */

#include "util.h"

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

using namespace std;

void sdl_abort(const char* errstr) {
    cerr << "ABORT: " << errstr << " - " << SDL_GetError() << endl;
    SDL_VideoQuit();
    SDL_Quit();
    TTF_Quit();
    exit(1);
}
