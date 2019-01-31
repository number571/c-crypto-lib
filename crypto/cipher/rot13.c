#include "../append/macro/consts.h"
#include "../append/types/char.h"

static uchar_t _char_rot13 (const uchar_t ch) {
	if ('A' <= ch && ch <= 'Z') 
		return ch % LEN_ALPHA + 'A';

	else if ('a' <= ch && ch <= 'z')
		return (ch - 'a' + 13) % LEN_ALPHA + 'a';
	
	return ch;
}

extern char rot13 (
	uchar_t * to, 
	const uchar_t * from
) {
	for (; *from != END_OF_STRING; ++from)
		*to++ = _char_rot13(*from);
	
	*to = END_OF_STRING;

	return 0;
}
