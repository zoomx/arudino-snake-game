#include "sure32x16.h"

// Define pins for display
#define PIN_DATA 7
#define PIN_WR   6
#define PIN_CLK  5
#define PIN_CS   4
#define DISPLAYS 1

#define FADE_TIME 1000

// http://arduinoetcetera.blogspot.co.uk/2011/01/classes-within-classes-initialiser.html
// Used of inialiser list to construct our display
sure32x16_t::sure32x16_t() : _matrix(&PORTD, PIN_DATA, PIN_WR, PIN_CLK, PIN_CS, GEOM_32x16, DISPLAYS)
{

}

// A routie for clearing the screen
void sure32x16_t::fade(void)
{
	int wait = FADE_TIME / (SCREEN_HEIGHT*2);
	for (uint8_t y = 0; y < SCREEN_HEIGHT; y++)
	{
		_matrix.line(0, y, SCREEN_WIDTH - 1, y, ORANGE);
		update();
		delay(wait);
	}
	for (uint8_t y = 0; y < SCREEN_HEIGHT; y++)
	{
		_matrix.line(0, y, SCREEN_WIDTH - 1, y, BLACK);
		update();
		delay(wait);
	}
}

// Display a title screen animation or whatever
void sure32x16_t::title(void)
{

	static uint8_t p;
	uint8_t c;

	if (p == 0)
		c = RED;
	else if (p == 1)
		c = ORANGE;
	else
		c = GREEN;

	clear();

	_matrix.putchar(1, 3, 'S', c);
	_matrix.putchar(7,  3, 'n', c);
	_matrix.putchar(13, 3, 'a', c);
	_matrix.putchar(19, 3, 'k', c);
	_matrix.putchar(26, 3, 'e', c);

	update();

	p++;
	if (p == 3)
		p = 0;
}

// Clear a point on screen
void sure32x16_t::clearPoint(point_t* p)
{
	_matrix.plot(p->x, p->y, BLACK);
	update();
}

// Draw a point on screen
void sure32x16_t::drawPoint(point_t* p, uint8_t c)
{
	_matrix.plot(p->x, p->y, c);
	update();
}

// Clear screen
void sure32x16_t::clear(void)
{
	_matrix.clear();
}

// Send screen buffer to screen
void sure32x16_t::update(void)
{
	_matrix.sendframe();
}

