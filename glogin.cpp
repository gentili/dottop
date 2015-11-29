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

        
	if (SDL_Init(0) < 0) {
		cerr << "ERROR: SDL_Init() - " << SDL_GetError() << endl;
		return 1;
	}
        if (SDL_VideoInit("directfb") != 0) {
                if (SDL_VideoInit(NULL) != 0) {
                    cerr << "ERROR: SDL_VideoInit() - " << SDL_GetError() << endl;
                    return 1;
                }
        }
	SDL_Window * win = SDL_CreateWindow("glogin",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,0);
	if (win == NULL) {
		cerr << "ERROR: SDL_CreateWindow() - " << SDL_GetError() << endl;
		return 1;
	}

	// Main loop
	bool isRunning = true;
	cout << "start" << endl;
	while(isRunning){
		SDL_Event event;
		if(SDL_PollEvent(&event) && event.type == SDL_QUIT){
			cout << "quit" << endl;
			isRunning=false;
		}
	}
	cout << "done" << endl;
        SDL_VideoQuit();
	SDL_Quit();
	return 0;
}
