#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/funcs/length.h"
#include "../utils/funcs/coordinates.h"

#include "../utils/macro/consts.h"
#include "../utils/macro/funcs.h"

#include "../utils/types/point.h"

#undef MAX_LENGTH
#define MAX_LENGTH 100

static uint8_t __alpha[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static uint8_t __sqrt_length_alpha = 6;

static void _encrypt (int8_t * to, const uint8_t * from) {
	for (; *from != END_OF_STRING; ++from) {
		Point pos = _coordinates(*from, __alpha, __sqrt_length_alpha);
		*to++ = (pos.x == -1) ? (*from + END_OF_NUMBER) : ((pos.x + 1) * 10 + (pos.y + 1));
	}

	*to = END_OF_NUMBER;
}

static void _decrypt (uint8_t * to, const int8_t * from) {
	for (; *from != END_OF_NUMBER; ++from)
		*to++ = (*from < 11) ? 
			(*from - END_OF_NUMBER) :
				__alpha[(*from / 10 - 1) * __sqrt_length_alpha + (*from % 10 - 1)];

	*to = END_OF_STRING;
}

extern char set_alpha_polybius (const uint8_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	uint8_t sqrt = 1;
	while (SQUARE(sqrt) < length)
		++sqrt;

	if (SQUARE(sqrt) >= MAX_LENGTH) 
		return 2;

	__sqrt_length_alpha = sqrt;
	strcpy(__alpha, alpha);

	return 0;
}

extern void to_string_polybius (uint8_t * const to, const int8_t * from) {
	const size_t length = _length('c', from, END_OF_NUMBER);

	uint8_t buffer[length * 4 + 1];
	uint8_t *p_buffer = buffer;

	for (; *from != END_OF_NUMBER; ++from) {
		uint8_t temp[5];
		sprintf(temp, "%d ", *from);

		for (uint8_t *p_temp = temp; *p_temp != END_OF_STRING; ++p_temp)
			*p_buffer++ = *p_temp;
	}

	*--p_buffer = END_OF_STRING;
	strcpy(to, buffer);
}

extern void to_bytes_polybius (int8_t * to, const uint8_t * from) {
	uint8_t temp[5];
	uint8_t *p_temp = temp;

	for (; *from != END_OF_STRING; ++from) {
		if (*from == ' ') {
			*p_temp = END_OF_STRING;
			*to++ = atoi(temp);
			p_temp = temp;
		} else
			*p_temp++ = *from;
	}
	
	*p_temp = END_OF_STRING;
	*to++ = atoi(temp);
	
	*to = END_OF_NUMBER;
}

extern char polybius (
	int8_t * const to, 
	const int8_t mode, 
	const int8_t * const from
) {
	switch (mode) {
		case ENCRYPT_MODE:
			_encrypt(to, from);
		break;
		case DECRYPT_MODE:
			_decrypt(to, from);
		break;
		default: return 1;
	}

	return 0;
}
