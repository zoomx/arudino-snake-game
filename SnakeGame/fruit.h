#ifndef fruit_h
#define fruit_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

#include "screen.h"

class fruit_t
{
	public:
		void draw(void);
		point_t* position(void);
	private:
		point_t _position;
};

#endif
