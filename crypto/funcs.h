#pragma once

#include "macro.h"
#include "types.h"

static inline size_t numlen (char * const from) {
	char *p = from;

	while (*p != END_OF_NUMBER) 
		++p;
    
	return p - from;
}

static inline Point get_coordinates (const char ch, char * const alpha, const unsigned char length) {
    Point coordinates = {-1, -1};

    for (char *p = alpha; *p != END_OF_STRING; ++p)
        if (*p == ch) {
            coordinates.x = (p - alpha) / length;
            coordinates.y = (p - alpha) % length;
            break;
        }

    return coordinates;
}
