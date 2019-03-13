#include <stdint.h>
#include <string.h>

#include "../utils/macro/consts.h"

#include "../utils/types/bool.h"

static uint8_t __alpha[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static uint8_t __length_alpha = LEN_ALPHA;

static uint8_t _char_encrypt (const int8_t mode, const int8_t nkey, uint8_t * const skey, const uint8_t ch) {
	const uint8_t * const to = (mode == ENCRYPT_MODE) ? skey : __alpha;
	uint8_t * const from = (mode == DECRYPT_MODE) ? skey : __alpha;
	
	for (uint8_t *p_from = from; *p_from != END_OF_STRING; ++p_from)
		if (*p_from == ch)
			return to[(p_from - from - nkey + __length_alpha) % __length_alpha]; 

	return ch;
}

static int8_t _check_wordkey (uint8_t * const skey) {
	const uint8_t length = strlen(skey);

	if (length >= MAX_LENGTH)
		return 1;

	for (uint8_t *p_skey = skey; *p_skey != END_OF_STRING; ++p_skey) {
		for (uint8_t i = p_skey - skey + 1; i < length; ++i)
			if (*p_skey == skey[i])
				return 2;

		bool flag = false;
		for (uint8_t *p = __alpha; *p != END_OF_STRING; ++p)
			if (*p_skey == *p) {
				flag = true;
				break;
			}

		if (!flag)
			return 3;
	}

	return 0;
}

static void _set_wordkey (uint8_t * const to, uint8_t * const from) {
	const size_t length = strlen(from);

	uint8_t buffer[__length_alpha + 1];
	strcpy(buffer, from);

	uint8_t *p_buffer = &buffer[length];
	
	for (uint8_t *p = __alpha; *p != END_OF_STRING; ++p) {
		bool flag = false;
		for (uint8_t *p_from = from; *p_from != END_OF_STRING; ++p_from) 
			if (*p == *p_from) {
				flag = true;
				break;
			}

		if (!flag)
			*p_buffer++ = *p;
	}

	*p_buffer = END_OF_STRING;

	strcpy(to, buffer);
}

extern char set_alpha_caesar_wordkey (const uint8_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	__length_alpha = (uint8_t)length;

	strcpy(__alpha, alpha);

	return 0;
}

extern char caesar_wordkey (
	uint8_t * to, 
	const int8_t mode, 
	int8_t nkey, 
	uint8_t * const skey,
	const uint8_t * from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	if (_check_wordkey(skey))
		return 2;

	nkey = ( (nkey < 0) ? (__length_alpha + (nkey % __length_alpha)) : (nkey % __length_alpha) ) * mode;

	uint8_t buffer[__length_alpha + 1];
	_set_wordkey(buffer, skey);

	while (*from != END_OF_STRING)
		*to++ = _char_encrypt(mode, nkey, buffer, *from++);
	
	*to = END_OF_STRING;

	return 0;
}
