#ifndef game_h
#define game_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

#include "screen.h"
#include "snake.h"
#include "fruit.h"

#if defined(SERIAL_INPUT)
	#include "serial.h"
#endif
#if defined(BUTTON_INPUT)
	#include "buttons.h"
#endif

class game_t
{
	public:
		game_t(uint8_t fps);

		void start(void);
		void render(void);

	private:
		void randomFruitPosition(void);
		
		int _fpsWait;

		boolean _gameOver;

		screen_t _screen;
		snake_t _snake;
		fruit_t _fruit;
		uint8_t _score;

#if defined(SERIAL_INPUT)
		serial_t _input;
#elif defined(BUTTON_INPUT)
		buttons_t _input;
#endif
		
};

#endif
