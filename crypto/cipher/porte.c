#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../append/macro/consts.h"
#include "../append/macro/copy.h"
#include "../append/types/bool.h"
#include "../append/types/char.h"
#include "../append/types/integer.h"
#include "../append/types/point.h"
#include "../append/funcs/get_length.h"

static uchar_t __alpha_porte[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static uchar_t __default_char_porte = 'Z';

static uchar_t __length_alpha_porte = LEN_ALPHA;

static void _encrypt_porte (INTEGER_TYPE * to, INTEGER_TYPE * const from) {
	const size_t length = get_length('i', from, END_OF_STRING);
	INTEGER_TYPE buffer[length + 2];

	COPY(buffer, INTEGER_TYPE, from, END_OF_STRING);

	if (length % 2) {
		buffer[length] = __default_char_porte;
		buffer[length + 1] = END_OF_STRING;
	}
	
	for (INTEGER_TYPE *p_buffer = buffer; *p_buffer != END_OF_STRING; p_buffer += 2) {
		Point pos = {0, 0};
		bool flag[2] = {false, false};

		for (uchar_t i = 0; i < __length_alpha_porte; ++i) {
			if (*p_buffer == __alpha_porte[i]) {
				pos.x = i;
				flag[0] = true;
			}

			if (*(p_buffer + 1) == __alpha_porte[i]) {
				pos.y = i;
				flag[1] = true;
			}

			if (flag[0] && flag[1])
				break;
		}

		*to++ = (pos.x * __length_alpha_porte) + pos.y;
	}

	*to = END_OF_NUMBER;
}

static void _decrypt_porte (INTEGER_TYPE * const to, INTEGER_TYPE * from) {
	const size_t length = get_length('i', from, END_OF_NUMBER) * 2;

	INTEGER_TYPE buffer[length + 1];
	INTEGER_TYPE *p_buffer = buffer;

	for (; *from != END_OF_NUMBER; ++from) {
		*p_buffer++ = __alpha_porte[*from / __length_alpha_porte];
		*p_buffer++ = __alpha_porte[*from % __length_alpha_porte];
	}

	*p_buffer = END_OF_STRING;
	COPY(to, INTEGER_TYPE, buffer, END_OF_STRING);
}

extern void set_char_porte (const uchar_t ch) {
	__default_char_porte = ch;
}

extern schar_t set_alpha_porte (uchar_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	__length_alpha_porte = (uchar_t)length;
	strcpy(__alpha_porte, alpha);

	return 0;
}

extern void to_string_porte (INTEGER_TYPE * const to, const INTEGER_TYPE * from) {
	const size_t length = get_length('i', from, END_OF_NUMBER);

	INTEGER_TYPE buffer[length * 6 + 1];
	INTEGER_TYPE *p_buffer = buffer;

	for (; *from != END_OF_NUMBER; ++from) {
		uchar_t temp[7];
		sprintf(temp, "%d ", *from);

		for (uchar_t *p_temp = temp; *p_temp != END_OF_STRING; ++p_temp)
			*p_buffer++ = *p_temp;
	}

	*--p_buffer = END_OF_STRING;
	COPY(to, INTEGER_TYPE, buffer, END_OF_STRING);
}

extern void to_bytes_porte (INTEGER_TYPE * to, const INTEGER_TYPE * from) {
	uchar_t temp[7];
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

extern char porte (
	INTEGER_TYPE * const to,
	const schar_t mode,
	INTEGER_TYPE * const from
) {
	switch (mode) {
		case ENCRYPT_MODE:
			_encrypt_porte(to, from);
		break;
		case DECRYPT_MODE:
			_decrypt_porte(to, from);
		break;
		default: return 1;
	}
	
	return 0;
}
