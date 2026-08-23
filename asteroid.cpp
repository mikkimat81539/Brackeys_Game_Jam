# include <iostream>
# include "raylib.h"
# include "constants.h"
# include "player.h"

using namespace std;

int main() {
	// SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Asteroid");

	Player player;
	player.position = SCREEN_CENTER;
	player.velocity =  {2, 2};

	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()) {
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

		DrawPoly(player.position, 3, 20, 0, WHITE);


		EndDrawing();	

	}

	CloseWindow();	

	return 0;
}

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
