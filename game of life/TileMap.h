#pragma once
#include "Game.h"

class TileMap
{

	int size_x = 80;
	int size_y = 64;

	SDL_Rect src, dest;
	SDL_Texture* panel;
	
	int map[64][80];
	int newMap[64][80];

	int neighbours(int x, int y);


public:
	TileMap();
	~TileMap();

	void LoadMap();
	void UpdateMap();
	void DrawMap();
};

