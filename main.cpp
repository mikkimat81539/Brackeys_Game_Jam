# include <iostream>
# include "raylib.h"
# include "constants.h"
# include "property.h"

using namespace std;

# define print(x) cout << x << endl;

int main(){
	// INITIALIZE SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Get Off My Lawn (Prototype)");

	// Create Lawn
	SQUARE lawn;
	lawn.x = SCREEN_CENTER.x - 350/2; // offset so it is centered
	lawn.y = SCREEN_CENTER.y - 450/2;
	lawn.width = 300;
	lawn.height = 300;

	// Create Walls
	SQUARE walls;
	walls.x = lawn.width + 32;
	walls.y = 200;
	walls.width = 100;
	walls.height = 100;
	

	// Create Roof
	ROOF roof1;
	roof1.position = {float(walls.x) + 50, 170};	
	roof1.sides = 3;
	roof1.size = 60;
	roof1.rotation = 270.0f;

	// Create Fence
	SQUARE fence;
	fence.x = 170;
	fence.y = 30;
	fence.width = 400;
	fence.height = 400;
	
	// Create Fence
	SQUARE player;
	player.x = 385;
	player.y = 319;
	player.width = 20;
	player.height = 20;

	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){
		// DELTA TIME
		float dt = GetFrameTime();

		// MOUSE
//		Vector2 mouse = GetMousePosition();
//		if (IsMouseButtonDown(0)){
//			cout << mouse.x << "," << mouse.y << endl;
//		}

		BeginDrawing();
		ClearBackground(RAYWHITE);

		// DRAW
		DrawRectangleLines(lawn.x, lawn.y, lawn.width, lawn.height, BLACK); // lawn
		DrawRectangleLines(walls.x, walls.y, walls.width, walls.height, BLACK); // walls
		DrawPolyLines(roof1.position, roof1.sides, roof1.size, roof1.rotation, BLACK); // left roof
		DrawRectangle(player.x, player.y, player.width, player.height, RED); // player



		EndDrawing();
	}
	
	CloseWindow();

	return 0;
}
