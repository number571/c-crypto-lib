#include <stdint.h>
#include <string.h>

#include "../utils/macro/consts.h"

static uint8_t __alpha[MAX_LENGTH] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
static uint8_t __length_alpha = LEN_ALPHA;

static uint8_t _char_encrypt (const uint8_t ch) {
	for (uint8_t *p = __alpha; *p != END_OF_STRING; ++p)
		if (*p == ch)
			return __alpha[__length_alpha - 1 - (p - __alpha)];
		
	return ch;
}

extern char set_alpha_atbash (const uint8_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	__length_alpha = (uint8_t)length;
	strcpy(__alpha, alpha);

	return 0;
}

extern char atbash (
	uint8_t * to, 
	const uint8_t * from
) {
	while (*from != END_OF_STRING)
		*to++ = _char_encrypt(*from++);
	
	*to = END_OF_STRING;
	
	return 0;
}
