/*
 * SDLManager.h
 *
 *  Created on: Dec 1, 2015
 *      Author: gentili
 */

#ifndef DOTTOP_H_
#define DOTTOP_H_

#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>

#include "SDLWidget.h"

using namespace std;

class Dottop {
public:
    static void mainLoop(SDL_Renderer*, TTF_Font * );
private:
    Dottop() = delete;
    static std::vector<unique_ptr<SDLWidget>> widgets;
};

#endif /* DOTTOP_H_ */
