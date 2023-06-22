#include <bits/stdc++.h>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <math.h>
#include <ratio>
#include <raylib.h>
using namespace std;

int player_score = 0;
int cpu_score = 0;
Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};

#define WIDTH 1280
#define HEIGHT 800

#define FPS 60
class Ball{
public:
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
		x = GetScreenWidth()/2;
		y= GetScreenHeight()/2;

		int speed_choices[2] = {-1,1};
		speed_X*=speed_choices[GetRandomValue(0, 1)];
		speed_Y*=speed_choices[GetRandomValue(0, 1)];
	}
};

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

class CpuPaddle: public Paddle
{
public:
	void Update(int ball_y){
		if(y+pHeight/2>ball_y)
			y-=speed;
		if(y+pHeight/2 <= ball_y)
			y+=speed;

		LimitMovement();
	}
};


Ball ball;
Paddle player;
CpuPaddle cpu;
int main()
{
	InitWindow(WIDTH ,HEIGHT, "PONG");
	SetTargetFPS(FPS);
	//Ball Creation
	ball.y=(float)HEIGHT/2;
	ball.x=(float)WIDTH/2;
	ball.speed_X=7;
	ball.speed_Y=7;
	ball.radius=20;
	//Player Creation
	player.pWidth=25;
	player.pHeight=120;
	player.x = WIDTH - player.pWidth -10;
	player.y = (float)HEIGHT/2 - player.pHeight/2;
	player.speed = 6;
	//Cpu Creation
	cpu.pWidth=25;
	cpu.pHeight=120;
	cpu.x = 10;
	cpu.y = (float)HEIGHT/2 - cpu.pHeight/2;
	cpu.speed = 6;
	

	//Game Loop
	while (!WindowShouldClose()) {
		BeginDrawing();
		
		//updating
		ball.Update();
		player.Update();
		cpu.Update(ball.y);
		
		//Checking Collisions
		if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, 
					Rectangle{player.x, player.y,player.pWidth,player.pHeight}))
			ball.speed_X *= -1;

		if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius,
					Rectangle{cpu.x, cpu.y,cpu.pWidth,cpu.pHeight}))
			ball.speed_X *= -1;


		//CLear Stage
		ClearBackground(Dark_Green);

		//Draw Objects		
		DrawRectangle(WIDTH/2, 0, WIDTH/2, HEIGHT, Green);
		DrawCircle(WIDTH/2, HEIGHT/2,150, Light_Green);
		DrawLine(WIDTH/2,0, WIDTH/2,HEIGHT,WHITE);
		ball.Draw();
		cpu.Draw();
		player.Draw();
		DrawText(TextFormat("%i",cpu_score), (WIDTH/4)-20, 20, 80, WHITE);
		DrawText(TextFormat("%i",player_score), 3 * ((WIDTH/4)-20), 20, 80, WHITE);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
