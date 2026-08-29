# include <iostream>
# include <vector>
# include <random>

# include "raylib.h"
# include "constants.h"
# include "mechanics.h"

using namespace std;

# define print(x) cout << x << endl;

int main() {
	// SCREEN
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Get Off My Lawn");
	
	// HOUSE
	Texture2D house = LoadTexture("assets/house.png");

	// FENCE
	Texture2D front_fence = LoadTexture("assets/front_fence.png");
	Texture2D back_fence = LoadTexture("assets/back_fence.png");

	// PLAYER

	// idle right
	Texture2D idle_right_img = LoadTexture("assets/idle_right.png");

	Player idle_right;
	idle_right.position = {110, 350}; // position of sprite
	idle_right.frameRec = {0, 0, 84, 92}; // crop spritesheet 
	idle_right.velocity = {200, 200};


	// idle left
	Texture2D idle_left_img = LoadTexture("assets/idle_left.png");

	Player idle_left;
	idle_left.position = {110, 350}; // position of sprite
	idle_left.frameRec = {0, 0, 84, 92}; // crop spritesheet 
	idle_left.velocity = {200, 200};

	// run right
	Texture2D run_right_img = LoadTexture("assets/run_right.png");

	Player run_right;
	run_right.position = idle_right.position; // position of sprite
	run_right.frameRec = {0, 0, 110, 110}; // crop spritesheet 
	run_right.velocity = {200, 200};
	

	// run left
	Texture2D run_left_img = LoadTexture("assets/run_left.png");

	Player run_left;
	run_left.position = idle_left.position; // position of sprite
	run_left.frameRec = {0, 0, 110, 110}; // crop spritesheet 
	run_left.velocity = {200, 200};


	// frame rate data
	int idleframeCount = 0; // number of frames in spritesheet
	int idleframeTimer = 0; // how fast computer runs each frame

	int runframeCount = 0; // number of frames in spritesheet
	int runframeTimer = 0; // how fast computer runs each frame


	// player state
	STATE player_state = IDLE_RIGHT;


	// PROJECTILE	
	Projectile projectile;
	projectile.radius = 5;

	projectile.active = false;

	// Store Projectile in vector
	vector<Projectile> magazine = {};

	// OPPONENTS
	Texture2D opponent_img = LoadTexture("assets/opps_left.png");

	Opponent opponent;
	opponent.position = {0, 0};
	opponent.frameRec = {0, 0, 64, 64};
	opponent.velocity = {100, 100};

	// OPPONENT STORAGE
	vector<Opponent> spawn = {};

	srand(time(0));
	float spawnTimer = 0; // spawn timer
	float difficultyTimer = 0.0; // difficulty timer

	float spawn_rate = 3.0;

	int opponentframeCount = 0;
	int opponentTimer = 0; // this timer is for the frames

	// HEALTH
	Texture2D health_img = LoadTexture("assets/health.png");

	Player health1;
	health1.position = {220, 130};
	health1.frameRec = {0, 0, 64, 64}; // crop spritesheet 

	Player health2;
	health2.position = {284, 130};
	health2.frameRec = {0, 0, 64, 64}; // crop spritesheet 

	Player health3;
	health3.position = {348, 130};
	health3.frameRec = {0, 0, 64, 64}; // crop spritesheet 

	vector<Player> health = {health1, health2, health3}; 

	// POINTS
	int pointCounter = 0;

	// FPS
	SetTargetFPS(FPS);

	// GAME LOOP
	while(!WindowShouldClose()){
		// MOUSE POSITION
		if (IsMouseButtonPressed(0)){
			cout << GetMousePosition().x << "," << GetMousePosition().y << endl;
		}

		float dt = GetFrameTime();

		// KEY INPUT
		if (IsKeyDown(KEY_RIGHT)) {

			if (player_state != RUN_RIGHT) {
				run_right.position = idle_right.position;
			}

			player_state = RUN_RIGHT;

			// FRAME RATE
			runframeTimer++;

			if (runframeTimer >= 6){
				runframeTimer = 0;
				runframeCount++; // iterate through frames

				if (runframeCount >= 34) {
					runframeCount = 0;
				}
				
				run_right.frameRec.x = runframeCount * run_right.frameRec.width;
				run_right.frameRec.y = runframeCount * run_right.frameRec.height;
			}

		}


		else if (IsKeyDown(KEY_LEFT)) {

			if (player_state != RUN_LEFT) {
				run_left.position = idle_left.position;
			}

			player_state = RUN_LEFT;

			// FRAME RATE
			runframeTimer++;

			if (runframeTimer >= 6){
				runframeTimer = 0;
				runframeCount++; // iterate through frames

				if (runframeCount >= 34) {
					runframeCount = 0;
				}
				
				run_left.frameRec.x = runframeCount * run_left.frameRec.width;
				run_left.frameRec.y = runframeCount * run_left.frameRec.height;
			}
		}

		
		else {
			// IDLE RIGHT
			if (player_state == RUN_RIGHT){
				idle_right.position = run_right.position;
				player_state = IDLE_RIGHT;
			}

			if (player_state == IDLE_RIGHT){

				// FRAME RATE
				idleframeTimer++;

				if (idleframeTimer >= 8){
					idleframeTimer = 0;
					idleframeCount++; // iterate through frames

					if (idleframeCount >= 28) {
						idleframeCount = 0;
					}
					
					idle_right.frameRec.x = idleframeCount * idle_right.frameRec.width;
					idle_right.frameRec.y = idleframeCount * idle_right.frameRec.height;
				}

			}

			// IDLE FRAME LEFT

			if (player_state == RUN_LEFT){
				idle_left.position = run_left.position;
				player_state = IDLE_LEFT;
			}

			if (player_state == IDLE_LEFT){

				idleframeTimer++;

				if (idleframeTimer >= 8){
					idleframeTimer = 0;
					idleframeCount++; // iterate through frames

					if (idleframeCount >= 28) {
						idleframeCount = 0;
					}
					
					idle_left.frameRec.x = idleframeCount * idle_left.frameRec.width;
					idle_left.frameRec.y = idleframeCount * idle_left.frameRec.height;
				}

			}
		}

		// MOVING UP AND DOWN LEFT STATE
		if (IsKeyDown(KEY_UP)){
			idle_right.position.y -= idle_right.velocity.y * dt;

			idle_left.position.y = idle_right.position.y; // make sure player stays in same position regardless of direction
			run_right.position.y = idle_right.position.y;
			run_left.position.y = idle_right.position.y;
		}

		if (IsKeyDown(KEY_DOWN)){
			idle_right.position.y += idle_right.velocity.y * dt;

			idle_left.position.y = idle_right.position.y;
			run_right.position.y = idle_right.position.y;
			run_left.position.y = idle_right.position.y;
		}


		if (IsKeyDown(KEY_RIGHT)){
			run_right.position.x += run_right.velocity.x * dt;

			idle_right.position = run_right.position;
			idle_left.position = run_right.position;
			run_left.position = run_right.position;

		}

		if (IsKeyDown(KEY_LEFT)){
			run_left.position.x -= run_left.velocity.x * dt;


			idle_left.position = run_left.position;
			idle_right.position = run_left.position;
			run_right.position = run_left.position;
		}


		// BOUNDARIES
		if (idle_right.position.y <= 270 || idle_left.position.y <= 270) {
			idle_right.position.y = 270;
			idle_left.position.y = 270;


		}

		if (idle_right.position.y >= 460 || idle_left.position.y >= 460) {
			idle_right.position.y = 460;
			idle_left.position.y = 460;

		}

		if (run_right.position.x <= 100 || run_left.position.x <= 100){
			run_right.position.x = 100;
			run_left.position.x = 100;
		}

		if (run_right.position.x >= SCREEN_WIDTH - run_right.frameRec.width){
			run_right.position.x = SCREEN_WIDTH - run_right.frameRec.width;
			run_left.position.x = SCREEN_WIDTH - run_left.frameRec.width;
		}


		if (run_left.position.x <= 100){
			run_right.position.x = 100;
			run_left.position.x = 100;
		}


		// SHOOTING PROJECTILE KEY INPUT
		if (IsKeyPressed(KEY_SPACE)){
			if (player_state == IDLE_RIGHT || player_state == RUN_RIGHT){
				projectile.position.x = idle_right.position.x + 130; // Reset back to original position
				projectile.position.y = idle_right.position.y + 60;

				projectile.velocity.x = 250;
				projectile.active = true;

				magazine.push_back(projectile);
			}


			else if (player_state == IDLE_LEFT || player_state == RUN_LEFT){
				projectile.position.x = idle_left.position.x - 10; // Reset back to original position
				projectile.position.y = idle_left.position.y + 60;

				projectile.velocity.x = -250;
				projectile.active = true;

				magazine.push_back(projectile);
			}

		}

		// Projectile Movement
		for (int i = 0; i < magazine.size(); i++){
			if (magazine[i].active) {
				magazine[i].position.x += magazine[i].velocity.x * dt;

			}

			if (magazine[i].position.x > SCREEN_WIDTH || magazine[i].position.x < 0 || magazine[i].position.y > SCREEN_HEIGHT || magazine[i].position.y < 0){
				magazine.erase(magazine.begin());
				i--;
			}
		}

		// SPAWN OPPONENT TIME
		spawnTimer += dt; // how fast opponents spawn
		difficultyTimer += dt; // every nth seconds more opponents should spawn

		if (difficultyTimer >= 10.0){
			spawn_rate -= 0.3;
			print(spawn_rate)
			difficultyTimer = 0.0;
			spawnTimer = 0.0f;
		}

		if (spawn_rate <= 0.3){
			spawn_rate += 0.3;
			print("true")
		}


		// ADD OPPONENT TO VECTOR
		if (spawnTimer >= spawn_rate){
			opponent.position.x = SCREEN_WIDTH;

			float min = 290.0;
			float max = 410.0;

			random_device rd;
			mt19937 gen(rd());
			uniform_real_distribution<> randY(min, max);

			opponent.position.y = randY(gen);

			spawn.push_back(opponent);

			spawnTimer = 0.0f;
		}


		// OPPONENT FRAME RATE
		opponentTimer++;

		if (opponentTimer >= 8){
			opponentTimer = 0;
			opponentframeCount++; // iterate through frames

			if (opponentframeCount >= 15) {
				opponentframeCount = 0;
			}
			
			// opponent.frameRec.x = opponentframeCount * opponent.frameRec.width;
			// opponent.frameRec.y = opponentframeCount * opponent.frameRec.height;
		}

		// UPDATE OPPONENT
		for (int i=0; i < spawn.size(); i++){
			spawn[i].position.x -= spawn[i].velocity.x * dt;
	
			spawn[i].frameRec.x = opponentframeCount * spawn[i].frameRec.width;
			spawn[i].frameRec.y = opponentframeCount * spawn[i].frameRec.height;
		}

		// COLLISION BETWEEN PROJECTILE AND OPPONENTS
		for (int i=0; i < magazine.size(); i++){
			for (int j = 0; j < spawn.size(); j++){
				Rectangle opponentRect = {
					spawn[j].position.x,
					spawn[j].position.y,
					spawn[j].frameRec.width,
					spawn[j].frameRec.height
				};
	
				if (CheckCollisionCircleRec(magazine[i].position, magazine[i].radius, opponentRect)){
					pointCounter += 10;
					magazine.erase(magazine.begin() + i);
					spawn.erase(spawn.begin() + j);
					j--; // decrement j after erasing
					// continue; // Don't access spawn[j] after erasing
					break;
				}
			}
			
		}

		// COLLISION BETWEEN PLAYER AND OPPONENTS
//		for (int i = 0; i < spawn.size(); i++){
//			Rectangle opponentRect = {
//				spawn[i].position.x,
//				spawn[i].position.y,
//				spawn[i].frameRec.width,
//				spawn[i].frameRec.height
//			};
//
//			Rectangle playerRect = {
//				idle_right.position.x,
//				idle_right.position.y,
//				idle_right.frameRec.width,
//				idle_right.frameRec.height
//			};
//
//			if (CheckCollisionRecs(playerRect, opponentRect)){
//				counter++;
//
//				print(counter)
//			}
//		}

		// COLLISION BETWEEN HOUSE AND OPPONENTS
		for (int i = 0; i < spawn.size(); i++){
			for (int j=0; j < health.size(); j++){
				Rectangle opponentRect = {
					spawn[i].position.x,
					spawn[i].position.y,
					spawn[i].frameRec.width,
					spawn[i].frameRec.height
				};

				Rectangle houseRect = {
					0.0,
					0.0,
					float(house.width),
					float(house.height)
				};

				if (CheckCollisionRecs(opponentRect, houseRect)){
					spawn.erase(spawn.begin() + i);
					health.pop_back();
				}

				if (health.size() == 0){
					exit(0);
				}
				
			}
		}


		// DRAW
		BeginDrawing();
		ClearBackground(RAYWHITE);


		// PLAYER
		if (player_state == IDLE_RIGHT){
			DrawTextureRec(idle_right_img, idle_right.frameRec, idle_right.position, WHITE);
		}

		if (player_state == IDLE_LEFT){
			DrawTextureRec(idle_left_img, idle_left.frameRec, idle_left.position, WHITE);
		}

		if (player_state == RUN_RIGHT){
			DrawTextureRec(run_right_img, run_right.frameRec, run_right.position, WHITE);
		}

		if (player_state == RUN_LEFT){
			DrawTextureRec(run_left_img, run_left.frameRec, run_left.position, WHITE);
		}

		// PROJECTILE
		for (int i=0; i < magazine.size(); i++){
			DrawCircle(magazine[i].position.x, magazine[i].position.y, magazine[i].radius, BLUE);
		}

		// OPPONENT
		for (int i=0; i < spawn.size(); i++){	
			DrawTextureRec(opponent_img, spawn[i].frameRec, spawn[i].position, WHITE);

		}
	
		// PROPERTY
		DrawTexture(house, 0, 0, WHITE);
		DrawTexture(front_fence, 0, 470, WHITE);	
		DrawTexture(back_fence, 0, 200, WHITE);	
	

		// TEXT
		DrawText("GET OFF MY LAWN", 190, 10, 50, BLACK);
		DrawText("use arrow keys to move around", 250, 70, 20, RED);
		DrawText("use SPACE BAR to shoot", 290, 100, 20, RED);
		DrawText("HEALTH:", 135, 150, 20, BLACK);

		// HEALTH
		for (int i=0; i < health.size(); i++){
			DrawTextureRec(health_img, health[i].frameRec, health[i].position, WHITE);
		}

		// POINTS
		DrawText("POINTS:", 545, 150, 20, BLACK);
		DrawText(TextFormat("%d", pointCounter), 640, 150, 20, BLACK);

		EndDrawing();
	}
	
	CloseWindow();

	return 0;
}
