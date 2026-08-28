# include <iostream>
# include <vector>
# include <cstdlib>
# include <ctime>

# include "raylib.h"
# include "constants.h"
//# include "player.h"
//# include "projectile.h"
//# include "opponents.h"

using namespace std;

# define print(x) cout << x << endl;

int main() {
	// SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Get Off My Lawn");


	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(RAYWHITE);

		EndDrawing();
	}
	
	CloseWindow();

	return 0;
}
