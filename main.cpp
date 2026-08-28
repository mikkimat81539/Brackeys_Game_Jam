# include <iostream>
# include <vector>
# include <cstdlib>
# include <ctime>

# include "raylib.h"
# include "constants.h"
# include "mechanics.h"

using namespace std;

# define print(x) cout << x << endl;

int main() {
	// SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Get Off My Lawn");
	
	// HOUSE
	Texture2D house = LoadTexture("assets/house.png");

	// FENCE
	Texture2D front_fence = LoadTexture("assets/front_fence.png");
	Texture2D back_fence = LoadTexture("assets/back_fence.png");

	// PLAYER
	Texture2D idle_right_img = LoadTexture("assets/idle_right.png");

	Player idle_right;
	idle_right.position = {350, 350}; // position of sprite
	idle_right.frameRec = {0, 0, 128, 128}; // crop spritesheet 
	idle_right.direction = IDLE_RIGHT;

	int frameCount = 0; // number of frames in spritesheet

	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){
		float dt = GetFrameTime();
	
		// IDLE RIGHT FRAME	
		if (idle_right.direction == IDLE_RIGHT){
			frameCount++; // iterate through frames

			if (frameCount >= 28) {
				frameCount = 0;
			}
		}
		


		// DRAW
		BeginDrawing();
		ClearBackground(RAYWHITE);

		if (idle_right.direction == IDLE_RIGHT){
			DrawTextureRec(idle_right_img, idle_right.frameRec, idle_right.position, WHITE);
		}

		DrawTexture(house, 0, 0, WHITE);
		DrawTexture(front_fence, 0, 470, WHITE);	
		DrawTexture(back_fence, 0, 200, WHITE);	
	

		EndDrawing();
	}
	
	CloseWindow();

	return 0;
}
