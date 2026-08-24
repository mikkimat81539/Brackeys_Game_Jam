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
	

	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){
		// DELTA TIME
		float dt = GetFrameTime();

		BeginDrawing();
		ClearBackground(RAYWHITE);

		// DRAW
		 DrawRectangleLines(lawn.x, lawn.y, lawn.width, lawn.height, BLACK); // lawn
		DrawRectangleLines(walls.x, walls.y, walls.width, walls.height, BLACK); // walls


		EndDrawing();
	}
	
	CloseWindow();

	return 0;
}
