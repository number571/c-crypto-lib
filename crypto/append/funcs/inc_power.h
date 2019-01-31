#pragma once

#include "../types/char.h"

static inline int inc_power(int x, schar_t y) {
	int mul = 1;
	while (y-- != 0)
		mul *= x;
	return mul;
}
