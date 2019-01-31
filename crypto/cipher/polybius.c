#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../append/macro/consts.h"
#include "../append/macro/funcs.h"
#include "../append/types/char.h"
#include "../append/types/point.h"
#include "../append/funcs/get_length.h"
#include "../append/funcs/get_coordinates.h"

#undef MAX_LENGTH
#define MAX_LENGTH 100

static uchar_t __alpha_polybius[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static uchar_t __sqrt_length_alpha_polybius = 6;

static void _encrypt_polybius (schar_t * to, const uchar_t * from) {
	for (; *from != END_OF_STRING; ++from) {
		Point pos = get_coordinates(*from, __alpha_polybius, __sqrt_length_alpha_polybius);
		*to++ = (pos.x == -1) ? (*from + END_OF_NUMBER) : ((pos.x + 1) * 10 + (pos.y + 1));
	}

	*to = END_OF_NUMBER;
}

static void _decrypt_polybius (uchar_t * to, const schar_t * from) {
	for (; *from != END_OF_NUMBER; ++from)
		*to++ = (*from < 11) ? 
			(*from - END_OF_NUMBER) :
				__alpha_polybius[(*from / 10 - 1) * __sqrt_length_alpha_polybius + (*from % 10 - 1)];

	*to = END_OF_STRING;
}

extern char set_alpha_polybius (const uchar_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	uchar_t sqrt = 1;
	while (SQUARE(sqrt) < length)
		++sqrt;

	if (SQUARE(sqrt) >= MAX_LENGTH) 
		return 2;

	__sqrt_length_alpha_polybius = sqrt;
	strcpy(__alpha_polybius, alpha);

	return 0;
}

extern void to_string_polybius (uchar_t * const to, const schar_t * from) {
	const size_t length = get_length('c', from, END_OF_NUMBER);

	uchar_t buffer[length * 4 + 1];
	uchar_t *p_buffer = buffer;

	for (; *from != END_OF_NUMBER; ++from) {
		uchar_t temp[5];
		sprintf(temp, "%d ", *from);

		for (uchar_t *p_temp = temp; *p_temp != END_OF_STRING; ++p_temp)
			*p_buffer++ = *p_temp;
	}

	*--p_buffer = END_OF_STRING;
	strcpy(to, buffer);
}

extern void to_bytes_polybius (schar_t * to, const uchar_t * from) {
	uchar_t temp[5];
	uchar_t *p_temp = temp;

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
	schar_t * const to, 
	const schar_t mode, 
	const schar_t * const from
) {
	switch (mode) {
		case ENCRYPT_MODE:
			_encrypt_polybius(to, from);
		break;
		case DECRYPT_MODE:
			_decrypt_polybius(to, from);
		break;
		default: return 1;
	}

	return 0;
}
