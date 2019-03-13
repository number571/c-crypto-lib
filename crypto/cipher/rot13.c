#include <stdint.h>

#include "../utils/macro/consts.h"

static uint8_t _char_encrypt (const uint8_t ch) {
	if ('A' <= ch && ch <= 'Z') 
		return ch % LEN_ALPHA + 'A';

	else if ('a' <= ch && ch <= 'z')
		return (ch - 'a' + 13) % LEN_ALPHA + 'a';
	
	return ch;
}

extern char rot13 (
	uint8_t * to, 
	const uint8_t * from
) {
	for (; *from != END_OF_STRING; ++from)
		*to++ = _char_encrypt(*from);
	
	*to = END_OF_STRING;

	return 0;
}
