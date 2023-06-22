CXX = g++
includes = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
CFLAGS = -Wall -Wextra -pedantic -o 
OBJECTS = Ball.h Paddle.h Cpu.h
all:
	$(CXX) $(CFLAGS) Pong Pong.cpp $(OBJECTS) $(includes)
cl: 
	rm Pong
