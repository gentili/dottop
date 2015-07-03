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
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_SetVideoMode(640,480,32,SDL_DOUBLEBUF);
	SDL_Event event;
	bool isRunning = true;
	cout << "start" << endl;
	while(isRunning){
		if(SDL_PollEvent(&event) && event.type == SDL_QUIT){
			cout << "quit" << endl;
			isRunning=false;
		}
	}
	cout << "done" << endl;
	SDL_Quit();
	return 0;
}
