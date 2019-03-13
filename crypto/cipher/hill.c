#include <stdint.h>
#include <string.h>

#include "../utils/funcs/transpose.h"
#include "../utils/funcs/algebraic.h"
#include "../utils/funcs/determinant.h"

#include "../utils/macro/consts.h"
#include "../utils/macro/funcs.h"
#include "../utils/macro/copy.h"

#include "../utils/types/integer.h"

static uint8_t __alpha[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static uint8_t __length_alpha = LEN_ALPHA;

static uint8_t __default_char = 'Z';

static int8_t _char_encrypt (const uint8_t ch) {
	for (uint8_t *p = __alpha; *p != END_OF_STRING; ++p)
		if (ch == *p)
			return p - __alpha;
	
	return ch + END_OF_NUMBER;
}

static void _to_index (int8_t * to) {
	for (; *to != END_OF_STRING; ++to)
		*to = _char_encrypt(*to);

	*to = END_OF_NUMBER;
}

static void _to_string (int8_t * to) {
	for (; *to != END_OF_NUMBER; ++to)
		*to = __alpha[*to];

	*to = END_OF_STRING;
}

static void _multiply_matrix (uint8_t * to, const uint8_t sqrt, uint8_t * key) {
	__INTEGER__ buffer[sqrt];
	memset(buffer, 0, sqrt * sizeof(__INTEGER__));

	for (uint8_t x = 0; x < sqrt; ++x) {
		for (uint8_t y = 0; y < sqrt; ++y)
			buffer[x] += key[x * sqrt + y] * to[y];
		buffer[x] %= __length_alpha;
	}

	for (uint8_t x = 0; x < sqrt; ++x)
		*to++ = buffer[x];
}

static void _encrypt (uint8_t * to, const uint8_t sqrt, uint8_t * index_key, uint8_t * from) {
	size_t start_length, final_length;
	start_length = final_length = strlen(from);

	while (final_length % sqrt != 0)
		++final_length;

	int8_t buffer[final_length + 1];
	strcpy(buffer, from);

	while (start_length++ < final_length)
		buffer[start_length - 1] = __default_char;

	buffer[final_length] = END_OF_STRING;
	_to_index(buffer);

	for (int8_t *p_buffer = buffer; *p_buffer != END_OF_NUMBER; p_buffer += sqrt)
		_multiply_matrix(p_buffer, sqrt, index_key);

	_to_string(buffer);
	strcpy(to, buffer);
}

static void _decrypt (uint8_t * to, const uint8_t sqrt, const __INTEGER__ det, uint8_t * index_key, uint8_t * from) {
	uint8_t algbrs[SQUARE(sqrt)];

	_algebraic(algbrs, index_key, sqrt, det, __length_alpha);
	_transpose(algbrs, sqrt);

	const size_t length = strlen(from);
	int8_t buffer[length + 1];

	strcpy(buffer, from);
	_to_index(buffer);

	for (int8_t *p_buffer = buffer; *p_buffer != END_OF_NUMBER; p_buffer += sqrt)
		_multiply_matrix(p_buffer, sqrt, algbrs);

	_to_string(buffer);
	strcpy(to, buffer);
}

extern void set_char_encrypt (const uint8_t ch) {
	__default_char = ch;
}

extern char set_alpha_hill (const uint8_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	__length_alpha = (uint8_t)length;
	strcpy(__alpha, alpha);

	return 0;
}

extern char hill (
	uint8_t * to,
	const int8_t mode,
	uint8_t * key,
	uint8_t * from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	const size_t length = strlen(key);
	if (length >= MAX_LENGTH)
		return 2;

	uint8_t sqrt = 1;
	while (SQUARE(sqrt) < length)
		++sqrt;

	if (SQUARE(sqrt) != length)
		return 3;

	const size_t key_length = strlen(key);
	int8_t index_key[key_length + 1];

	strcpy(index_key, key);
	_to_index(index_key);

	const __INTEGER__ det = _determinant(index_key, sqrt);
	if (!(det % __length_alpha))
		return 4;

	switch (mode) {
		case ENCRYPT_MODE:
			_encrypt(to, sqrt, index_key, from);
		break;
		case DECRYPT_MODE:
			_decrypt(to, sqrt, det, index_key, from);
		break;
	}

	return 0;
}
