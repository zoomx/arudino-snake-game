#ifndef sure32x16_h
#define sure32x16_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

#include "types.h"
#include "display.h"

/*
 Note: the display drivers has to be included in the same folder as the project 
 as the arduino id doesn't won't includes imports libraries within < > 

 Library can be found here:
 https://code.google.com/p/ht1632c/
 */
#include "ht1632c.h"

class sure32x16_t : public display_t
{
	public:
		sure32x16_t();

		void fade(void);
		void title(void);
		void clearPoint(point_t* p);
		void drawPoint(point_t* p, uint8_t c);
		void clear(void);

	private:
		ht1632c _matrix;
		void update();
};

#endif
