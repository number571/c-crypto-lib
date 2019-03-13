#include <stdint.h>
#include <string.h>

#include "../utils/macro/consts.h"

static uint8_t __alpha[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static uint8_t __length_alpha = LEN_ALPHA;

static uint8_t _char_encrypt (const int8_t mode, int8_t key, const uint8_t ch) {
	const uint8_t length = __length_alpha;
	key = ( (key < 0) ? (length + (key % length)) : (key % length) ) * mode;

	for (uint8_t *p = __alpha; *p != END_OF_STRING; ++p)
		if (*p == ch)
			return __alpha[(p - __alpha + key + length) % length];
		
	return ch;
}

extern char set_alpha_trithemius (const uint8_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	__length_alpha = (uint8_t)length;
	strcpy(__alpha, alpha);

	return 0;
}

extern char trithemius (
	uint8_t * to, 
	const int8_t mode, 
	int8_t (* const key) (const int8_t x), 
	uint8_t * const from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	for (uint8_t *p_from = from; *p_from != END_OF_STRING; ++p_from)
		*to++ = _char_encrypt(mode, key(p_from - from), *p_from);
			
	*to = END_OF_STRING;

	return 0;
}
