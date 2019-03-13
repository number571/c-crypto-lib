#include <stdint.h>
#include <string.h>

#include "../utils/funcs/insertion_sort.h"
#include "../utils/funcs/index_vector.h"

#include "../utils/macro/consts.h"
#include "../utils/macro/funcs.h"

static uint8_t __default_char_horizontal = 'X';
static uint8_t __default_char_vertical = 'Z';

static void _index_sorted_key (uint8_t * const indexed_key, const int8_t mode, const size_t length_key, uint8_t * const key) {
	uint8_t sorted_key[length_key + 1];
	strcpy(sorted_key, key);
	_insertion_sort(sorted_key, length_key);

	if (mode == ENCRYPT_MODE)
		_index_vector(indexed_key, key, sorted_key, length_key);
	else
		_index_vector(indexed_key, sorted_key, key, length_key);
}

static void _encrypt_horizontal (uint8_t * to, uint8_t * const key, const uint8_t * const from) {
	const size_t length_key = strlen(key);
	size_t start_length = strlen(from);

	const size_t final_length = ALIGNH(start_length, length_key);

	const size_t col_length = final_length / length_key;
	const size_t row_length = final_length / col_length;

	uint8_t indexed_key[length_key];
	_index_sorted_key(indexed_key, ENCRYPT_MODE, length_key, key);

	uint8_t buffer[final_length + 1];
	strcpy(buffer, from);

	while (start_length < final_length)
		buffer[start_length++] = __default_char_horizontal;

	for (size_t x = 0; x < row_length; ++x)
		for (size_t y = 0; y < col_length; ++y)
			*to++ = buffer[row_length * y + indexed_key[x]];

	*to = END_OF_STRING;
}

static void _decrypt_horizontal (uint8_t * to, uint8_t * const key, const uint8_t * const from) {
	const size_t length_key = strlen(key);
	const size_t start_length = strlen(from);

	const size_t final_length = ALIGNL(start_length, length_key);

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

static void _encrypt_vertical (const int8_t mode, uint8_t * to, uint8_t * const key, const uint8_t * const from) {
	const size_t length_key = strlen(key);
	size_t start_length = strlen(from);

	const size_t final_length = ALIGNH(start_length, length_key);

	const size_t col_length = final_length / length_key;
	const size_t row_length = final_length / col_length;

	uint8_t indexed_key[length_key];
	_index_sorted_key(indexed_key, mode, length_key, key);

	uint8_t buffer[final_length + 1];
	strcpy(buffer, from);

	while (start_length < final_length) 
		buffer[start_length++] = __default_char_vertical;

	for (size_t y = 0; y < col_length; ++y)
		for (size_t x = 0; x < row_length; ++x)
			*to++ = buffer[row_length * y + indexed_key[x]];

	*to = END_OF_STRING;
}

extern char set_char_permutation_double (const uint8_t ch1, const uint8_t ch2) {
	__default_char_horizontal = ch1;
	__default_char_vertical = ch2;
}

extern char permutation_double (
	uint8_t * const to,
	const int8_t mode,
	uint8_t * const key1,
	uint8_t * const key2,
	const uint8_t * const from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	if (mode == ENCRYPT_MODE) {
		size_t length = strlen(from);
		const size_t length_key1 = strlen(key1);
		const size_t length_key2 = strlen(key2);

		length = ALIGNH(length, length_key1);
		length = ALIGNH(length, length_key2);

		if (!(length % length_key1) && !(length % length_key2))
			return 2;
	}
	
	switch (mode) {
		case ENCRYPT_MODE:
			_encrypt_horizontal(to, key1, from);
			_encrypt_vertical(mode, to, key2, to);
		break;
		case DECRYPT_MODE:
			_encrypt_vertical(mode, to, key2, from);
			_decrypt_horizontal(to, key1, to);
		break;
	}

	return 0;
}
