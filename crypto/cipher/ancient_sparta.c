#include <stdint.h>
#include <string.h>

#include "../utils/macro/consts.h"
#include "../utils/macro/funcs.h"

static uint8_t __default_char = 'Z';

static void _encrypt_ancient (
	uint8_t * to, const uint8_t nkey, const uint8_t * const from
) {
	size_t start_length = strlen(from);

	const size_t final_length = ALIGNH(start_length, nkey);
	const size_t block_length = final_length / nkey;

	uint8_t buffer[final_length + 1];
	strcpy(buffer, from);

	while (start_length < final_length)
		buffer[start_length++] = __default_char;

	for (size_t x = 0; x < block_length; ++x)
		for (size_t y = x; y < final_length; y += block_length)
			*to++ = buffer[y];

	*to = END_OF_STRING;
}

static void _decrypt_ancient (
	uint8_t * const to, const uint8_t nkey, const uint8_t * const from
) {
	const size_t length = strlen(from);

	uint8_t buffer[length + 1];
	uint8_t *p_buffer = buffer;

	for (size_t x = 0; x < nkey; ++x)
		for (size_t y = x; y < length; y += nkey)
			*p_buffer++ = from[y];

	*p_buffer = END_OF_STRING;

	strcpy(to, buffer);
}

extern void set_char_ancient_sparta (const uint8_t ch) {
	__default_char = ch;
}

extern char ancient_sparta (
	uint8_t * const to, 
	const int8_t mode, 
	const uint8_t nkey, 
	const uint8_t * const from
) {
	if (!nkey) return 2;

	switch (mode) {
		case ENCRYPT_MODE: 
			_encrypt_ancient(to, nkey, from); 
		break;
		case DECRYPT_MODE: 
			_decrypt_ancient(to, nkey, from); 
		break;
		default: return 1;
	}
	
	return 0;
}
