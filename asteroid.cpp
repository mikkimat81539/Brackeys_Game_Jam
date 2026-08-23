# include <iostream>
# include "raylib.h"
# include "constants.h"

using namespace std;

int main() {
	// SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Asteroid");

	// GAME LOOP
	while(!WindowShouldClose()) {
		BeginDrawing();
		HideCursor();
		ClearBackground(BLACK);

		EndDrawing();	

	}
	

	return 0;
}
