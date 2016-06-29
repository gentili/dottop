//============================================================================
// Test to make sure we understand libproc
//============================================================================

#include <iostream>

#include "ProcEvents.h"

using namespace std;

int main(int argc, char *argv[]) {
    /**
     * ProcEvent::process()
     *  CNProc::connect()
     *  CNProc::subscribe() - proc events start to pile up
     *  openproc - send cur procs as events
     *  CNProc::process() - send along events
     */
    return 0;
}
