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

	int drivercount = SDL_GetNumVideoDrivers();
	for (int i = 0; i < drivercount; i++) {
		auto driver = SDL_GetVideoDriver(i);
		cout << driver << "\n";
	}
	return 0;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return 1;
	}
	SDL_Window * win = SDL_CreateWindow("glogin",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,0);
	if (win == NULL) {
		cerr << "ERROR: SDL_CreateWindow() - " << SDL_GetError();
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
	SDL_Quit();
	return 0;
}
