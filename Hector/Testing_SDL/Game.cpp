#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* player;
GameObject* enemy;

Game::Game(){}
Game::~Game(){}

SDL_Renderer* Game::renderer = nullptr;

void Game::Create_Window(const int WIDTH, const int HEIGHT, bool fullscrn){
	window = NULL;

	Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;

	if (fullscrn) {flags = SDL_WINDOW_FULLSCREEN;}

	if(SDL_Init(SDL_INIT_EVERYTHING)==0) 
	{
		std::cout<<"Window Initialised....\n";
		window = SDL_CreateWindow("SDL TUT", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT,flags);
		std::cout<<"Window Created\n";
		renderer = SDL_CreateRenderer(window, -1, 0);
		if(renderer){
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			std::cout<<"render Created\n";
		}
		isRunning = true;
	}
	std::cout<<"player Created\n";
	player = new GameObject("assets/player.png",0,0);
	std::cout<<"Enemy Created\n";
	enemy = new GameObject("assets/Enemy.png", 200, 200);

}
void Game::update(){
	player->oUpdate();
	enemy->oUpdate();
}
void Game::render(){
	SDL_RenderClear(renderer);
	player->oRender();
	enemy->oRender();
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