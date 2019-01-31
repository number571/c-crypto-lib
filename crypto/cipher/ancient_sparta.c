#include <string.h>

#include "../append/macro/consts.h"
#include "../append/types/char.h"

static uchar_t __default_char_ancient_sparta = 'Z';

static void _encrypt_ancient_sparta (
	uchar_t * to, const uchar_t nkey, const uchar_t * const from
) {
	size_t start_length, final_length;
	start_length = final_length = strlen(from);

	while (final_length % nkey != 0)
		++final_length;

	const size_t block_length = final_length / nkey;

	uchar_t buffer[final_length + 1];
	strcpy(buffer, from);

	while (start_length++ < final_length)
		buffer[start_length - 1] = __default_char_ancient_sparta;

	for (size_t x = 0; x < block_length; ++x)
		for (size_t y = x; y < final_length; y += block_length)
			*to++ = buffer[y];

	*to = END_OF_STRING;
}

static void _decrypt_ancient_sparta (
	uchar_t * const to, const uchar_t nkey, const uchar_t * const from
) {
	const size_t length = strlen(from);

	uchar_t buffer[length + 1];
	uchar_t *p_buffer = buffer;

	for (size_t x = 0; x < nkey; ++x)
		for (size_t y = x; y < length; y += nkey)
			*p_buffer++ = from[y];

	*p_buffer = END_OF_STRING;

	strcpy(to, buffer);
}

extern void set_char_ancient_sparta (const uchar_t ch) {
	__default_char_ancient_sparta = ch;
}

extern char ancient_sparta (
	uchar_t * const to, 
	const schar_t mode, 
	const uchar_t nkey, 
	const uchar_t * const from
) {
	if (!nkey) return 1;

	switch (mode) {
		case ENCRYPT_MODE: 
			_encrypt_ancient_sparta(to, nkey, from); 
		break;
		case DECRYPT_MODE: 
			_decrypt_ancient_sparta(to, nkey, from); 
		break;
		default: return 2;
	}
	
	return 0;
}
