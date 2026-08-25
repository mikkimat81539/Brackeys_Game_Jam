# include <iostream>
# include <vector>
# include <cstdlib>
# include <ctime>

# include "raylib.h"
# include "constants.h"
# include "property.h"
# include "player.h"
# include "opponents.h"

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
	projectiles.projectile_num = 1;


//	projectiles.right = true;
//	projectiles.left = false;
//	projectiles.up = false;
//	projectiles.down = false;


	// OPPONENTS
	Opponent opponent;	
	opponent.x = SCREEN_WIDTH + 40; // need to spawn outside of screen

	srand(time(0)); // set up random seed

	float spawnTimer = 0; // spawn timer

//	int randY = rand() % SCREEN_HEIGHT; // spawn random pos between 0 - 599;
//	opponent.y = randY;

	opponent.radius = 10;
	opponent.velocity = 20;

	vector<Opponent> spawn = {};

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
		if (IsKeyPressed(KEY_SPACE)) {
			projectiles.x = player.position.x;
			projectiles.y = player.position.y;
			
			projectiles.direction = player.direction;

			projectiles.active = true;
		}

		if (projectiles.active) {
			if (projectiles.direction == Direction::Left){
				projectiles.x -= projectiles.velocity * dt;
			}

			else if (projectiles.direction == Direction::Right){
				projectiles.x += projectiles.velocity * dt;
			}

			else if (projectiles.direction == Direction::Up){
				projectiles.y -= projectiles.velocity * dt;
			}

			else if (projectiles.direction == Direction::Down){
				projectiles.y += projectiles.velocity * dt;
			}
		}


		hose.end_pos = player.position; // Have hose follow player

		// SPAWN OPPONENT
		spawnTimer += GetFrameTime();

		if (spawnTimer >= 1.0f){
			int randY = rand() % SCREEN_HEIGHT; // spawn random pos between 0 - 599;

			opponent.y = randY;
			spawn.push_back(opponent);

			spawnTimer = 0;
		}

	
		// UPDATE
		for (int i=0; i < spawn.size(); i++){
			spawn[i].x -= spawn[i].velocity * dt;
			spawn[i].y += spawn[i].velocity * dt;
		}


		BeginDrawing();
		ClearBackground(RAYWHITE);


		// DRAW
		DrawRectangleLines(lawn.x, lawn.y, lawn.width, lawn.height, GREEN); // lawn
		DrawRectangleLines(walls.x, walls.y, walls.width, walls.height, BLACK); // walls
		DrawRectangleLines(fence.x, fence.y, fence.width, fence.height, RED); // fence
		DrawLineBezier(hose.start_pos, hose.end_pos, hose.thickness, hose_color); // garden hose
		
		DrawCircleLines(projectiles.x, projectiles.y, projectiles.radius, BLACK); // projectiles

		DrawPoly(player.position, 4, 15, 45, BLACK); // player
		DrawPoly(roof.position, roof.sides, roof.size, roof.rotation, BLACK); // roof

		for (int i=0; i < spawn.size(); i++){	
			DrawCircleLines(spawn[i].x, spawn[i].y, spawn[i].radius, RED); // opponent	
		}

		EndDrawing();
	}
	
	CloseWindow();

	return 0;
}

// PLAYER MOVEMENT FUNCTIONS
void player_move_left(Player &player, float dt, SQUARE walls, Projectiles &projectiles){
	player.position.x -= player.velocity.x * dt;

	player.direction = Direction::Left;
	// player.position.x -= player.velocity.x * dt;
	

//	projectiles.left = true;
//	projectiles.right = false;
//	projectiles.up = false;
//	projectiles.down = false;


	if (CheckCollisionPointRec(player.position, Rectangle{float(walls.x), float(walls.y), float(walls.width)+8, float(walls.height)})) {
		player.position.x += player.velocity.x * dt;
	}

	if (player.position.x <= 235){
		player.position.x += player.velocity.x * dt;
	}
}

void player_move_right(Player &player, float dt, SQUARE walls, Projectiles &projectiles){
	player.position.x += player.velocity.x * dt;

	player.direction = Direction::Right;
	// player.position.x += player.velocity.x * dt;
	
//	projectiles.left = false;
//	projectiles.right = true;
//	projectiles.up = false;
//	projectiles.down = false;


	if (CheckCollisionPointRec(player.position, Rectangle{float(walls.x)-10, float(walls.y), float(walls.width), float(walls.height)})) {
		player.position.x -= player.velocity.x * dt;
	}

	if (player.position.x >= 515){
		player.position.x -= player.velocity.x * dt;
	}

}

void player_move_up(Player &player, float dt, SQUARE walls, Projectiles &projectiles){
	player.position.y -= player.velocity.y * dt;

	player.direction = Direction::Up;
	// player.position.y -= player.velocity.y * dt;

//	projectiles.left = false;
//	projectiles.right = false;
//	projectiles.up = true;
//	projectiles.down = false;


	if (CheckCollisionPointRec(player.position, Rectangle{float(walls.x), float(walls.y), float(walls.width), float(walls.height)+8})) {
		player.position.y += player.velocity.y * dt;
	}

	if (player.position.y <= 85){
		player.position.y += player.velocity.y * dt;
	}

}

void player_move_down(Player &player, float dt, SQUARE walls, Projectiles &projectiles){
	player.position.y += player.velocity.y * dt;

	player.direction = Direction::Down;
	// player.position.y += player.velocity.y * dt;

//	projectiles.left = false;
//	projectiles.right = false;
//	projectiles.up = false;
//	projectiles.down = true;


	if (CheckCollisionPointRec(player.position, Rectangle{float(walls.x), float(walls.y)-12, float(walls.width), float(walls.height)})) {
		player.position.y -= player.velocity.y * dt;
	}

	if (player.position.y >= 365){
		player.position.y -= player.velocity.y * dt;
	}
}
