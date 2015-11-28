//
//  EdGlobal.h
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/27/15.
//
//

#ifndef EdGlobal_h
#define EdGlobal_h

#include <Carbon/Carbon.h>
#include <algorithm>
#include "global.h"

short get_ran (short times,short  min,short  max);
short s_pow(short x,short y);
short dist(location p1,location p2);

static inline short max(short a,short b)
{
	return std::max(a,b);
}

static inline short min(short a,short b)
{
	return std::min(a,b);
}

static inline short minmax(short min,short max,short k)
{
	if (k < min)
		return min;
	if (k > max)
		return max;
	return k;
}

static inline bool same_point(location l1,location l2)
{
	return((l1.x == l2.x) && (l1.y == l2.y));
}

#endif /* EdGlobal_h */
