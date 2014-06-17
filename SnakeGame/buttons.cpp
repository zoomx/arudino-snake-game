#include "buttons.h"

// http://arduinoetcetera.blogspot.co.uk/2011/01/classes-within-classes-initialiser.html
// Used of inialiser list to construct our display
buttons_t::buttons_t() : _leftButton(LEFT_BUTTON, true, true, DEBOUNCE_MS), _rightButton(RIGHT_BUTTON, true, true, DEBOUNCE_MS)
{

}

// Read the state of both buttons
void buttons_t::read(void)
{
	_leftButton.read();
	_rightButton.read();
}

// Has the left button been pressed?
boolean buttons_t::leftPressed(void)
{
	return _leftButton.isPressed();
}

// Has the right button been pressed?
boolean buttons_t::rightPressed(void)
{
	return _rightButton.isPressed();
}



