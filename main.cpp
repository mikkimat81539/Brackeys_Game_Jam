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

	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){

		// DRAW
		BeginDrawing();
		ClearBackground(RAYWHITE);
		
		DrawTexture(house, 0, 0, WHITE);

		DrawTexture(front_fence, 0, 470, WHITE);
		DrawTexture(back_fence, 0, 250, WHITE);


		EndDrawing();
	}

	CloseWindow();

	return 0;
}
