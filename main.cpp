# include <iostream>

# include "raylib.h"
# include "constants.h"
# include "gameplay.h"

using namespace std;

int main(){
	// SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Get Off My Lawn");
	Color screen_color = {247, 239, 218, 255};
	
	bool insert_coin = true;

	
	// GAME LOOP

	while(!WindowShouldClose()){
		// IF SPACE BAR IS PRESSED START GAME PLAY
		if (IsKeyPressed(KEY_ENTER)){
			insert_coin = false;
			gameplay();
			exit(0);
		}

		BeginDrawing();
		ClearBackground(screen_color);

		if (insert_coin){
			DrawText("PRESS ENTER TO BEGIN", 80, SCREEN_CENTER.y, 50, RED);
		}

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
