// ParticleMotion.cpp : This file contains the 'main' function. Program execution begins and ends there.
#pragma comment(lib, "sdl2.lib")
#include "Screen.h"
#include <math.h>

using namespace std;
using namespace SDLScreen;


int main(int argc, char* argv[])
{
	Screen screen;
	if (screen.init() == false)
	{
		cout << "Error initializing SDL." << endl;
	}

	while (true) 
	{
		//Update particles
		//Draw particles
		//Check for messages/events
		int elapsed = SDL_GetTicks();
		unsigned char red = (1 + sin(elapsed * 0.001)) * 128;
		unsigned char green = (1 + cos(elapsed * 0.001))*128;
		unsigned char blue = (1 + sin(elapsed * 0.001)) * 128;

		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, red, green, blue);
			}
		}

		// Draw the screen
		screen.update();

		if (screen.processEvents() == false) {
			break;
		}
	}
	
	screen.close();

	return 0;
}