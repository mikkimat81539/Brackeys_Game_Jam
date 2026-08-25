# ifndef PLAYER
# define PLAYER

// DEFINE PLAYER
struct Player {
	float x;
	float y;
	float width;
	float height;
	Vector2 velocity;
};

// PLAYER MOVEMENT FUNCTIONS
void player_move_left(Player &player, float dt){
	player.x -= player.velocity.x * dt;
}

void player_move_right(Player &player, float dt){
	player.x += player.velocity.x * dt;
}

void player_move_up(Player &player, float dt){
	player.y -= player.velocity.y * dt;
}

void player_move_down(Player &player, float dt){
	player.y += player.velocity.y * dt;
}


# endif
