# ifndef SPRITES
# define SPRITES

enum STATE {
	IDLE,
	RIGHT,
	LEFT,
	UP,
	DOWN,
	SHOT
};

struct Sprite {
	Vector2 position;
	Rectangle frameRec;
	bool active;
	Vector2 velocity;
};

# endif 
