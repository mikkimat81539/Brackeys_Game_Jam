# include <iostream>

# include "raylib.h"
# include "constants.h"
# include "sprites.h"

using namespace std;

# define print(x) cout << x << endl;

int main() {
	// SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sprite Practice");

	// HOUSE
	Texture2D house = LoadTexture("assets/house.png");

	// FENCE
	Texture2D front_fence = LoadTexture("assets/front_fence.png");
	Texture2D back_fence = LoadTexture("assets/back_fence.png");

	// PLAYER
	Texture2D player = LoadTexture("assets/idle.png");

	Sprite sprite;
	sprite.position = {SCREEN_CENTER.x, 350};
	sprite.frameRec = {0, 0, 128, 128};
	
	int frameCounter = 0;

	// FPS
	SetTargetFPS(FPS / 2);

	// GAME LOOP
	while(!WindowShouldClose()){
		// SPRITE MOVEMENT
		frameCounter++;

		if (frameCounter >= 28){
			frameCounter = 0;
		}

		sprite.frameRec.x = (frameCounter % 4) * sprite.frameRec.width; // moves across the 4 columns.
		sprite.frameRec.y = (frameCounter / 4) * sprite.frameRec.height; // moves down the 7 rows
		

		// DRAW
		BeginDrawing();
		ClearBackground(WHITE);
		
		DrawTexture(house, 0, 0, WHITE); // house

		DrawTexture(front_fence, 0, 470, WHITE); // front fence
		DrawTexture(back_fence, 0, 250, WHITE); // back fence

		DrawTextureRec(player, sprite.frameRec, sprite.position, WHITE); // player

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
