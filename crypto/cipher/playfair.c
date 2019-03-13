#include <stdint.h>
#include <string.h>

#include "../utils/funcs/coordinates.h"

#include "../utils/macro/consts.h"
#include "../utils/macro/funcs.h"

#include "../utils/types/bool.h"
#include "../utils/types/point.h"

static uint8_t __alpha[MAX_LENGTH] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
static uint8_t __default_char = 'X';

static uint8_t __length_alpha = 25;
static uint8_t __sqrt_length_alpha = 5;

static void _initial_setup (uint8_t * const to, const uint8_t * from) {
	const size_t length = strlen(from);

	uint8_t buffer[length + 1];
	uint8_t *p_buffer = buffer;

	for (; *from != END_OF_STRING || *(from + 1) != END_OF_STRING; ++from) {
		*p_buffer++ = *from;
		if (*from == *(from + 1))
			*p_buffer++ = __default_char;
	}
	
	*p_buffer = END_OF_STRING;

	if (strlen(buffer) % 2) {
		*p_buffer++ = __default_char;
		*p_buffer = END_OF_STRING;
	}

	strcpy(to, buffer);
}

static char _check_key (uint8_t * const key) {
	const uint8_t length = strlen(key);

	if (length >= MAX_LENGTH)
		return 1;

	for (uint8_t *p_key = key; *p_key != END_OF_STRING; ++p_key) {
		for (uint8_t i = p_key - key + 1; i < length; ++i)
			if (*p_key == key[i])
				return 2;

		bool flag = false;

		for (uint8_t *p = __alpha; *p != END_OF_STRING; ++p)
			if (*p_key == *p) {
				flag = true;
				break;
			}

		if (!flag)
			return 3;
	}

	return 0;
}

static void _set_key (uint8_t * const to, uint8_t * const from) {
	const size_t length = strlen(from);

	uint8_t buffer[__length_alpha + 1];
	strcpy(buffer, from);

	uint8_t *p_buffer = &buffer[length];
	
	for (uint8_t *p = __alpha; *p != END_OF_STRING; ++p) {
		bool flag = false;
		for (uint8_t *p_from = from; *p_from != END_OF_STRING; ++p_from) 
			if (*p == *p_from) {
				flag = true;
				break;
			}

		if (!flag)
			*p_buffer++ = *p;
	}

	*p_buffer = END_OF_STRING;

	strcpy(to, buffer);
}


static void _chars_encrypt (uint8_t * const to, const int8_t mode, uint8_t * const from) {
	const uint8_t sqrt = __sqrt_length_alpha;

	const Point one = _coordinates(*to, from, sqrt);
	const Point two = _coordinates(*(to + 1), from, sqrt);

	if (one.x != -1 && two.x != -1)
		if (one.x == two.x) {
			*to       = from[sqrt * one.x + (one.y + mode + sqrt) % sqrt];
			*(to + 1) = from[sqrt * two.x + (two.y + mode + sqrt) % sqrt];

		} else if (one.y == two.y) {
			*to       = from[sqrt * ((one.x + mode + sqrt) % sqrt) + one.y];
			*(to + 1) = from[sqrt * ((two.x + mode + sqrt) % sqrt) + two.y];

		} else {
			*to       = from[sqrt * two.x + one.y];
			*(to + 1) = from[sqrt * one.x + two.y];
		}
}

extern void set_char_playfair (const uint8_t ch) {
	__default_char = ch;
}

extern char set_alpha_playfair (const uint8_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	uint8_t temp, sqrt = 1;
	while ((temp = SQUARE(sqrt)) < MAX_LENGTH) {
		if (temp == length)
			break;
		++sqrt;
	}

	if (temp >= MAX_LENGTH)
		return 2;

	__length_alpha = temp;
	__sqrt_length_alpha = sqrt;

	strcpy(__alpha, alpha);

	return 0;
}

extern char playfair (
	uint8_t * to,
	const int8_t mode,
	uint8_t * const key,
	const uint8_t * const from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	if (_check_key(key))
		return 2;

	uint8_t buffer[__length_alpha + 1];
	_set_key(buffer, key);
	_initial_setup(to, from);

	for (; *to != END_OF_STRING; to += 2)
		_chars_encrypt(to, mode, buffer);

	*to = END_OF_STRING;

	return 0;
}
