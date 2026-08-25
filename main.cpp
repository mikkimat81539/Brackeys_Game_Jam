# include <iostream>

# include "raylib.h"
# include "constants.h"
# include "player.h"

using namespace std;

# define print(x); cout << x << endl;

int main(){
	// SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Spawning Opponents");

	// PLAYER
	Player player;
	player.x = SCREEN_WIDTH/2;
	player.y = SCREEN_HEIGHT/2;
	player.width = 20;
	player.height = 20;	

	int playerCenterX = player.x - player.width;
	int playerCenterY = player.y - player.height;


	// GAME LOOP
	while(!WindowShouldClose()){

		// DRAWING
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawRectangle(playerCenterX, playerCenterY, player.width, player.height, BLACK);
		
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
