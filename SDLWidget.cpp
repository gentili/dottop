/*
 * SDLWidget.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: gentili
 */

#include "SDLWidget.h"

#include <iostream>
#include <sys/time.h>

using namespace std;

bool ClockWidget::draw(SDL_Renderer * rnd) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    struct tm tm = *localtime(&tv.tv_sec);
    char str[100];

    sprintf(str, "%d-%d-%d %02d:%02d:%02d.%d", tm.tm_year + 1900, tm.tm_mon + 1,
            tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec,tv.tv_usec);

    // SDL_SetRenderDrawColor(rnd, 255, 100, 100, 255);
    // SDL_RenderDrawLine(rnd, 10, 10, 100, 100);
    SDL_Color color = { 200, 0, 0 };
    SDL_Surface * surface = TTF_RenderText_Solid(_font, str, color);
    SDL_Rect rect;
    rect.w = surface->w * 1;
    rect.h = surface->h * 1;
    rect.x = 20;
    rect.y = 20;
    SDL_Texture * texture = SDL_CreateTextureFromSurface(rnd, surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(rnd, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
    return true;
}
