#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <memory>

#include "SDLWidget.h"

using namespace std;

class Dottop {
public:
    static void mainLoop(SDL_Renderer*, TTF_Font * );
private:
    Dottop() = delete;
    static std::vector<unique_ptr<SDLWidget>> widgets;
};
