// ParticleMotion.cpp : This file contains the 'main' function. Program execution begins and ends there.
#pragma comment(lib, "sdl2.lib")
#include "Screen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"

using namespace std;
using namespace particleMotion;


int main(int argc, char* argv[])
{
	srand(time(NULL));

	Screen screen;

	if (screen.init() == false)
	{
		cout << "Error initializing SDL." << endl;
	}

	Swarm swarm;


	while (true) 
	{
		//Update particles
		//Draw particles
		//Check for messages/events
		const Particle* const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle = pParticles[i];
			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT/2;
			screen.setPixel(x, y, 255, 255, 255);
		}


		/* int elapsed = SDL_GetTicks();

		unsigned char red = (1 + sin(elapsed * 0.001)) * 128;
		unsigned char green = (1 + cos(elapsed * 0.001))*128;
		unsigned char blue = (1 + sin(elapsed * 0.001)) * 128;

		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, red, green, blue);
			}
		}*/

		// Draw the screen
		screen.update();

		if (screen.processEvents() == false) {
			break;
		}
	}
	
	screen.close();

	return 0;
}