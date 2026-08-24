# ifndef PLAYER_H_
# define PLAYER_H_

// DEFINE PLAYER
struct Player {
	Vector2 position;
	Vector2 velocity;
	float rotation;
};

// DEFINE PLAYER MOVEMENT FUNCTIONS
void player_move_left(Player &player, float dt);
void player_move_right(Player &player, float dt);

void player_move_up(Player &player, float dt);
void player_move_down(Player &player, float dt);

# endif
