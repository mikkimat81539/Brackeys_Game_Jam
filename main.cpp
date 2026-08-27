# include <iostream>
# include <vector>
# include <cstdlib>
# include <ctime>
# include <random>

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
	
	// opps.position = {0, 0};
	
	opps.velocity = {250, 250};
	
	opps.radius = 10;
	
	vector<Color> oppsColor = {RED, GREEN, BLUE}; // vector of colors

	opps.SPAWN_RATE = 10;

	srand(time(0)); // seed for randomness
	// int randOpps = rand() % oppsColor.size(); // grab a random index from oppsList

	vector<Opponent> oppsList = {};

	float spawnTimer = 0; // spawn timer

	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){
		// DELTA TIME
		float dt = GetFrameTime();

		// GET MOUSE POS
		if (IsMouseButtonPressed(0)){
			cout << GetMousePosition().x << "," << GetMousePosition().y << endl;
		}

		// Spawn Opponents
		spawnTimer += GetFrameTime();

		if (spawnTimer >= 1.0f){
			opps.position.x = SCREEN_WIDTH + 10;
			
			// set random range
			float min = 205.0;
			float max = 330.0;

			random_device rd;
			mt19937 gen(rd());
			uniform_real_distribution<> randY(min, max);

			opps.position.y = randY(gen);

			int randOpps = rand() % oppsColor.size(); // grab a random index from oppsList

			opps.color = oppsColor[randOpps];

			oppsList.push_back(opps);

			spawnTimer = 0.0f;
		}			


		// Update opponents
		for (int i = 0; i < oppsList.size(); i++){
			oppsList[i].position.x -= opps.velocity.x * dt;
		}


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

		// COLLISION BETWEEN PROJECTILE AND OPPONENTS
		for (int i=0; i < magazine.size(); i++){
			for (int j = 0; j < oppsList.size(); j++){
				if (CheckCollisionCircles(magazine[i].position, magazine[i].radius, oppsList[j].position, oppsList[j].radius)){
						oppsList.erase(oppsList.begin() + j);
						j--; // decrement j after erasing
						continue; // Don't access oppsList[j] after erasing
				}
			}
			
		}

		// COLLISION BETWEEN PLAYER AND OPPONENTS
		for (int i = 0; i < oppsList.size(); i++){
			if(CheckCollisionCircleRec(oppsList[i].position, oppsList[i].radius, Rectangle{playerCenterX, playerCenterY, player.width, player.height})){
				exit(0);
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

		for (int i=0; i < oppsList.size(); i++){
			DrawCircle(oppsList[i].position.x, oppsList[i].position.y, oppsList[i].radius, oppsList[i].color); // opponents

		}

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
