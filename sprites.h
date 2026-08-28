# ifndef SPRITES
# define SPRITES

enum STATE {
	IDLE, // this is idle right just do not feel like changing whole thing
	IDLE_LEFT,
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
