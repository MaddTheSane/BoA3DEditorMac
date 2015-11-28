#include <Carbon/Carbon.h>
#include <math.h>
#include "global.h"
#include "EdGlobal.h"

short get_ran (short times,short  min,short  max)
{
	unsigned int store;
	short i, to_ret = 0;
	
	for (i = 1; i < times + 1; i++) {
		store = random() & 0x7fff;
		to_ret = to_ret + min + ((store * (max - min + 1)) / 0x7fff);
		}
	return to_ret;
}

short s_pow(short x,short y)
{
	return (short) pow((double) x, (double) y);
}

short dist(location p1,location p2)
{
	return (short) sqrt((double)((p1.x - p2.x) * (p1.x - p2.x) +
							(p1.y - p2.y) * (p1.y - p2.y)));
}
