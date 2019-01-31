#include <string.h>

#include "../append/macro/consts.h"
#include "../append/types/char.h"

static uchar_t __alpha_trithemius[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static uchar_t __length_alpha_trithemius = LEN_ALPHA;

static uchar_t _char_trithemius (const schar_t mode, schar_t key, const uchar_t ch) {
	const uchar_t length = __length_alpha_trithemius;
	key = ( (key < 0) ? (length + (key % length)) : (key % length) ) * mode;

	for (uchar_t *p = __alpha_trithemius; *p != END_OF_STRING; ++p)
		if (*p == ch)
			return __alpha_trithemius[(p - __alpha_trithemius + key + length) % length];
		
	return ch;
}

extern char set_alpha_trithemius (const uchar_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	__length_alpha_trithemius = (uchar_t)length;
	strcpy(__alpha_trithemius, alpha);

	return 0;
}

extern char trithemius (
	uchar_t * to, 
	const schar_t mode, 
	schar_t (* const key) (const schar_t x), 
	uchar_t * const from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	for (uchar_t *p_from = from; *p_from != END_OF_STRING; ++p_from)
		*to++ = _char_trithemius(mode, key(p_from - from), *p_from);
			
	*to = END_OF_STRING;

	return 0;
}
