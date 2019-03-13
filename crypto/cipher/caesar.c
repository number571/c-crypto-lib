#include <stdint.h>
#include <string.h>

#include "../utils/macro/consts.h"

static uint8_t __alpha[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static uint8_t __length_alpha = LEN_ALPHA;

static uint8_t _char_encrypt (const int8_t nkey, const uint8_t ch) {
	for (uint8_t *p = __alpha; *p != END_OF_STRING; ++p)
		if (*p == ch)
			return __alpha[(p - __alpha + nkey + __length_alpha) % __length_alpha];
		
	return ch;
}

extern char set_alpha_caesar (const uint8_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	__length_alpha = (uint8_t)length;
	strcpy(__alpha, alpha);

	return 0;
}

extern char caesar (
	uint8_t * to, 
	const int8_t mode, 
	uint8_t nkey, 
	const uint8_t * from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	nkey %= __length_alpha;

	while (*from != END_OF_STRING)
		*to++ = _char_encrypt(mode * nkey, *from++);
	
	*to = END_OF_STRING;

	return 0;
}
