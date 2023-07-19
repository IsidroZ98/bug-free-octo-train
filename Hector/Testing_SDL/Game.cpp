#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"

#define LOG(x) std::cout<<"created "<<x<<"\n";

SDL_Event Game::event;

Map* map;
Manager manager;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

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
		LOG("Window");
		renderer = SDL_CreateRenderer(window, -1, 0);
		if(renderer){
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			LOG("render Created");
		}
		isRunning = true;
	}
	LOG("map");
	map = new Map();

	LOG("player");
	player.addComponent<TransformComponent>(2);
	player.addComponent<SpriteComponent>("assets/player.png");
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");

	wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	wall.addComponent<SpriteComponent>("assets/wall.png");
	wall.addComponent<ColliderComponent>("wall");

}
void Game::update(){
	manager.refresh();
	manager.update();
	if(Collision::AABB(player.getComponent<ColliderComponent>().collider, wall.getComponent<ColliderComponent>().collider))
	{
		player.getComponent<TransformComponent>().velocity * -1;
		LOG("walll hit");
	}
}
void Game::render(){
	SDL_RenderClear(renderer);
	map->DrawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}
void Game::Clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout<<"sweeped window\n";
}
void Game::handelEvents(){
	SDL_PollEvent(&event);
	if(Game::event.type == SDL_KEYDOWN)
	{
    switch (Game::event.key.keysym.sym){
			case SDLK_q:
				isRunning =false;
				break;
			default:
				break;
		}
	}

	switch (event.type){
		case SDL_QUIT:
			isRunning =false;
			break;
		default:
			break;
	}
}
