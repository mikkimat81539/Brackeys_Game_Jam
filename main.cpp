# include <iostream>
# include <vector>

# include "raylib.h"
# include "player.h"
# include "constants.h"
# include "projectile.h"

using namespace std;

int main(){
	// SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Projectile Practice");

	// PLAYER
	Player player;
	player.position.x = SCREEN_WIDTH/2;
	player.position.y = SCREEN_HEIGHT/2;
	player.width = 20;
	player.height = 20;

	float playerCenterX = player.position.x - player.width;
	float playerCenterY = player.position.y - player.height;
	
	player.velocity = {100, 100};

	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){
		float dt = GetFrameTime();

		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawRectangle(playerCenterX, playerCenterY, player.width, player.height, BLACK);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
