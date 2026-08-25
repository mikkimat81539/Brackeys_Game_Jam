# include <iostream>
# include <cmath>
# include "raylib.h"
# include "constants.h"
# include "property.h"
# include "player.h"


using namespace std;

# define print(x) cout << x << endl;

int main(){
	// INITIALIZE SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Get Off My Lawn (Prototype)");

	// Create Lawn
	SQUARE lawn;
	lawn.x = SCREEN_CENTER.x - 350/2; // offset so it is centered
	lawn.y = SCREEN_CENTER.y - 450/2;
	lawn.width = 300;
	lawn.height = 300;

	// Create Walls
	SQUARE walls;
	walls.x = lawn.width + 32;
	walls.y = 200;
	walls.width = 100;
	walls.height = 100;

	float wall_area = walls.width * walls.height;	

	// Create Roof
	ROOF roof;
	roof.position = {float(walls.x) + 50, 170};	
	roof.sides = 3;
	roof.size = 60;
	roof.rotation = 270.0f;

	// Create Fence
	SQUARE fence;
	fence.x = 170;
	fence.y = 30;
	fence.width = 400;
	fence.height = 400;
	
	// Create Player
	Player player;
	player.position = {385, 319};
	player.velocity = {300, 300};

	// Create Hose
	HOSE hose;
	hose.start_pos = {332, 280};
	hose.end_pos = player.position;
	hose.thickness = 3;
	Color hose_color = {43, 217, 182, 255};

	// PROJECTILES
	Projectiles projectiles;
	projectiles.radius = 5.0f;
	projectiles.velocity = 1000.0f;
	projectiles.active = false;

	projectiles.right = true;
	projectiles.left = false;
	projectiles.up = false;
	projectiles.down = false;


	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){

	// MOUSE POSITION
	Vector2 mouse = GetMousePosition();	

	if (IsMouseButtonPressed(0)){
		cout << mouse.x << "," << mouse.y << endl;

	}

		// DELTA TIME
		float dt = GetFrameTime();


		//PLAYER MOVEMENT CONDITIONS
		if (IsKeyDown(KEY_LEFT)){
			player_move_left(player, dt, walls, projectiles);
		}

		else if (IsKeyDown(KEY_RIGHT)){
			player_move_right(player, dt, walls, projectiles);
		}

		else if (IsKeyDown(KEY_UP)){
			player_move_up(player, dt, walls, projectiles);
		}

		else if (IsKeyDown(KEY_DOWN)){
			player_move_down(player, dt, walls, projectiles);
		}

		// Projectile movement
		else if (IsKeyPressed(KEY_SPACE)) {
			projectiles.x = player.position.x;
			projectiles.y = player.position.y;
			projectiles.active = true;
		}

		if (projectiles.active) {
			if (projectiles.right){
				projectiles.x += projectiles.velocity * dt;
			}

			else if (projectiles.left){
				projectiles.x -= projectiles.velocity * dt;
			}

			else if (projectiles.down){
				projectiles.y += projectiles.velocity * dt;
			}

			else if (projectiles.up){
				projectiles.y -= projectiles.velocity * dt;
			}
		
//			if (projectiles.x > SCREEN_WIDTH || projectiles.x < 0 || projectiles.y > SCREEN_HEIGHT || projectiles.y < 0){
//				projectiles.active = false;
//			}
		}


		hose.end_pos = player.position; // Have hose follow player

		BeginDrawing();
		ClearBackground(RAYWHITE);


		// DRAW
		DrawRectangleLines(lawn.x, lawn.y, lawn.width, lawn.height, GREEN); // lawn
		DrawRectangleLines(walls.x, walls.y, walls.width, walls.height, BLACK); // walls
		DrawRectangleLines(fence.x, fence.y, fence.width, fence.height, RED); // fence
		DrawLineBezier(hose.start_pos, hose.end_pos, hose.thickness, hose_color); // garden hose
		DrawCircleLines(projectiles.x, projectiles.y, projectiles.radius, BLACK); // projectiles
		DrawPoly(player.position, 4, 15, 45, BLACK);
		DrawPoly(roof.position, roof.sides, roof.size, roof.rotation, BLACK); // roof
		
		EndDrawing();
	}
	
	CloseWindow();

	return 0;
}

// PLAYER MOVEMENT FUNCTIONS
void player_move_left(Player &player, float dt, SQUARE walls, Projectiles &projectiles){
	player.position.x -= player.velocity.x * dt;
	projectiles.left = true;
	projectiles.right = false;
	projectiles.up = false;
	projectiles.down = false;


	if (CheckCollisionPointRec(player.position, Rectangle{float(walls.x), float(walls.y), float(walls.width)+8, float(walls.height)})) {
		player.position.x += player.velocity.x * dt;
	}

	if (player.position.x <= 235){
		player.position.x += player.velocity.x * dt;
	}
}

void player_move_right(Player &player, float dt, SQUARE walls, Projectiles &projectiles){
	player.position.x += player.velocity.x * dt;
	projectiles.left = false;
	projectiles.right = true;
	projectiles.up = false;
	projectiles.down = false;


	if (CheckCollisionPointRec(player.position, Rectangle{float(walls.x)-10, float(walls.y), float(walls.width), float(walls.height)})) {
		player.position.x -= player.velocity.x * dt;
	}

	if (player.position.x >= 515){
		player.position.x -= player.velocity.x * dt;
	}

}

void player_move_up(Player &player, float dt, SQUARE walls, Projectiles &projectiles){
	player.position.y -= player.velocity.y * dt;
	projectiles.left = false;
	projectiles.right = false;
	projectiles.up = true;
	projectiles.down = false;


	if (CheckCollisionPointRec(player.position, Rectangle{float(walls.x), float(walls.y), float(walls.width), float(walls.height)+8})) {
		player.position.y += player.velocity.y * dt;
	}

	if (player.position.y <= 85){
		player.position.y += player.velocity.y * dt;
	}

}

void player_move_down(Player &player, float dt, SQUARE walls, Projectiles &projectiles){
	player.position.y += player.velocity.y * dt;
	projectiles.left = false;
	projectiles.right = false;
	projectiles.up = false;
	projectiles.down = true;


	if (CheckCollisionPointRec(player.position, Rectangle{float(walls.x), float(walls.y)-12, float(walls.width), float(walls.height)})) {
		player.position.y -= player.velocity.y * dt;
	}

	if (player.position.y >= 365){
		player.position.y -= player.velocity.y * dt;
	}
}
