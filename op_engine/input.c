#include <stdio.h>
#include <termio.h>


 int scanKeyboard()
{
	int in;
	struct termios new_settings;
	struct termios stored_settings;
	tcgetattr(0, &stored_settings);			
	new_settings = stored_settings;
	new_settings.c_lflag &= (~ICANON);		
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &new_settings);	
	
	in = getchar();
	
	tcsetattr(0, TCSANOW, &stored_settings);	
	return in;
}


static struct termios new_settings;
static struct termios init_settings;


void init_keyboard()
{
	tcgetattr(0, &init_settings);		
	new_settings = init_settings;


	new_settings.c_lflag &= (~ICANON);	
	
	new_settings.c_lflag &= (~ECHO);
	new_settings.c_lflag |= ISIG; 		
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &new_settings); 
}


void close_keyboard()
{
	tcsetattr(0, TCSANOW, &init_settings); 
}


int scan_keyboard()
{
	return getchar();
}

