#include <string.h>

#include "../append/macro/consts.h"
#include "../append/macro/funcs.h"
#include "../append/macro/copy.h"
#include "../append/types/char.h"
#include "../append/types/integer.h"
#include "../append/funcs/transpose.h"
#include "../append/funcs/get_determinant.h"
#include "../append/funcs/get_algebraic_additions.h"

static uchar_t __alpha_hill[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static uchar_t __length_alpha_hill = LEN_ALPHA;

static uchar_t __default_char_hill = 'X';

static schar_t _char_hill (const uchar_t ch) {
	for (uchar_t *p = __alpha_hill; *p != END_OF_STRING; ++p)
		if (ch == *p)
			return p - __alpha_hill;
	
	return ch + END_OF_NUMBER;
}

static void _to_index_hill (schar_t * to) {
	for (; *to != END_OF_STRING; ++to)
		*to = _char_hill(*to);

	*to = END_OF_NUMBER;
}

static void _to_string_hill (schar_t * to) {
	for (; *to != END_OF_NUMBER; ++to)
		*to = __alpha_hill[*to];

	*to = END_OF_STRING;
}

static void _multiply_hill (uchar_t * to, const uchar_t sqrt, uchar_t * key) {
	INTEGER_TYPE buffer[sqrt];
	memset(buffer, 0, sqrt * sizeof(INTEGER_TYPE));

	for (uchar_t x = 0; x < sqrt; ++x) {
		for (uchar_t y = 0; y < sqrt; ++y)
			buffer[x] += key[x * sqrt + y] * to[y];
		buffer[x] %= __length_alpha_hill;
	}

	for (uchar_t x = 0; x < sqrt; ++x)
		*to++ = buffer[x];
}

static void _encrypt_hill (uchar_t * to, const uchar_t sqrt, uchar_t * index_key, uchar_t * from) {
	size_t start_length, final_length;
	start_length = final_length = strlen(from);

	while (final_length % sqrt != 0)
		++final_length;

	schar_t buffer[final_length + 1];
	strcpy(buffer, from);

	while (start_length++ < final_length)
		buffer[start_length - 1] = __default_char_hill;

	buffer[final_length] = END_OF_STRING;
	_to_index_hill(buffer);

	for (schar_t *p_buffer = buffer; *p_buffer != END_OF_NUMBER; p_buffer += sqrt)
		_multiply_hill(p_buffer, sqrt, index_key);

	_to_string_hill(buffer);
	strcpy(to, buffer);
}

static void _decrypt_hill (uchar_t * to, const uchar_t sqrt, const INTEGER_TYPE det, uchar_t * index_key, uchar_t * from) {
	uchar_t algbrs[SQUARE(sqrt)];
	get_algebraic_additions(algbrs, index_key, sqrt, det, __length_alpha_hill);
	transpose(algbrs, sqrt);

	const size_t length = strlen(from);
	schar_t buffer[length + 1];

	strcpy(buffer, from);
	_to_index_hill(buffer);

	for (schar_t *p_buffer = buffer; *p_buffer != END_OF_NUMBER; p_buffer += sqrt)
		_multiply_hill(p_buffer, sqrt, algbrs);

	_to_string_hill(buffer);
	strcpy(to, buffer);
}

extern void set_char_hill (const uchar_t ch) {
	__default_char_hill = ch;
}

extern char set_alpha_hill (const uchar_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	__length_alpha_hill = (uchar_t)length;
	strcpy(__alpha_hill, alpha);

	return 0;
}

extern char hill (
	uchar_t * to,
	const schar_t mode,
	uchar_t * key,
	uchar_t * from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	const size_t length = strlen(key);
	if (length >= MAX_LENGTH)
		return 2;

	uchar_t sqrt = 1;
	while (SQUARE(sqrt) < length)
		++sqrt;

	if (SQUARE(sqrt) != length)
		return 3;

	const size_t key_length = strlen(key);
	schar_t index_key[key_length + 1];

	strcpy(index_key, key);
	_to_index_hill(index_key);

	const INTEGER_TYPE det = get_determinant(index_key, sqrt);
	if (!(det % __length_alpha_hill))
		return 4;

	switch (mode) {
		case ENCRYPT_MODE:
			_encrypt_hill(to, sqrt, index_key, from);
		break;
		case DECRYPT_MODE:
			_decrypt_hill(to, sqrt, det, index_key, from);
		break;
	}

	return 0;
}
