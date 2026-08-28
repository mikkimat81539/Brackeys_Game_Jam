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
	sprite.position = {SCREEN_CENTER};
	sprite.frameRec = {0, 0, 128, 128};
	
	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){




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
