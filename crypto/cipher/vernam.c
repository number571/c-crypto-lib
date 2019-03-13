#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

#include "../utils/macro/consts.h"

static uint8_t __alpha[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static uint8_t __length_alpha = LEN_ALPHA;

static uint8_t _char_encrypt (const int8_t mode, const uint8_t k, const uint8_t ch) {
	for (uint8_t *p = __alpha; *p != END_OF_STRING; ++p)
		if (*p == ch)
			return __alpha[((p - __alpha) + (mode * k) + __length_alpha) % __length_alpha];

	return ch;
}

static char _index_key (uint8_t * const indexed_key, uint8_t * const key) {
	uint8_t *p_key = key;
	size_t count = 0;

	for (; *p_key != END_OF_STRING; ++p_key)
		for (uint8_t *p = __alpha; *p != END_OF_STRING; ++p)
			if (*p_key == *p) {
				indexed_key[p_key - key] = p - __alpha;
				++count;
			}

	if ((p_key - key) != count)
		return 1;

	return 0;
}

static void _generate_random_key (uint8_t * const key, const size_t length) {
	// UNSAFE!
	srand(time(NULL));
	size_t index = 0;

	for (; index < length; ++index)
		// UNSAFE!
		key[index] = __alpha[rand() % __length_alpha];

	key[index] = END_OF_STRING;
}

extern char set_alpha_vernam (const uint8_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	__length_alpha = (uint8_t)length;
	strcpy(__alpha, alpha);

	return 0;
}

extern char vernam (
	uint8_t * to, 
	const int8_t mode,
	uint8_t * const key, 
	uint8_t * const from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	const size_t length = strlen(from);

	if (mode == ENCRYPT_MODE)
		_generate_random_key(key, length);

	uint8_t indexed_key[length];
	if (_index_key(indexed_key, key))
		return 2;

	for (uint8_t *p_from = from; *p_from != END_OF_STRING; ++p_from)
		*to++ = _char_encrypt(mode, indexed_key[p_from - from], *p_from);

	*to = END_OF_STRING;

	return 0;
}
