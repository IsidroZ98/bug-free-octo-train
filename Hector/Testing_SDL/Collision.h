#ifndef __COLLISION_H__
#define __COLLISION_H__
#include <SDL2/SDL.h>

class Collision
{
  public:
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
};
#endif // __COLLISION_H__