#include "fruit.h"

// Draw the fruit
void fruit_t::draw(void){
	screen.drawPoint(&_position, GREEN);
}

// Return pointer to it's position
point_t* fruit_t::position(void){
	return &_position;
}

