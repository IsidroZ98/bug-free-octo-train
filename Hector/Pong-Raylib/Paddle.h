#ifndef PADDLE_H
#define PADDLE_H
#include <raylib.h>
class Paddle {
protected:
	void LimitMovement(){
		if(y <= 0)
			y = 0;
		if(y+pHeight>=GetScreenHeight())
			y = GetScreenHeight()-pHeight;	
	}
public:
	float x,y;
	float pWidth,pHeight;
	int speed;

	void Draw(){
		DrawRectangleRounded(Rectangle{x,y,pWidth,pHeight}, 0.8, 0, WHITE);
	}
	void Update(){
		if(IsKeyDown(KEY_UP)||IsKeyDown(KEY_W))
			y -= speed;
		if(IsKeyDown(KEY_DOWN)||IsKeyDown(KEY_S))
			y += speed;

		LimitMovement();
	}
};

#endif
