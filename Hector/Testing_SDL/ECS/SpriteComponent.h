#ifndef __SPRITECOMPONENT_H__
#define __SPRITECOMPONENT_H__

  #include "ECS.h"
  #include "TransformComponent.h"
  #include <SDL2/SDL.h>
  #include "../TextureManager.h"
  
  class SpriteComponent : public Component
  {
    private:
      TransformComponent *transform;
      SDL_Texture *texture;
      SDL_Rect srcRect, destRect;

    public:
      SpriteComponent() = default;
      SpriteComponent(const char* path)
      {
        setTex(path);
      }
      ~SpriteComponent()
      {
        SDL_DestroyTexture(texture);
      }

      void setTex(const char* path)
      {
        texture = TextureManager::LoadTexture(path);
      }


      void init() override
      {
        transform = &entity->getComponent<TransformComponent>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = transform->width; 
        srcRect.h = transform->height;
      }
      void update() override
      {
        destRect.x = static_cast<int>(transform->position.x);
        destRect.y = static_cast<int>(transform->position.y);
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
      }

      void draw() override
      {
        TextureManager::Draw(texture, srcRect, destRect);
      }
  };

#endif // __SPRITECOMPONENT_H__