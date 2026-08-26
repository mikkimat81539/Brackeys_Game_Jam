# ifndef PROJECTILE
# define PROJECTILE

struct Projectile{
	Vector2 position;
	float radius;
	Vector2 velocity;
	bool active;

	Direction direction;
};

# endif
