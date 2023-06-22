#include<bits/stdc++.h>
#include <cstdio>
#include <raylib.h>

#define width 800
#define height 500

#define FPS 30


int main(){

	InitWindow(width, height, "new window");

	SetTargetFPS(FPS);

	while(!WindowShouldClose()){
		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("congrats window success!",(width/2),(height/2),20,BLACK);
		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}

