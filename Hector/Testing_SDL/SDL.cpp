#include "Game.h"

#define WIDTH 1280
#define HEIGHT 800
int main(){
	int full;
	std::cout<<"Enter true or false for fullscreen ";
	std::cin>>full;

	Game *game = nullptr;
	game = new Game();
	game->Create_Window(WIDTH, WIDTH, full);
	while (game->_Running()) {

		
		game->handelEvents();
		game->Update();
		game->Render();
	}
	game->Clean();
	return 0;
}

