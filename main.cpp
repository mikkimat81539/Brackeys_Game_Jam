# include <iostream>

# include "raylib.h"
# include "constants.h"

using namespace std;

# define print(x) cout << x << endl;o

int main(){

	// SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sprite Practice");


	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){
	flaot dt = GetFrameTime(); delta time

	// DRAW
	BeginDrawing();
	ClearBackground(RAYWHITE);

	EndDrawing();

	}

	CloseWindow();

	return 0;
}
