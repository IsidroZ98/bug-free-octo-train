#include "Game.h"
Game::Game(){}
Game::~Game(){}

void Game::Create_Window(const int WIDTH, const int HEIGHT, bool fullscrn){
	window = NULL;

	SDL_Surface* screenSurface = NULL;
		
	Uint32 flags = SDL_WINDOW_SHOWN;

	if (fullscrn) {flags = SDL_WINDOW_FULLSCREEN;}

	if(SDL_Init(SDL_INIT_EVERYTHING)<0)
	{
		std::cout<< "SDL Error\n"<< SDL_GetError();
		isRunning = false;
	}
	else 
	{
		std::cout<<"Window Initialised....\n";

		window = SDL_CreateWindow("SDL TUT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,flags);
		if(window == NULL)
			std::cout<<"Window Broken"<< SDL_GetError();
		std::cout<<"Window Created\n";
		renderer = SDL_CreateRenderer(window, -1, 0);
		if(!renderer)
			std::cout<<"render broke\n";
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		std::cout<<"render Created\n";
		isRunning = true;
	}
}
void Game::Update(){
	
}
void Game::Render(){
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}
void Game::Clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout<<"sweeped window\n";
}
void Game::handelEvents(){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type){
		case SDL_QUIT:
			isRunning =false;
			break;
		default:
			break;
	}
}
	



