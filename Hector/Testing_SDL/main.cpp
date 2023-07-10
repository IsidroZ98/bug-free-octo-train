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
class TextureManager{
	public:
		static SDL_Texture* LoadTexture(const char* fileName);
};
SDL_Texture* TextureManager::LoadTexture(const char *fileName){
	SDL_Surface* tmpSurface = IMG_Load(fileName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return tex;
}

GameObject::GameObject(const char* texturesheet, float x, float y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
}

void GameObject::oUpdate()
{
	xpos++;
	ypos++;

	srcRect.h = 50;
	srcRect.w = 50;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}
void GameObject::oRender()
{	//for some reason the srcRect doesnt work here
	//SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}

int main(int argc , char *argv[])
{
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