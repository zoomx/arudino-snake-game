#include "screen.h"

// Retrieve the width of the screen in pixels
int screen_t::width(void)
{
	return SCREEN_WIDTH;
}

// Retreive the height of the screen in pixels
int screen_t::height(void)
{
	return SCREEN_HEIGHT;
}

// Find the centre poision of the screen
void screen_t::centre(point_t* p)
{
	p->x = SCREEN_WIDTH / 2;
	p->y = SCREEN_HEIGHT / 2;
}

// Generate a random person (for fruit)
void screen_t::randomPosition(point_t* p)
{
	p->x = random(SCREEN_WIDTH);
	p->y = random(SCREEN_HEIGHT);
}

// Generate a random direction
direction_t screen_t::randomDirection(void)
{
	switch (random(4)){
		case 0:
			return S_UP;
			break;
		case 1: 
			return S_DOWN;
			break;
		case 2: 
			return S_LEFT;
			break;
		case 3:
			return S_RIGHT;
			break;
	}
}

boolean screen_t::hitTest(point_t* a, point_t* b)
{
	return (a->x == b->x) && (a->y == b->y);
}

// The following methods exposed methods on our display object

// Clear a point
void screen_t::clearPoint(point_t* p)
{
	_display.clearPoint(p);
}

// Draw a point
void screen_t::drawPoint(point_t* p, uint8_t c)
{
	_display.drawPoint(p, c);
}

// Clear a point
void screen_t::clear()
{
	_display.clear();
}

// Render title screen frame
void screen_t::title(void)
{
	_display.title();
}

// Render a fade tranisition
void screen_t::fade(void)
{
	_display.fade();
}

// Instansiate the screen class so that it's globally accessible
screen_t screen;