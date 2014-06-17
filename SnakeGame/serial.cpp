#include "serial.h"

// Constructor
serial_t::serial_t()
{
	
}

// Read data from serial connection
void serial_t::read(void)
{
	if (Serial.available() > 0)
	{
		_key = Serial.read();
		Serial.write(_key);
		//while (Serial.read() != -1 );
	}
	else
		_key = 0;
}

// Check for both lowercase and uppercase
boolean serial_t::leftPressed(void)
{
	return (_key == LEFT_CHAR) || (_key == LEFT_CHAR + 32);
}

// Check for both lowercase and uppercase
boolean serial_t::rightPressed(void)
{
	return (_key == RIGHT_CHAR) || (_key == RIGHT_CHAR + 32);
}



