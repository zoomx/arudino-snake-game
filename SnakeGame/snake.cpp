#include "snake.h"

// Reset our snake
void snake_t::reset(void)
{
	_maxLength = START_LENGTH;
	_length = 1;
	screen.centre(&_position);
	_direction = screen.randomDirection();
}

// Draw the head of the snake
void snake_t::draw(void)
{
	screen.drawPoint(&_position, RED);
}

// Update the position based on direction and position
void snake_t::updatePosition()
{
	switch(_direction)
	{
		case S_LEFT:
			if (_position.x > 0)
				_position.x--;
			else
				_position.x = SCREEN_WIDTH - 1;
			break; 
		case S_RIGHT:
			if (_position.x < SCREEN_WIDTH - 1)
				_position.x++;
			else
				_position.x = 0;
			break;
	   case S_UP:
			if (_position.y > 0)
				_position.y--;
			else
				_position.y = SCREEN_HEIGHT - 1;
			break;
		case S_DOWN:
			if (_position.y < SCREEN_HEIGHT - 1)
				_position.y++;
			else
				_position.y = 0;
			break;
	}
}

// Is the input point in the tail?
boolean snake_t::isPointInTail(point_t* p)
{
	for (uint8_t t = 0; t < _length; t++)
		if (screen.hitTest(&_tail[t], p))
			return true;

	return false;
}

// Expose the snake's position
point_t* snake_t::position(void)
{
	return &_position;
}

// Has the head hit the tail?
boolean snake_t::hasHitTail(void)
{
	return isPointInTail(&_position);
}

// Clear a piece of the tail
void snake_t::clearTail(void)
{
	for (uint8_t t = _length; t > 0; t--)
		_tail[t] = _tail[t-1];

	_tail[0] = _position;

	if (_length <= _maxLength)
		_length++;
	else
		screen.clearPoint(&_tail[_length - 1]);
}

// Increase snake length when he's eaten a fruit
void snake_t::increaseLength(void)
{
	_maxLength += LENGTH_INCREMENT;
}

// Turn the snake based on current direction
void snake_t::turn(direction_t dir)
{
	if (dir == S_LEFT)
	{
		if(_direction == S_LEFT)
			_direction = S_DOWN;
		else if(_direction == S_DOWN)
			_direction = S_RIGHT;
		else if(_direction == S_RIGHT)
			_direction = S_UP;
		else if(_direction == S_UP)
			_direction = S_LEFT;
		}
	else if(dir == S_RIGHT)
	{
		if(_direction == S_LEFT)
			_direction = S_UP;
		else if(_direction == S_DOWN)
			_direction = S_LEFT;
		else if(_direction == S_RIGHT)
			_direction = S_DOWN;
		else if(_direction == S_UP)
			_direction = S_RIGHT;
	}
}

// Animate a detah sequence of our poor snake
void snake_t::death(void)
{
	int wait = DEATH_TIME /_length;
	for (uint8_t t = _length - 1; t > 0; t--)
	{
		screen.clearPoint(&_tail[t]);
		delay(wait);
	}
	screen.clearPoint(&_position);
}