#pragma once

#include "copy.h"

#define SET_CHAR(to, Type, from, endfrom, endto) \
	({ \
		Type *p = from; \
		while (*p != endfrom) { \
			++p; \
		} \
		to[p - from] = endto; \
	})

#define SET_MESSAGE(Type, name, mem, string, end) \
		Type name[mem]; \
		COPY(name, char, string, END_OF_STRING); \
		SET_CHAR(name, char, string, END_OF_STRING, end)
