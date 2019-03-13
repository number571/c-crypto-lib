#include <stdint.h>
#include <string.h>

#include "../utils/funcs/insertion_sort.h"
#include "../utils/funcs/index_vector.h"
#include "../utils/funcs/coordinates.h"

#include "../utils/macro/consts.h"
#include "../utils/macro/funcs.h"

#include "../utils/types/point.h"

#define MAX_CHARS (12 + 1)

static uint8_t __alph1[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
static uint8_t __alph2[MAX_CHARS] = "ADFGVX";

static uint8_t __sqrt_length_alph2 = 6;
static uint8_t __default_char = 'X';

static void _encrypt_substitution (uint8_t * const to, const uint8_t * from) {
	const size_t length = strlen(from);

	uint8_t buffer[length * 2 + 1];
	uint8_t *p_buffer = buffer;

	for (; *from != END_OF_STRING; ++from) {
		Point pos = _coordinates(*from, __alph1, __sqrt_length_alph2);

		if (pos.x != -1) {
			*p_buffer++ = __alph2[pos.x];
			*p_buffer++ = __alph2[pos.y];
		} else {
			*p_buffer++ = __default_char;
			*p_buffer++ = *from;
		}
	}

	*p_buffer = END_OF_STRING;
	strcpy(to, buffer);
}

static void _index_sorted_key (uint8_t * const indexed_key, const int8_t mode, const size_t length_key, uint8_t * const key) {
	uint8_t sorted_key[length_key + 1];
	strcpy(sorted_key, key);
	_insertion_sort(sorted_key, length_key);

	if (mode == ENCRYPT_MODE)
		_index_vector(indexed_key, key, sorted_key, length_key);
	else
		_index_vector(indexed_key, sorted_key, key, length_key);
}

static void _encrypt_permutation (uint8_t * to, uint8_t * const key, const uint8_t * const from) {
	const size_t length_key = strlen(key);
	size_t start_length = strlen(from);

	const size_t final_length = ALIGNH(start_length, length_key);

	const size_t col_length = final_length / length_key;
	const size_t row_length = final_length / col_length;

	uint8_t indexed_key[length_key];
	_index_sorted_key(indexed_key, ENCRYPT_MODE, length_key, key);

	uint8_t buffer[final_length + 1];
	strcpy(buffer, from);

	while (start_length++ < final_length)
		buffer[start_length - 1] = __default_char;

	for (size_t x = 0; x < row_length; ++x)
		for (size_t y = 0; y < col_length; ++y)
			*to++ = buffer[row_length * y + indexed_key[x]];

	*to = END_OF_STRING;
}

static void _decrypt_permutation (uint8_t * to, uint8_t * const key, const uint8_t * const from) {
	const size_t length_key = strlen(key);
	const size_t start_length = strlen(from);
	
	const size_t final_length = ALIGNH(start_length, length_key);

	const size_t col_length = final_length / length_key;
	const size_t row_length = final_length / col_length;

	uint8_t indexed_key[length_key];
	_index_sorted_key(indexed_key, DECRYPT_MODE, length_key, key);

	uint8_t buffer[final_length + 1];
	strcpy(buffer, from);

	for (size_t y = 0; y < col_length; ++y)
		for (size_t x = 0; x < row_length; ++x)
			*to++ = buffer[col_length * indexed_key[x] + y];

	*to = END_OF_STRING;
}

static void _decrypt_substitution (uint8_t * to, const uint8_t * from) {
	for (; *from != END_OF_STRING; from += 2) {
		Point pos = {-1, -1};

		for (uint8_t *p = __alph2; *p != END_OF_STRING; ++p) {
			if (*p == *from)
				pos.x = p - __alph2;

			if (*p == *(from + 1))
				pos.y = p - __alph2;

			if (pos.x != -1 && pos.y != -1)
				break;
		}

		if (pos.x != -1 && pos.y != -1)
			*to++ = __alph1[pos.y + pos.x * __sqrt_length_alph2];
		else
			*to++ = *(from + 1);
	}

	*to = END_OF_STRING;
}

extern char set_char_adfgvx (const uint8_t ch) {
	__default_char = ch;
}

extern char set_alpha_adfgvx (const uint8_t * const alph1, const uint8_t * const alph2) {
	const size_t alph1_length = strlen(alph1);
	const size_t alph2_length = strlen(alph2);

	if (alph2_length > MAX_CHARS)
		return 1;

	if (alph2_length < __sqrt_length_alph2)
		return 2;

	strcpy(__alph2, alph2);

	if (alph1_length >= MAX_LENGTH)
		return 3;

	uint8_t sqrt = 1;
	while (SQUARE(sqrt) < alph1_length)
		++sqrt;

	if (sqrt > alph2_length)
		return 4;

	__sqrt_length_alph2 = sqrt;
	strcpy(__alph1, alph1);

	return 0;
}

extern char adfgvx (
	uint8_t * const to,
	const int8_t mode,
	uint8_t * const key,
	const uint8_t * const from
) {
	switch (mode) {
		case ENCRYPT_MODE:
			_encrypt_substitution(to, from);
			_encrypt_permutation(to, key, to);
		break;
		case DECRYPT_MODE:
			_decrypt_permutation(to, key, from);
			_decrypt_substitution(to, to);
		break;
		default: return 1;
	}

	return 0;
}
