#include <string.h>

#include "../append/macro.h"
#include "../append/types.h"
#include "../append/funcs.h"

static char __alpha_playfair[MAX_LENGTH] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
static char __default_char_playfair = 'X';

static unsigned char __sqrt_length_playfair = 5;

static void _initial_setup_playfair (char * const to, const char * from) {
	const size_t length = strlen(from);

	char buffer[length + 1];
	char *p_buffer = buffer;

	for (; *from != END_OF_STRING || *(from + 1) != END_OF_STRING; ++from) {
		*p_buffer++ = *from;
		if (*from == *(from + 1))
			*p_buffer++ = __default_char_playfair;
	}
	*p_buffer = END_OF_STRING;

	if (strlen(buffer) % 2 == 1) {
		*p_buffer++ = __default_char_playfair;
		*p_buffer = END_OF_STRING;
	}

	strcpy(to, buffer);
}

static char _check_key_playfair (char * const key) {
	const unsigned char length = strlen(key);

	for (char *p_key = key; *p_key != END_OF_STRING; ++p_key) {
		for (unsigned char i = p_key - key + 1; i < length; ++i)
			if (*p_key == key[i])
				return 1;

		bool flag = false;

		for (char *p = __alpha_playfair; *p != END_OF_STRING; ++p)
			if (*p_key == *p) {
				flag = true;
				break;
			}

		if (!flag)
			return 2;
	}

	return 0;
}

static char _set_key_playfair (char * const key) {
	const unsigned char length_alpha = strlen(__alpha_playfair);
	const unsigned char length_key = strlen(key);

	char buffer[length_key + length_alpha + 1];
	strcpy(buffer, key);

	unsigned char position = length_key;
	for (char *p = __alpha_playfair; *p != END_OF_STRING; ++p) {
		bool flag = false;

		for (char *p_key = key; *p_key != END_OF_STRING; ++p_key)
			if (*p == *p_key) {
				flag = true;
				break;
			}

		if (!flag)
			buffer[position++] = *p;
	}

	buffer[position] = END_OF_STRING;

	if (position >= MAX_LENGTH)
		return 2;

	strcpy(__alpha_playfair, buffer);

	return 0;
}


static void _chars_playfair (char * const to, const char mode) {
	const unsigned char sqrt = __sqrt_length_playfair;

	const Point one = get_coordinates(*to, __alpha_playfair, sqrt);
	const Point two = get_coordinates(*(to + 1), __alpha_playfair, sqrt);

	if (one.x != -1 && two.x != -1)
		if (one.x == two.x) {
			*to       = __alpha_playfair[sqrt * one.x + (one.y + mode + sqrt) % sqrt];
			*(to + 1) = __alpha_playfair[sqrt * two.x + (two.y + mode + sqrt) % sqrt];

		} else if (one.y == two.y) {
			*to       = __alpha_playfair[sqrt * ((one.x + mode + sqrt) % sqrt) + one.y];
			*(to + 1) = __alpha_playfair[sqrt * ((two.x + mode + sqrt) % sqrt) + two.y];

		} else {
			*to       = __alpha_playfair[sqrt * two.x + one.y];
			*(to + 1) = __alpha_playfair[sqrt * one.x + two.y];
		}
}

extern void set_char_playfair (const char ch) {
	__default_char_playfair = ch;
}

extern char set_alpha_playfair (const char * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	unsigned char temp, sqrt = 1;
	while ((temp = SQUARE(sqrt)) < MAX_LENGTH) {
		if (temp == length)
			break;
		++sqrt;
	}

	if (temp >= MAX_LENGTH)
		return 2;

	__sqrt_length_playfair = sqrt;
	strcpy(__alpha_playfair, alpha);

	return 0;
}

extern char playfair (
	char * to,
	const char mode,
	char * const key,
	const char * const from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	if (_check_key_playfair(key))
		return 2;

	if (_set_key_playfair(key))
		return 3;

	_initial_setup_playfair(to, from);

	for (; *to != END_OF_STRING; to += 2)
		_chars_playfair(to, mode);

	return 0;
}