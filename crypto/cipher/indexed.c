#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/funcs/length.h"

#include "../utils/macro/consts.h"

#include "../utils/types/bool.h"

typedef struct {
	uint8_t buffer[MAX_LENGTH];
	uint8_t count;
} Indexed;

static void _encrypt (int8_t * to, uint8_t * key, const uint8_t * from) {
	Indexed in_object = { {0}, 0 };
	uint8_t first_symbol = 0;

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

static void _decrypt (uint8_t * to, const uint8_t * key, const int8_t * from) {
	Indexed in_object = { {0}, 0 };

	for (; *key != END_OF_STRING; ++key)
		in_object.buffer[in_object.count++] = *key;

	for (; *from != END_OF_NUMBER; ++from)
		*to++ = in_object.buffer[*from];

	*to = END_OF_STRING;
}

extern void to_string_indexed (uint8_t * const to, const int8_t * from) {
	const size_t length = _length('c', from, END_OF_NUMBER);

	uint8_t buffer[length * 3 + 1];
	uint8_t *p_buffer = buffer;

	for (; *from != END_OF_NUMBER; ++from) {
		uint8_t temp[4];
		sprintf(temp, "%d ", *from);

		for (uint8_t *p_temp = temp; *p_temp != END_OF_STRING; ++p_temp)
			*p_buffer++ = *p_temp;
	}

	*--p_buffer = END_OF_STRING;
	strcpy(to, buffer);
}

extern void to_bytes_indexed (int8_t * to, const uint8_t * from) {
	uint8_t temp[4];
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

extern char indexed (
	int8_t * to,
	const int8_t mode,
	uint8_t * key,
	const int8_t * from
) {
	switch (mode) {
		case ENCRYPT_MODE:
			_encrypt(to, key, from);
		break;
		case DECRYPT_MODE:
			_decrypt(to, key, from);
		break;
		default: return 1;
	}
	return 0;
}
