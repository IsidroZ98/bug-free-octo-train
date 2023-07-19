#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>
#include <iostream>

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

		static SDL_Renderer *renderer;
		static SDL_Event event;

	private:
		bool isRunning;
		SDL_Window *window;
		
};
#endif