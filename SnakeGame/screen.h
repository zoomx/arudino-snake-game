#ifndef screen_h
#define screen_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

#include "sure32x16.h"
#include "types.h"

class screen_t
{
	public:
		static int width(void);
		static int height(void);

		void fade();
		void title(void);
		void clear(void);
		void centre(point_t* p);
		void randomPosition(point_t* p);
		void clearPoint(point_t* p);
		void drawPoint(point_t* p, uint8_t c);
		static direction_t randomDirection(void);
		static boolean hitTest(point_t* a, point_t* b);
	private:
		sure32x16_t _display;
};

extern screen_t screen;

#endif
