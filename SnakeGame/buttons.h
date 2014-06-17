#ifndef button_h
#define buttons_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

#include "input.h"
#include "Button.h"

#define DEBOUNCE_MS		20

#define LEFT_BUTTON		2
#define RIGHT_BUTTON	3

class buttons_t : public input_t
{
	public:
		buttons_t();

		void read(void);
		boolean leftPressed(void);
		boolean rightPressed(void);
		
	private:
		Button _leftButton;
		Button _rightButton;
};

#endif
