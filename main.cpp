# include <iostream>
# include <cstdlib>
# include <vector>

# include "raylib.h"
# include "constants.h"
# include "sprites.h"

using namespace std;

# define print(x) cout << x << endl;

int main(){

	// SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sprite Practice");

	// Load Player Texture
	Texture2D player = LoadTexture("assets/idle.png");

	Sprite sprite;
	sprite.position = {0, 0}; // where to position spritesheet on screen

	sprite.frameRec = {0, 0, 128, 128}; // crop the spritesheet

	int frameCounter = 0;

	// FPS
	SetTargetFPS(30);

	// GAME LOOP
	while(!WindowShouldClose()){
		float dt = GetFrameTime(); // delta time

		frameCounter++; // move frames

		if (frameCounter >= 28){
			frameCounter = 0;
		}

		sprite.frameRec.x = (frameCounter % 4) * sprite.frameRec.width; // moves across the 4 columns.
		sprite.frameRec.y = (frameCounter / 4) * sprite.frameRec.height; // moves down the 7 rows

		// DRAW
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawTextureRec(player, sprite.frameRec, sprite.position, WHITE);

		EndDrawing();

	}

	CloseWindow();

	return 0;
}
