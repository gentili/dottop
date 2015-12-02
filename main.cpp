//============================================================================
// Name        : glogin.cpp
// Author      : Michael Gentili
// Version     :
// Copyright   : Copyright 2015
// Description : retro graphical login interface
//============================================================================

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

#include "Glogin.h"

using namespace std;

void sdl_abort(const char* errstr) {
    cerr << "ABORT: " << errstr << " - " << SDL_GetError() << endl;
    SDL_VideoQuit();
    SDL_Quit();
    TTF_Quit();
    exit(1);
}

int main(int argc, char *argv[]) {

    if (SDL_Init(0) != 0) {
        cerr << "ERROR: SDL_Init() - " << SDL_GetError() << endl;
        return 1;
    }
    if (SDL_VideoInit("directfb") != 0) {
        cerr << "WARN: No directfb" << endl;
        if (SDL_VideoInit(NULL) != 0) {
            cerr << "ERROR: SDL_VideoInit() - " << SDL_GetError() << endl;
            return 1;
        }

    }

    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }

    SDL_DisplayMode mode;
    for (int m = 0; m < SDL_GetNumDisplayModes(0); m++) {
        SDL_GetDisplayMode(0, m, &mode);
        cout << mode.w << "," << mode.h << " " << mode.format
                << endl;
        if ((mode.w == 640) && (mode.h == 480)) {
            break;
        }
    }

    if ((mode.w != 640) || (mode.h != 480)) {
        sdl_abort("640x480 mode not available");
    }

    SDL_Window * win = SDL_CreateWindow("glogin", SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, mode.w, mode.h, 0);// SDL_WINDOW_FULLSCREEN);
    if (win == NULL)
        sdl_abort("SDL_CreateWindow()");

    /*
    if (SDL_SetWindowDisplayMode(win, &mode) != 0)
        sdl_abort("SDL_SetWindowDisplayMode()");

    if (SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN) != 0)
        sdl_abort("SDL_SetWindowFullscreen()");
    */

    SDL_Renderer * rnd = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);
    if (rnd == NULL)
        sdl_abort("SDL_CreateRenderer()");

    SDL_ShowCursor(0);

    // Main loop
    Glogin::mainLoop(win, rnd);

    SDL_VideoQuit();
    SDL_Quit();
    return 0;
}
