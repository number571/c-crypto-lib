#include <stddef.h>

#include "../utils/types/integer.h"

extern char xor (
	__INTEGER__ * to, 
	const __INTEGER__ key, 
	const size_t length,
	const __INTEGER__ * from
) {
	for (size_t i = 0; i < length; ++i)
		*to++ = from[i] ^ key;
	
	return 0;
}
