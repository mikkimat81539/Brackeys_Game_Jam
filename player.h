# ifndef PLAYER
# define PLAYER

// PLAYER DIRECTION
enum Direction {
	Left,
	Right,
	Up,
	Down
};

// DEFINE PLAYER
struct Player {
	Vector2 position;
	float width;
	float height;
	Vector2 velocity;

	// Direction direction = Direction::Right;
};


// PLAYER MOVEMENT FUNCTIONS
void player_move_left(Player &player, float dt){
	player.position.x -= player.velocity.x * dt;
}

void player_move_right(Player &player, float dt){
	player.position.x += player.velocity.x * dt;
}

void player_move_up(Player &player, float dt){
	player.position.y -= player.velocity.y * dt;
}

void player_move_down(Player &player, float dt){
	player.position.y += player.velocity.y * dt;
}


# endif
