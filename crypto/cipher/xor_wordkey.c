#include <stdint.h>
#include <string.h>

#include "../utils/types/integer.h"

extern char xor_wordkey (
	__INTEGER__ * to, 
	uint8_t * const key,
	const size_t length,
	const __INTEGER__ * from
) {
	const size_t length_key = strlen(key);

	for (size_t i = 0; i < length; ++i)
		*to++ = from[i] ^ key[i % length_key];

	return 0;
}
