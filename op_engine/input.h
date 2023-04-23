#ifdef __linux__
    #ifndef FPS_SIMULATOR_INPUT_H
    #define FPS_SIMULATOR_INPUT_H

    #define     ESC     "\033"
    #define     UP      "\033[A"
    #define     DOWN    "\033[B"
    #define     LEFT    "\033[D"
    #define     RIGHT   "\033[C"
    #define     SPACE   " "
    #define     A   "a"
    #define     B   "b"
    #define     C   "c"
    #define     D   "d"
    #define     E   "e"
    #define     F   "f"
    #define     G   "g"
    #define     H   "h"
    #define     I   "i"
    #define     J   "j"
    #define     K   "k"
    #define     L   "l"
    #define     M   "m"
    #define     N   "n"
    #define     O   "o"
    #define     P   "p"
    #define     Q   "q"
    #define     R   "r"
    #define     S   "s"
    #define     T   "t"
    #define     U   "u"
    #define     V   "v"
    #define     W   "w"
    #define     X   "x"
    #define     Y   "y"
    #define     Z   "z"
    #define     ONE "1"
    #define     TWO "2"
    #define     THREE   "3"
    #define     FOUR    "4"
    #define     FIVE    "5"
    #define     SIX     "6"
    #define     SEVEN   "7"
    #define     EIGHT   "8"
    #define     NINE    "9"
    #define     ZERO    "0"
    #define     ENTER   "\n"
    void term_setup(void (*sighandler)(int));
    void term_restore();
    int kbhit();
    int keydown(const char* key);

    #endif //FPS_SIMULATOR_INPUT_H
#endif
#ifdef __windows__
#include <windows.h>
#define keydown(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#endif