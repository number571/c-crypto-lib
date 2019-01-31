#include <string.h>

#include "../append/macro/consts.h"
#include "../append/types/bool.h"
#include "../append/types/char.h"
#include "../append/types/point.h"

static uchar_t __alpha_vigenere[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static uchar_t __length_alpha_vigenere = LEN_ALPHA;

static uchar_t _char_vigenere (const schar_t mode, const uchar_t key, const uchar_t ch) {
	bool flag[2] = {false, false};
	Point pos = {0, 0};

	for (uchar_t *p = __alpha_vigenere; *p != END_OF_STRING; ++p) {
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
		return __alpha_vigenere[(pos.x + pos.y + __length_alpha_vigenere) % __length_alpha_vigenere];

	return ch;
}

extern char set_alpha_vigenere (const uchar_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	__length_alpha_vigenere = (uchar_t)length;
	strcpy(__alpha_vigenere, alpha);

	return 0;
}

extern char vigenere (
	uchar_t * to,
	const schar_t mode,
	const uchar_t * const key,
	uchar_t * const from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	const size_t length = strlen(key);

	for (uchar_t *p_from = from; *p_from != END_OF_STRING; ++p_from)
		*to++ = _char_vigenere(mode, key[(p_from - from) % length], *p_from);

	*to = END_OF_STRING;

	return 0;
}
