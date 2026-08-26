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
	opponent.velocity = {150, 150};

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

			// Opponent distance
			float dx = pow((spawn[i].x - spawn[i-1].x),2);
			float dy = pow((spawn[i].y - spawn[i-1].y),2);
	
			float d = sqrt(dx+dy);
	
			if (d <= 50){
				// If distance between two points is less than 5 space out
				spawn[i].x -= 100;
				spawn[i].y -= 100;

				spawn[i-1].x += 100;
				spawn[i-1].y += 100;

			}

			if (spawn.size() == SPAWN_RATE) {
				exit(0);
			}
			
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
			DrawCircle(spawn[i].x, spawn[i].y, spawn[i].radius, RED); // Opponent
		}
	
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
