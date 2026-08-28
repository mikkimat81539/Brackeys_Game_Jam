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
	Texture2D idle = LoadTexture("assets/idle.png"); // right idle facing sprite

	Sprite sprite_idle;
	sprite_idle.position = {200, 350};
	sprite_idle.frameRec = {0, 0, 128, 128};
	// sprite_idle.active = true;

	int frameCounter = 0; // iterates throgh each frame

	// PLAYER LEFT IDLE SPRITE
	Texture2D left_idle = LoadTexture("assets/left_idle.png"); // left idle facing sprite

	Sprite sprite_idle_left;
	sprite_idle_left.position = {200, 350};
	sprite_idle_left.frameRec = {0, 0, 128, 128};
	// sprite_idle_left.active = false;

	int frameCounterLeft = 0;

	// PLAYER RUN SPRITE
	Texture2D run = LoadTexture("assets/run.png");

	Sprite sprite_run;
	sprite_run.position = {sprite_idle.position};
	sprite_run.frameRec = {0, 0, 128, 128};
	sprite_run.velocity = {100, 100};
	// sprite_run.active = false;

	int frameCounterRun = 0;	
	int runTimer = 0;


	// PLAYER RUN LEFT SPRITE
	Texture2D run_left = LoadTexture("assets/run_left.png");

	Sprite sprite_run_left;
	sprite_run_left.position = {sprite_idle_left.position};
	sprite_run_left.frameRec = {0, 0, 128, 128};
	sprite_run_left.velocity = {100, 100};
	// sprite_run_left.active = false;

	int frameCounterRunLeft = 0;	

	int runLeftTimer = 0;

	// PLAYER STATE
	STATE sprite_state = IDLE;

	// FPS
	SetTargetFPS(FPS/2);

	// GAME LOOP
	while(!WindowShouldClose()){
		float dt = GetFrameTime();

		// RUN CONDITION RIGHT
		if (IsKeyDown(KEY_RIGHT)) {
//			sprite_idle.active = false;
//			sprite_run.active = true;
//			sprite_idle_left.active = false;
//			sprite_run_left.active = false;

//			if (sprite_state == RIGHT){
//				sprite_run.position = sprite_run_left.position;
//			}

			sprite_state = RIGHT;


			sprite_run.position.x += sprite_run.velocity.x * dt;
	
			// out of bounds
			if (sprite_run.position.x >= SCREEN_WIDTH - sprite_run.frameRec.width) {
				sprite_run.position.x -= sprite_run.velocity.x * dt;
			}

			sprite_idle.position.x = sprite_run.position.x;
		}

		// RUN CONDITION LEFT
		else if (IsKeyDown(KEY_LEFT)) {
//			sprite_idle.active = false;
//			sprite_run.active = false;
//			sprite_idle_left.active = false;
//			sprite_run_left.active = true;

			if (sprite_state == RIGHT){
				sprite_run_left.position = sprite_run.position;
			}

			sprite_state = LEFT;


			sprite_run_left.position.x -= sprite_run_left.velocity.x * dt;

			if (sprite_run_left.position.x <= 0 + 90) {
				sprite_run_left.position.x += sprite_run_left.velocity.x * dt;
			}

			sprite_idle_left.position.x = sprite_run_left.position.x;

		}


		// IDLE CONDITION
		else {
			if (sprite_state == LEFT){
//				sprite_idle.active = false;
//				sprite_run.active = false;
//				sprite_idle_left.active = true;
//				sprite_run_left.active = false;

				sprite_state = IDLE_LEFT;

				sprite_idle_left.position.x = sprite_run_left.position.x;

			}

			else if (sprite_state == RIGHT){
//				sprite_idle.active = true;
//				sprite_idle_left.active = false;
//				sprite_run.active = false;
//				sprite_run_left.active = false;

				sprite_state = IDLE;
		
				sprite_idle.position.x = sprite_run.position.x;

			}
		}


		// IDLE FRAME MOVEMENT
		if (sprite_state == IDLE){

			frameCounter++;

			if (frameCounter >= 28){
				frameCounter = 0;
			}

			sprite_idle.frameRec.x = (frameCounter % 4) * sprite_idle.frameRec.width; // moves across the 4 columns.
			sprite_idle.frameRec.y = (frameCounter / 4) * sprite_idle.frameRec.height; // moves down the 7 rows
		}

		
		// LEFT IDLE FRAME MOVEMENT
		if (sprite_state == IDLE_LEFT){

			frameCounterLeft++;

			if (frameCounterLeft >= 28){
				frameCounterLeft = 0;
			}

			sprite_idle_left.frameRec.x = (frameCounterLeft % 4) * sprite_idle_left.frameRec.width; // moves across the 4 columns.
			sprite_idle_left.frameRec.y = (frameCounterLeft / 4) * sprite_idle_left.frameRec.height; // moves down the 7 rows

		}

		// RUN MOVEMENT
		if (sprite_state == RIGHT){
			runTimer++;

			if (runTimer >= 1){
				runTimer = 0;
		
				frameCounterRun++;

				if (frameCounterRun >= 34){
					frameCounterRun = 0;
				}

			}

			sprite_run.frameRec.x = (frameCounterRun % 2) * sprite_run.frameRec.width;
			sprite_run.frameRec.y = (frameCounterRun / 2) * sprite_run.frameRec.height;
		}

		// RUN LEFT MOVEMENT
		if (sprite_state == LEFT){
			runLeftTimer++;

			if (runLeftTimer >= 1){
				runLeftTimer = 0;
		
				frameCounterRunLeft++;

				if (frameCounterRunLeft >= 34){
					frameCounterRunLeft = 0;
				}

			}

			sprite_run_left.frameRec.x = (frameCounterRunLeft % 2) * sprite_run_left.frameRec.width;
			sprite_run_left.frameRec.y = (frameCounterRunLeft / 2) * sprite_run_left.frameRec.height;
		}

		// DRAW
		BeginDrawing();
		ClearBackground(WHITE);
		
		DrawTexture(house, 0, 0, WHITE); // house

		DrawTexture(front_fence, 0, 470, WHITE); // front fence
		DrawTexture(back_fence, 0, 250, WHITE); // back fence

		if(sprite_state == RIGHT){
			DrawTextureRec(run, sprite_run.frameRec, sprite_run.position, WHITE); // run right sprite
		}

		else if(sprite_state == LEFT){
			DrawTextureRec(run_left, sprite_run_left.frameRec, sprite_run_left.position, WHITE); // run left sprite
		}

		else if (sprite_state == IDLE){
			DrawTextureRec(idle, sprite_idle.frameRec, sprite_idle.position, WHITE); // right idle player
		}

		else if (sprite_state == IDLE_LEFT){
			DrawTextureRec(left_idle, sprite_idle_left.frameRec, sprite_idle_left.position, WHITE); // left idle player
		}

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
