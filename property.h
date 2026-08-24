# ifndef PROPERTY
# define PROPERTY

// Define Property
struct SQUARE {
	int x;
	int y;
	int width;
	int height;
};

struct ROOF {
	Vector2 position;
	int sides;
	int size;
	float rotation;
};

struct HOSE {
	Vector2 start_pos;
	Vector2 end_pos;
	float thickness;
};
# endif
