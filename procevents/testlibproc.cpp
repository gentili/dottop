//============================================================================
// Test to make sure we understand libproc
//============================================================================

#include <iostream>
#include <proc/readproc.h>

using namespace std;

int main(int argc, char *argv[]) {
    PROCTAB* PT = openproc(PROC_FILLARG|PROC_FILLCOM|PROC_FILLUSR|PROC_FILLSTAT);
    proc_t * ptsk = NULL;
    while ( (ptsk = readproc(PT, ptsk)) )
    {
        cout << ptsk->cmd << endl;
    }
    freeproc(ptsk);
    closeproc(PT);
    return 0;
}
