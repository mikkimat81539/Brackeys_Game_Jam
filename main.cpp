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
			player_state = IDLE_RIGHT;
		}

		if (IsKeyDown(KEY_LEFT)) {
			player_state = IDLE_LEFT;
		}


		// IDLE RIGHT
		if (player_state == IDLE_RIGHT){

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

			// MOVING UP AND DOWN RIGHT STATE
			if (IsKeyDown(KEY_UP)){
				idle_right.position.y -= idle_right.velocity.y * dt;
			}

			else if (IsKeyDown(KEY_DOWN)){
				idle_right.position.y += idle_right.velocity.y * dt;
			}

			// BOUNDARIES
			if (idle_right.position.y <= 270) {
				idle_right.position.y = 270;

			}

			else if (idle_right.position.y >= 420) {
				idle_right.position.y = 420;
			}

		}

		// IDLE FRAME LEFT
		if (player_state == IDLE_LEFT){
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

			// MOVING UP AND DOWN LEFT STATE
			if (IsKeyDown(KEY_UP)){
				idle_left.position.y -= idle_left.velocity.y * dt;
			}

			else if (IsKeyDown(KEY_DOWN)){
				idle_left.position.y += idle_left.velocity.y * dt;

			}
		
			// BOUNDARIES
			if (idle_left.position.y <= 270) {
				idle_left.position.y = 270;
			}

			else if (idle_left.position.y >= 420) {
				idle_left.position.y = 420;
			}
	
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

		DrawTexture(house, 0, 0, WHITE);
		DrawTexture(front_fence, 0, 470, WHITE);	
		DrawTexture(back_fence, 0, 200, WHITE);	
	

		EndDrawing();
	}
	
	CloseWindow();

	return 0;
}
