#ifndef snake_h
#define snake_h

#include "screen.h"

class snake_t
{
	public:
		void reset(void);
		void draw(void);
		void turn(direction_t d);
		void updatePosition(void);
		void increaseLength(void);
		void clearTail(void);
		void death(void);
		boolean hasHitTail();
		boolean isPointInTail(point_t* p);

		point_t* position(void);
	private:
		int _length;
		int _maxLength;
		point_t _tail[SCREEN_WIDTH * SCREEN_HEIGHT];
		direction_t _direction;
		point_t _position;
};

#endif
