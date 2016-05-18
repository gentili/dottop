//============================================================================
// Name        : dottop
// Author      : Michael Gentili
// Version     :
// Copyright   : Copyright 2015
// Description : graphical top
//============================================================================

#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <chrono>

#include "procevents/CNProc.h"
#include "display/Screen.h"
#include "display/util.h"

using namespace std;
using namespace std::chrono;

std::deque<struct proc_event> proc_events;
std::mutex proc_events_mutex;

const std::chrono::milliseconds ms100(100);

int main(int argc, char *argv[]) {

    if (!CNProc::connect())
        return 1;

    if (!CNProc::subscribe()) 
        return 1;

    std::thread tproc([] () {
        std::function<void(const struct proc_event&)> lambda =
        [] (const struct proc_event & proc_ev)
        {
            std::lock_guard<std::mutex> l(proc_events_mutex);
            proc_events.push_back(proc_ev);
        };
        CNProc::process(lambda);
    });

    while (true) {
        std::this_thread::sleep_for(ms100);
        {
            std::lock_guard<std::mutex> l(proc_events_mutex);
            while (!proc_events.empty()) {
                auto proc_ev(proc_events.front());
                proc_events.pop_front();
                switch (proc_ev.what) {
                    case proc_event::PROC_EVENT_NONE:
                        cout << "none" << endl;
                        break;
                    case proc_event::PROC_EVENT_FORK:
                        cout << "fork" << endl;
                        break;
                    case proc_event::PROC_EVENT_EXEC:
                        cout << "exec" << endl;
                        break;
                    case proc_event::PROC_EVENT_UID:
                        cout << "gid" << endl;
                        break;
                    case proc_event::PROC_EVENT_GID:
                        cout << "gid" << endl;
                        break;
                    case proc_event::PROC_EVENT_EXIT:
                        cout << "exit" << endl;
                        break;
                    default:
                        cout << "unknown" << endl;
                        break;
                }
            }
        }
    }

    if (SDL_Init(0) != 0) {
        cerr << "ERROR: SDL_Init() - " << SDL_GetError() << endl;
        return 1;
    }
    if (SDL_VideoInit("directfb") != 0) {
        cerr << "WARN: No directfb" << endl;
        if (SDL_VideoInit(NULL) != 0) {
            cerr << "ERROR: SDL_VideoInit() - " << SDL_GetError() << endl;
            return 1;
        }

    }

    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    auto font = TTF_OpenFont("font/VISITOR.FON",7);
    if (!font)
        sdl_abort("TTF_OpenFont()");

    SDL_DisplayMode mode;
    for (int m = 0; m < SDL_GetNumDisplayModes(0); m++) {
        SDL_GetDisplayMode(0, m, &mode);
        cout << mode.w << "," << mode.h << " " << mode.format
                << endl;
        if ((mode.w == 640) && (mode.h == 480)) {
            break;
        }
    }

    if ((mode.w != 640) || (mode.h != 480))
        sdl_abort("640x480 mode not available");

    SDL_Window * win = SDL_CreateWindow("dottop", SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, mode.w, mode.h, 0);// SDL_WINDOW_FULLSCREEN);
    if (win == NULL)
        sdl_abort("SDL_CreateWindow()");

    /*
    if (SDL_SetWindowDisplayMode(win, &mode) != 0)
        sdl_abort("SDL_SetWindowDisplayMode()");

    if (SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN) != 0)
        sdl_abort("SDL_SetWindowFullscreen()");
    */

    SDL_Renderer * rnd = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);
    if (rnd == NULL)
        sdl_abort("SDL_CreateRenderer()");

    SDL_ShowCursor(0);

    // Main loop
    Dottop::mainLoop(rnd,font);

    SDL_VideoQuit();
    SDL_Quit();
    TTF_Quit();
    return 0;
}
