#pragma once 

#include "consts.h"
#include "../types/integer.h"

#define COPY(to, Type, from, end) \
	({ \
		Type *p = from; \
		while (*p != end) { \
			to[p - from] = *p; \
			++p; \
		} \
		to[p - from] = end; \
	})
