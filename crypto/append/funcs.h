#pragma once

#include <stddef.h>

#include "macro.h"
#include "types.h"

static inline size_t get_length (const char type, const void * from, const char end) {
	if (type == 'c') {
		char *p = (char *)from;
		while (*p != end)
			++p;
		return p - (char *)from;

	} else if (type == 's') {
		short *p = (short *)from;
		while (*p != end)
			++p;
		return p - (short *)from;
	}
}

static inline Point get_coordinates (const char ch, char * const alpha, const size_t length) {
	Point coordinates = {-1, -1};

	for (char *p = alpha; *p != END_OF_STRING; ++p)
		if (*p == ch) {
			coordinates.x = (p - alpha) / length;
			coordinates.y = (p - alpha) % length;
			break;
		}

	return coordinates;
}
