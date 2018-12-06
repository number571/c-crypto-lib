#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../polybius.h"
#include "../polybius_obj.h"

#include "../../append/macro.h"
#include "../../append/types.h"

static void _free_memsize_polybius (void) {
	free(polybius_obj.message);
}

static void _set_memsize_polybius (const size_t size) {
	polybius_obj.message = (char *)malloc(size * sizeof(char));
}

static void _set_message_polybius (const char * const from) {
	strcpy(polybius_obj.message, from);
}

static char _to_string_polybius (char * const to) {
	if (!polybius_obj.encrypted)
		return -1;

	to_string_polybius(to, polybius_obj.message);
	return 0;
}

static char _to_bytes_polybius (char * const to) {
	if (!polybius_obj.encrypted)
		return -1;

	to_bytes_polybius(to, polybius_obj.message);
	return 0;
}

static void _print_polybius (void) {
	if (polybius_obj.encrypted)
		print_nums(char, polybius_obj.message);
	else
		printf("%s", polybius_obj.message);
}

static void _println_polybius (void) {
	if (polybius_obj.encrypted)
		println_nums(char, polybius_obj.message);
	else
		printf("%s\n", polybius_obj.message);
}

static char _encrypt_polybius (void) {
	if (polybius_obj.encrypted)
		return -1;

	polybius_obj.encrypted = true;
	return polybius(polybius_obj.message, ENCRYPT_MODE, polybius_obj.message);
}

static char _decrypt_polybius (void) {
	if (!polybius_obj.encrypted)
		return -1;

	polybius_obj.encrypted = false;
	return polybius(polybius_obj.message, DECRYPT_MODE, polybius_obj.message);
}

POLYBIUS polybius_obj = {
	.encrypted 	  = false,
	.free_memsize = _free_memsize_polybius,
	.set_memsize  = _set_memsize_polybius,
	.set_message  = _set_message_polybius,
	.set_alpha 	  = set_alpha_polybius,
	.to_string    = _to_string_polybius,
	.to_bytes     = _to_bytes_polybius,
	.print	      = _print_polybius,
	.println      = _println_polybius,
	.encrypt      = _encrypt_polybius,
	.decrypt      = _decrypt_polybius,
};
