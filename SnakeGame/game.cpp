#include "game.h"

game_t::game_t(uint8_t fps)
{
	_fpsWait = 1000 / fps;

	srand(millis());
	//randomSeed(millis());
	// rand() % MAX_RANGE
	_gameOver = true;
}

// Start the game
void game_t::start(void)
{
	_screen.fade();
	_score = 0;
	_snake.reset();
	_gameOver = false;
	randomFruitPosition();
}

// Draw fruit in a random position not on the snake's tial
void game_t::randomFruitPosition(void)
{
	do
	{
		screen.randomPosition(_fruit.position());
	} 
	while (_snake.isPointInTail(_fruit.position()));
	_fruit.draw();
}

// Render a frame of the game
void game_t::render(void)
{

	if (_gameOver){
		_screen.title();
		_input.read();
		if (_input.leftPressed() || _input.rightPressed())
			start();
	}
	else
	{
		_snake.draw();

		if (screen.hitTest(_snake.position(), _fruit.position()))
		{
			_score++;
			_snake.increaseLength();
			randomFruitPosition();
		}

		if (_snake.hasHitTail())
		{
			_snake.death();
			_screen.fade();
			_gameOver = true;
			return;
		}

		_snake.clearTail();

		_input.read();

		if (!(_input.leftPressed() && _input.rightPressed()))
			if (_input.leftPressed())
			{
				_snake.turn(S_LEFT);
			}
			else if (_input.rightPressed())
			{
				_snake.turn(S_RIGHT);
			}

		_snake.updatePosition();
	}

	delay(_fpsWait);
}


