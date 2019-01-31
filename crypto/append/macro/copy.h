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

#define COPY_STR(to, from) COPY(to, char, from, END_OF_STRING)
#define COPY_NUM(to, from) COPY(to, INTEGER_TYPE, from, END_OF_NUMBER)
