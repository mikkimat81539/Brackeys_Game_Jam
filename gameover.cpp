# include <iostream>

# include "raylib.h"
# include "constants.h"
# include "gameplay.h"

using namespace std;

void gameover(){

	// GAME LOOP
	while(!WindowShouldClose()){

		BeginDrawing();
		ClearBackground(Color {247, 239, 218, 255});

		DrawText("GAME OVER", 100, SCREEN_CENTER.y, 100, BLACK);

		EndDrawing();
	}
}
