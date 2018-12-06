#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../playfair.h"
#include "../playfair_obj.h"

#include "../../append/macro.h"

static void _free_memsize_playfair (void) {
	free(playfair_obj.message);
}

static void _set_memsize_playfair (const size_t size) {
	playfair_obj.message = (char *)malloc(size * sizeof(char));
}

static void _set_message_playfair (const char * const from) {
	strcpy(playfair_obj.message, from);
}

static void _print_playfair (void) {
	printf("%s", playfair_obj.message);
}

static void _println_playfair (void) {
	printf("%s\n", playfair_obj.message);
}

static char _encrypt_playfair (char * const key) {
	return playfair(playfair_obj.message, ENCRYPT_MODE, key, playfair_obj.message);
}

static char _decrypt_playfair (char * const key) {
	return playfair(playfair_obj.message, DECRYPT_MODE, key, playfair_obj.message);
}

PLAYFAIR playfair_obj = {
	.free_memsize = _free_memsize_playfair,
	.set_memsize  = _set_memsize_playfair,
	.set_message  = _set_message_playfair,
	.set_alpha 	  = set_alpha_playfair,
	.set_char	  = set_char_playfair,
	.print	      = _print_playfair,
	.println      = _println_playfair,
	.encrypt      = _encrypt_playfair,
	.decrypt      = _decrypt_playfair,
};
