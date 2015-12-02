/*
 * SDLManager.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: gentili
 */

#include "Glogin.h"

#include <stdexcept>

std::vector<unique_ptr<SDLWidget>> Glogin::widgets;

void Glogin::mainLoop(SDL_Window* window, SDL_Renderer* renderer) {
    // Main loop

    widgets.push_back(unique_ptr<SDLWidget>(new ClockWidget()));
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
