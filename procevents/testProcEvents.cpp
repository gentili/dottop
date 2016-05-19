//============================================================================
// Test to make sure we understand libproc
//============================================================================

#include <iostream>

#include "ProcEvents.h"

using namespace std;

int main(int argc, char *argv[]) {
    ProcEvents::trackEvents();
    return 0;
}
