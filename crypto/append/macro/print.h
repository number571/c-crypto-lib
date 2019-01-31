#pragma once

#include <stdio.h>

#include "consts.h"
#include "../types/byte.h"

// PRINT BYTES
#define PRINT_BYTE(from) \
	({ \
		unsigned char *p = &from; \
		Byte x = {.byte = *p}; \
		printf("%hhu%hhu%hhu%hhu%hhu%hhu%hhu%hhu ", \
			x.bit._7, x.bit._6, x.bit._5, x.bit._4, \
			x.bit._3, x.bit._2, x.bit._1, x.bit._0); \
	}) \

#define PRINTLN_BYTE(from) ({ PRINT_BYTE(from); putchar('\n'); })

#define PRINT_BYTES(from) \
	({ \
		for (char *p = from; *p != END_OF_NUMBER; ++p) { \
			Byte x = {.byte = *p}; \
			printf("%hhu%hhu%hhu%hhu%hhu%hhu%hhu%hhu ", \
				x.bit._7, x.bit._6, x.bit._5, x.bit._4, \
				x.bit._3, x.bit._2, x.bit._1, x.bit._0); \
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

#define PRINT_CHARS(Type, from) PRINT_CHARS_WHILE(Type, from, END_OF_STRING)
#define PRINTLN_CHARS(Type, from) ({ PRINT_CHARS(Type, from); putchar('\n'); })

// PRINT NUMS
#define PRINT_NUMS_WHILE(Type, from, end) \
	({ \
		for (Type *p = from; *p != end; ++p) \
			printf("%d ", *p); \
	})

#define PRINTLN_NUMS_WHILE(Type, from, end)  ({ PRINT_NUMS_WHILE(Type, from, end); putchar('\n'); })

#define PRINT_NUMS(Type, from) PRINT_NUMS_WHILE(Type, from, END_OF_NUMBER)
#define PRINTLN_NUMS(Type, from) ({ PRINT_NUMS(Type, from); putchar('\n'); })
