#include "Game.h"


int main(){
	
	const int WIDTH = 1370;
	const int HEIGHT = 900;
	Uint32 frameStart;
	int frameTime;
	const int FPS = 60;
	const int DELAY = (1000/FPS);

	Game *game = nullptr;
	game = new Game();
	game->Create_Window(WIDTH, HEIGHT, 0);
	while (game->_Running()) {

		frameStart = SDL_GetTicks();
		
		game->handelEvents();
		game->update();
		game->render();
		
		frameTime = (SDL_GetTicks() - frameStart);
		if(DELAY > frameTime)
		{
			SDL_Delay(DELAY - frameTime);
		}	
	}
	game->Clean();
	return 0;
}

