#include "../append/macro.h"

static char _char_rot13 (const char ch) {
	if ('A' <= ch && ch <= 'Z') 
		return ch % LEN_ALPHA + 'A';

	else if ('a' <= ch && ch <= 'z')
		return (ch - 'a' + 13) % LEN_ALPHA + 'a';
	
	return ch;
}

extern char rot13 (char * to, const char * from) {
	for (; *from != END_OF_STRING; ++from)
		*to++ = _char_rot13(*from);
	
	*to = END_OF_STRING;

	return 0;
}
