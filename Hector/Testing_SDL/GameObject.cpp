#include "GameObject.h"
#include "TextureManager.h"
GameObject::GameObject(const char* texturesheet, float x, float y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
}

void GameObject::oUpdate()
{
	xpos++;
	ypos++;

	srcRect.h = 50;
	srcRect.w = 50;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}
void GameObject::oRender()
{	//for some reason the srcRect doesnt work here
	//SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}
