#include <stdint.h>
#include <string.h>

#include "../utils/funcs/gcd.h"

#include "../utils/macro/consts.h"

static uint8_t __alpha[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static uint8_t __length_alpha = LEN_ALPHA;

static uint8_t _char_encrypt (const int8_t mode, const uint8_t ch, const uint8_t nkey1, const uint8_t nkey2) {
	for (uint8_t *p = __alpha; *p != END_OF_STRING; ++p)
		if (*p == ch)
			switch (mode) {
				case ENCRYPT_MODE: return __alpha[(nkey1 * (p - __alpha) + nkey2) % __length_alpha];
				case DECRYPT_MODE: return __alpha[(nkey1 * (((p - __alpha) - nkey2) % __length_alpha + __length_alpha) ) % __length_alpha];
			}
			
	return ch;
}

extern char set_alpha_affine (const uint8_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	__length_alpha = (uint8_t)length;
	strcpy(__alpha, alpha);

	return 0;
}

extern char affine (
	uint8_t * to, 
	const int8_t mode, 
	uint8_t nkey1, 
	const uint8_t nkey2,
	const uint8_t * from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	if (_gcd(nkey1, __length_alpha) != 1)
		return 2;

	if (mode == DECRYPT_MODE) {
		uint8_t b = 1;
		while (nkey1 * b % __length_alpha != 1)
			++b;
		nkey1 = b;
	}

	for (; *from != END_OF_STRING; ++from) 
		*to++ = _char_encrypt(mode, *from, nkey1, nkey2);

	*to = END_OF_STRING;

	return 0;
}
