#include "Map.h"
#include "TextureManager.h"




Map::Map(){
  dirt = TextureManager::LoadTexture("assets/dirt.png");
  grass = TextureManager::LoadTexture("assets/grass.png");
  water = TextureManager::LoadTexture("assets/water.png");
  
  LoadMap();

  src.x = src.y = 0;
  src.w = dest.w = 60; 
  src.h = dest.h = 50;

  dest.x = dest.y = 0;

}
Map::~Map()
{
  SDL_DestroyTexture(grass);
  SDL_DestroyTexture(water);
  SDL_DestroyTexture(dirt);
}

void Map::LoadMap(){
  for(int row = 0; row<20;++row)
  {
    for(int cols = 0; cols<25;++cols)
    {
      map[row][cols] = rand() % 3;
    }
  }
}
void Map::DrawMap(){
  int type = 0;

  for(int row = 0; row<20;++row)
  {
    for(int cols = 0; cols<25;++cols)
    {
      type = map[row][cols];
      dest.x = cols * 60;
      dest.y = row * 50;

      switch (type)
      {
      case 0:
        TextureManager::Draw(water, src, dest);
        break;
      case 1:
        TextureManager::Draw(grass, src, dest);
        break;
      case 2:
        TextureManager::Draw(dirt, src, dest);
        break;
      default:
        break;
      }
    }
  }

}