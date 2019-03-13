#include <stdint.h>
#include <string.h>

#include "../utils/macro/consts.h"

static uint8_t __alpha[2][MAX_LENGTH] = {
	"ABCDEFGHIJKLMNOPQRSTUWXYZ",
	"zyxwutsrqponmlkjihgfedcba",
};

static uint8_t _char_encrypt (const uint8_t * const to, const uint8_t ch, uint8_t * const from) {
	for (uint8_t *p_from = from; *p_from != END_OF_STRING; ++p_from)
		if (ch == *p_from)
			return to[p_from - from];

	return ch;
}

extern char set_alpha_substitution (const uint8_t * const alph1, const uint8_t * const alph2) {
	const size_t length = strlen(alph1);

	if (length >= MAX_LENGTH)
		return 1;

	if (length != strlen(alph2))
		return 2;

	strcpy(__alpha[0], alph1);
	strcpy(__alpha[1], alph2);

	return 0;
}

extern char substitution (
	uint8_t * to, 
	const int8_t mode, 
	const uint8_t * from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	const uint8_t * const to_vector = (mode == ENCRYPT_MODE) ? __alpha[1] : __alpha[0];
	uint8_t * const from_vector = (mode == DECRYPT_MODE) ? __alpha[1] : __alpha[0];

	for (; *from != END_OF_STRING; ++from)
		*to++ = _char_encrypt(to_vector, *from, from_vector);
	
	*to = END_OF_STRING;

	return 0;
}
