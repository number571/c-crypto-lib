#include <stdint.h>
#include <string.h>

#include "../utils/macro/consts.h"

static uint8_t __alpha[2][MAX_LENGTH] = {
	"ACEGIKMOQSUWY",
	"BDFHJLNPRTVXZ",
};
static uint8_t __length_alpha = LEN_ALPHA / 2;

static uint8_t _char_encrypt (const uint8_t ch) {
	for (uint8_t x = 0; x < __length_alpha; ++x)
		if (ch == __alpha[0][x]) 
			return __alpha[1][x];

		else if (ch == __alpha[1][x])
			return __alpha[0][x];

	return ch;
}

extern char set_alpha_couple (uint8_t * const alph1, uint8_t * const alph2) {
	const size_t length = strlen(alph1);

	if (length >= MAX_LENGTH)
		return 1;

	if (length != strlen(alph2))
		return 2;

	for (uint8_t *p_alph1 = alph1; *p_alph1 != END_OF_STRING; ++p_alph1)
		for (uint8_t *p_alph2 = alph2; *p_alph2 != END_OF_STRING; ++p_alph2)
			if (*p_alph1 == *p_alph2)
				return 3;

	__length_alpha = (uint8_t)length;

	strcpy(__alpha[0], alph1);
	strcpy(__alpha[1], alph2);

	return 0;
}

extern char couple (
	uint8_t * to, 
	const uint8_t * from
) {
	for (; *from != END_OF_STRING; ++from)
		*to++ = _char_encrypt(*from);

	*to = END_OF_STRING;
	
	return 0;
}
