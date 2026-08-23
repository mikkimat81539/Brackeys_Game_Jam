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
			player_movement(player);

		}

		BeginDrawing();
		HideCursor();
		ClearBackground(BLACK);

		DrawPoly(player.position, 3, 20, 0, WHITE);


		// DrawPoly(player.position, 3, 20, 0, WHITE);


		EndDrawing();	

	}

	CloseWindow();	

	return 0;
}

void player_movement(Player &player){
	player.position.x -= player.velocity.x;
}
