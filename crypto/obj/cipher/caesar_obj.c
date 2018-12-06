#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../caesar.h"
#include "../caesar_obj.h"

#include "../../append/macro.h"

static void _free_memsize_caesar (void) {
	free(caesar_obj.message);
}

static void _set_memsize_caesar (const size_t size) {
	caesar_obj.message = (char *)malloc(size * sizeof(char));
}

static void _set_message_caesar (const char * const from) {
	strcpy(caesar_obj.message, from);
}

static void _print_caesar (void) {
	printf("%s", caesar_obj.message);
}

static void _println_caesar (void) {
	printf("%s\n", caesar_obj.message);
}

static char _encrypt_caesar (const char key) {
	return caesar(caesar_obj.message, ENCRYPT_MODE, key, caesar_obj.message);
}

static char _decrypt_caesar (const char key) {
	return caesar(caesar_obj.message, DECRYPT_MODE, key, caesar_obj.message);
}

CAESAR caesar_obj = {
	.free_memsize = _free_memsize_caesar,
	.set_memsize  = _set_memsize_caesar,
	.set_message  = _set_message_caesar,
	.set_alpha 	  = set_alpha_caesar,
	.print	      = _print_caesar,
	.println      = _println_caesar,
	.encrypt      = _encrypt_caesar,
	.decrypt      = _decrypt_caesar,
};
