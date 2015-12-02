/*
 * SDLManager.h
 *
 *  Created on: Dec 1, 2015
 *      Author: gentili
 */

#ifndef SDLMANAGER_H_
#define SDLMANAGER_H_

#include <SDL.h>
#include <vector>

#include "SDLWidget.h"

using namespace std;

class SDLManager {
public:
    static void mainLoop(SDL_Window* , SDL_Renderer* );
private:
    SDLManager() = delete;
    static std::vector<unique_ptr<SDLWidget>> widgets;
};

#endif /* SDLMANAGER_H_ */
