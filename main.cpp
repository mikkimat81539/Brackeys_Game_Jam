# include <iostream>
# include "raylib.h"
# include "constants.h"
# include "property.h"

using namespace std;

# define print(x) cout << x << endl;

int main(){
	// INITIALIZE SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Get Off My Lawn (Prototype)");

	// GAME LOOP
	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(RAYWHITE);

		EndDrawing();
	}
	
	CloseWindow();

	return 0;
}
