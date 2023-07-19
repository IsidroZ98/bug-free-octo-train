#ifndef __COLLIDERCOMPONENT_H__
#define __COLLIDERCOMPONENT_H__
  #include "Components.h"
  #include <string>
  #include <SDL2/SDL.h>
  

  class ColliderComponent : public Component
  {
    public:
      SDL_Rect collider;
      std::string tag;

      TransformComponent* transform;

      ColliderComponent(const std::string t)
      {
        tag = t; 
      }
      void init() override
      {
        if(!entity->hasComponent<TransformComponent>())
        {
          entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();
      }
      void update() override
      {
        collider.x = static_cast<int>(transform->position.x);
        collider.y = static_cast<int>(transform->position.y);
        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;
      }

  };

#endif // __COLLIDERCOMPONENT_H__