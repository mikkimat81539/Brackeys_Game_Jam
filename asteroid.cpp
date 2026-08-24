# include <iostream>
# include "raylib.h"
# include "constants.h"
# include "player.h"
# include "asteroid.h"
# include <ctime>
# include <cstdlib>
# include <random>

using namespace std;

# define print(x) cout << x << endl;

int main() {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Asteroid"); // SCREEN

	// PLAYER
	Player player; // Define player
	player.position = SCREEN_CENTER;
	player.velocity =  {400, 400};
	player.rotation = 0;

	// ASTEROID
	srand(time(0));

	float rand_y = rand() % 602;

	mt19937 generator(random_device{}());

	uniform_int_distribution<int>distribution(4, 7);
	int sides = distribution(generator);

	Asteroid asteroid1;
	asteroid1.position = {-1, rand_y};
	asteroid1.sides = float(sides);

	float rand_y2 = rand() % 601;

	uniform_int_distribution<int>distribution2(4, 7);
	int sides2 = distribution2(generator);

	Asteroid asteroid2;
	asteroid2.position = {SCREEN_WIDTH, rand_y2};
	asteroid2.sides = float(sides2);

	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()) {
		// DELTA TIME
		float dt = GetFrameTime();


		//PLAYER MOVEMENT CONDITIONS
		if (IsKeyDown(KEY_LEFT)){
			player_move_left(player, dt);
			player.rotation = 180;

		}

		if (IsKeyDown(KEY_RIGHT)){
			player_move_right(player, dt);
			player.rotation = 0;

		}

		if (IsKeyDown(KEY_UP)){
			player_move_up(player, dt);
			player.rotation = 270;

		}

		if (IsKeyDown(KEY_DOWN)){
			player_move_down(player, dt);
			player.rotation = 90;

		}


		// PLAYER OUT OF BOUNDS
		if (player.position.x > SCREEN_WIDTH){
			player.position.x = 0;
		}

		if (player.position.x < 0){
			player.position.x = SCREEN_WIDTH;
		}

		if (player.position.y > SCREEN_HEIGHT){
			player.position.y = 0;
		}

		if (player.position.y < 0){
			player.position.y = SCREEN_HEIGHT;
		}

		BeginDrawing();
		HideCursor();
		ClearBackground(BLACK);

		// DRAWING PLAYER
		DrawPoly(player.position, 3, 20, player.rotation, WHITE);
	
		// DRAWING ASTEROIDS
		
		DrawPolyLines(asteroid1.position, asteroid1.sides, 20, 0, WHITE);
		DrawPolyLines(asteroid2.position, asteroid2.sides, 20, 0, WHITE);
	
		EndDrawing();	

	}

	CloseWindow();	

	return 0;
}

// PLAYER MOVEMENT FUNCTIONS
void player_move_left(Player &player, float dt){
	player.position.x -= player.velocity.x * dt;

}

void player_move_right(Player &player, float dt){
	player.position.x += player.velocity.x * dt;
}

void player_move_up(Player &player, float dt){
	player.position.y -= player.velocity.y * dt;
}

void player_move_down(Player &player, float dt){
	player.position.y += player.velocity.y * dt;
}
