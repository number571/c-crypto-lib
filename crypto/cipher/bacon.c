#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "../utils/funcs/length.h"

#include "../utils/macro/consts.h"
#include "../utils/macro/copy.h"

#include "../utils/types/byte.h"

static uint8_t __alpha[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static uint8_t __default_char[2] = {'A', 'B'};

static int8_t _char_encrypt (const uint8_t ch) {
	for (uint8_t *p = __alpha; *p != END_OF_STRING; ++p)
		if (*p == ch)
			return p - __alpha;

	return ch + END_OF_NUMBER;
}

static void _encrypt (int8_t * to, const int8_t * from) {
	for (; *from != END_OF_STRING; ++from)
		*to++ = _char_encrypt((uint8_t)*from);

	*to = END_OF_NUMBER;
}

static void _decrypt (int8_t * to, const int8_t * from) {
	for (; *from != END_OF_NUMBER; ++from)
		if (*from < 0)
			*to++ = *from - END_OF_NUMBER;
		else
			*to++ = __alpha[*from];

	*to = END_OF_STRING;
}

extern void set_char_bacon (const uint8_t ch1, const uint8_t ch2) {
	__default_char[0] = ch1;
	__default_char[1] = ch2;
}

extern char set_alpha_bacon (const uint8_t * const alpha) {
	if (strlen(alpha) >= MAX_LENGTH)
		return 1;

	strcpy(__alpha, alpha);

	return 0;
}

extern void to_string_bacon (uint8_t * to, int8_t * const from) {
	Byte x;
	const size_t length = _length('c', from, END_OF_NUMBER);

	int8_t buffer[length + 1];
	COPY(buffer, int8_t, from, END_OF_NUMBER);

	for (int8_t *p_buffer = buffer; *p_buffer != END_OF_NUMBER; ++p_buffer)
		if (*p_buffer >= 0) {
			x.byte = *p_buffer;
			*to++ = x.bit._7 ? __default_char[1] : __default_char[0];
			*to++ = x.bit._6 ? __default_char[1] : __default_char[0];
			*to++ = x.bit._5 ? __default_char[1] : __default_char[0];
			*to++ = x.bit._4 ? __default_char[1] : __default_char[0];
			*to++ = x.bit._3 ? __default_char[1] : __default_char[0];
			*to++ = x.bit._2 ? __default_char[1] : __default_char[0];
			*to++ = x.bit._1 ? __default_char[1] : __default_char[0];
			*to++ = x.bit._0 ? __default_char[1] : __default_char[0];
		} else 
			*to++ = *p_buffer - END_OF_NUMBER;

	*to = END_OF_STRING;
}

extern void to_bytes_bacon (int8_t * to, const uint8_t * from) {
	Byte x;
	int8_t position = 0;

	for (; *from != END_OF_STRING; ++from) 
		if (*from == __default_char[0] || *from == __default_char[1]) {
			switch (position) {
				case 0: x.bit._7 = (*from == __default_char[0]) ? 0 : 1; break;
				case 1: x.bit._6 = (*from == __default_char[0]) ? 0 : 1; break;
				case 2: x.bit._5 = (*from == __default_char[0]) ? 0 : 1; break;
				case 3: x.bit._4 = (*from == __default_char[0]) ? 0 : 1; break;
				case 4: x.bit._3 = (*from == __default_char[0]) ? 0 : 1; break;
				case 5: x.bit._2 = (*from == __default_char[0]) ? 0 : 1; break;
				case 6: x.bit._1 = (*from == __default_char[0]) ? 0 : 1; break;
				case 7: x.bit._0 = (*from == __default_char[0]) ? 0 : 1; break;
			}
			++position;
			if (position && !(position % 8)) {
				*to++ = x.byte;
				position = 0;
			}
		} else 
			*to++ = *from + END_OF_NUMBER;

	*to = END_OF_NUMBER;
}

extern void print_bacon (const int8_t * from) {
	for (; *from != END_OF_NUMBER; ++from)
		if (*from >= 0) {
			Byte x = { .byte = *from };
			printf("%c%c%c%c%c%c%c%c", 
				x.bit._7 ? __default_char[1] : __default_char[0],
				x.bit._6 ? __default_char[1] : __default_char[0],
				x.bit._5 ? __default_char[1] : __default_char[0],
				x.bit._4 ? __default_char[1] : __default_char[0],
				x.bit._3 ? __default_char[1] : __default_char[0],
				x.bit._2 ? __default_char[1] : __default_char[0],
				x.bit._1 ? __default_char[1] : __default_char[0],
				x.bit._0 ? __default_char[1] : __default_char[0]);
		} else 
			putchar(*from - END_OF_NUMBER);
}

extern void println_bacon (const int8_t * from) {
	print_bacon(from);
	putchar('\n');
}

extern char bacon (
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
