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

	// GAME LOOP
	while(!WindowShouldClose()) {
		BeginDrawing();
		HideCursor();
		ClearBackground(BLACK);

		DrawPoly(player.position, 3, 20, 0, WHITE);

		EndDrawing();	

	}

	CloseWindow();	

	return 0;
}
