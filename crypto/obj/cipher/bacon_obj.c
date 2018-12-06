#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../bacon.h"
#include "../bacon_obj.h"

#include "../../append/macro.h"
#include "../../append/types.h"

static void _free_memsize_bacon (void) {
	free(bacon_obj.message);
}

static void _set_memsize_bacon (const size_t size) {
	bacon_obj.message = (char *)malloc(size * sizeof(char));
}

static void _set_message_bacon (const char * const from) {
	strcpy(bacon_obj.message, from);
}

static char _to_string_bacon (char * const to) {
	if (!bacon_obj.encrypted)
		return -1;

	to_string_bacon(to, bacon_obj.message);
	return 0;
}

static char _to_bytes_bacon (char * const to) {
	if (!bacon_obj.encrypted)
		return -1;

	to_bytes_bacon(to, bacon_obj.message);
	return 0;
}

static void _print_bacon (void) {
	if (bacon_obj.encrypted)
		print_bacon(bacon_obj.message);
	else
		printf("%s", bacon_obj.message);
}

static void _println_bacon (void) {
	if (bacon_obj.encrypted)
		println_bacon(bacon_obj.message);
	else
		printf("%s\n", bacon_obj.message);
}

static char _encrypt_bacon (void) {
	if (bacon_obj.encrypted)
		return -1;

	bacon_obj.encrypted = true;
	return bacon(bacon_obj.message, ENCRYPT_MODE, bacon_obj.message);
}

static char _decrypt_bacon (void) {
	if (!bacon_obj.encrypted)
		return -1;

	bacon_obj.encrypted = false;
	return bacon(bacon_obj.message, DECRYPT_MODE, bacon_obj.message);
}

BACON bacon_obj = {
	.encrypted 	  = false,
	.free_memsize = _free_memsize_bacon,
	.set_memsize  = _set_memsize_bacon,
	.set_message  = _set_message_bacon,
	.set_alpha 	  = set_alpha_bacon,
	.set_char     = set_char_bacon,
	.to_string    = _to_string_bacon,
	.to_bytes     = _to_bytes_bacon,
	.print	      = _print_bacon,
	.println      = _println_bacon,
	.encrypt      = _encrypt_bacon,
	.decrypt      = _decrypt_bacon,
};
