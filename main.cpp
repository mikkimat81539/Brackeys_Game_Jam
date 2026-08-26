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
	// projectile.position.x = playerCenterX;
	// projectile.position.y = playerCenterY;
	projectile.radius = 5;

	// float projectileCenterX = projectile.position.x + projectile.radius;
	// float projectileCenterY = projectile.position.y + projectile.radius;
	
	projectile.velocity = {250, 250};

	projectile.active = false;

	// Store Projectile in vector
	vector<Projectile> magazine = {};


	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){
		float dt = GetFrameTime();

		// KEY INPUT
		if (IsKeyDown(KEY_LEFT)){
			projectile.direction = Direction::Left;
		}
			
		else if (IsKeyDown(KEY_RIGHT)){
			projectile.direction = Direction::Right;
		}

		else if (IsKeyDown(KEY_UP)){
			projectile.direction = Direction::Up;
		}

		else if (IsKeyDown(KEY_DOWN)){
			projectile.direction = Direction::Down;
		}

		if (IsKeyPressed(KEY_SPACE)){
			projectile.position.x = player.position.x;
			projectile.position.y = player.position.y;
			
			projectile.direction = player.direction;

			projectile.active = true;

		}

		if (projectile.active) {
			if (projectile.direction == Direction::Left){
				projectile.position.x -= projectile.velocity.x * dt;
			}

			else if (projectile.direction == Direction::Right){
				projectile.position.x += projectile.velocity.x * dt;
			}

			else if (projectile.direction == Direction::Up){
				projectile.position.y -= projectile.velocity.y * dt;
			}

			else if (projectile.direction == Direction::Down){
				projectile.position.y += projectile.velocity.y * dt;
			}
		}


		float projectileCenterX = projectile.position.x - projectile.radius;
		float projectileCenterY = projectile.position.y - projectile.radius;


		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawCircle(projectileCenterX, projectileCenterY, projectile.radius, RED); // PROJECTILE

		DrawRectangle(playerCenterX, playerCenterY, player.width, player.height, BLACK); // PLAYER

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
