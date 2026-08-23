# ifndef PLAYER_H_
# define PLAYER_H_

struct Player {
	Vector2 position;
	Vector2 velocity;
};

void player_movement(Player &player);

# endif
