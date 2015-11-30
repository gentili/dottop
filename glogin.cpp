//============================================================================
// Name        : glogin.cpp
// Author      : Michael Gentili
// Version     :
// Copyright   : Copyright 2015
// Description : Hello World in C, Ansi-style
//============================================================================

#include <SDL.h>
#include <iostream>

using namespace std;

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

        SDL_DisplayMode mode;
        for (int d = 0; d < SDL_GetNumVideoDisplays(); d++) {
            for (int m = 0; m < SDL_GetNumDisplayModes(0); m++) {
                SDL_GetDisplayMode(d,m,&mode);
                cout << d << ":" << mode.w << "," << mode.h << " " << mode.format << endl;
                if ((mode.w == 640) && (mode.h == 480)) {
                    break;
                }
            }
        }

	SDL_Window * win = SDL_CreateWindow("glogin", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, mode.w, mode.h, SDL_WINDOW_FULLSCREEN);
	if (win == NULL) {
		cerr << "ERROR: SDL_CreateWindow() - " << SDL_GetError() << endl;
                SDL_VideoQuit();
                SDL_Quit();
		return 1;
	}
        if (SDL_SetWindowDisplayMode(win,&mode) != 0) {
		cerr << "ERROR: SDL_SetWindowDisplayMode() - " << SDL_GetError() << endl;
                SDL_VideoQuit();
                SDL_Quit();
		return 1;
        }
        if (SDL_SetWindowFullscreen(win,SDL_WINDOW_FULLSCREEN) != 0) {
		cerr << "ERROR: SDL_SetWindowFullscreen() - " << SDL_GetError() << endl;
                SDL_VideoQuit();
                SDL_Quit();
		return 1;
        }
	SDL_Renderer * rnd = SDL_CreateRenderer(win,-1,SDL_RENDERER_SOFTWARE);
	if (rnd == NULL) {
		cerr << "ERROR: SDL_CreateRenderer() - " << SDL_GetError() << endl;
                SDL_VideoQuit();
                SDL_Quit();
		return 1;
	}
	SDL_SetRenderDrawColor(rnd,100,0,0,255);
	SDL_RenderClear(rnd);
	SDL_RenderPresent(rnd);

	// Main loop
	bool isRunning = true;
	cout << "start" << endl;
	while (isRunning) {
		SDL_Event event;
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
			cout << "quit" << endl;
			isRunning = false;
		}
	}
	cout << "done" << endl;
	SDL_VideoQuit();
	SDL_Quit();
	return 0;
}
