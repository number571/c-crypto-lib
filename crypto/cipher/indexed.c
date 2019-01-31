#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../append/macro/consts.h"
#include "../append/types/bool.h"
#include "../append/types/char.h"
#include "../append/funcs/get_length.h"

typedef struct {
	uchar_t buffer[MAX_LENGTH];
	uchar_t count;
} Indexed;

static void _encrypt_indexed (schar_t * to, uchar_t * key, const uchar_t * from) {
	Indexed in_object = { {0}, 0 };
	uchar_t first_symbol = 0;

	for (; *from != END_OF_STRING; ++from) {
		if (*from >= MAX_LENGTH)
			continue;

		if (in_object.buffer[*from] || *from == first_symbol) {
			*to++ = in_object.buffer[*from];

		} else {
			in_object.buffer[*from] = in_object.count++;

			if (!first_symbol)
				first_symbol = *from;

			*key++ = *from;
			*to++ = in_object.buffer[*from];
		} 
	}

	*key = END_OF_STRING;
	*to = END_OF_NUMBER;
}

static void _decrypt_indexed (uchar_t * to, const uchar_t * key, const schar_t * from) {
	Indexed in_object = { {0}, 0 };

	for (; *key != END_OF_STRING; ++key)
		in_object.buffer[in_object.count++] = *key;

	for (; *from != END_OF_NUMBER; ++from)
		*to++ = in_object.buffer[*from];

	*to = END_OF_STRING;
}

extern void to_string_indexed (uchar_t * const to, const schar_t * from) {
	const size_t length = get_length('c', from, END_OF_NUMBER);

	uchar_t buffer[length * 3 + 1];
	uchar_t *p_buffer = buffer;

	for (; *from != END_OF_NUMBER; ++from) {
		uchar_t temp[4];
		sprintf(temp, "%d ", *from);

		for (uchar_t *p_temp = temp; *p_temp != END_OF_STRING; ++p_temp)
			*p_buffer++ = *p_temp;
	}

	*--p_buffer = END_OF_STRING;
	strcpy(to, buffer);
}

extern void to_bytes_indexed (schar_t * to, const uchar_t * from) {
	uchar_t temp[4];
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

extern char indexed (
	schar_t * to,
	const schar_t mode,
	uchar_t * key,
	const schar_t * from
) {
	switch (mode) {
		case ENCRYPT_MODE:
			_encrypt_indexed(to, key, from);
		break;
		case DECRYPT_MODE:
			_decrypt_indexed(to, key, from);
		break;
		default: return 1;
	}
	return 0;
}
