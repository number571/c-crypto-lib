#include "../append/macro/consts.h"
#include "../append/types/char.h"
#include "../append/types/integer.h"

extern char xor_wordkey (
	INTEGER_TYPE * to, 
	uchar_t * const key, 
	const INTEGER_TYPE * from
) {
	uchar_t *p_key = key;

	for (; *from != END_OF_NUMBER; ++from) {
		INTEGER_TYPE temp = *from ^ *p_key++;

		if (!temp) 
			*to++ = *from;
		else 
			*to++ = temp;

		if (!*p_key) 
			p_key = key;
	}

	*to = END_OF_NUMBER;
	
	return 0;
}
