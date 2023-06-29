#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* player;

Game::Game(){}
Game::~Game(){}

void Game::Create_Window(const int WIDTH, const int HEIGHT, bool fullscrn){
	window = NULL;

	Uint32 flags = SDL_WINDOW_SHOWN;

	if (fullscrn) {flags = SDL_WINDOW_FULLSCREEN;}

	if(SDL_Init(SDL_INIT_EVERYTHING)==0) 
	{
		std::cout<<"Window Initialised....\n";
		window = SDL_CreateWindow("SDL TUT", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT,flags);
		std::cout<<"Window Created\n";
		renderer = SDL_CreateRenderer(window, -1, 0);
		if(renderer){
			SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
			std::cout<<"render Created\n";
		}
		isRunning = true;
	}
	player = new GameObject("player.png",renderer);
	printf("player Created");
}
void Game::update(){
	player->oUpdate();
}
void Game::render(){
	SDL_RenderClear(renderer);
	player->oRender();
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
