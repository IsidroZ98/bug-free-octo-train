#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Game.h"

class GameObject
{
public:
	GameObject(const char* texturesheet, float x, float y);
	~GameObject();

	void oUpdate();
	void oRender();


private:
	float xpos;
	float ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};
#endif