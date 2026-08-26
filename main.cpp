# include <iostream>

# include "raylib.h"
# include "constants.h"
# include "player.h"

using namespace std;

# define print(x); cout << x << endl;
# define print2(x, y) cout << x << "," << y << endl;


int main(){
	// SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Collision Practice");

	// PLAYER
	Player player;
	player.position.x = SCREEN_CENTER.x;
	player.position.y = SCREEN_CENTER.y;	
	player.width = 25;
	player.height = 50;
	
	float playerCenterX = player.position.x - player.width;
	float playerCenterY = player.position.y - player.height;

	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){
		BeginDrawing();	
		ClearBackground(RAYWHITE);		

		DrawRectangle(playerCenterX, playerCenterY, player.width, player.height, BLACK);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
