#pragma once

#include <stdio.h>
#include <stdint.h>

#include "consts.h"
#include "../types/byte.h"

// PRINT BYTES
#define PRINT_BYTE(from) \
	({ \
		Byte _var_ = {.byte = from}; \
		printf("%hhu%hhu%hhu%hhu%hhu%hhu%hhu%hhu ", \
			_var_.bit._7, _var_.bit._6, _var_.bit._5, _var_.bit._4, \
			_var_.bit._3, _var_.bit._2, _var_.bit._1, _var_.bit._0); \
	})
#define PRINTLN_BYTE(from) ({ PRINT_BYTE(from); putchar('\n'); })

#define PRINT_BYTES(from) \
	({ \
		for (int8_t *p = from; *p != END_OF_NUMBER; ++p) { \
			PRINT_BYTE(*p); \
		} \
	})
#define PRINTLN_BYTES(from) ({ PRINT_BYTES(from); putchar('\n'); })

// PRINT CHARS
#define PRINT_CHARS_WHILE(Type, from, end) \
	({ \
		for (Type *p = from; *p != end; ++p) \
			putchar(*p); \
	})
#define PRINTLN_CHARS_WHILE(Type, from, end) ({ PRINT_CHARS_WHILE(Type, from, end); putchar('\n'); })

#define PRINT_CHARS_FOR(from, length) \
	({ \
		for (size_t i = 0; i < length; ++i) \
			putchar(from[i]); \
	})
#define PRINTLN_CHARS_FOR(from, length) ({ PRINT_CHARS_FOR(from, length); putchar('\n'); })

#define PRINT_CHARS(Type, from) PRINT_CHARS_WHILE(Type, from, END_OF_STRING)
#define PRINTLN_CHARS(Type, from) ({ PRINT_CHARS(Type, from); putchar('\n'); })

// PRINT NUMS
#define PRINT_NUMS_WHILE(Type, from, end) \
	({ \
		for (Type *p = from; *p != end; ++p) \
			printf("%d ", *p); \
	})
#define PRINTLN_NUMS_WHILE(Type, from, end)  ({ PRINT_NUMS_WHILE(Type, from, end); putchar('\n'); })

#define PRINT_NUMS_FOR(from, length) \
	({ \
		for (size_t i = 0; i < length; ++i) \
			printf("%d ", from[i]); \
	})
#define PRINTLN_NUMS_FOR(from, length) ({ PRINT_NUMS_FOR(from, length); putchar('\n'); })

#define PRINT_NUMS(Type, from) PRINT_NUMS_WHILE(Type, from, END_OF_NUMBER)
#define PRINTLN_NUMS(Type, from) ({ PRINT_NUMS(Type, from); putchar('\n'); })
