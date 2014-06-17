#ifndef input_h
#define input_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

class input_t
{
	public:
		virtual void read(void);
		virtual boolean leftPressed(void);
		virtual boolean rightPressed(void);
};

#endif
