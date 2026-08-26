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
