#include "Game.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "TileMap.h"


GameObject* player;
GameObject* player2;
TileMap* map;


SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{

}


Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Podsystemy dzia³aj¹\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Otwarto okno" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			std::cout << "Stworzono renderer" << std::endl;
		}

		isRunning = true;
	}
	else
	{
		std::cout << "Podsystemy nie dzia³aj¹!";
		isRunning = false;
	}


	map = new TileMap();
}


void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
		break;

	}

}

void Game::update()
{   
	cnt++;
	int gameSpeed = 1;
	//TODO to powinno byc gdzie indziej, najlepiej jako zmienna klasy game tak aby inne klasy mialy nad tym kontrole (chodzi o gameSpeed)

	if (cnt % gameSpeed == 0)
	{
		map->LoadMap();
		map->UpdateMap();

	}
	
	//std::cout << cnt << std::endl;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	
	map->DrawMap();
	
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "koniec gry" << std::endl;

}

