//============================================================================
// Test to make sure CNProc works
//============================================================================

#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <chrono>

#include "CNProc.h"

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

    return 0;
}
