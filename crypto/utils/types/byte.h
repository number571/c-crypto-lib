#pragma once

#include <stdint.h>

typedef union {
	uint8_t byte;
	struct {
		uint8_t _0: 1;
		uint8_t _1: 1;
		uint8_t _2: 1;
		uint8_t _3: 1;
		uint8_t _4: 1;
		uint8_t _5: 1;
		uint8_t _6: 1;
		uint8_t _7: 1;
	} bit;
} Byte;
