# include <iostream>
# include "raylib.h"
# include "constants.h"
# include "player.h"

using namespace std;

# define print(x) cout << x << endl;

int main() {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Asteroid"); // SCREEN

	Player player; // Define player
	player.position = SCREEN_CENTER;
	player.velocity =  {500, 500};

	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()) {
		// DELTA TIME
		float dt = GetFrameTime();


		//PLAYER MOVEMENT CONDITIONS
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


		BeginDrawing();
		HideCursor();
		ClearBackground(BLACK);

		// DRAWING PLAYER
		DrawPoly(player.position, 3, 20, 0, WHITE);
		
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
