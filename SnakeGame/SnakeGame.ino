#include "game.h"

// Declare the frame rate for the game
#define FPS 10

//  Define the game
game_t game(FPS);

// Setup serial port
void setup()
{
	Serial.begin(9600);
}

// Continuall render the game
void loop()
{
	game.render();
}