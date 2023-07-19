CXX = g++ -std=c++11
CFLAGS = -Wall -Wextra -pedantic -g -o 
CPP = Game.cpp TextureManager.cpp Map.cpp Vector2D.cpp Collision.cpp
HEAD = Game.h TextureManager.h Map.h Vector2D.h Collision.h
ECS =  ECS/ECS.h ECS/SpriteComponent.h ECS/KeyboardController.h ECS/ColliderComponent.h
LFLAGS= -lmingw32 -lSDL2main -lSDL2 -lSDL2_image 
SDLI = -I src/include -L src/lib

 

all:
	$(CXX) $(SDLI) -Wall -Wextra -pedantic  ECS/TransformComponent.h
	$(CXX) $(SDLI) -Wall -Wextra -pedantic  ECS/Components.h 
	$(CXX) $(SDLI) -Wall -Wextra -pedantic  $(ECS)
	$(CXX) $(SDLI) -Wall -Wextra -pedantic	$(HEAD)
	$(CXX) $(SDLI) $(CFLAGS) SDL SDL.cpp $(CPP) $(LFLAGS)

cl:
	rm SDL.exe ECS/ECS.h.gch  ECS/TransformComponent.h.gch ECS/SpriteComponent.h.gch ECS/Components.h.gch Game.h.gch TextureManager.h.gch Map.h.gch
