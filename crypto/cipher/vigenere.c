#include <string.h>

#include "../append/macro.h"
#include "../append/types.h"

static char __alpha_vigenere[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static unsigned char __length_vigenere = LEN_ALPHA;

static char _char_vigenere (const char mode, const char key, const char ch) {
	bool flag[2] = {false, false};
	Point pos = {0, 0};

	for (char *p = __alpha_vigenere; *p != END_OF_STRING; ++p) {
		if (*p == ch) {
			pos.x = (p - __alpha_vigenere);
			flag[0] = true;
		}

		if (*p == key) {
			pos.y = (p - __alpha_vigenere) * mode;
			flag[1] = true;
		}
		
		if (flag[0] && flag[1])
			break;
	}

	if (flag[0] && flag[1])
		return __alpha_vigenere[(pos.x + pos.y + __length_vigenere) % __length_vigenere];

	return ch;
}

extern char set_alpha_vigenere (const char * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	__length_vigenere = (unsigned char)length;
	strcpy(__alpha_vigenere, alpha);

	return 0;
}

extern char vigenere (
	char * to,
	const char mode,
	const char * const key,
	char * const from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	const size_t length = strlen(key);

	for (char *p_from = from; *p_from != END_OF_STRING; ++p_from)
		*to++ = _char_vigenere(mode, key[(p_from - from) % length], *p_from);

	*to = END_OF_STRING;

	return 0;
}
