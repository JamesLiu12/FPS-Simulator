#ifndef FPS_SIMULATOR_INPUT_H
#define FPS_SIMULATOR_INPUT_H

#ifdef __linux__
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
#endif

#ifdef _WIN32
#include <windows.h>
#define     ESC     0x1B
#define     UP      0x26
#define     DOWN    0x28
#define     LEFT    0x25
#define     RIGHT   0x27
#define     SPACE   0x20
#define     A   0x41
#define     B   0x42
#define     C   0x43
#define     D   0x44
#define     E   0x45
#define     F   0x46
#define     G   0x47
#define     H   0x48
#define     I   0x49
#define     J   0x4A
#define     K   0x4B
#define     L   0x4C
#define     M   0x4D
#define     N   0x4E
#define     O   0x4F
#define     P   0x50
#define     Q   0x51
#define     R   0x52
#define     S   0x53
#define     T   0x54
#define     U   0x55
#define     V   0x56
#define     W   0x57
#define     X   0x58
#define     Y   0x59
#define     Z   0x5A
#define     ZERO    0x30
#define     ONE     0x31
#define     TWO     0x32
#define     THREE   0x33
#define     FOUR    0x34
#define     FIVE    0x35
#define     SIX     0x36
#define     SEVEN   0x37
#define     EIGHT   0x38
#define     NINE    0x39
#define     ENTER   0
int kbhit();
#define keydown(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#endif

#endif //FPS_SIMULATOR_INPUT_H
