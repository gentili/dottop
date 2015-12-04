/*
 * SDLManager.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: gentili
 */

#include "Glogin.h"

#include <stdexcept>

std::vector<unique_ptr<SDLWidget>> Glogin::widgets;

void Glogin::mainLoop(SDL_Renderer* renderer, TTF_Font * font) {
    // Main loop

    widgets.push_back(unique_ptr<SDLWidget>(new ClockWidget(font)));
    while (true) {
        SDL_Event event;
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
            break;
        }
        SDL_SetRenderDrawColor(renderer, 100, 0, 0, 255);
        SDL_RenderClear(renderer);

        for (auto& widget : widgets) {
            widget->draw(renderer);
        }

        SDL_RenderPresent(renderer);
    }
}
