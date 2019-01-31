#include <string.h>

#include "../append/macro/consts.h"
#include "../append/types/char.h"

static uchar_t __alpha_couple[2][MAX_LENGTH] = {
	"ACEGIKMOQSUWY",
	"BDFHJLNPRTVXZ",
};
static uchar_t __length_alpha_couple = LEN_ALPHA / 2;

static uchar_t _char_couple (const uchar_t ch) {
	for (uchar_t x = 0; x < __length_alpha_couple; ++x)
		if (ch == __alpha_couple[0][x]) 
			return __alpha_couple[1][x];

		else if (ch == __alpha_couple[1][x])
			return __alpha_couple[0][x];

	return ch;
}

extern char set_alpha_couple (uchar_t * const alph1, uchar_t * const alph2) {
	const size_t length = strlen(alph1);

	if (length >= MAX_LENGTH)
		return 1;

	if (length != strlen(alph2))
		return 2;

	for (uchar_t *p_alph1 = alph1; *p_alph1 != END_OF_STRING; ++p_alph1)
		for (uchar_t *p_alph2 = alph2; *p_alph2 != END_OF_STRING; ++p_alph2)
			if (*p_alph1 == *p_alph2)
				return 3;

	__length_alpha_couple = (uchar_t)length;

	strcpy(__alpha_couple[0], alph1);
	strcpy(__alpha_couple[1], alph2);

	return 0;
}

extern char couple (
	uchar_t * to, 
	const uchar_t * from
) {
	for (; *from != END_OF_STRING; ++from)
		*to++ = _char_couple(*from);

	*to = END_OF_STRING;
	
	return 0;
}
