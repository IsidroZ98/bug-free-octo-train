CXX = g++
CFLAGS = -Wall -Wextra -pedantic -g -o 
CPP = Game.cpp TextureManager.cpp GameObject.cpp Map.cpp
HEAD = Game.h TextureManager.h GameObject.h Map.h ECS.h Components.h
LFLAGS= -lmingw32 -lSDL2main -lSDL2 -lSDL2_image 

 

all:
	$(CXX) -I src/include -L src/lib $(CFLAGS) SDL SDL.cpp $(CPP) $(HEAD) $(LFLAGS)

cl:
	rm SDL.exe
