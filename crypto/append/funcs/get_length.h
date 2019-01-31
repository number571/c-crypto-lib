#pragma once

#include <stddef.h>

#include "../types/char.h"
#include "../types/integer.h"

static inline size_t get_length (const uchar_t type, const void * from, const schar_t end) {
	if (type == 'c' || type == 'C') {
		schar_t *p = (schar_t *)from;
		while (*p != end)
			++p;
		return p - (schar_t *)from;

	} else if (type == 'i' || type == 'I') {
		INTEGER_TYPE *p = (INTEGER_TYPE *)from;
		while (*p != end)
			++p;
		return p - (INTEGER_TYPE *)from;
	}
}
