# ifndef MECHANICS
# define MECHANICS

enum STATE {
	IDLE_RIGHT,
	IDLE_LEFT,
	RUN_RIGHT,
	RUN_LEFT,
	UP,
	DOWN
};

struct Player {
	Vector2 position; // position of the sprite
	Rectangle frameRec; // put the sprite in a rect
	Vector2 velocity;
};

# endif
