#include <string.h>

#include "../append/macro/consts.h"
#include "../append/types/bool.h"
#include "../append/types/char.h"

static uchar_t __alpha_caesar[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static uchar_t __length_alpha_caesar = LEN_ALPHA;

static uchar_t _char_caesar_wordkey (const schar_t mode, const schar_t nkey, uchar_t * const skey, const uchar_t ch) {
	const uchar_t * const to = (mode == ENCRYPT_MODE) ? skey : __alpha_caesar;
	uchar_t * const from = (mode == DECRYPT_MODE) ? skey : __alpha_caesar;
	
	for (uchar_t *p_from = from; *p_from != END_OF_STRING; ++p_from)
		if (*p_from == ch)
			return to[(p_from - from - nkey + __length_alpha_caesar) % __length_alpha_caesar]; 

	return ch;
}

static schar_t _check_caesar_wordkey (uchar_t * const skey) {
	const uchar_t length = strlen(skey);

	if (length >= MAX_LENGTH)
		return 1;

	for (uchar_t *p_skey = skey; *p_skey != END_OF_STRING; ++p_skey) {
		for (uchar_t i = p_skey - skey + 1; i < length; ++i)
			if (*p_skey == skey[i])
				return 2;

		bool flag = false;
		for (uchar_t *p = __alpha_caesar; *p != END_OF_STRING; ++p)
			if (*p_skey == *p) {
				flag = true;
				break;
			}

		if (!flag)
			return 3;
	}

	return 0;
}

static void _set_caesar_wordkey (uchar_t * const to, uchar_t * const from) {
	const size_t length = strlen(from);

	uchar_t buffer[__length_alpha_caesar + 1];
	strcpy(buffer, from);

	uchar_t *p_buffer = &buffer[length];
	
	for (uchar_t *p = __alpha_caesar; *p != END_OF_STRING; ++p) {
		bool flag = false;
		for (uchar_t *p_from = from; *p_from != END_OF_STRING; ++p_from) 
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

extern char set_alpha_caesar_wordkey (const uchar_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	__length_alpha_caesar = (uchar_t)length;

	strcpy(__alpha_caesar, alpha);

	return 0;
}

extern char caesar_wordkey (
	uchar_t * to, 
	const schar_t mode, 
	schar_t nkey, 
	uchar_t * const skey,
	const uchar_t * from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	if (_check_caesar_wordkey(skey))
		return 2;

	nkey = ( (nkey < 0) ? (__length_alpha_caesar + (nkey % __length_alpha_caesar)) : (nkey % __length_alpha_caesar) ) * mode;

	uchar_t buffer[__length_alpha_caesar + 1];
	_set_caesar_wordkey(buffer, skey);

	while (*from != END_OF_STRING)
		*to++ = _char_caesar_wordkey(mode, nkey, buffer, *from++);
	
	*to = END_OF_STRING;

	return 0;
}
