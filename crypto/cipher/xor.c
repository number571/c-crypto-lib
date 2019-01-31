#include "../append/macro/consts.h"
#include "../append/types/char.h"
#include "../append/types/integer.h"

extern char xor (
	INTEGER_TYPE * to, 
	const uchar_t key, 
	const INTEGER_TYPE * from
) {
	for (; *from != END_OF_NUMBER; ++from) {
		INTEGER_TYPE temp = *from ^ key;

		if (!temp) 
			*to++ = *from;
		else 
			*to++ = temp;
	}

	*to = END_OF_NUMBER;
	
	return 0;
}
