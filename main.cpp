# include <iostream>
# include <cmath>
# include <vector>
# include <cstdlib>
# include <ctime>

# include "raylib.h"
# include "constants.h"
# include "player.h"
# include "opponent.h"


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

	// OPPONENT
	Opponent opponent;
	opponent.x = 0;
	opponent.y = 0;
	opponent.radius = 10;
	opponent.velocity = {250, 250};

	// OPPONENT STORAGE
	vector<Opponent> spawn = {};

	srand(time(0));
	float spawnTimer = 0; // spawn timer

	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){
		// DELTA TIME
		float dt = GetFrameTime();

		// grab the difference between player and opponent
//		float dir_x = player.x - opponent.x;
//		float dir_y = player.y - opponent.y;
//
//		// define the distance using distance formula
//		float length = sqrt(dir_x*dir_x + dir_y*dir_y); // Euclidean distance / magnitude formula for a 2D vector.
//
//		// NORMALIZE
//		if (length > 0.0f){
//			dir_x /= length; // Normalizing direction makes the direction have a length of 1.
//			dir_y /= length;
//		}

		// opponent.x += dir_x * opponent.velocity.x * dt;
		// opponent.y += dir_y * opponent.velocity.y * dt;

		// SPAWN OPPONENT TIME
		spawnTimer += GetFrameTime();

		// ADD OPPONENT TO VECTOR
		if (spawnTimer >= 3.0f){
			opponent.x = SCREEN_WIDTH;
			opponent.y = rand() % SCREEN_HEIGHT;

			spawn.push_back(opponent);

			spawnTimer = 0.0f;
		}

		// UPDATE OPPONENT
		for (int i=0; i < spawn.size(); i++){
			// grab the difference between player and opponent
			float dir_x = player.x - spawn[i].x;
			float dir_y = player.y - spawn[i].y;

			// define the distance using distance formula
			float length = sqrt(dir_x*dir_x + dir_y*dir_y); // Euclidean distance / magnitude formula for a 2D vector.

			// NORMALIZE
			if (length > 0.0f){
				dir_x /= length; // Normalizing direction makes the direction have a length of 1.
				dir_y /= length;
			}
			
			spawn[i].x += dir_x * spawn[i].velocity.x * dt;
			spawn[i].y += dir_y * spawn[i].velocity.y * dt;
		}

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

		DrawRectangle(playerCenterX, playerCenterY, player.width, player.height, BLACK); // Player

		for (int i=0; i < spawn.size(); i++){	
			DrawCircleLines(spawn[i].x, spawn[i].y, spawn[i].radius, RED); // Opponent
		}
	
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
