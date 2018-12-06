#include <string.h>

#include "../append/macro.h"
#include "../append/types.h"

static char __alpha_one_couple[MAX_LENGTH] = "ACEGIKMOQSUWY";
static char __alpha_two_couple[MAX_LENGTH] = "BDFHJLNPRTVXZ";

static unsigned char __length_couple = LEN_ALPHA / 2;

static char _char_couple (const char ch) {
	for (unsigned char x = 0; x < __length_couple; ++x)
		if (ch == __alpha_one_couple[x]) 
			return __alpha_two_couple[x];

		else if (ch == __alpha_two_couple[x])
			return __alpha_one_couple[x];

	return ch;
}

extern char set_alpha_couple (char * const alph1, char * const alph2) {
	const size_t length = strlen(alph1);

	if (length >= MAX_LENGTH)
		return 1;

	if (length != strlen(alph2))
		return 2;

	for (char *p_alph1 = alph1; *p_alph1 != END_OF_STRING; ++p_alph1)
		for (char *p_alph2 = alph2; *p_alph2 != END_OF_STRING; ++p_alph2)
			if (*p_alph1 == *p_alph2)
				return 3;

	__length_couple = (unsigned char)length;

	strcpy(__alpha_one_couple, alph1);
	strcpy(__alpha_two_couple, alph2);

	return 0;
}

extern char couple (char * to, const char * from) {
	for (; *from != END_OF_STRING; ++from)
		*to++ = _char_couple(*from);

	*to = END_OF_STRING;
	
	return 0;
}
