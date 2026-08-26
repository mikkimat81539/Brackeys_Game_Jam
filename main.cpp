# include <iostream>
# include <vector>

# include "raylib.h"
# include "player.h"
# include "constants.h"
# include "projectile.h"

using namespace std;

# define print(x) cout << x << endl;

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
	projectile.radius = 5;

	projectile.velocity = {250, 250};

	projectile.active = false;

	projectile.direction = Direction::Right;


	// Store Projectile in vector
	vector<Projectile> magazine = {};


	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){
		float dt = GetFrameTime();

		// KEY INPUT
		if (IsKeyPressed(KEY_LEFT)){
			projectile.direction = Direction::Left;
		}
			
		if (IsKeyPressed(KEY_RIGHT)){
			projectile.direction = Direction::Right;
		}

		if (IsKeyPressed(KEY_UP)){
			projectile.direction = Direction::Up;
		}

		if (IsKeyPressed(KEY_DOWN)){
			projectile.direction = Direction::Down;
		}

		if (IsKeyPressed(KEY_SPACE)){
			projectile.position.x = player.position.x - 10; // Reset back to original position
			projectile.position.y = player.position.y - 10;
			
			projectile.active = true;

			magazine.push_back(projectile);

		}


		// Projectile Movement
		for (int i = 0; i < magazine.size(); i++){
			if (magazine[i].active) {
				if (magazine[i].direction == Direction::Left){
					magazine[i].position.x -= magazine[i].velocity.x * dt;
				}

				if (magazine[i].direction == Direction::Right){
					magazine[i].position.x += magazine[i].velocity.x * dt;
				}

				if (magazine[i].direction == Direction::Up){
					magazine[i].position.y -= magazine[i].velocity.y * dt;
				}

				if (magazine[i].direction == Direction::Down){
					magazine[i].position.y += magazine[i].velocity.y * dt;
				}
			}
		}


		BeginDrawing();
		ClearBackground(RAYWHITE);

	
		// Draw Projectile	
		for (int i=0; i < magazine.size(); i++){
			DrawCircle(magazine[i].position.x, magazine[i].position.y, magazine[i].radius, RED);
		}

		DrawRectangle(playerCenterX, playerCenterY, player.width, player.height, BLACK); // PLAYER

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
