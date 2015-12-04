/*
 * SDLWidget.h
 *
 *  Created on: Dec 1, 2015
 *      Author: gentili
 */

#ifndef SDLWIDGET_H_
#define SDLWIDGET_H_

#include <SDL.h>
#include <SDL_ttf.h>

class SDLWidget {
public:
    SDLWidget() { };
    virtual ~SDLWidget() { };

    virtual bool draw(SDL_Renderer * rnd) = 0;
};

class ClockWidget: public SDLWidget {
public:
    TTF_Font * _font;
    ClockWidget(TTF_Font * font) : SDLWidget() { _font = font; }
    virtual ~ClockWidget() { }

    virtual bool draw(SDL_Renderer * rnd);
};


#endif /* SDLWIDGET_H_ */
