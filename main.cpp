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

	// idle right
	Texture2D idle_right_img = LoadTexture("assets/idle_right.png");

	Player idle_right;
	idle_right.position = {350, 350}; // position of sprite
	idle_right.frameRec = {0, 0, 128, 128}; // crop spritesheet 
	idle_right.velocity = {100, 100};


	// idle left
	Texture2D idle_left_img = LoadTexture("assets/idle_left.png");

	Player idle_left;
	idle_left.position = {350, 350}; // position of sprite
	idle_left.frameRec = {0, 0, 128, 128}; // crop spritesheet 
	idle_left.velocity = {100, 100};

	// run right
	Texture2D run_right_img = LoadTexture("assets/run_right.png");

	Player run_right;
	run_right.position = idle_right.position; // position of sprite
	run_right.frameRec = {0, 0, 128, 128}; // crop spritesheet 
	run_right.velocity = {100, 100};
	

	// run left
	Texture2D run_left_img = LoadTexture("assets/run_left.png");

	Player run_left;
	run_left.position = idle_left.position; // position of sprite
	run_left.frameRec = {0, 0, 128, 128}; // crop spritesheet 
	run_left.velocity = {100, 100};


	// frame rate data
	int frameCount = 0; // number of frames in spritesheet
	int frameTimer = 0; // how fast computer runs each frame

	// player state
	STATE player_state = IDLE_RIGHT;

	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){
		float dt = GetFrameTime();

		// KEY INPUT
		if (IsKeyDown(KEY_RIGHT)) {

			if (player_state != RUN_RIGHT) {
				run_right.position = idle_right.position;
			}

			player_state = RUN_RIGHT;

			// FRAME RATE
			frameTimer++;

			if (frameTimer >= 6){
				frameTimer = 0;
				frameCount++; // iterate through frames

				if (frameCount >= 34) {
					frameCount = 0;
				}
				
				run_right.frameRec.x = frameCount * run_right.frameRec.width;
				run_right.frameRec.y = frameCount * run_right.frameRec.height;
			}

		}


		else if (IsKeyDown(KEY_LEFT)) {

			if (player_state != RUN_LEFT) {
				run_left.position = idle_left.position;
			}

			player_state = RUN_LEFT;

			// FRAME RATE
			frameTimer++;

			if (frameTimer >= 6){
				frameTimer = 0;
				frameCount++; // iterate through frames

				if (frameCount >= 34) {
					frameCount = 0;
				}
				
				run_left.frameRec.x = frameCount * run_left.frameRec.width;
				run_left.frameRec.y = frameCount * run_left.frameRec.height;
			}
		}

		
		else {
			// IDLE RIGHT
			if (player_state == RUN_RIGHT){

				idle_right.position = run_right.position;
				player_state = IDLE_RIGHT;


				// FRAME RATE
				frameTimer++;

				if (frameTimer >= 8){
					frameTimer = 0;
					frameCount++; // iterate through frames

					if (frameCount >= 28) {
						frameCount = 0;
					}
					
					idle_right.frameRec.x = frameCount * idle_right.frameRec.width;
					idle_right.frameRec.y = frameCount * idle_right.frameRec.height;
				}

			}

			// IDLE FRAME LEFT
			if (player_state == RUN_LEFT){

				idle_left.position = run_left.position;			
				player_state = IDLE_LEFT;


				frameTimer++;

				if (frameTimer >= 8){
					frameTimer = 0;
					frameCount++; // iterate through frames

					if (frameCount >= 28) {
						frameCount = 0;
					}
					
					idle_left.frameRec.x = frameCount * idle_left.frameRec.width;
					idle_left.frameRec.y = frameCount * idle_left.frameRec.height;
				}

			}
		}

		// MOVING UP AND DOWN LEFT STATE
		if (IsKeyDown(KEY_UP)){
			idle_right.position.y -= idle_right.velocity.y * dt;

			idle_left.position.y = idle_right.position.y; // make sure player stays in same position regardless of direction
			run_right.position.y = idle_right.position.y;
			run_left.position.y = idle_right.position.y;
		}

		else if (IsKeyDown(KEY_DOWN)){
			idle_right.position.y += idle_right.velocity.y * dt;

			idle_left.position.y = idle_right.position.y;
			run_right.position.y = idle_right.position.y;
			run_left.position.y = idle_right.position.y;
		}


		if (IsKeyDown(KEY_RIGHT)){
			run_right.position.x += run_right.velocity.x * dt;

			idle_right.position = run_right.position;
			idle_left.position = run_right.position;
			run_left.position = run_right.position;

		}

		else if (IsKeyDown(KEY_LEFT)){
			run_left.position.x -= run_left.velocity.x * dt;


			idle_left.position = run_left.position;
			idle_right.position = run_left.position;
			run_right.position = run_left.position;
		}


		// BOUNDARIES
		if (idle_right.position.y <= 270 || idle_left.position.y <= 270) {
			idle_right.position.y = 270;
			idle_left.position.y = 270;


		}

		else if (idle_right.position.y >= 420 || idle_left.position.y >= 420) {
			idle_right.position.y = 420;
			idle_left.position.y = 420;

		}

		// DRAW
		BeginDrawing();
		ClearBackground(RAYWHITE);

		if (player_state == IDLE_RIGHT){
			DrawTextureRec(idle_right_img, idle_right.frameRec, idle_right.position, WHITE);
		}

		if (player_state == IDLE_LEFT){
			DrawTextureRec(idle_left_img, idle_left.frameRec, idle_left.position, WHITE);
		}

		if (player_state == RUN_RIGHT){
			DrawTextureRec(run_right_img, run_right.frameRec, run_right.position, WHITE);
		}

		if (player_state == RUN_LEFT){
			DrawTextureRec(run_left_img, run_left.frameRec, run_left.position, WHITE);
		}

		DrawTexture(house, 0, 0, WHITE);
		DrawTexture(front_fence, 0, 470, WHITE);	
		DrawTexture(back_fence, 0, 200, WHITE);	
	

		EndDrawing();
	}
	
	CloseWindow();

	return 0;
}
