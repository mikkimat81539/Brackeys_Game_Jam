# include <iostream>

# include "raylib.h"
# include "constants.h"
# include "sprites.h"

using namespace std;

# define print(x) cout << x << endl;

int main() {
	// SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sprite Practice");

	// GAME LOOP
	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(RAYWHITE);

		EndDrawing();

	}

	CloseWindow();

	return 0;
}
