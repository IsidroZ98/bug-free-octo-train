CXX = g++
CFLAGS = -Wall -Wextra -pedantic -g -o 
CPP = Game.cpp TextureManager.cpp GameObject.cpp
LFLAGS= -lSDL2 -lSDL2_image

 

all:
	$(CXX) $(CFLAGS) SDL SDL.cpp $(CPP) Game.h TextureManager.h GameObject.h $(LFLAGS)

cl:
	rm SDL
