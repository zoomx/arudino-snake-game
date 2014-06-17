#ifndef button_h
#define buttons_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

#include "input.h"

#define LEFT_CHAR 'Z'
#define RIGHT_CHAR 'X'

#define BAUD 9600

class serial_t : public input_t
{
	public:
		serial_t();

		void read(void);
		boolean leftPressed(void);
		boolean rightPressed(void);
		
	private:
		int _key;
};

#endif
