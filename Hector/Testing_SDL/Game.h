#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <bits/stdc++.h>

class Game {
public:
Game();
~Game();
void Create_Window(const int WIDTH, const int HEIGHT, bool fullscrn);

void handelEvents();
void update();
void render();
void Clean(); 

bool _Running(){return isRunning;}
private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
		
};
#endif
