# ifndef OPPONENTS
# define OPPONENTS

struct Opponent {
	Vector2 position;
	Vector2 velocity;
	float radius;
	Color color;
	int SPAWN_RATE;
};

# endif
