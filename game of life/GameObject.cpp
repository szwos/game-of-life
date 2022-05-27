#include "GameObject.h"
#include "TextureManager.h"
#include <cmath>

GameObject::GameObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
	t = 0;
}


void GameObject::Update()
{
	t++;
	
	xpos = (cos((float)t / 9.5 ) * 350 + 350);
	ypos = (sin((float)t / 10 ) * 200 + 300);

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	dstRect.x = xpos;
	dstRect.y = ypos;
	dstRect.w = srcRect.w * 2;
	dstRect.h = srcRect.h * 2;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &dstRect);
}