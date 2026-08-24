# include <iostream>
# include "raylib.h"
# include "constants.h"

using namespace std;

# define print(x) cout << x << endl;

int main(){
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Get Off My Lawn (Prototype)");

	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(RAYWHITE);

		EndDrawing();
	}
	
	CloseWindow();

	return 0;
}
