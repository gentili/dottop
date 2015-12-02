/*
 * SDLManager.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: gentili
 */

#include "SDLManager.h"
#include <stdexcept>

void SDLManager::mainLoop(SDL_Window* window, SDL_Renderer* renderer) {
    // Main loop
    if (window == NULL)
        throw std::invalid_argument("Window == NULL");

    if (renderer == NULL)
        throw std::invalid_argument("Renderer == NULL");

    while (true) {
        SDL_Event event;
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
            break;
        }
        SDL_SetRenderDrawColor(renderer, 100, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
}
