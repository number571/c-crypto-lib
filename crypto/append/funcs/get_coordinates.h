#pragma once

#include <stddef.h>

#include "../macro/consts.h"
#include "../types/char.h"
#include "../types/point.h"

static inline Point get_coordinates (const uchar_t ch, uchar_t * const alpha, const size_t length) {
	Point coordinates = {-1, -1};

	for (uchar_t *p = alpha; *p != END_OF_STRING; ++p)
		if (*p == ch) {
			coordinates.x = (p - alpha) / length;
			coordinates.y = (p - alpha) % length;
			break;
		}

	return coordinates;
}
