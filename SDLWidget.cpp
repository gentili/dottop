/*
 * SDLWidget.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: gentili
 */

#include <iostream>

#include "SDLWidget.h"

using namespace std;

bool ClockWidget::draw(SDL_Renderer * rnd) {
    SDL_SetRenderDrawColor(rnd,255,100,100,255);
    SDL_RenderDrawLine(rnd,10,10,100,100);
    return true;
}
