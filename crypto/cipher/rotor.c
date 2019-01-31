#include <string.h>

#include "../append/macro/consts.h"
#include "../append/types/char.h"

static uchar_t __alpha_rotor[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static uchar_t __length_alpha_rotor = LEN_ALPHA;

static uchar_t _char_rotor (const schar_t mode, schar_t key, const uchar_t ch) {
	key = ( (key < 0) ? (__length_alpha_rotor + (key % __length_alpha_rotor)) : (key % __length_alpha_rotor) ) * mode;

	for (uchar_t *p = __alpha_rotor; *p != END_OF_STRING; ++p)
		if (*p == ch)
			return __alpha_rotor[(p - __alpha_rotor + key + __length_alpha_rotor) % __length_alpha_rotor];

	return ch;
}

extern schar_t set_alpha_rotor (const uchar_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	__length_alpha_rotor = (uchar_t)length;
	strcpy(__alpha_rotor, alpha);

	return 0;
}

extern char rotor (
	uchar_t * to,
	const schar_t mode, 
	const uchar_t period, 
	schar_t * const rot, 
	const uchar_t * const from
) {
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	if (!period) 
		return 2;

	schar_t *key = rot;

	if (*key == END_OF_NUMBER)
		return 3;

	for (size_t index = 0; from[index] != END_OF_STRING; ++index) {
		if (index && !(index % period)) {
			++key;
			if (*key == END_OF_NUMBER) 
				key = rot;
		}

		*to++ = _char_rotor(mode, *key, from[index]);
	}

	*to = END_OF_STRING;

	return 0;
}
