#include <stdio.h>
#include "op_engine/op_engine.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "playground.h"
#ifdef __linux__
static sig_atomic_t end = 0;
static void sighandler(int signo)
{
    end = 1;
}
#include "Game/runner.h"
int main() {
//    term_setup(sighandler);
//    system("clear");
    test();
//    term_restore();
    return 0;
}
#endif
#ifdef __windows__
int main() { 
    test();
    return 0;
}
#endif