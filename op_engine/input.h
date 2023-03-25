#ifndef INPUT
#include <stdio.h>
#include <termio.h>


int scanKeyboard();
static struct termios new_settings;
static struct termios init_settings;
void init_keyboard();
void close_keyboard();
int scan_keyboard();

#define INPUT
#endif