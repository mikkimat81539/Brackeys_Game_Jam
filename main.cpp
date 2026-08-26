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
	Opponent opps1;
	Opponent opps2;
	Opponent opps3;

	opps1.position = {100, 100};
	opps2.position = {100, 100};
	opps3.position = {100, 100};

	opps1.velocity = {250, 250};
	opps2.velocity = {250, 250};
	opps3.velocity = {250, 250};

	opps1.radius = 20;
	opps2.radius = 20;
	opps3.radius = 20;

	opps1.color = RED;
	opps2.color = GREEN;
	opps3.color = BLUE;

	vector<Opponent> oppsList= {opps1, opps2, opps3}; // vector of opponents

	srand(time(0)); // seed for randomness
	int randOpps = rand() % oppsList.size(); // grab a random index from oppsList
	int randOpps1 = rand() % oppsList.size(); // grab a random index from oppsList
	int randOpps2 = rand() % oppsList.size(); // grab a random index from oppsList


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
		}

		// DRAW
		BeginDrawing();	
		ClearBackground(RAYWHITE);		
	
		// draw projectile
		for (int i =0; i < magazine.size(); i++){
			DrawCircle(magazine[i].position.x, magazine[i].position.y, magazine[i].radius, BLUE);
		}	

		DrawRectangle(playerCenterX, playerCenterY, player.width, player.height, BLACK); // player

		DrawCircle(oppsList[randOpps].position.x, oppsList[randOpps].position.y, oppsList[randOpps].radius, oppsList[randOpps].color); // opponents

		DrawCircle(oppsList[randOpps1].position.x + 30, oppsList[randOpps1].position.y + 50, oppsList[randOpps1].radius, oppsList[randOpps1].color); // opponents

	
		DrawCircle(oppsList[randOpps2].position.x + 50, oppsList[randOpps2].position.y + 90, oppsList[randOpps2].radius, oppsList[randOpps2].color); // opponents


		EndDrawing();
	}

	CloseWindow();

	return 0;
}
