# include <iostream>
# include <vector>
# include <cstdlib>
# include <ctime>

# include "raylib.h"
# include "constants.h"
# include "player.h"
# include "projectile.h"
# include "opponent.h"

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

	// PROJECTILES
	Projectile projectile;
	projectile.radius = 3;

	projectile.direction = Direction::Right; // INITIAL IS RIGHT

	projectile.velocity = {500, 500};
	projectile.active = false;

	// projectile storage
	vector<Projectile> magazine = {};

	// OPPONENTS
	Opponent opps;
	
	opps.position = {700, 270};
	
	opps.velocity = {250, 250};
	
	opps.radius = 10;
	
	vector<Color> oppsColor = {RED, GREEN, BLUE}; // vector of opponents

	srand(time(0)); // seed for randomness
	int randOpps = rand() % oppsColor.size(); // grab a random index from oppsList


	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){
		// DELTA TIME
		float dt = GetFrameTime();

		// set player direction when key is pressed
		if (IsKeyPressed(KEY_LEFT)){
			projectile.direction =  Direction::Left;	
		}

		else if (IsKeyPressed(KEY_RIGHT)){
			projectile.direction =  Direction::Right;
		}

		else if (IsKeyPressed(KEY_UP)){
			projectile.direction =  Direction::Up;
		}

		else if (IsKeyPressed(KEY_DOWN)){
			projectile.direction =  Direction::Down;
		}

		// set projectile movement when space bar is pressed
		if (IsKeyPressed(KEY_SPACE)){
			projectile.position.x = player.position.x - 10;
			projectile.position.y = player.position.y - 30;

			projectile.active = true;

			magazine.push_back(projectile);
		}

		// apply projectile movement from vector
		for (int i=0; i < magazine.size(); i++){
			if (magazine[i].direction == Direction::Left){
				magazine[i].position.x -= magazine[i].velocity.x * dt;
			}

			if (magazine[i].direction == Direction::Right){
				magazine[i].position.x += magazine[i].velocity.x * dt;
			}

			if (magazine[i].direction == Direction::Up){
				magazine[i].position.y -= magazine[i].velocity.y * dt;
			}

			if (magazine[i].direction == Direction::Down){
				magazine[i].position.y += magazine[i].velocity.y * dt;
			}

			if (magazine[i].position.x > SCREEN_WIDTH || magazine[i].position.x < 0 || magazine[i].position.y > SCREEN_HEIGHT || magazine[i].position.y < 0) {
				magazine.erase(magazine.begin());
			}

			if (CheckCollisionCircles(magazine[i].position, magazine[i].radius, opps.position, opps.radius)){
				// the opponent that is hit will disappear from the vector
				print(true);
			}
		}


		// DRAW
		BeginDrawing();	
		ClearBackground(RAYWHITE);		
	
		// draw projectile
		for (int i =0; i < magazine.size(); i++){
			DrawCircle(magazine[i].position.x, magazine[i].position.y, magazine[i].radius, BLUE);
		}	

		DrawRectangle(playerCenterX, playerCenterY, player.width, player.height, BLACK); // player

		DrawCircle(opps.position.x, opps.position.y, opps.radius, oppsColor[randOpps]); // opponents

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
