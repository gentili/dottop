#pragma once

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
