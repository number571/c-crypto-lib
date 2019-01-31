#include <string.h>

#include "../append/macro/consts.h"
#include "../append/types/char.h"

static uchar_t __alpha_caesar[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static uchar_t __length_alpha_caesar = LEN_ALPHA;

static uchar_t _char_caesar (const schar_t nkey, const uchar_t ch) {
	for (uchar_t *p = __alpha_caesar; *p != END_OF_STRING; ++p)
		if (*p == ch)
			return __alpha_caesar[(p - __alpha_caesar + nkey + __length_alpha_caesar) % __length_alpha_caesar];
		
	return ch;
}

extern char set_alpha_caesar (const uchar_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	__length_alpha_caesar = (uchar_t)length;
	strcpy(__alpha_caesar, alpha);

	return 0;
}

extern char caesar (
	uchar_t * to, 
	const schar_t mode, 
	schar_t nkey, 
	const uchar_t * from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	nkey = ( (nkey < 0) ? (__length_alpha_caesar + (nkey % __length_alpha_caesar)) : (nkey % __length_alpha_caesar) ) * mode;

	while (*from != END_OF_STRING)
		*to++ = _char_caesar(nkey, *from++);
	
	*to = END_OF_STRING;

	return 0;
}
