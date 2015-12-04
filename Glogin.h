/*
 * SDLManager.h
 *
 *  Created on: Dec 1, 2015
 *      Author: gentili
 */

#ifndef GLOGIN_H_
#define GLOGIN_H_

#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>

#include "SDLWidget.h"

using namespace std;

class Glogin {
public:
    static void mainLoop(SDL_Renderer*, TTF_Font * );
private:
    Glogin() = delete;
    static std::vector<unique_ptr<SDLWidget>> widgets;
};

#endif /* GLOGIN_H_ */
