#ifndef types_h
#define types_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

// Direcction enum
enum direction_t
{
	S_UP,
	S_DOWN,
	S_LEFT,
	S_RIGHT
};

// Sructure for holding point on screen
struct point_t
{
	uint8_t x;
	uint8_t y;
};

// Global screen width
#define SCREEN_WIDTH 32

// Globacl screen height
#define SCREEN_HEIGHT 16

// Snake start length
#define START_LENGTH 4

// Start increment after eating a fruit
#define LENGTH_INCREMENT 4

// Number of MS for the death animation to take
#define DEATH_TIME 500

// Serial input
#define SERIAL_INPUT 1

// Button input
//#define BUTTON_INPUT 1

#endif