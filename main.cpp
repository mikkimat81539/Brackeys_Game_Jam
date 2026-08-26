# include <iostream>

# include "raylib.h"
# include "player.h"
# include "constants.h"

using namespace std;

int main(){
	// SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Projectile Practice");
	

	// GAME LOOP
	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(RAYWHITE);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
