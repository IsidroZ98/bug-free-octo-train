#include "GameObject.h"
#include "TextureManager.h"
#include <SDL2/SDL_render.h>
GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);
	xpos = 0;
	ypos = 0;
}

void GameObject::oUpdate()
{
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
	SDL_RenderCopy(renderer, objTexture, NULL, &destRect);
}
