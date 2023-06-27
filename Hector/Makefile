CXX = g++
RaylibIncludes = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
CFLAGS = -Wall -Wextra -pedantic -o 



sdl:
	$(CXX) $(CFLAGS) SDL SDL.cpp -lSDL2

raylib:
	$(CXX) $(CFLAGS) WindowC++ WindowC++.cpp $(RaylibIncludes)
clean_ray: 
	rm WindowC++
clean_sdl:
	rm SDL
