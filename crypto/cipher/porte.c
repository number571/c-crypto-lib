#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/funcs/length.h"

#include "../utils/macro/consts.h"
#include "../utils/macro/copy.h"

#include "../utils/types/bool.h"
#include "../utils/types/point.h"
#include "../utils/types/integer.h"

static uint8_t __alpha[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static uint8_t __default_char = 'Z';

static uint8_t __length_alpha = LEN_ALPHA;

static void _encrypt (__INTEGER__ * to, __INTEGER__ * const from) {
	const size_t length = _length('i', from, END_OF_STRING);
	__INTEGER__ buffer[length + 2];

	COPY(buffer, __INTEGER__, from, END_OF_STRING);

	if (length % 2) {
		buffer[length] = __default_char;
		buffer[length + 1] = END_OF_STRING;
	}
	
	for (__INTEGER__ *p_buffer = buffer; *p_buffer != END_OF_STRING; p_buffer += 2) {
		Point pos = {0, 0};
		bool flag[2] = {false, false};

		for (uint8_t i = 0; i < __length_alpha; ++i) {
			if (*p_buffer == __alpha[i]) {
				pos.x = i;
				flag[0] = true;
			}

			if (*(p_buffer + 1) == __alpha[i]) {
				pos.y = i;
				flag[1] = true;
			}

			if (flag[0] && flag[1])
				break;
		}

		*to++ = (pos.x * __length_alpha) + pos.y;
	}

	*to = END_OF_NUMBER;
}

static void _decrypt (__INTEGER__ * const to, __INTEGER__ * from) {
	const size_t length = _length('i', from, END_OF_NUMBER) * 2;

	__INTEGER__ buffer[length + 1];
	__INTEGER__ *p_buffer = buffer;

	for (; *from != END_OF_NUMBER; ++from) {
		*p_buffer++ = __alpha[*from / __length_alpha];
		*p_buffer++ = __alpha[*from % __length_alpha];
	}

	*p_buffer = END_OF_STRING;
	COPY(to, __INTEGER__, buffer, END_OF_STRING);
}

extern void set_char_porte (const uint8_t ch) {
	__default_char = ch;
}

extern int8_t set_alpha_porte (uint8_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	__length_alpha = (uint8_t)length;
	strcpy(__alpha, alpha);

	return 0;
}

extern void to_string_porte (__INTEGER__ * const to, const __INTEGER__ * from) {
	const size_t length = _length('i', from, END_OF_NUMBER);

	__INTEGER__ buffer[length * 6 + 1];
	__INTEGER__ *p_buffer = buffer;

	for (; *from != END_OF_NUMBER; ++from) {
		uint8_t temp[7];
		sprintf(temp, "%d ", *from);

		for (uint8_t *p_temp = temp; *p_temp != END_OF_STRING; ++p_temp)
			*p_buffer++ = *p_temp;
	}

	*--p_buffer = END_OF_STRING;
	COPY(to, __INTEGER__, buffer, END_OF_STRING);
}

extern void to_bytes_porte (__INTEGER__ * to, const __INTEGER__ * from) {
	uint8_t temp[7];
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

extern char porte (
	__INTEGER__ * const to,
	const int8_t mode,
	__INTEGER__ * const from
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
