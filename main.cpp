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

	// PLAYER IDLE SPRITE
	Texture2D idle = LoadTexture("assets/idle.png");

	Sprite sprite_idle;
	sprite_idle.position = {SCREEN_CENTER.x, 350};
	sprite_idle.frameRec = {0, 0, 128, 128};
	sprite_idle.active = true;

	
	int frameCounter = 0;

	// PLAYER RUN SPRITE
	Texture2D run = LoadTexture("assets/run.png");

	Sprite sprite_run;
	sprite_run.position = {sprite_idle.position};
	sprite_run.frameRec = {0, 0, 128, 128};
	sprite_run.velocity = {10, 10};

	// PLAYER STATE
	STATE sprite_state;

	// FPS
	SetTargetFPS(FPS / 2);

	// GAME LOOP
	while(!WindowShouldClose()){
		// SPRITE MOVEMENT

		print(sprite_state)

		// PROJECTILE CONDITION
		if (IsKeyDown(KEY_SPACE)){
			sprite_idle.active = false;
			sprite_state = SHOT;
			print(sprite_state)
		}

		else if (IsKeyDown(KEY_RIGHT)) {
			sprite_idle.active = false;
			sprite_state = RIGHT;
			print(sprite_state)
		}

		// IDLE CONDITION
		else if (GetKeyPressed() == 0){
			sprite_idle.active = true;
			sprite_state = IDLE;
		}

		// IDLE MOVEMENT
		if (sprite_state == IDLE){
			frameCounter++;

			if (frameCounter >= 28){
				frameCounter = 0;
			}

			sprite_idle.frameRec.x = (frameCounter % 4) * sprite_idle.frameRec.width; // moves across the 4 columns.
			sprite_idle.frameRec.y = (frameCounter / 4) * sprite_idle.frameRec.height; // moves down the 7 rows
		}

		// DRAW
		BeginDrawing();
		ClearBackground(WHITE);
		
		DrawTexture(house, 0, 0, WHITE); // house

		DrawTexture(front_fence, 0, 470, WHITE); // front fence
		DrawTexture(back_fence, 0, 250, WHITE); // back fence

		if (sprite_idle.active){
			DrawTextureRec(idle, sprite_idle.frameRec, sprite_idle.position, WHITE); // player
		}

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
