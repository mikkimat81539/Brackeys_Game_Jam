# include <iostream>

# include "raylib.h"
# include "constants.h"
# include "player.h"

using namespace std;

# define print(x); cout << x << endl;

int main(){
	// SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Spawning Opponents");

	// PLAYER
	Player player;
	player.x = SCREEN_WIDTH/2;
	player.y = SCREEN_HEIGHT/2;
	player.width = 20;
	player.height = 20;	
	player.velocity = {500, 500};

	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){
		// DELTA TIME
		float dt = GetFrameTime();

		// PLAYER MOVEMENT
		if (IsKeyDown(KEY_LEFT)){
			player_move_left(player, dt);

		}

		if (IsKeyDown(KEY_RIGHT)){
			player_move_right(player, dt);

		}

		if (IsKeyDown(KEY_UP)){
			player_move_up(player, dt);

		}

		if (IsKeyDown(KEY_DOWN)){
			player_move_down(player, dt);

		}

		int playerCenterX = player.x - player.width;
		int playerCenterY = player.y - player.height;


		// DRAWING
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawRectangle(playerCenterX, playerCenterY, player.width, player.height, BLACK);
		
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
