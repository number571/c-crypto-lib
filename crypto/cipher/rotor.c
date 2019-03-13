#include <stdint.h>
#include <string.h>

#include "../utils/macro/consts.h"

static uint8_t __alpha[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static uint8_t __length_alpha = LEN_ALPHA;

static uint8_t _char_encrypt (const int8_t mode, int8_t key, const uint8_t ch) {
	key = ( (key < 0) ? (__length_alpha + (key % __length_alpha)) : (key % __length_alpha) ) * mode;

	for (uint8_t *p = __alpha; *p != END_OF_STRING; ++p)
		if (*p == ch)
			return __alpha[(p - __alpha + key + __length_alpha) % __length_alpha];

	return ch;
}

extern int8_t set_alpha_rotor (const uint8_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	__length_alpha = (uint8_t)length;
	strcpy(__alpha, alpha);

	return 0;
}

extern char rotor (
	uint8_t * to,
	const int8_t mode, 
	const uint8_t period, 
	int8_t * rotor_key, 
	const uint8_t * const from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	if (period == 0)
		return 2;

	int8_t *key = rotor_key;

	if (*key == END_OF_NUMBER)
		return 3;

	for (size_t index = 0; from[index] != END_OF_STRING; ++index) {
		if (index && !(index % period)) {
			++key;
			if (*key == END_OF_NUMBER) 
				key = rotor_key;
		}

		*to++ = _char_encrypt(mode, *key, from[index]);
	}

	*to = END_OF_STRING;

	return 0;
}
