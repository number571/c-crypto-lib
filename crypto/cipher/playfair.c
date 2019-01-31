#include <string.h>

#include "../append/macro/consts.h"
#include "../append/macro/funcs.h"
#include "../append/types/bool.h"
#include "../append/types/char.h"
#include "../append/types/point.h"
#include "../append/funcs/get_coordinates.h"

static uchar_t __alpha_playfair[MAX_LENGTH] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
static uchar_t __default_char_playfair = 'X';

static uchar_t __length_alpha_playfair = 25;
static uchar_t __sqrt_length_alpha_playfair = 5;

static void _initial_setup_playfair (uchar_t * const to, const uchar_t * from) {
	const size_t length = strlen(from);

	uchar_t buffer[length + 1];
	uchar_t *p_buffer = buffer;

	for (; *from != END_OF_STRING || *(from + 1) != END_OF_STRING; ++from) {
		*p_buffer++ = *from;
		if (*from == *(from + 1))
			*p_buffer++ = __default_char_playfair;
	}
	
	*p_buffer = END_OF_STRING;

	if (strlen(buffer) % 2) {
		*p_buffer++ = __default_char_playfair;
		*p_buffer = END_OF_STRING;
	}

	strcpy(to, buffer);
}

static char _check_key_playfair (uchar_t * const key) {
	const uchar_t length = strlen(key);

	if (length >= MAX_LENGTH)
		return 1;

	for (uchar_t *p_key = key; *p_key != END_OF_STRING; ++p_key) {
		for (uchar_t i = p_key - key + 1; i < length; ++i)
			if (*p_key == key[i])
				return 2;

		bool flag = false;

		for (uchar_t *p = __alpha_playfair; *p != END_OF_STRING; ++p)
			if (*p_key == *p) {
				flag = true;
				break;
			}

		if (!flag)
			return 3;
	}

	return 0;
}

static void _set_key_playfair (uchar_t * const to, uchar_t * const from) {
	const size_t length = strlen(from);

	uchar_t buffer[__length_alpha_playfair + 1];
	strcpy(buffer, from);

	uchar_t *p_buffer = &buffer[length];
	
	for (uchar_t *p = __alpha_playfair; *p != END_OF_STRING; ++p) {
		bool flag = false;
		for (uchar_t *p_from = from; *p_from != END_OF_STRING; ++p_from) 
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


static void _chars_playfair (uchar_t * const to, const schar_t mode, uchar_t * const from) {
	const uchar_t sqrt = __sqrt_length_alpha_playfair;

	const Point one = get_coordinates(*to, from, sqrt);
	const Point two = get_coordinates(*(to + 1), from, sqrt);

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

extern void set_char_playfair (const uchar_t ch) {
	__default_char_playfair = ch;
}

extern char set_alpha_playfair (const uchar_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	uchar_t temp, sqrt = 1;
	while ((temp = SQUARE(sqrt)) < MAX_LENGTH) {
		if (temp == length)
			break;
		++sqrt;
	}

	if (temp >= MAX_LENGTH)
		return 2;

	__length_alpha_playfair = temp;
	__sqrt_length_alpha_playfair = sqrt;

	strcpy(__alpha_playfair, alpha);

	return 0;
}

extern char playfair (
	uchar_t * to,
	const schar_t mode,
	uchar_t * const key,
	const uchar_t * const from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	if (_check_key_playfair(key))
		return 2;

	uchar_t buffer[__length_alpha_playfair + 1];
	_set_key_playfair(buffer, key);
	_initial_setup_playfair(to, from);

	for (; *to != END_OF_STRING; to += 2)
		_chars_playfair(to, mode, buffer);

	*to = END_OF_STRING;

	return 0;
}
