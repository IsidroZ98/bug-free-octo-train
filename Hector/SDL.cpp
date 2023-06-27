#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <bits/stdc++.h>

const int WIDTH = 800;
const int HEIGHT = 900;

int main(){
	
	SDL_Window* window = NULL;

	SDL_Surface* screenSurface = NULL;

	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		std::cout<< "SDL Error\n"<< SDL_GetError();
	}
	else 
	{
		window = SDL_CreateWindow("SDL TUT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,WIDTH, HEIGHT,SDL_WINDOW_SHOWN);
		if(window == NULL)
			std::cout<<"Window Broken"<< SDL_GetError();
		else{
			screenSurface = SDL_GetWindowSurface(window);

			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			SDL_UpdateWindowSurface(window);
		
			SDL_Event e;bool quit=false;while(quit == false){while(SDL_PollEvent(&e)){if(e.type == SDL_QUIT)quit= true;}}
		}
	}
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}

