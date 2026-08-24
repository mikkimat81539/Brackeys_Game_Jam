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
	lawn.x = SCREEN_CENTER.x - 300/2;
	lawn.y = SCREEN_CENTER.y - 300/2;
	lawn.width = 300;
	lawn.height = 300;
		

	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){
		// DELTA TIME
		float dt = GetFrameTime();

		BeginDrawing();
		ClearBackground(RAYWHITE);

		// DRAW
		DrawRectangle(lawn.x, lawn.y, lawn.width, lawn.height, GREEN);

		EndDrawing();
	}
	
	CloseWindow();

	return 0;
}
