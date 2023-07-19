CXX = g++
includes = -lraylib -lgl -lm -lpthread -ldl -lrt -lx11
CFLAGS = -Wall -Wextra -pedantic -o 
OBJECTS = Ball.h Paddle.h Cpu.h
all:
	$(CXX) $(CFLAGS) Pong Pong.cpp $(OBJECTS) $(includes)
cl: 
	rm Pong
