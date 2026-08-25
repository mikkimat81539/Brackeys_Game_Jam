# ifndef PLAYER_H_
# define PLAYER_H_

enum class Direction
{
    Left,
    Right,
    Up,
    Down
};

struct Player {
	Vector2 position;
	Vector2 velocity;

	Direction direction = Direction::Right;
};

// CREATE PROJECTILES
struct Projectiles {
	int x;
	int y;
	float radius;
	float velocity;
	bool active;
	int projectile_num;

	Direction direction;
	
//	bool right;
//	bool left;
//	bool up;
//	bool down;
};

// DEFINE PLAYER MOVEMENT FUNCTIONS
void player_move_left(Player &player, float dt, SQUARE walls, Projectiles &projectiles);
void player_move_right(Player &player, float dt, SQUARE walls, Projectiles &projectiles);

void player_move_up(Player &player, float dt, SQUARE walls, Projectiles &projectiles);
void player_move_down(Player &player, float dt, SQUARE walls, Projectiles &projectiles);


# endif
