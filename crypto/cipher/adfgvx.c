#include <string.h>

#include "../append/macro/consts.h"
#include "../append/macro/funcs.h"
#include "../append/types/char.h"
#include "../append/types/point.h"
#include "../append/funcs/insertion_sort.h"
#include "../append/funcs/get_coordinates.h"

#define MAX_CHARS 12

static uchar_t __alph1_adfgvx[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
static uchar_t __alph2_adfgvx[MAX_CHARS + 1] = "ADFGVX";

static uchar_t __sqrt_length_alpha_adfgvx = 6;
static uchar_t __default_char_adfgvx = 'X';

static void _encrypt_substitution_adfgvx (uchar_t * const to, const uchar_t * from) {
	const size_t length = strlen(from);

	uchar_t buffer[length * 2 + 1];
	uchar_t *p_buffer = buffer;

	for (; *from != END_OF_STRING; ++from) {
		Point pos = get_coordinates(*from, __alph1_adfgvx, __sqrt_length_alpha_adfgvx);

		if (pos.x != -1) {
			*p_buffer++ = __alph2_adfgvx[pos.x];
			*p_buffer++ = __alph2_adfgvx[pos.y];
		} else {
			*p_buffer++ = __default_char_adfgvx;
			*p_buffer++ = *from;
		}
	}

	*p_buffer = END_OF_STRING;
	strcpy(to, buffer);
}

static void _index_key_adfgvx (uchar_t * const indexed_key, uchar_t * const key, uchar_t * const sorted, const size_t length_key) {
	uchar_t checked[length_key];
	memset(checked, 0, length_key * sizeof(uchar_t));

	for (uchar_t *p_sorted = sorted; (p_sorted - sorted) < length_key; ++p_sorted)
		for (uchar_t *p_key = key; (p_key - key) < length_key; ++p_key)
			if (*p_key == *p_sorted && !checked[p_key - key]) {
				indexed_key[p_sorted - sorted] = p_key - key;
				checked[p_key - key] = 1;
				break;
			}
}

static size_t _get_length_adfgvx(const size_t length_key, const uchar_t * const from) {
	size_t final_length = strlen(from);

	while (final_length % length_key != 0)
		++final_length;

	return final_length;
}

static void _index_sorted_key_adfgvx (const schar_t mode, const size_t length_key, uchar_t * const key, uchar_t * indexed_key) {
	uchar_t sorted_key[length_key + 1];
	strcpy(sorted_key, key);
	insertion_sort(sorted_key, length_key);

	if (mode == ENCRYPT_MODE)
		_index_key_adfgvx(indexed_key, key, sorted_key, length_key);
	else
		_index_key_adfgvx(indexed_key, sorted_key, key, length_key);
}

static void _encrypt_permutation_adfgvx (uchar_t * to, uchar_t * const key, const uchar_t * const from) {
	const size_t length_key = strlen(key);
	size_t start_length = strlen(from);
	size_t final_length = _get_length_adfgvx(length_key, from);

	const size_t col_length = final_length / length_key;
	const size_t row_length = final_length / col_length;

	uchar_t indexed_key[length_key];
	_index_sorted_key_adfgvx(ENCRYPT_MODE, length_key, key, indexed_key);

	uchar_t buffer[final_length + 1];
	strcpy(buffer, from);

	while (start_length++ < final_length)
		buffer[start_length - 1] = __default_char_adfgvx;

	for (size_t x = 0; x < row_length; ++x)
		for (size_t y = indexed_key[x]; y < final_length; y += row_length)
			*to++ = buffer[y];

	*to = END_OF_STRING;
}

static void _decrypt_permutation_adfgvx (uchar_t * to, uchar_t * const key, const uchar_t * const from) {
	const size_t length_key = strlen(key);
	size_t final_length = _get_length_adfgvx(length_key, from);

	const size_t col_length = final_length / length_key;
	const size_t row_length = final_length / col_length;

	uchar_t indexed_key[length_key];
	_index_sorted_key_adfgvx(DECRYPT_MODE, length_key, key, indexed_key);

	uchar_t buffer[final_length + 1];
	strcpy(buffer, from);

	for (size_t y = 0; y < col_length; ++y)
		for (size_t x = 0; x < row_length; ++x)
			*to++ = buffer[y + indexed_key[x] * col_length];

	*to = END_OF_STRING;
}

static void _decrypt_substitution_adfgvx (uchar_t * to, const uchar_t * from) {
	for (; *from != END_OF_STRING; from += 2) {
		Point pos = {-1, -1};

		for (uchar_t *p = __alph2_adfgvx; *p != END_OF_STRING; ++p) {
			if (*p == *from)
				pos.x = p - __alph2_adfgvx;

			if (*p == *(from + 1))
				pos.y = p - __alph2_adfgvx;

			if (pos.x != -1 && pos.y != -1)
				break;
		}

		if (pos.x != -1 && pos.y != -1)
			*to++ = __alph1_adfgvx[pos.y + pos.x * __sqrt_length_alpha_adfgvx];
		else
			*to++ = *(from + 1);
	}

	*to = END_OF_STRING;
}

extern char set_char_adfgvx (const uchar_t ch) {
	__default_char_adfgvx = ch;
}

extern char set_alpha_adfgvx (const uchar_t * const alph1, const uchar_t * const alph2) {
	const size_t alph1_length = strlen(alph1);
	const size_t alph2_length = strlen(alph2);

	if (alph2_length > MAX_CHARS)
		return 1;

	if (alph2_length < __sqrt_length_alpha_adfgvx)
		return 2;

	strcpy(__alph2_adfgvx, alph2);

	if (alph1_length >= MAX_LENGTH)
		return 3;

	uchar_t sqrt = 1;
	while (SQUARE(sqrt) < alph1_length)
		++sqrt;

	if (sqrt > alph2_length)
		return 4;

	__sqrt_length_alpha_adfgvx = sqrt;
	strcpy(__alph1_adfgvx, alph1);

	return 0;
}

extern char adfgvx (
	uchar_t * const to,
	const schar_t mode,
	uchar_t * const key,
	const uchar_t * const from
) {
	switch (mode) {
		case ENCRYPT_MODE:
			_encrypt_substitution_adfgvx(to, from);
			_encrypt_permutation_adfgvx(to, key, to);
		break;
		case DECRYPT_MODE:
			_decrypt_permutation_adfgvx(to, key, from);
			_decrypt_substitution_adfgvx(to, to);
		break;
		default: return 1;
	}

	return 0;
}
