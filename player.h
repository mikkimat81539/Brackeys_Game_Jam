# ifndef PLAYER_H_
# define PLAYER_H_

// DEFINE PLAYER
struct Player {
	Vector2 position;
	Vector2 velocity;
};

// DEFINE PLAYER MOVEMENT FUNCTIONS
void player_move_left(Player &player);
void player_move_right(Player &player);

void player_move_up(Player &player);
void player_move_down(Player &player);


# endif
