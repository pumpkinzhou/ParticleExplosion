// ParticleMotion.cpp : This file contains the 'main' function. Program execution begins and ends there.
#pragma comment(lib, "sdl2.lib")
#include "Screen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"

using namespace std;
using namespace particleExplosion;


int main(int argc, char* argv[])
{
	srand(time(NULL));

	Screen screen;

	if (screen.init() == false)
		cout << "Error initializing SDL." << endl;

	Swarm swarm;

	while (true) 
	{
		int elapsed = SDL_GetTicks();

		//Update particles
		//screen.clear();
		swarm.update(elapsed);


		unsigned char red = (1 + sin(elapsed * 0.001)) * 128;
		unsigned char green = (1 + cos(elapsed * 0.001))*128;
		unsigned char blue = (1 + sin(elapsed * 0.001)) * 128;
		
		const Particle* const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle = pParticles[i];
			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH /2;
			int y = particle.m_y * Screen::SCREEN_WIDTH /2 + Screen::SCREEN_HEIGHT / 2;
			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		//Draw particles
		screen.update();

		//Check for messages/events
		if (screen.processEvents() == false) {
			break;
		}
	}
	
	screen.close();

	return 0;
}