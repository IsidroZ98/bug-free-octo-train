#include "Ball.h"
#include "Paddle.h"
#include "Cpu.h"

#define WIDTH 1280
#define HEIGHT 800

#define FPS 60

Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};


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
		DrawText(TextFormat("%i",ball.cpu_score), (WIDTH/4)-20, 20, 80, WHITE);
		DrawText(TextFormat("%i",ball.player_score), 3 * ((WIDTH/4)-20), 20, 80, WHITE);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
