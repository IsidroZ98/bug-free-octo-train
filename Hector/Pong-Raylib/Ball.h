#ifndef BALL_H
#define BALL_H
#include <raylib.h>
class Ball{
public:
	int player_score = 0;
	int cpu_score = 0;
	Color Yellow = Color{243, 213, 91, 255};
	float x, y;
	int speed_X, speed_Y;
	int radius;
	void Draw(){
		DrawCircle(x, y, radius, Yellow);
	}
	void Update(){

		y+=speed_Y;
		x+=speed_X;
		int deltaY = y+radius;
		int deltaX = x+radius;
		
		if(deltaY >= GetScreenHeight() || (y-radius) <= 0)
			speed_Y*=-1;
		if(deltaX >= GetScreenWidth()){// cpu win
			cpu_score++;
			ResetBall();
		}
		if((x-radius) <= 0){//player win
			player_score++;
			ResetBall();
		}
	}

	void ResetBall()
	{
		x = (float)GetScreenWidth()/2;
		y = (float)GetScreenHeight()/2;

		int speed_choices[2] = {-1,1};
		speed_X*=speed_choices[GetRandomValue(0, 1)];
		speed_Y*=speed_choices[GetRandomValue(0, 1)];
	}
};
#endif
