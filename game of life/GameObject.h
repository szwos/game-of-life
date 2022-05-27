#pragma once
#include "Game.h"

class GameObject
{
	int t;
	int xpos;
	int ypos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, dstRect;

public:
	GameObject(const char* texturesheet, int x, int y);
	~GameObject();

	void Update();
	void Render();


};

