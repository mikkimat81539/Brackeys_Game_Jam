# include <iostream>
# include <vector>

# include "raylib.h"
# include "constants.h"
# include "player.h"
# include "projectile.h"

using namespace std;

# define print(x); cout << x << endl;
# define print2(x, y) cout << x << "," << y << endl;


int main(){
	// SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Collision Practice");

	// PLAYER
	Player player;
	player.position.x = SCREEN_CENTER.x;
	player.position.y = SCREEN_CENTER.y;	
	player.width = 25;
	player.height = 50;
	
	float playerCenterX = player.position.x - player.width;
	float playerCenterY = player.position.y - player.height;

	// PROJECTILES
	Projectile projectile;
	projectile.position.x = player.position.x - 5;
	projectile.position.y = player.position.y - 5;

	projectile.direction = player.direction; // INITIAL IS RIGHT

	projectile.velocity = {300, 300};
	projectile.active = false;

	// projectile storage
	vector<Projectile> magazine = {};

	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){
		// DELTA TIME
		float dt = GetFrameTime();

		// set player direction when key is pressed
		if (IsKeyPressed(KEY_LEFT)){
			projectile.direction =  Direction::Left;	
		}

		if (IsKeyPressed(KEY_RIGHT)){
			projectile.direction =  Direction::Right;
		}

		if (IsKeyPressed(KEY_UP)){
			projectile.direction =  Direction::Up;
		}

		if (IsKeyPressed(KEY_DOWN)){
			projectile.direction =  Direction::Down;
		}

		print(projectile.direction);

		// set projectile direction when space bar is pressed

		// apply projectile movement from vector
	
		BeginDrawing();	
		ClearBackground(RAYWHITE);		

		DrawRectangle(playerCenterX, playerCenterY, player.width, player.height, BLACK);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
