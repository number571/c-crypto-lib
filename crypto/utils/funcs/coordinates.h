#pragma once

#include <stdint.h>
#include <stddef.h>

#include "../macro/consts.h"
#include "../types/point.h"

static inline Point _coordinates (const uint8_t ch, uint8_t * const alpha, const size_t length) {
	Point coord = {-1, -1};

	for (uint8_t *p = alpha; *p != END_OF_STRING; ++p)
		if (*p == ch) {
			coord.x = (p - alpha) / length;
			coord.y = (p - alpha) % length;
			break;
		}

	return coord;
}
