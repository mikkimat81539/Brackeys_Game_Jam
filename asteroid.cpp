# include <iostream>
# include "raylib.h"
# include "constants.h"
# include "player.h"

using namespace std;

int main() {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Asteroid"); // SCREEN

	Player player; // Define player
	player.position = SCREEN_CENTER;
	player.velocity =  {2, 2};

	SetTargetFPS(FPS); // FPS

	// GAME LOOP
	while(!WindowShouldClose()) {

		//PLAYER MOVEMENT CONDITIONS
		if (IsKeyDown(KEY_LEFT)){
			player_move_left(player);

		}

		if (IsKeyDown(KEY_RIGHT)){
			player_move_right(player);

		}

		if (IsKeyDown(KEY_UP)){
			player_move_up(player);

		}

		if (IsKeyDown(KEY_DOWN)){
			player_move_down(player);

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
void player_move_left(Player &player){
	player.position.x -= player.velocity.x;
}

void player_move_right(Player &player){
	player.position.x += player.velocity.x;
}

void player_move_up(Player &player){
	player.position.y -= player.velocity.y;
}

void player_move_down(Player &player){
	player.position.y += player.velocity.y;
}
