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
	
	player.velocity = {400, 400};

	// PROJECTILE
	Projectile projectile;
	projectile.position.x = playerCenterX;
	projectile.position.y = playerCenterY;
	projectile.radius = 5;

	float projectileCenterX = playerCenterX - projectile.radius;
	float projectileCenterY = playerCenterY - projectile.radius;

	projectile.active = false;

	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){
		float dt = GetFrameTime();

		BeginDrawing();
		ClearBackground(RAYWHITE);

		if (projectile.active){
			DrawCircle(projectileCenterX, projectileCenterY, projectile.radius, RED); // PROJECTILE
		}

		DrawRectangle(playerCenterX, playerCenterY, player.width, player.height, BLACK); // PLAYER

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
