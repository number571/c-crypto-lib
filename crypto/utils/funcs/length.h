#pragma once

#include <stdint.h>

#include "../types/integer.h"

static inline size_t _length (const uint8_t type, const void * from, const int8_t end) {
	if (type == 'c' || type == 'C') {
		int8_t *p = (int8_t *)from;
		while (*p != end)
			++p;
		return p - (int8_t *)from;

	} else if (type == 'i' || type == 'I') {
		__INTEGER__ *p = (__INTEGER__ *)from;
		while (*p != end)
			++p;
		return p - (__INTEGER__ *)from;
	}
}
