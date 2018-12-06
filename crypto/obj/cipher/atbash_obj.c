#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../atbash.h"
#include "../atbash_obj.h"

static void _free_memsize_atbash (void) {
	free(atbash_obj.message);
}

static void _set_memsize_atbash (const size_t size) {
	atbash_obj.message = (char *)malloc(size * sizeof(char));
}

static void _set_message_atbash (const char * const from) {
	strcpy(atbash_obj.message, from);
}

static void _print_atbash (void) {
	printf("%s", atbash_obj.message);
}

static void _println_atbash (void) {
	printf("%s\n", atbash_obj.message);
}

static char _encrypt_atbash (void) {
	return atbash(atbash_obj.message, atbash_obj.message);
}

ATBASH atbash_obj = {
	.free_memsize = _free_memsize_atbash,
	.set_memsize  = _set_memsize_atbash,
	.set_message  = _set_message_atbash,
	.set_alpha    = set_alpha_atbash,
	.print        = _print_atbash,
	.println      = _println_atbash,
	.encrypt      = _encrypt_atbash,
	.decrypt      = _encrypt_atbash,
};
