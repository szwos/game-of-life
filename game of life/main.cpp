#include "SDL.h"
#include "Game.h"
#include <iostream> 
using namespace std;


Game* game = nullptr;

int main(int argc, char * argv[])
{

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("Game of life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (game->running())
	{

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			//SDL_Delay(frameDelay - frameTime);
		}//TODO przerobic ten system w taki sposob, ze beda dwa oddzielne timery, jeden od fizyki, drugi od wyswielania, ten od fizyki bedzie dostepny dla jakiejs nowej klasy fizyki
		 //natomiast metoda render() bedzie korzystala tylko i wylacznie z timera na podstawie fpsow
	}

	game->clean();


	return 0;
}