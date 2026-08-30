# include <iostream>

# include "raylib.h"
# include "constants.h"
# include "gameplay.h"
# include "assets.h"

using namespace std;

int main(){
	// SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Get Off My Lawn");
	Color screen_color = {247, 239, 218, 255};
	
	bool insert_coin = true;
	
	// WALLPAPER
	LoadGameAssets();	
	
	// GAME LOOP
	while(!WindowShouldClose()){
		// IF SPACE BAR IS PRESSED START GAME PLAY
		if (IsKeyPressed(KEY_ENTER)){
			insert_coin = false;
			gameplay();
			break;
		}

		BeginDrawing();
		ClearBackground(screen_color);

		if (insert_coin){
			DrawTexture(wallpaper, 0, 0, WHITE);
			DrawText("PRESS ENTER TO BEGIN", 170, SCREEN_CENTER.y, 40, RED);
		}

		EndDrawing();
	}

	UnloadTexture(wallpaper);

	CloseWindow();

	return 0;
}
