#ifndef display_h
#define display_h

#include "types.h"

class display_t
{
	public:
		virtual void fade(void);
		virtual void title(void);
		virtual void clearPoint(point_t* p);
		virtual void drawPoint(point_t* p, uint8_t c);
		virtual void clear(void);
};

#endif
